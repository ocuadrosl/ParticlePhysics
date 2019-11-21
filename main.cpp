#include <iostream>
#include <memory>

#include <GL/glew.h>
#include <GLFW/glfw3.h>


#include "particlesystem.h"






int main()
{


    std::unique_ptr<ParticleSystem> pSystem(new ParticleSystem());
    pSystem->setNumberOfParticles(1000);
    pSystem->initSystem();
    pSystem->setRandonInitPosition();
    pSystem->startSystem();







    /*

    // Initialise GLFW
    glewExperimental = true; // Needed for core profile
    if( !glfwInit() )
    {
        std::cerr<<"Failed to initialize GLFW\n"<<std::endl;
        return -1;
    }

    glfwWindowHint(GLFW_SAMPLES, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    //glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE); // MacOS needs it
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    // Open a window and create its OpenGL context

    GLFWwindow* window = glfwCreateWindow(600, 600, "Particles System", nullptr,nullptr);

    if( window == nullptr ){
        std::cerr<<"Failed to open GLFW window"<<std::endl;
        glfwTerminate();
        return -1;
    }

    glfwMakeContextCurrent(window);

    // Initialize GLEW
    if (glewInit() != GLEW_OK)
    {
        std::cerr<<"Failed to initialize GLEW"<<std::endl;
        glfwTerminate();
        return -1;
    }
    // Ensure we can capture the escape key being pressed below
    glfwSetInputMode(window, GLFW_STICKY_KEYS, GL_TRUE);

    // Dark blue background
    glClearColor(0.2f, 0.2f, 0.5f, 0.0f);


    std::vector<float> points = {
       0.0f,  0.5f,  0.0f,
       0.5f, -0.5f,  0.0f,
      -0.5f, -0.5f,  0.0f
    };

    GLuint vbo;
    glGenBuffers(1, &vbo);
    glBindBuffer(GL_ARRAY_BUFFER, vbo);
    glBufferData(GL_ARRAY_BUFFER, 9 * sizeof(float), &points[0], GL_STATIC_DRAW);


    GLuint vao = 0;
    glGenVertexArrays(1, &vao);
    glBindVertexArray(vao);
    glEnableVertexAttribArray(0);
    glBindBuffer(GL_ARRAY_BUFFER, vbo);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, nullptr);

    //shaders
    const char* vertex_shader =
            "#version 400\n"
            "in vec3 vp;"
            "void main() {"
            "  gl_Position = vec4(vp, 1.0);"
            "}";

    const char* fragment_shader =
            "#version 400\n"
            "out vec4 frag_colour;"
            "void main() {"
            "  frag_colour = vec4(0.5, 0.0, 0.0, 1.0);"
            "}";

    GLuint vs = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vs, 1, &vertex_shader, nullptr);
    glCompileShader(vs);
    GLuint fs = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fs, 1, &fragment_shader, nullptr);
    glCompileShader(fs);

    GLuint shader_programme = glCreateProgram();
    glAttachShader(shader_programme, fs);
    glAttachShader(shader_programme, vs);
    glLinkProgram(shader_programme);
    glUseProgram(shader_programme);

     while(glfwWindowShouldClose(window) == 0 )
     {
        // Clear the screen.
        glClear(GL_COLOR_BUFFER_BIT);

        // draw points 0-3 from the currently bound VAO with current in-use shader
        glDrawArrays(GL_TRIANGLES, 0, 3);

        // update other events like input handling
        glfwPollEvents();
        // put the stuff we've been drawing onto the display
        glfwSwapBuffers(window);


    }


    // Close OpenGL window and terminate GLFW
    glfwTerminate();
*/
    return 0;
}
