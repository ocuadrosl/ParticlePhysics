#include <iostream>
#include <memory>
#include <vector>

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>



//local includes
#include "Util.h"

const unsigned int WIDTH  = 800;
const unsigned int HEIGHT = 800;

int main()
{


    // Initialise GLFW
    glewExperimental = true; // Needed for core profile
    if( !glfwInit() )
    {
        std::cerr<<"Failed to initialize GLFW"<<std::endl;
        return -1;
    }

    glfwWindowHint(GLFW_SAMPLES, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    //glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE); // MacOS needs it
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    // Open a window and create its OpenGL context
    GLFWwindow* window = glfwCreateWindow(WIDTH, HEIGHT, "Particles System", nullptr,nullptr);

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



   //We have to create an array of vertices and data associate to it and tell to OpenGL how to read it
   //In this example we create a box componsed of two triangles (tree vertices per triangle) for each face.
   //We can associate attributes to each vertex, e.g., color. In this example we are associating normals.
   //array data 6 floats: 3 vertices, 3 normals
   //See https://www.khronos.org/opengl/wiki/Vertex_Specification for more information
   //More info https://learnopengl.com/Getting-started/Shaders

   //A box with randon normals
    std::vector<float> boxData = {
                -1.0f,-1.0f,-1.0f, 1.f, 0.f, 0.f,
                -1.0f,-1.0f, 1.0f, 0.f, 0.f, 0.f,
                -1.0f, 1.0f, 1.0f, 0.f, 0.f, 0.f,

                 1.0f, 1.0f,-1.0f, 1.f, 0.f, 0.f,
                -1.0f,-1.0f,-1.0f, 1.f, 0.f, 0.f,
                -1.0f, 1.0f,-1.0f, 1.f, 0.f, 1.f,

                 1.0f,-1.0f, 1.0f, 1.f, 0.f, 0.f,
                -1.0f,-1.0f,-1.0f, 1.f, 0.f, 0.f,
                 1.0f,-1.0f,-1.0f, 0.f, 1.f, 0.f,

                 1.0f, 1.0f,-1.0f, 1.f, 0.f, 0.f,
                 1.0f,-1.0f,-1.0f, 1.f, 0.f, 0.f,
                -1.0f,-1.0f,-1.0f, 1.f, 0.f, 0.f,

                -1.0f,-1.0f,-1.0f, 1.f, 0.f, 0.f,
                -1.0f, 1.0f, 1.0f, 1.f, 0.f, 0.f,
                -1.0f, 1.0f,-1.0f, 1.f, 0.f, 0.f,

                 1.0f,-1.0f, 1.0f, 1.f, 0.f, 0.f,
                -1.0f,-1.0f, 1.0f, 1.f, 0.f, 0.f,
                -1.0f,-1.0f,-1.0f, 1.f, 0.f, 0.f,

                -1.0f, 1.0f, 1.0f, 1.f, 0.f, 0.f,
                -1.0f,-1.0f, 1.0f, 1.f, 0.f, 0.f,
                 1.0f,-1.0f, 1.0f, 1.f, 0.f, 0.f,

                 1.0f, 1.0f, 1.0f, 1.f, 0.f, 0.f,
                 1.0f,-1.0f,-1.0f, 1.f, 0.f, 0.f,
                 1.0f, 1.0f,-1.0f, 1.f, 0.f, 0.f,

                 1.0f,-1.0f,-1.0f, 1.f, 1.f, 0.f,
                 1.0f, 1.0f, 1.0f, 1.f, 0.f, 0.f,
                 1.0f,-1.0f, 1.0f, 1.f, 1.f, 0.f,

                 1.0f, 1.0f, 1.0f, 1.f, 0.f, 0.f,
                 1.0f, 1.0f,-1.0f, 1.f, 0.f, 0.f,
                -1.0f, 1.0f,-1.0f, 1.f, 0.f, 0.f,

                 1.0f, 1.0f, 1.0f, 1.f, 1.f, 0.f,
                -1.0f, 1.0f,-1.0f, 1.f, 0.f, 0.f,
                -1.0f, 1.0f, 1.0f, 1.f, 0.f, 1.f,

                 1.0f, 1.0f, 1.0f, 1.f, 0.f, 0.f,
                -1.0f, 1.0f, 1.0f, 0.f, 0.f, 1.f,
                 1.0f,-1.0f, 1.0f, 0.5f, 0.f, 1.f

    };

    //Creating a Vertex buffer object and setting the object data
    GLuint vbo;
    glGenBuffers(1, &vbo); //generate buffer object names, 1 = number of buffer object names to be generated.
    glBindBuffer(GL_ARRAY_BUFFER, vbo); //bind a named buffer object
    glBufferData(GL_ARRAY_BUFFER, boxData.size()*6* sizeof(float), &boxData[0], GL_STATIC_DRAW); //creates and initializes a buffer object's data store


    //creating a vertex array object and set the vertex buffer object
    GLuint vao = 0;
    glGenVertexArrays(1, &vao); // generate vertex array object names
    glBindVertexArray(vao); //bind a vertex array object
    glBindBuffer(GL_ARRAY_BUFFER, vbo); // bind a named buffer object
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE,  6 * sizeof(float), nullptr); //define an array of generic vertex attribute data
    glEnableVertexAttribArray(1);
    //define an array of generic vertex attribute data
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE,  6 * sizeof(float), reinterpret_cast<const void *>(3*sizeof(float)) );


    //A pyramid, same process as the box above
    std::vector<float> pyramidData = {

       -5.0f, 5.0f,  0.0f, 1.f, 0.f, 0.f,
       -5.0f, 3.0f,  1.0f, 1.f, 0.f, 0.f,
       -4.0f, 3.0f,  1.0f, 1.f, 1.f, 0.f,

       -5.0f, 5.0f,  0.0f, 1.f, 0.f, 0.f,
       -4.0f, 3.0f,  1.0f, 1.f, 0.f, 0.f,
       -4.0f, 3.0f, -1.0f, 1.f, 0.f, 1.f,

       -5.0f, 5.0f,  0.0f, 1.f, 0.f, 0.f,
       -4.0f, 3.0f, -1.0f, 1.f, 1.f, 0.f,
       -6.0f, 3.0f, -1.0f, 1.f, 0.f, 0.f,

       -5.0f, 5.0f, 0.0f, 1.f, 0.f, 0.f,
       -6.0f, 3.0f, -1.0f,1.f, 0.f, 0.f,
       -6.0f, 3.0f, 1.0f, 1.f, 1.f, 0.f


    };

    GLuint vbo2;
    glGenBuffers(1, &vbo2); //generate buffer object names, 1 = number of buffer object names to be generated.
    glBindBuffer(GL_ARRAY_BUFFER, vbo2); //bind a named buffer object
    glBufferData(GL_ARRAY_BUFFER, pyramidData.size()*6 * sizeof(GLfloat), &pyramidData[0], GL_STATIC_DRAW); //creates and initializes a buffer object's data store

    GLuint vao2;
    glGenVertexArrays(1, &vao2); // generate vertex array object names
    glBindVertexArray(vao2); //bind a vertex array object
    glBindBuffer(GL_ARRAY_BUFFER, vbo2); // bind a named buffer object
    glEnableVertexAttribArray(0); //Enable or disable a generic vertex attribute array
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE,  6 * sizeof(float), nullptr); //define an array of generic vertex attribute data
    glEnableVertexAttribArray(1);
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), reinterpret_cast<const void *>(3*sizeof(float))); //define an array of generic vertex attribute data


    //shaders: for this example we need two shaders, vertex and fragment.
    //vertex_shader input: positions, color, normals, and model-view-projection matrix (MVP)
    const char* vertexShader =
            "#version 400\n"
            "layout (location = 0) in vec3 position;"
            "layout (location = 1) in vec3 normal;"
            "out vec3 vColor;"
            "out vec3 vNormal;"
            "uniform mat4 MVP;"
            "void main() {"
            " gl_Position = MVP*vec4(position, 5.0f);"
            //" vColor = vec3(1, 1, 0);" // to setup a color here, uncomment "in  vec3 vColor" and comment the uniform one
            " vNormal = normal;"
           "}";


    //fragment shader input: color, normal from the vertex shader
    const char* fragmentShader =
            "#version 400\n"
            "uniform  vec3 vColor;"
            //"in  vec3 vColor;"
            "in  vec3 vNormal;"
            "out vec4 fColor;"
            "void main() {"
            "   vec3 lightColor = vec3(0.5f, 0.5f, 0.5f);"
            "   vec3 norm = normalize(vNormal);"
            "   float cos = dot(norm, lightColor);"
            "   cos = clamp(cos, 0.0, 1.0);"
            "   fColor = vec4(vColor * cos, 1.0f);"
            "}";




    GLuint vs = glCreateShader(GL_VERTEX_SHADER); //GL_VERTEX_SHADER is a shader that is intended to run on the programmable vertex processor.
    glShaderSource(vs, 1, &vertexShader, nullptr); //Replaces the source code in a shader object
    glCompileShader(vs); //Compiles a shader object


    GLuint fs = glCreateShader(GL_FRAGMENT_SHADER); //GL_FRAGMENT_SHADER is a shader that is intended to run on the programmable fragment processor.
    glShaderSource(fs, 1, &fragmentShader, nullptr); // Replaces the source code in a shader object
    glCompileShader(fs);



    GLuint shaders = glCreateProgram();//Creates a program object, A program object is an object to which shader objects can be attached.

    //glAttachShader(shader_programm, fs); // Attaches a shader object to a program object
    glAttachShader(shaders, fs); // Attaches a shader object to a program object
    glAttachShader(shaders, vs);
    glLinkProgram(shaders);
    glUseProgram(shaders); //Installs a program object as part of current rendering state



    while(glfwWindowShouldClose(window) == 0 )
    {

        // Clear the screen.
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);



        //Camera setup
        //See http://www.opengl-tutorial.org/beginners-tutorials/tutorial-3-matrices/
        glm::mat4 model         = glm::mat4(1.0f); // make sure to initialize matrix to identity matrix first
        glm::mat4 view          = glm::mat4(1.0f);
        glm::mat4 projection    = glm::mat4(1.0f);

        model = glm::rotate(model, glm::radians(-55.0f), glm::vec3(1.0f, 1.0f, 0.0f));
        view  = glm::translate(view, glm::vec3(0.0f, 0.0f, -3.0f));
        projection = glm::perspective(glm::radians(45.0f), static_cast<float>(WIDTH)/HEIGHT, 0.1f, 100.0f);
        glm::mat4 mvp = projection*view*model;

        GLint MatrixID = glGetUniformLocation(shaders, "MVP");
        glUniformMatrix4fv(MatrixID, 1, GL_FALSE, &mvp[0][0]);



        glBindVertexArray(vao);
        glDrawArrays(GL_TRIANGLES, 0, static_cast<GLsizei>(boxData.size()/6)); //telling OpenGL the number of triangles to render


        //Setup a color for all objects
        //It does not work when we use "in  vec3 vColor;"
        int vertexColorLocation = glGetUniformLocation(shaders, "vColor");
        glUseProgram(shaders);
        glUniform3f(vertexColorLocation, 0.0f, 1.0f, 0.0f);


        glBindVertexArray(vao2);
        glDrawArrays(GL_TRIANGLES, 0, static_cast<GLsizei>(pyramidData.size()/6));


        // update other events like input handling
        glfwPollEvents();
        // put the stuff we've been drawing onto the display
        glfwSwapBuffers(window);



    }


    // Close OpenGL window and terminate GLFW
    glfwTerminate();

    return 0;
}
