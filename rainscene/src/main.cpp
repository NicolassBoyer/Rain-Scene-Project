

#include <stdio.h>
#include <string.h>
#include <cmath>
#include <vector>
#include <cstdlib>
#include <random>

#define GLEW_STATIC 1

#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include "CommonValues.h"

#include "Window.h"
#include "Mesh.h"
#include "Shader.h"
#include "Camera.h"
#include "Texture.h"
#include "DirectionalLight.h"
#include "PointLight.h"
#include "Material.h"
#include "SpotLight.h"
#include "Model.h"

#include <glm/ext/vector_float3.hpp>
#include <glm/gtx/norm.hpp>
#include <glm/gtx/quaternion.hpp>

const float toRadians = 3.14159265f / 180.0f;

#define MAX_PARTICLES 1000

// Window and lists
Window mainWindow;
std::vector<Mesh*> MeshList;
std::vector<Shader> shaderList;
Camera camera;

// Textures
Texture groundAsphalt;
Texture pavement;
Texture mud;
Texture plain;
Texture steel;
Texture bark;
Texture blue;
Texture grayLeaves;
Texture greenLeaves;
Texture wood;

// Materials
Material shinyMaterial;
Material dullMaterial;

Model lamp;
Model tree;
Model raindrop;
Model bench;

// Lights
DirectionalLight mainLight;
PointLight pointLights[MAX_POINT_LIGHTS];
SpotLight spotLights[MAX_SPOT_LIGHTS];

// Time values
GLfloat deltaTime = 0.0f;
GLfloat lastTime = 0.0f;

std::random_device rd;
std::mt19937 gen(rd());

struct Particle {
    // life
    bool alive;
    float life;
    float fade;
    // Position and direction
    float xpos;
    float ypos;
    float zpos;
    // direction, only goes down
    float spd;

    float xscale;
    float yscale;
    float zscale;
    // Gravity
    float gravity;
};

// System
float slowDown = 1.0f;
float speed = 1.0f;
float size = 1.0f;
int i;
int fall;
float r = 0.0f;
float g = 1.0f;
float b = 0.0f;
float groundPts[21][21][3];
float accum = -10.0f;
Particle parSys[MAX_PARTICLES];
Particle puddleSys[MAX_PARTICLES];

// Vertex Shader
static const char* vShader = "../shaders/shader.vert";

// Fragment Shader
static const char* fShader = "../shaders/shader.frag";


const int maxParticles = 10000;
Particle particlesContainer[maxParticles];
Particle puddleContainer[maxParticles];
int lastUsedParticle = 0;
int delta = 1;


void calcAverageNormals(unsigned int * indices, unsigned int indiceCount, GLfloat * vertices, unsigned int verticeCount, unsigned int vLength, 
                        unsigned int normalOffset){
	for (size_t i = 0; i < indiceCount; i += 3)
	{
		unsigned int in0 = indices[i] * vLength;
		unsigned int in1 = indices[i + 1] * vLength;
		unsigned int in2 = indices[i + 2] * vLength;
		glm::vec3 v1(vertices[in1] - vertices[in0], vertices[in1 + 1] - vertices[in0 + 1], vertices[in1 + 2] - vertices[in0 + 2]);
		glm::vec3 v2(vertices[in2] - vertices[in0], vertices[in2 + 1] - vertices[in0 + 1], vertices[in2 + 2] - vertices[in0 + 2]);
		glm::vec3 normal = glm::cross(v1, v2);
		normal = glm::normalize(normal);
		
		in0 += normalOffset; in1 += normalOffset; in2 += normalOffset;
		vertices[in0] += normal.x; vertices[in0 + 1] += normal.y; vertices[in0 + 2] += normal.z;
		vertices[in1] += normal.x; vertices[in1 + 1] += normal.y; vertices[in1 + 2] += normal.z;
		vertices[in2] += normal.x; vertices[in2 + 1] += normal.y; vertices[in2 + 2] += normal.z;
	}

	for (size_t i = 0; i < verticeCount / vLength; i++)
	{
		unsigned int nOffset = i * vLength + normalOffset;
		glm::vec3 vec(vertices[nOffset], vertices[nOffset + 1], vertices[nOffset + 2]);
		vec = glm::normalize(vec);
		vertices[nOffset] = vec.x; vertices[nOffset + 1] = vec.y; vertices[nOffset + 2] = vec.z;
	}
}

void CreateObjects()
{


    fprintf(stderr, "CreateObjects starting\n");
    unsigned int indices[] = {
        0, 3, 1,
        1, 3, 2,
        2, 3, 0,
        0, 1, 2
    };

    GLfloat vertices[] = {
    //  x      y       z         u      v       nx     ny   nz
        -1.0f, -1.0f, -0.6f,     0.0f, 0.0f,     0.0f, 0.0f, 0.0f,
        0.0f, -1.0, 1.0f,       0.5f, 0.0f,     0.0f, 0.0f, 0.0f,
        1.0f, -1.0f, -0.6f,      1.0f, 0.0f,     0.0f, 0.0f, 0.0f,
        0.0f, 1.0f, 0.0f,       0.5f, 1.0f,     0.0f, 0.0f, 0.0f
    };

    unsigned int groundIndices[] {
        0, 2, 1,
        1, 2, 3
    };

    GLfloat groundVertices[] = {
        -5.0f, 1.0f, -5.0f,   0.0f, 0.0f,     0.0f, -1.0f, 0.0f,
        5.0f, 1.0f, -5.0f,    5.0f, 0.0f,    0.0f, -1.0f, 0.0f,
        -5.0f, 1.0f, 5.0f,    0.0f, 5.0f,    0.0f, -1.0f, 0.0f,
        5.0f, 1.0f, 5.0f,     5.0f, 5.0f,   0.0f, -1.0f, 0.0f
    };

    unsigned int groundIndices2[] {
        0, 2, 1,
        1, 2, 3
    };

    GLfloat groundVertices2[] = {
        -5.0f, 1.0f, -3.0f,   0.0f, 0.0f,     0.0f, -1.0f, 0.0f,
        5.0f, 1.0f, -3.0f,    5.0f, 0.0f,    0.0f, -1.0f, 0.0f,
        -5.0f, 1.0f, 3.0f,    0.0f, 3.0f,    0.0f, -1.0f, 0.0f,
        5.0f, 1.0f, 3.0f,     5.0f, 3.0f,   0.0f, -1.0f, 0.0f
    };

    fprintf(stderr, "Calculating Average Normals\n");
    calcAverageNormals(indices, 12, vertices, 32, 8, 5);


    fprintf(stderr, "Creating Meshes\n");

    fprintf(stderr, "Mesh 1:\n");
    Mesh *obj1 = new Mesh();
    obj1->CreateMesh(vertices, indices, 32, 12);
    MeshList.push_back(obj1);
    //delete obj1;

    fprintf(stderr, "Mesh 2:\n");
    Mesh *obj2 = new Mesh();
    obj2->CreateMesh(vertices, indices, 32, 12);
    MeshList.push_back(obj2);
    //delete obj2;

    fprintf(stderr, "Mesh 3:\n");
    Mesh *obj3 = new Mesh();
    obj3->CreateMesh(groundVertices, groundIndices, 32, 6);
    MeshList.push_back(obj3);
    //delete obj3;

    fprintf(stderr, "Mesh 4:\n");
    Mesh *obj4 = new Mesh();
    obj4->CreateMesh(groundVertices2, groundIndices2, 32, 6);
    MeshList.push_back(obj4);
    //delete obj3;

    fprintf(stderr, "CreateObjects ending\n");
}

void CreateShaders() {
    fprintf(stderr, "CreateShaders starting\n");

    Shader *shader1 = new Shader();
    shader1->CreateFromFiles(vShader, fShader);
    shaderList.push_back(*shader1);

    fprintf(stderr, "CreateShaders ending\n");
}

void initParticles(int i) {
    parSys[i].alive = true;
    parSys[i].life = 1.0f;
    parSys[i].fade = float(std::rand()%100)/1000.0f+0.003f;

    float boundUpper = 2.0f;
    float boundLower = -2.0f;

    std::uniform_real_distribution<float> dis(boundLower, boundUpper);

    parSys[i].xpos = dis(gen);
    parSys[i].ypos = 5.0;
    parSys[i].zpos = dis(gen);

    parSys[i].xscale = 0.04f;
    parSys[i].yscale = 0.04f;
    parSys[i].zscale = 0.04f;

    parSys[i].spd = speed;
    parSys[i].gravity = -0.8;
}

int main()
{   
    int w = 1366;
    int h = 768;

    fprintf(stderr, "Starting main...\n");
    mainWindow = Window(w, h);
    mainWindow.Initialise();

    fprintf(stderr, "Creating objects and shaders\n");

    CreateObjects();
    CreateShaders();

    fprintf(stderr, "Done creating objects and shaders\n");

    camera = Camera(glm::vec3(-2.0f, 0.0f, -2.0f), glm::vec3(0.0f, 1.0f, 0.0f), 0.0f, 0.0f, 5.0f, 1.5f);

    //groundAsphalt = Texture("../textures/ground_asphalt.jpg");
    //groundAsphalt.LoadTexture();
    pavement      = Texture((char*)("../textures/pavement.png"));
    pavement.LoadTextureA();

    plain      = Texture((char*)("../textures/plain.png"));
    Texture* plainPtr = &plain;
    plain.LoadTextureA();

    mud      = Texture((char*)("../textures/dirt.png"));
    Texture* mudPtr = &mud;
    mud.LoadTextureA();

    steel      = Texture((char*)("../textures/steel.png"));
    Texture* steelPtr = &steel;
    steel.LoadTextureA();

    greenLeaves      = Texture((char*)("../textures/green_leaves.png"));
    Texture* greenLeafPtr = &greenLeaves;
    greenLeaves.LoadTextureA();

    grayLeaves      = Texture((char*)("../textures/gray_leaves.png"));
    Texture* grayLeafPtr = &grayLeaves;
    grayLeaves.LoadTextureA();

    bark      = Texture((char*)("../textures/bark.png"));
    Texture* barkPtr = &bark;
    bark.LoadTextureA();

    blue      = Texture((char*)("../textures/blue.png"));
    Texture* bluePtr = &blue;
    blue.LoadTextureA();

    wood      = Texture((char*)("../textures/wood.png"));
    Texture* woodPtr = &wood;
    wood.LoadTextureA();

    shinyMaterial = Material(5.0f, 200);
    dullMaterial = Material(0.3f, 4);

    std::vector<Texture*> lampTextures;
    lampTextures.push_back(steelPtr);
    lampTextures.push_back(plainPtr);
    lampTextures.push_back(steelPtr);
    lampTextures.push_back(steelPtr);
    lampTextures.push_back(steelPtr);

    std::vector<Texture*> treeTextures;
    treeTextures.push_back(barkPtr);
    treeTextures.push_back(greenLeafPtr);

    std::vector<Texture*> rainTextures;

    lamp = Model(lampTextures);
    lamp.LoadModel("../obj/models/Street Lamp.obj");

    tree = Model(treeTextures);
    tree.LoadModel("../obj/models/Tree.obj");

    raindrop = Model();
    raindrop.LoadModel("../obj/models/Low Poly Water Drop.obj");

    bench = Model();
    bench.LoadModel("../obj/models/Bench.obj");

    mainLight = DirectionalLight(1.0f, 1.0f, 1.0f, 
                                0.2f, 0.4f,
                                0.0f, 0.0f, -1.0f);

    fprintf(stderr, "PointLights beginning\n");

    //Point lights, increase every time we add one
    unsigned int pointLightCount = 0;
    pointLights[0] = PointLight(1.0f, 1.0f, 1.0f,
                                0.1f, 0.1f,
                                4.0f, 0.0f, 3.0f,
                                0.3f, 0.2f, 0.1f);
    pointLightCount++;
    pointLights[1] = PointLight(1.0f, 1.0f, 1.0f,
                                0.0f, 0.1f,
                                4.0f, 2.0f, 3.0f,
                                0.1f, 0.1f, 0.1f);
    pointLightCount++;

    fprintf(stderr, "SpotLights beginning\n");

    unsigned int spotLightCount = 0;

    spotLights[0] = SpotLight(  1.0f, 1.0f, 1.0f,
                                0.0f, 1.0f,
                                0.0f, 0.0f, 0.0f,
                                0.0f, -1.0f, 0.0f,
                                0.3f, 0.2f, 0.1f, 
                                20.0f);
    spotLightCount++;

    fprintf(stderr, "SpotLights ending\n");

    GLuint uniformProjection = 0, uniformModel = 0, uniformView = 0, 
            uniformAmbientIntensity = 0, uniformAmbientColor = 0, uniformDirection = 0, uniformDiffuseIntensity = 0,
            uniformSpecularIntensity = 0, uniformShininess = 0, uniformEyePosition = 0;
    glm::mat4 projection = glm::perspective(glm::radians(45.0f), (GLfloat)mainWindow.GetBufferWidth() / mainWindow.GetBufferHeight(), 0.1f, 100.0f);

    glUniformMatrix4fv(uniformProjection, 1, GL_FALSE, glm::value_ptr(projection));
    glUniformMatrix4fv(uniformView, 1, GL_FALSE, glm::value_ptr(camera.calculateViewMatrix()));
    glUniform3f(uniformEyePosition, camera.getCameraPosition().x, camera.getCameraPosition().y, camera.getCameraPosition().z);

    for (int i = 0; i < MAX_PARTICLES; i++) {
        initParticles(i);
    }

    // Loop until window closed
    while (!mainWindow.GetShouldClose()) {
        glGetError();

        GLfloat now = glfwGetTime(); // SDL_GetPerformanceCounter();
        deltaTime = now - lastTime; // (now - lastTime)*1000/SDL_GetPerformnaceFrequency();
        lastTime = now;

        // Get + Handle user input events
        glfwPollEvents();

        camera.keyControl(mainWindow.getKeys(), deltaTime);
        camera.mouseControl(mainWindow.getXChange(), mainWindow.getYChange());

        // Clear window
        glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        shaderList[0].UseShader();
        uniformModel = shaderList[0].GetModelLocation();
        uniformProjection = shaderList[0].GetProjectionLocation();
        uniformView = shaderList[0].GetViewLocation();
        uniformEyePosition = shaderList[0].GetEyePositionLocation();
        uniformSpecularIntensity = shaderList[0].GetSpecularIntensityLocation();
        uniformShininess = shaderList[0].GetShininessLocation();

        // glm::vec3 lowLight = camera.getCameraPosition();
        // lowLight.y -= 0.3f;
        // spotLights[0].SetFlash(camera.getCameraPosition(), camera.getCameraDirection());

        shaderList[0].SetDirectionalLight(&mainLight);
        shaderList[0].SetPointLights(pointLights, pointLightCount);
        shaderList[0].SetSpotLights(spotLights, spotLightCount);

        glUniformMatrix4fv(uniformProjection, 1, GL_FALSE, glm::value_ptr(projection));
		glUniformMatrix4fv(uniformView, 1, GL_FALSE, glm::value_ptr(camera.calculateViewMatrix()));
		glUniform3f(uniformEyePosition, camera.getCameraPosition().x, camera.getCameraPosition().y, camera.getCameraPosition().z);

        // Render first triangle
        glm::mat4 model(1.0f);

        // Render second ground
        model = glm::mat4(1.0f);
        model = glm::translate(model, glm::vec3(0.0f, -2.0f, 0.0f));
        model = glm::scale(model, glm::vec3(0.4f, 0.4f, 0.4f));
        glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
        mud.UseTexture();
        shinyMaterial.UseMaterial(uniformSpecularIntensity, uniformShininess);
        MeshList[2]->RenderMesh();

        // Render ground
        model = glm::mat4(1.0f);
        model = glm::translate(model, glm::vec3(0.0f, -1.99f, 0.0f));
        model = glm::scale(model, glm::vec3(0.4f, 0.4f, 0.4f));
        glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
        pavement.UseTexture();
        shinyMaterial.UseMaterial(uniformSpecularIntensity, uniformShininess);
        MeshList[3]->RenderMesh();

        
        // Lamp Model
        model = glm::mat4(1.0f);
        model = glm::translate(model, glm::vec3(-0.7f, -1.1f, 0.0f));
        model = glm::scale(model, glm::vec3(0.001f, 0.001f, 0.001f));
        glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
        steel.UseTexture();
        shinyMaterial.UseMaterial(uniformSpecularIntensity, uniformShininess);
        lamp.RenderModel();

        // Tree Model at -1.6f
        model = glm::mat4(1.0f);
        model = glm::translate(model, glm::vec3(1.6f, -1.6f, 1.6f));
        model = glm::scale(model, glm::vec3(1.5f, 1.0f, 1.5f));
        glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
        dullMaterial.UseMaterial(uniformSpecularIntensity, uniformShininess);
        tree.RenderModel();

        // Bench Model
        model = glm::mat4(1.0f);
        model = glm::translate(model, glm::vec3(0.5f, -1.6f, 0.0f));
        model = glm::scale(model, glm::vec3(0.01f, 0.01f, 0.01f));
        model = glm::rotate(model, 190 * toRadians, glm::vec3(0.0f, 1.0f, 0.0f));
        glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
        dullMaterial.UseMaterial(uniformSpecularIntensity, uniformShininess);
        wood.UseTexture();
        bench.RenderModel();

        model = glm::mat4(1.0f);
        model = glm::translate(model, glm::vec3(0.2f, -1.5f, -0.2f));
        model = glm::scale(model, glm::vec3(1.0f, 0.0001, 1.0f));
        glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
        blue.UseTexture();
        shinyMaterial.UseMaterial(uniformSpecularIntensity, uniformShininess);
        raindrop.RenderModel();

        // update particles
        if (mainWindow.rainTrue) {
            float x, y, z;
            for (int i = 0; i < MAX_PARTICLES; i++) {
                if (parSys[i].alive == true) {
                    x = parSys[i].xpos;
                    y = parSys[i].ypos;
                    z = parSys[i].zpos;

                    // draw
                    model = glm::mat4(1.0f);
                    model = glm::translate(model, glm::vec3(x, y, z));
                    model = glm::scale(model, glm::vec3(parSys[i].xscale, parSys[i].yscale, parSys[i].zscale));
                    glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
                    blue.UseTexture();
                    shinyMaterial.UseMaterial(uniformSpecularIntensity, uniformShininess);
                    raindrop.RenderModel();
                    
                    // update values
                    // move
                    // adjust moving for speed
                    parSys[i].ypos += parSys[i].spd / (slowDown*100);
                    parSys[i].spd  += parSys[i].gravity;
                    // Decay
                    parSys[i].life -= parSys[i].fade;

                    if (parSys[i].ypos <= -1.45f) {
                        if (mainWindow.splashTrue) {
                            parSys[i].xscale = 0.3f;
                            parSys[i].yscale = 0.0001f;
                            parSys[i].zscale = 0.3f;
                        }
                    }
                    if (parSys[i].ypos <= -1.55f) {
                        parSys[i].life = -1.0f;
                    }
                    // revive once raindrop is gone
                    if (parSys[i].life < 0.0) {
                        initParticles(i);
                    }
                }
            }
        }

        glUseProgram(0);

        mainWindow.SwapBuffers();
    }
 
    return 0;
}
