#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include <iostream>
#include <unistd.h>
#include "Shader.h"
#include "Box.h"
#include "Camera.h"
#include "Move.h"

void framebuffer_size_callback(GLFWwindow* window, int width, int height);
void processInput(GLFWwindow *window);
void mouse_callback(GLFWwindow* window, double xpos, double ypos);
void scroll_callback(GLFWwindow* window, double xpos, double ypos);
void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods);

float deltaTime = 0.0f;	// Time between current frame and last frame
float lastFrame = 0.0f; // Time of last frame

bool firstMouse = true;
float lastX =  800.0f / 2.0;
float lastY =  600.0 / 2.0;

float angleX = 0.f;
float angleZ = 0.f;

bool wired = false;

const unsigned int SCR_WIDTH = 800;
const unsigned int SCR_HEIGHT = 600;

Shader* shader;
Camera camera;
Box* box[27];
Move* move;


// Animate animate(0, 0, 1, deltaTime);

glm::mat4 model;

glm::vec3 model1 = glm::vec3(0.f, 0.f, 0.f);

int main()
{
    // glfw: initialize and configure
    // ------------------------------
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

#ifdef __APPLE__
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
#endif

    // glfw window creation
    // --------------------
    GLFWwindow* window = glfwCreateWindow(SCR_WIDTH, SCR_HEIGHT, "LearnOpenGL", NULL, NULL);
    if (window == NULL)
    {
        std::cout << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
        return -1;
    }
    glfwMakeContextCurrent(window);
    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

    glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);
    glfwSetCursorPosCallback(window, mouse_callback);
    glfwSetScrollCallback(window, scroll_callback);
    glfwSetKeyCallback(window, key_callback);

    // glew initilization
    // ---------------------------------------
    if(glewInit()) {
      std::cout << "Failed to initialize GLEW" << std::endl;
      return -1;
    }
    glEnable(GL_DEPTH_TEST);

    shader = new Shader("../src/shaders/shader.vs","../src/shaders/shader.fs");

    for(unsigned int i = 0; i < 27; i++)
    {
        box[i] = new Box(0.49f, 0.49f, 0.49f);
    }

    for(int x = 0; x < 3; x++)
    {
        for(int y = 0; y < 3; y++)
        {
            for(int z = 0; z < 3; z++)
            {
                model = glm::mat4(1.f);
                model = glm::translate(model, glm::vec3(x-1, y-1, z-1));
                box[x*9+y*3+z]->SetLocalTransform(model);
                box[x*9+y*3+z]->position = glm::vec3(x-1, y-1, z-1);
            }
        }
    }

    move = new Move(1, 0, 0, box);




    double timer = 0;
    while (!glfwWindowShouldClose(window))
    {
        float currentFrame = glfwGetTime();
        deltaTime = currentFrame - lastFrame;
        lastFrame = currentFrame;

        timer += deltaTime;
        if(timer > 1.f)
        {
            timer -= 1.f;
            double fps = 1./deltaTime;
            std::cout << "FPS: " << fps << std::endl;
        }

        processInput(window);

        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);


        shader->Use();

        glm::mat4 view;
        view = camera.GetViewMatrix();
        shader->SetMat4("view", view);

        glm::mat4 projection = glm::mat4(1.f);
        projection = glm::perspective(glm::radians(camera.Zoom), 800.0f / 600.0f, 0.1f, 100.0f);
        shader->SetMat4("projection", projection);

        for(unsigned int i = 0; i < 27 ; i++)
        {
            if(box[i]->position.x != 0){
                move->TurnX(0, deltaTime);
            }
            if(box[i]->position.y != 0){
                move->TurnY(0, deltaTime);
            }
            if(box[i]->position.z != 0){
                move->TurnZ(0, deltaTime);
            }
            box[i]->Draw(shader);
        }
        glfwSwapBuffers(window);
        glfwPollEvents();
    }
    delete shader;
    glfwTerminate();
    return 0;
}

void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
    glViewport(0, 0, width, height);
}

void processInput(GLFWwindow *window)
{
    if(glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
        glfwSetWindowShouldClose(window, true);
    if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS)
        camera.ProcessKeyboard(FORWARD, deltaTime);
    if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS)
        camera.ProcessKeyboard(BACKWARD, deltaTime);
    if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS)
        camera.ProcessKeyboard(LEFT, deltaTime);
    if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS)
        camera.ProcessKeyboard(RIGHT, deltaTime);
    if (glfwGetKey(window, GLFW_KEY_Q) == GLFW_PRESS)
        camera.ProcessKeyboard(UP, deltaTime);
    if (glfwGetKey(window, GLFW_KEY_E) == GLFW_PRESS)
        camera.ProcessKeyboard(DOWN, deltaTime);
}

void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
    if(move->angle[0] >= 90.f && move->angle[1] >= 90.f && move->angle[2] >= 90.f)
    {
        if (key == GLFW_KEY_KP_3 && action == GLFW_PRESS)
        {
            move->SetDirection(1, 0, 0, 1);
            move->ResetAngle(0);
        }

        if (key == GLFW_KEY_KP_1 && action == GLFW_PRESS)
        {
            move->SetDirection(1, 0, 0,-1);
            move->ResetAngle(0);
        }

        if (key == GLFW_KEY_KP_6 && action == GLFW_PRESS)
        {
            move->SetDirection(0, 1, 0, 1);
            move->ResetAngle(1);
        }

        if (key == GLFW_KEY_KP_4 && action == GLFW_PRESS)
        {
            move->SetDirection(0, 1, 0, -1);
            move->ResetAngle(1);
        }

        if (key == GLFW_KEY_KP_9 && action == GLFW_PRESS)
        {
            move->SetDirection(0, 0, 1, 1);
            move->ResetAngle(2);
        }

        if (key == GLFW_KEY_KP_7 && action == GLFW_PRESS)
        {
            move->SetDirection(0, 0, 1, -1);
            move->ResetAngle(2);
        }
    }

    if (key == GLFW_KEY_P && action == GLFW_PRESS)
    {
        if(wired == false)
        {
            glPolygonMode( GL_FRONT_AND_BACK, GL_LINE );
            wired = true;
        }
        else
        {
            glPolygonMode( GL_FRONT_AND_BACK, GL_FILL );
            wired = false;
        }
    }
}

void mouse_callback(GLFWwindow* window, double xpos, double ypos)
{
    if (firstMouse) // initially set to true
    {
        lastX = xpos;
        lastY = ypos;
        firstMouse = false;
    }
    float xoffset = xpos - lastX;
    float yoffset = lastY - ypos;
    lastX = xpos;
    lastY = ypos;

    camera.ProcessMouseMovement(xoffset, yoffset, true);
}

void scroll_callback(GLFWwindow* window, double xoffset, double yoffset)
{
    camera.ProcessMouseScroll(yoffset);
}
