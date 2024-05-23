#include "Window.h"
#define GLEW_STATIC 1
#include <GL/glew.h>
#include <GLFW/glfw3.h>

Window::Window() {
    w = 800;
    h = 600;

    for(size_t i = 0; i < 1024; i++)
    {
        keys[i] = 0;
    }

    xChange = 0.0f;
    yChange = 0.0f;

}

Window::Window(GLint windowWidth, GLint windowHeight)
{
    w = windowWidth;
    h = windowHeight;

    xChange = 0.0f;
    yChange = 0.0f;

    for(size_t i = 0; i < 1024; i++)
    {
        keys[i] = 0;
    }
}

int Window::Initialise()
{
    // Going bit by bit here, old code is commented out for now
    // Initialize GLFW

    fprintf(stderr, "initialization beginning\n");

    if (!glfwInit())
    {   
        fprintf(stderr, "GLFW initialization failed!\n");

        int code = glfwGetError(NULL);
 
        if (code != GLFW_NO_ERROR)
            fprintf(stderr, "Error code %d\n", code);

        glfwTerminate();
        return 1;
    }
    
    // Setup GLFW window properties
    // OpenGL version
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    // Core profile = No Backwards Compatibility
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    // Allow forward compatibility
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);

    mainWIn = glfwCreateWindow(w, h, "Test Window", NULL, NULL);

    if (!mainWIn) 
    {
        printf("GLFW window creation failed!");
        glfwTerminate();
        return 1;
    }

    // Get Buffer size information
    glfwGetFramebufferSize(mainWIn, &bufferWidth, &bufferHeight);

    // Set context for GLEW to use
    glfwMakeContextCurrent(mainWIn);

    // HAndle key + mouse input
    createCallbacks();
    glfwSetInputMode(mainWIn, GLFW_CURSOR, GLFW_CURSOR_DISABLED);

    fprintf(stderr, "glew experimental on\n");
    // Allow modern extension features
    glewExperimental = GL_TRUE;

    fprintf(stderr, "glew init\n");
    GLenum error = glewInit();
    if (error != GLEW_OK) {
        printf("Error: %s", glewGetErrorString(error));
        glfwDestroyWindow(mainWIn);
        glfwTerminate();
        return 1;
    }

    glEnable(GL_DEPTH_TEST);

    // Setup Viewport size
    glViewport(0, 0, bufferWidth, bufferHeight);

    glfwSetWindowUserPointer(mainWIn, this);
    //glfwSwapInterval(1);
    glfwSwapBuffers(mainWIn);
    return 0;
}

void Window::frameBufferSizeCallback(GLFWwindow* window, int w, int h) {
    glViewport(0, 0, w, h);
}

void Window::createCallbacks() {
    glfwSetKeyCallback(mainWIn, handleKeys);
    glfwSetCursorPosCallback(mainWIn, handleMouse);
}

GLfloat Window::getXChange() {
    GLfloat theChange = xChange;
    xChange = 0.0f;
    return theChange;
}

GLfloat Window::getYChange() {
    GLfloat theChange = yChange;
    yChange = 0.0f;
    return theChange;
}

GLFWwindow* Window::getWindow() {
    return mainWIn;
}

void Window::handleKeys(GLFWwindow* window, int key, int code, int action, int mode)
{
    Window* theWindow = static_cast<Window*>(glfwGetWindowUserPointer(window));

    if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS){
        glfwSetWindowShouldClose(window, GL_TRUE);
    }

    if (key == GLFW_KEY_ENTER && action == GLFW_PRESS){
        theWindow->rainTrue = !theWindow->rainTrue;
    }
    if (key == GLFW_KEY_SPACE && action == GLFW_PRESS){
        theWindow->splashTrue = !theWindow->splashTrue;
    }

    if(key >= 0 && key < 1024){
        if (action == GLFW_PRESS)
        {
            theWindow->keys[key] = true;
        }
        else if (action == GLFW_RELEASE)
        {
            theWindow->keys[key] = false;
        }
    }
}

void Window::handleMouse(GLFWwindow* window, double xPos, double yPos) {
    Window* theWindow = static_cast<Window*>(glfwGetWindowUserPointer(window));

    if (theWindow->mouseFirstMoved)
    {
        theWindow->lastX = xPos;
        theWindow->lastY = yPos;
        theWindow->mouseFirstMoved = false;
    }

    theWindow->xChange = xPos - theWindow->lastX;
    theWindow->yChange = theWindow->lastY - yPos;

    theWindow->lastX = xPos;
    theWindow->lastY = yPos;
}

Window::~Window()
{
    glfwDestroyWindow(mainWIn);
    glfwTerminate();
}