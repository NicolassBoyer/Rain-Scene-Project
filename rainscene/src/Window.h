#ifndef WINDOW_H
#define WINDOW_H

#include <stdio.h>

#define GLEW_STATIC 1
#include <GL/glew.h>
#include <GLFW/glfw3.h>

class Window
{
public:
    Window();
    ~Window();
    Window(GLint windowWidth, GLint windowHeight);

    int Initialise();

    GLfloat GetBufferWidth() { return bufferWidth; }
    GLfloat GetBufferHeight() { return bufferHeight; }

    bool GetShouldClose() { return glfwWindowShouldClose(mainWIn); }
    void frameBufferSizeCallback(GLFWwindow* window, int w, int h);

    bool* getKeys() { return keys; }
    GLfloat getXChange();
    GLfloat getYChange();

    void SwapBuffers() { glfwSwapBuffers(mainWIn); }
    GLFWwindow* getWindow();

    bool rainTrue = true;
    bool splashTrue = true;
private:
    GLFWwindow *mainWIn;

    GLint w, h;
    GLint bufferWidth, bufferHeight;

    bool keys[1024];

    GLfloat lastX;
    GLfloat lastY;
    GLfloat xChange;
    GLfloat yChange;
    bool mouseFirstMoved;

    void createCallbacks();
    static void handleKeys(GLFWwindow* window, int key, int code, int action, int mode);
    static void handleMouse(GLFWwindow* window, double xPos, double yPos);
};

#endif