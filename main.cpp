#include <iostream>
#include <memory>
#include <vector>

#include <GL/glew.h>
#include <GLFW/glfw3.h>


int main()
{

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
        0.0f,  0.5f,  0.5f,
        0.5f, -0.5f,  0.5f,
        -0.5f, -0.5f,  0.5f,

    };

    GLuint vbo;
    glGenBuffers(1, &vbo); //generate buffer object names, 1 = number of buffer object names to be generated.
    glBindBuffer(GL_ARRAY_BUFFER, vbo); //bind a named buffer object
    glBufferData(GL_ARRAY_BUFFER, 9 * sizeof(float), &points[0], GL_STATIC_DRAW); //creates and initializes a buffer object's data store



    std::vector<float> points2 = {
        0.20f,  0.5f,  0.20f,
        0.25f, -0.25f,  0.5f,
        -0.25f, -0.25f,  0.5f
    };

    GLuint vbo2;
    glGenBuffers(1, &vbo2); //generate buffer object names, 1 = number of buffer object names to be generated.
    glBindBuffer(GL_ARRAY_BUFFER, vbo2); //bind a named buffer object
    glBufferData(GL_ARRAY_BUFFER, 9 * sizeof(float), &points2[0], GL_STATIC_DRAW); //creates and initializes a buffer object's data store




    GLuint vao = 0;
    glGenVertexArrays(1, &vao); // generate vertex array object names
    glBindVertexArray(vao); //bind a vertex array object
    glEnableVertexAttribArray(0); //Enable or disable a generic vertex attribute array
    //glEnableVertexAttribArray(2); //Enable or disable a generic vertex attribute array
    glBindBuffer(GL_ARRAY_BUFFER, vbo); // bind a named buffer object
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, nullptr); //define an array of generic vertex attribute data


    GLuint vao2 = 0;
    glGenVertexArrays(1, &vao2); // generate vertex array object names
    glBindVertexArray(vao2); //bind a vertex array object
    glEnableVertexAttribArray(0); //Enable or disable a generic vertex attribute array
   // glEnableVertexAttribArray(2); //Enable or disable a generic vertex attribute array
    glBindBuffer(GL_ARRAY_BUFFER, vbo2); // bind a named buffer object
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, nullptr); //define an array of generic vertex attribute data




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
            "  frag_colour = vec4(0.5, 0.0, 0.2, 0.5);"
            "}";

    const char* fragment_shader2 =
            "#version 400\n"
            "out vec4 FragColor;"
            "uniform vec4 ourColor;"
            "void main() {"
            "  FragColor = ourColor;"
            "}";


    GLuint vs = glCreateShader(GL_VERTEX_SHADER); //GL_VERTEX_SHADER is a shader that is intended to run on the programmable vertex processor.
    glShaderSource(vs, 1, &vertex_shader, nullptr); //Replaces the source code in a shader object
    glCompileShader(vs); //Compiles a shader object

    GLuint fs = glCreateShader(GL_FRAGMENT_SHADER); //GL_FRAGMENT_SHADER is a shader that is intended to run on the programmable fragment processor.
    glShaderSource(fs, 1, &fragment_shader, nullptr); // Replaces the source code in a shader object
    glCompileShader(fs);

    GLuint fs2 = glCreateShader(GL_FRAGMENT_SHADER); //GL_FRAGMENT_SHADER is a shader that is intended to run on the programmable fragment processor.
    glShaderSource(fs2, 1, &fragment_shader2, nullptr); // Replaces the source code in a shader object
    glCompileShader(fs2);


    GLuint shader_programm = glCreateProgram();//Creates a program object, A program object is an object to which shader objects can be attached.

    //glAttachShader(shader_programm, fs); // Attaches a shader object to a program object
    glAttachShader(shader_programm, fs2); // Attaches a shader object to a program object
    glAttachShader(shader_programm, vs);
    glLinkProgram(shader_programm);
    glUseProgram(shader_programm); //Installs a program object as part of current rendering state





    while(glfwWindowShouldClose(window) == 0 )
    {

        // Clear the screen.
        glClear(GL_COLOR_BUFFER_BIT);






        //draw points 0-3 from the currently bound VAO with current in-use shader

        int vertexColorLocation = glGetUniformLocation(shader_programm, "ourColor");
        //glUseProgram(shader_programm);
        glUniform4f(vertexColorLocation, 0.0f, 52, 0.0f, 1.0f);
        glBindVertexArray(vao);
        glDrawArrays(GL_TRIANGLES, 0, 3);

        //int vertexColorLocation = glGetUniformLocation(shader_programm, "ourColor");
        //glUseProgram(shader_programm);
        glUniform4f(vertexColorLocation, 0.5f, 52, 0.0f, 1.0f);

        glBindVertexArray(vao2);
        glDrawArrays(GL_TRIANGLES, 0, 3);


        //glBindVertexArray(vao2);
        //glUniform3f(offsetUniform, 0.0f, 0.0f, 0.0f);
        //glDrawElements(GL_TRIANGLES, 3, GL_FLOAT, nullptr);

        //glBindVertexArray(vao2);
        //glUniform3f(offsetUniform, 0.0f, 0.0f, -1.0f);
        //glDrawElements(GL_TRIANGLES, 3, GL_FLOAT, nullptr);


        // update other events like input handling
        glfwPollEvents();
        // put the stuff we've been drawing onto the display
        glfwSwapBuffers(window);



    }

  glDisableVertexAttribArray(0);
    // Close OpenGL window and terminate GLFW
    glfwTerminate();

    return 0;
}
