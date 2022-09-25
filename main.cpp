#include "imgui/imgui.h"
#include "imgui/imgui_impl_glfw.h"
#include "imgui/imgui_impl_opengl3.h"

#include "glew/include/GL/glew.h"
#include <GLFW/glfw3.h>
#include "soil/include/soil/SOIL.h"

#include <cstdlib>
#include <cmath>

//Window doesn't scale, resolution is hardcoded
int screenWidth = 1920;
int screenHeight = 1080;
const char windowName[] = "Processor Designer";
const float pi = 3.141592653598793f;

GLuint getShaderProgramId (const char *vertexFile, const char *fragmentFile);
GLuint compileShader (const GLchar *source, GLuint shaderType);

GLuint shaderProgramId, vao, vbo, ubo, textureId;

//To stop sending information to shaders, screen resolution is hard coded (half per dimension)
const char *vertexShader =
    "#version 330\n"
    "layout (location = 0) in vec2 vert;\n"
    "layout (location = 1) in vec2 _uv;\n"
    "out vec2 uv;\n"
    "void main () {\n"
    "    uv = _uv;\n"
    "    gl_Position = vec4 (vert.x / 960.0 - 1.0, vert.y / 540.0 - 1.0, 0.0, 1.0);\n"
    "}\n";

const char *fragmentShader =
    "#version 330\n"
    "out vec4 color;\n"
    "in vec2 uv;\n"
    "uniform sampler2D tex;\n"
    "void main () {\n"
    "    color = texture(tex, uv);\n"
    "}\n";

struct Texture {unsigned short width, height; float u1, v1, u2, v2;};
struct Object  {int x, y; Texture texture;};

//For corners, (u1, v1) is the top left and (u2, v2) is bottom right. (0, 0) is top left corner
Texture notGate = {200, 100, 0.0f,   0.0f,   1.0f,   0.5f};
Texture andGate = {200, 100, 0.0f,   0.5f,   1.0f,   1.0f};

Texture textures[2] = {notGate, andGate};

const unsigned int OBJECT_COUNT = 2;
static Object objects[OBJECT_COUNT];

static short vertices[OBJECT_COUNT * 12];
static float uvs[OBJECT_COUNT * 12];

//Each pixel has a position and 3 values for RGB
//Position is x + (y * screenWidth)
float* pixels = new float[screenWidth * screenHeight * 3];



void SetPixel (int x, int y, float r, float g, float b) {
    if ((x + y * screenWidth) * 3 < screenWidth * screenHeight * 3) {
        pixels[(x + y * screenWidth) * 3] = r;
        pixels[(x + y * screenWidth) * 3 + 1] = g;
        pixels[(x + y * screenWidth) * 3 + 2] = b;
    }
}



void Draw () {
    //Draw background
    //Loop scans from bottom to top, left to right (One row at a time)
    for (int i = 0; i < screenHeight; i++) {
        for (int j = 0; j < screenWidth; j++) {
            pixels[(j + i * screenWidth) * 3] = 0.0f;
            pixels[(j + i * screenWidth) * 3 + 1] = 0.0f;
            pixels[(j + i * screenWidth) * 3 + 2] = 1.0f;
        }
    }
}



//Creates a callback to listen for the escape key, it will work on press down or up (down in this case)
void KeyCallback (GLFWwindow* window, int key, int scancode, int action, int mods) {
    if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS) {
        glfwSetWindowShouldClose (window, GL_TRUE);
    }
}



int main () {
    GLFWwindow* window;

    //Setup GLFW
    glfwInit ();
    glfwWindowHint (GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint (GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint (GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint (GLFW_RESIZABLE, GL_FALSE);

    if (!window) {
        glfwTerminate ();
        return -1;
    }

    //Create a window and set the OpenGL context (Make it windowed fullscreen)
    window = glfwCreateWindow (screenWidth, screenHeight, windowName, NULL, NULL);

    //Set window context to current
    glfwMakeContextCurrent (window);

    //Setup GLEW
    glewExperimental = GL_TRUE;
    glewInit ();

    //Setup OpenGL
    glBlendFunc (GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    glEnable (GL_CULL_FACE);
    glFrontFace (GL_CCW);
    glEnable (GL_BLEND);
    glDisable (GL_DEPTH_TEST);
    glDisable (GL_SCISSOR_TEST);

    //Setup viewport
    glfwGetFramebufferSize (window, &screenWidth, &screenHeight);
    glViewport (0, 0, screenWidth, screenHeight);

    //Setup shader
    shaderProgramId = getShaderProgramId (vertexShader, fragmentShader);

    //Setup texture
    glGenTextures (1, &textureId);
    glBindTexture (GL_TEXTURE_2D, textureId);

    glTexParameteri (GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri (GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    glTexParameteri (GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    glTexParameteri (GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);

    //Load imagemap using SOIL and store it on GPU
    int width, height;
    unsigned char* image = SOIL_load_image ("2gates.png", &width, &height, 0, SOIL_LOAD_RGBA);
    glTexImage2D (GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, image);
    if (image == 0) {
        exit (1);
    } else {
        SOIL_free_image_data (image);
    }

    for (int i = 0; i < OBJECT_COUNT; i++) {
        //Draw one of each gate
        Texture t = textures[i];
        objects[i] = {600 + (i * 200), 600 + (i * 200), t};

        //Vertices
        //Top right
        vertices[i * 12] = objects[i].x + objects[i].texture.width;
        vertices[i * 12 + 1] = objects[i].y;

        //Bottom right
        vertices[i * 12 + 2] = objects[i].x + objects[i].texture.width;
        vertices[i * 12 + 3] = objects[i].y + objects[i].texture.height;

        //Top left
        vertices[i * 12 + 4] = objects[i].x;
        vertices[i * 12 + 5] = objects[i].y;

        //Bottom right
        vertices[i * 12 + 6] = objects[i].x + objects[i].texture.width;
        vertices[i * 12 + 7] = objects[i].y + objects[i].texture.height;

        //Bottom left
        vertices[i * 12 + 8] = objects[i].x;
        vertices[i * 12 + 9] = objects[i].y + objects[i].texture.height;

        //Top left
        vertices[i * 12 + 10] = objects[i].x;
        vertices[i * 12 + 11] = objects[i].y;

        //UVs
        //Top right
        uvs[i * 12] = objects[i].texture.u2;
        uvs[i * 12 + 1] = objects[i].texture.v2;

        //Bottom right
        uvs[i * 12 + 2] = objects[i].texture.u2;
        uvs[i * 12 + 3] = objects[i].texture.v1;

        //Top left
        uvs[i * 12 + 4] = objects[i].texture.u1;
        uvs[i * 12 + 5] = objects[i].texture.v2;

        //Bottom right
        uvs[i * 12 + 6] = objects[i].texture.u2;
        uvs[i * 12 + 7] = objects[i].texture.v1;

        //Bottom left
        uvs[i * 12 + 8] = objects[i].texture.u1;
        uvs[i * 12 + 9] = objects[i].texture.v1;

        //Top left
        uvs[i * 12 + 10] = objects[i].texture.u1;
        uvs[i * 12 + 11] = objects[i].texture.v2;
    }
    
    //Init OpenGL buffers
    glGenVertexArrays (1, &vao);
    glGenBuffers (1, &vbo);
    glGenBuffers (1, &ubo);
    glBindVertexArray (vao);

    glBindBuffer (GL_ARRAY_BUFFER, vbo);
    glBufferData (GL_ARRAY_BUFFER, sizeof (vertices), vertices, GL_DYNAMIC_DRAW);
    glVertexAttribPointer (0, 2, GL_SHORT, GL_FALSE, 2 * sizeof (short), 0);

    glBindBuffer (GL_ARRAY_BUFFER, ubo);
    glBufferData (GL_ARRAY_BUFFER, sizeof (uvs), uvs, GL_STATIC_DRAW);
    glVertexAttribPointer (1, 2, GL_FLOAT, GL_TRUE, 2 * sizeof (GLfloat), 0);
    
    glEnableVertexAttribArray (0);
    glEnableVertexAttribArray (1);

    glBindBuffer (GL_ARRAY_BUFFER, 0);
    glBindVertexArray (0);

    //Set OpenGL shader and VAO
    glUseProgram (shaderProgramId);
    glActiveTexture (GL_TEXTURE0);
    glBindTexture (GL_TEXTURE_2D, textureId);
    glBindVertexArray (vao);

    //Create ImGui environment
    IMGUI_CHECKVERSION ();
    ImGui::CreateContext ();
    ImGuiIO& io = ImGui::GetIO (); (void)io;
    ImGui::StyleColorsDark ();
    ImGui_ImplGlfw_InitForOpenGL (window, true);
    ImGui_ImplOpenGL3_Init ("#version 130");

    /*
    //Make app work on second monitor only
    int count;
    GLFWmonitor** monitors = glfwGetMonitors (&count);
    glfwSetWindowMonitor (window,  monitors[1], 0, 0, screenWidth, screenHeight, 500);
    */

    //Force window to be fullscreen on the main monitor
    glfwSetWindowMonitor (window, glfwGetPrimaryMonitor (), 0, 0, screenWidth, screenHeight, 500);

    //Grabs the callback set earlier, only runs if pollEvents is running
    glfwSetKeyCallback (window, KeyCallback);

    //Loop until window is closed
    while (!glfwWindowShouldClose (window)) {
        glfwPollEvents ();
        glBufferSubData (GL_ARRAY_BUFFER, 0, sizeof (vertices), vertices);

        //Draw ();
        //Draw pixels to frame buffer
        //glDrawPixels (screenWidth, screenHeight, GL_RGB, GL_FLOAT, pixels);

        glClearColor (0.2f, 0.25f, 0.3f, 1.0f);
        glClear (GL_COLOR_BUFFER_BIT);

        //If you had to unbind VAO bind it again
        //glBindVertexArray (vao);
        glDrawArrays (GL_TRIANGLES, 0, OBJECT_COUNT * 6);

        ImGui_ImplOpenGL3_NewFrame ();
        ImGui_ImplGlfw_NewFrame ();
        ImGui::NewFrame ();

        static float f = 0.0f;
        static int counter = 0;

        ImGui::Begin ("Debug Window");
        ImGui::Text ("Test text");
        //ImGui::Text ("Processor Designer average %.3f ms/frame (%.1f FPS)", 1000.0f / ImGui::GetIO ().Framerate, ImGui::GetIO ().Framerate);
        ImGui::End ();
        ImGui::Render ();
        ImGui_ImplOpenGL3_RenderDrawData (ImGui::GetDrawData ());

        //Swap front and back buffers
        glfwSwapBuffers (window);
    }

    //Memory cleanup
    ImGui_ImplOpenGL3_Shutdown ();
    ImGui_ImplGlfw_Shutdown ();
    ImGui::DestroyContext ();

    glDeleteVertexArrays (1, &vao);
    glDeleteBuffers (1, &vbo);
    glDeleteBuffers (1, &ubo);
    glDeleteTextures (1, &textureId);
    glDeleteProgram (shaderProgramId);

    glfwDestroyWindow (window);
    glfwTerminate ();
    delete[] pixels;

    return 0;
}



GLuint getShaderProgramId (const char *vertexFile, const char *fragmentFile) {
    GLuint programId, vertexHandler, fragmentHandler;

    vertexHandler = compileShader (vertexFile, GL_VERTEX_SHADER);
    fragmentHandler = compileShader (fragmentFile, GL_FRAGMENT_SHADER);

    programId = glCreateProgram ();
    glAttachShader (programId, vertexHandler);
    glAttachShader (programId, fragmentHandler);
    glLinkProgram (programId);

    GLint success;
    GLchar infoLog[512];
    glGetProgramiv (programId, GL_LINK_STATUS, &success);
    if (!success) {
        glGetProgramInfoLog (programId, 512, 0, infoLog);
        exit (1);
    }

    glDeleteShader (vertexHandler);
    glDeleteShader (fragmentHandler);

    return programId;
}



GLuint compileShader (const GLchar *source, GLuint shaderType) {
    GLuint shaderHandler;

    shaderHandler = glCreateShader (shaderType);
    glShaderSource (shaderHandler, 1, &source, 0);
    glCompileShader (shaderHandler);

    GLint success;
    GLchar infoLog[512];
    glGetShaderiv (shaderHandler, GL_COMPILE_STATUS, &success);
    if (!success) {
        glGetShaderInfoLog (shaderHandler, 512, 0, infoLog);
        exit (1);
    };

    return shaderHandler;
}