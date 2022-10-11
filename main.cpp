#include "imgui/imgui.h"
#include "imgui/imgui.cpp"
#include "imgui/imgui_impl_glfw.h"
#include "imgui/imgui_impl_opengl3.h"

#ifndef designerHeader
#define designerHeader
#endif
#include "graphics.cpp"
#include "debug.cpp"

//Window doesn't scale, resolution is hardcoded
int screenWidth = 1920;
int screenHeight = 1080;
const char windowName[] = "Processor Designer";
const float pi = 3.141592653598793f;
bool isEscapePressed = false;
bool trueBool = true;
bool redrawSprites = true;
bool placingGate = false;
int mouseX;
int mouseY;
int rawMouseX;
int rawMouseY;
int gatesToDraw = 0;
std::vector<GateData> gateData;
std::vector<ConnectionData> connectionData;
bool isConnectingGates = false;
Point connectionPoint;
bool isOverGateConnection = false;
int gateDataHoverIndex;
int gateConnectionIndex;



//Creates a callback to listen for the escape key, it will work on press down or up (down in this case)
void KeyCallback (GLFWwindow* window, int key, int scancode, int action, int mods) {
    if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS) {
        glfwSetWindowShouldClose (window, GL_TRUE);
    }
}



static void CursorCallback (GLFWwindow* window, double x, double y) {
    rawMouseX = (int) x;
    rawMouseY = (int) screenHeight - y;
    mouseX = (int) x - 100;
    mouseY = (int) screenHeight - y - 50;
    isOverGateConnection = false;
    gateDataHoverIndex = 0;
    gateConnectionIndex = 0;

    for (int i = 0; i < gateData.size (); i++) {
        switch (gateData[i].gateType) {
            case NOT:
                if ((rawMouseX <= gateData[i].position.x + 160 && rawMouseX >= gateData[i].position.x + 130) && (rawMouseY >= gateData[i].position.y + 25 && rawMouseY <= gateData[i].position.y + 75)) {
                    //Mouse over output
                    isOverGateConnection = true;
                    gateDataHoverIndex = i;
                    gateConnectionIndex = 1;
                }
                if ((rawMouseX <= gateData[i].position.x + 80 && rawMouseX >= gateData[i].position.x + 50) && (rawMouseY >= gateData[i].position.y + 25 && rawMouseY <= gateData[i].position.y + 75)) {
                    //Mouse over input
                    isOverGateConnection = true;
                    gateDataHoverIndex = i;
                    gateConnectionIndex = 0;
                }
            break;
            case AND:
                if ((rawMouseX <= gateData[i].position.x + 70 && rawMouseX >= gateData[i].position.x + 40) && (rawMouseY >= gateData[i].position.y && rawMouseY <= gateData[i].position.y + 50)) {
                    //Mouse over input A
                    isOverGateConnection = true;
                    gateDataHoverIndex = i;
                    gateConnectionIndex = 0;
                }
                if ((rawMouseX <= gateData[i].position.x + 70 && rawMouseX >= gateData[i].position.x + 40) && (rawMouseY >= gateData[i].position.y + 55 && rawMouseY <= gateData[i].position.y + 105)) {
                    //Mouse over input B
                    isOverGateConnection = true;
                    gateDataHoverIndex = i;
                    gateConnectionIndex = 1;
                }
                if ((rawMouseX <= gateData[i].position.x + 170 && rawMouseX >= gateData[i].position.x + 140) && (rawMouseY >= gateData[i].position.y + 25 && rawMouseY <= gateData[i].position.y + 75)) {
                    //Mouse over output
                    isOverGateConnection = true;
                    gateDataHoverIndex = i;
                    gateConnectionIndex = 2;
                }
            break;
        }
    }
}



static void MouseButtonCallback (GLFWwindow* window, int button, int action, int mods) {
    bool registerOneClick = false;

    //Place the gate
    if (button == GLFW_MOUSE_BUTTON_LEFT && action == GLFW_PRESS && placingGate && !registerOneClick) {
        placingGate = false;
        //Set connection location data
        switch (gateData.back ().gateType) {
            case NOT:
                gateData.back ().connectionPoints[0].point = {gateData.back ().position.x + 65, gateData.back ().position.y + 50};
                gateData.back ().connectionPoints[1].point = {gateData.back ().position.x + 145, gateData.back ().position.y + 50};
            break;
            case AND:
                gateData.back ().connectionPoints[0].point = {gateData.back ().position.x + 55, gateData.back ().position.y + 33};
                gateData.back ().connectionPoints[1].point = {gateData.back ().position.x + 55, gateData.back ().position.y + 64};
                gateData.back ().connectionPoints[2].point = {gateData.back ().position.x + 155, gateData.back ().position.y + 50};
            break;
        }
        registerOneClick = true;
    }

    //Start a gate connection
    if (button == GLFW_MOUSE_BUTTON_LEFT && action == GLFW_PRESS && !isConnectingGates && !placingGate && !registerOneClick && isOverGateConnection) {
        isConnectingGates = true;
        connectionPoint = gateData[gateDataHoverIndex].connectionPoints[gateConnectionIndex].point;
        registerOneClick = true;
    }

    //End a gate connection
    if (button == GLFW_MOUSE_BUTTON_LEFT && action == GLFW_PRESS && isConnectingGates && !registerOneClick && isOverGateConnection) {
        isConnectingGates = false;
        if (!gateData[gateDataHoverIndex].connectionPoints[gateConnectionIndex].connected) {
            connectionData.push_back ({{connectionPoint.x, connectionPoint.y}, {gateData[gateDataHoverIndex].connectionPoints[gateConnectionIndex].point.x, gateData[gateDataHoverIndex].connectionPoints[gateConnectionIndex].point.y}});
            gateData[gateDataHoverIndex].connectionPoints[gateConnectionIndex].connected = true;
        }
        registerOneClick = true;
    } else if (button == GLFW_MOUSE_BUTTON_LEFT && action == GLFW_PRESS && isConnectingGates && !registerOneClick && !isOverGateConnection) {
        isConnectingGates = false;
        registerOneClick = true;
    }
}



int main () {
    GLFWwindow* window;
    //Setup GLFW
    glfwInit ();
    glfwWindowHint (GLFW_RESIZABLE, GL_FALSE);
    if (!window) {
        glfwTerminate ();
        return -1;
    }

    window = glfwCreateWindow (screenWidth, screenHeight, windowName, NULL, NULL);
    //Set window context to current
    glfwMakeContextCurrent (window);
    glfwSwapInterval (1);
    //Setup GLEW
    glewExperimental = GL_TRUE;
    glewInit ();
    //Setup OpenGL
    glEnable (GL_CULL_FACE);
    glFrontFace (GL_CCW);
    glEnable (GL_BLEND);
    glBlendFunc (GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    glDisable (GL_DEPTH_TEST);
    glDisable (GL_SCISSOR_TEST);
    //Setup viewport
    glfwGetFramebufferSize (window, &screenWidth, &screenHeight);
    glViewport (0, 0, screenWidth, screenHeight);
    glMatrixMode (GL_PROJECTION);
	glLoadIdentity ();
    glOrtho (0, screenWidth, 0, screenHeight, 0, 1);
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

    /*
    //Make app work on second monitor only
    int count;
    GLFWmonitor** monitors = glfwGetMonitors (&count);
    glfwSetWindowMonitor (window, monitors[1], 0, 0, screenWidth, screenHeight, 155);
    */

    //Force window to be fullscreen on the main monitor
    glfwSetWindowMonitor (window, glfwGetPrimaryMonitor (), 0, 0, screenWidth, screenHeight, 155);

    //Setup callbacks
    glfwSetKeyCallback (window, KeyCallback);
    glfwSetMouseButtonCallback (window, MouseButtonCallback);
    glfwSetCursorPosCallback (window, CursorCallback);

    //Create ImGui environment
    IMGUI_CHECKVERSION ();
    ImGui::CreateContext ();
    ImGuiIO& io = ImGui::GetIO (); (void)io;
    ImGui::StyleColorsDark ();
    ImGui_ImplGlfw_InitForOpenGL (window, true);
    ImGui_ImplOpenGL3_Init ("#version 130");

    //Loop until window is closed
    while (!glfwWindowShouldClose (window)) {
        glEnable (GL_BLEND);
        if (redrawSprites) {
            std::vector<Object> objects (gatesToDraw, {0, 0, 0});
            std::vector<short> vertices (gatesToDraw * 12, 0);
            std::vector<float> uvs (gatesToDraw * 12, 0.0f);
            DrawSprites (objects, vertices, uvs, gateData, gatesToDraw);
            glBufferSubData (GL_ARRAY_BUFFER, 0, vertices.size () * sizeof (short), &vertices[0]);
            redrawSprites = false;
        }

        if (placingGate) {
            gateData.back () = {mouseX, mouseY, gateData.back ().gateType, gateData.back ().connectionPoints};
            redrawSprites = true;
        }

        //Set background
        glClearColor (0.2f, 0.25f, 0.3f, 1.0f);
        glClear (GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        //If you had to unbind VAO bind it again
        //glBindVertexArray (vao);
        glDrawArrays (GL_TRIANGLES, 0, gatesToDraw * 6);
        //Note, line drawing doesn't work when blending is enabled
        glDisable (GL_BLEND);
        glPointSize (10);
        glLineWidth (3); 
        glColor3f (1, 0, 0);

        //Show existing connections
        for (int i = 0; i < connectionData.size (); i++) {
            glBegin (GL_LINES);
            glVertex3f (connectionData[i].start.x, connectionData[i].start.y, 0);
            glVertex3f (connectionData[i].start.x + abs (connectionData[i].start.x - connectionData[i].end.x) / 2, connectionData[i].start.y, 0);
            glVertex3f (connectionData[i].start.x + abs (connectionData[i].start.x - connectionData[i].end.x) / 2, connectionData[i].start.y, 0);
            glVertex3f (connectionData[i].start.x + abs (connectionData[i].start.x - connectionData[i].end.x) / 2, connectionData[i].end.y, 0);
            glVertex3f (connectionData[i].start.x + abs (connectionData[i].start.x - connectionData[i].end.x) / 2, connectionData[i].end.y, 0);
            glVertex3f (connectionData[i].end.x, connectionData[i].end.y, 0);
            glEnd ();
        }

        //Starting a connection, draw straight line from point to cursor
        if (isConnectingGates) {
            glBegin (GL_LINES);
            glVertex3f (connectionPoint.x, connectionPoint.y, 0);
            glVertex3f (rawMouseX, rawMouseY, 0);
            glEnd ();
        }

        if (showGateConnectionBoxes) {
            DrawConnectionBoxes (gateData);
        }

        //IMGUI runs here
        ImGui_ImplOpenGL3_NewFrame ();
        ImGui_ImplGlfw_NewFrame ();
        ImGui::NewFrame ();

        ImGui::Begin ("Debug Window");
        ImGui::Text ("Debug and Testing Data");
        if (showGateConnectionBoxes) {
            if (ImGui::Button ("Hide clickable area over gate connections")) {
                showGateConnectionBoxes = false;
            }
        } else {
            if (ImGui::Button ("Show clickable area over gate connections")) {
                showGateConnectionBoxes = true;
            }
        }
        ImGui::End ();

        ImGui::Begin ("Top Window", &trueBool, ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoMove);
        ImGui::SetWindowSize (ImVec2 ((float)screenWidth + 10, (float)20.0f));
        ImGui::SetWindowPos (ImVec2 (-1, -1));
        ImGui::End ();

        ImGui::Begin ("Place Gates", &trueBool, ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoMove);
        ImGui::SetWindowSize (ImVec2 ((float)120.0f, (float)90.0f));
        ImGui::SetWindowPos (ImVec2 (-1, 30));
        ImGui::Text ("Place Gates");
        if (ImGui::Button ("NOT")) {
            gateData.push_back ({0, -100, NOT, std::vector<ConnectorData> {{{0, 0}, true, false}, {{0, 0}, false, false}}});
            gatesToDraw++;
            placingGate = true;
            redrawSprites = true;
        }
        if (ImGui::Button ("AND")) {
            gateData.push_back ({0, -100, AND, std::vector<ConnectorData> {{{0, 0}, true, false}, {{0, 0}, true, false}, {{0, 0}, false, false}}});
            gatesToDraw++;
            placingGate = true;
            redrawSprites = true;
        }
        ImGui::End ();

        ImGui::Render ();
        ImGui_ImplOpenGL3_RenderDrawData (ImGui::GetDrawData ());

        //Swap front and back buffers
        glfwSwapBuffers (window);
        glfwPollEvents ();
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

    return 0;
}