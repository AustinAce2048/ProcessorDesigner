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
bool redrawSprites = true;
bool placingGate = false;
int mouseX;
int mouseY;
int rawMouseX;
int rawMouseY;
int gatesToDraw = 0;
std::vector<Gate> gateData;
bool isConnectingGates = false;
//x is gateIndex, y is connectionIndex
Point connectionPoint;
bool isOverGateConnection = false;
bool isOverInputConnection = false;
bool isOverManualInput = false;
int gateDataHoverIndex;
int gateDataConnectionStartIndex;
int gateConnectionIndex;
bool isOverGate = false;
bool isDraggingGate = false;
int gateDragIndex;
int oldGateDragIndex;



void UpdateConnectionPoints (int gateIndex) {
    switch (gateData[gateIndex].gateType) {
        case NOT:
            gateData[gateIndex].connectionPoints[0].point = {gateData[gateIndex].position.x + 65, gateData[gateIndex].position.y + 50};
            gateData[gateIndex].connectionPoints[1].point = {gateData[gateIndex].position.x + 145, gateData[gateIndex].position.y + 50};
        break;
        case AND:
            gateData[gateIndex].connectionPoints[0].point = {gateData[gateIndex].position.x + 55, gateData[gateIndex].position.y + 32};
            gateData[gateIndex].connectionPoints[1].point = {gateData[gateIndex].position.x + 55, gateData[gateIndex].position.y + 63};
            gateData[gateIndex].connectionPoints[2].point = {gateData[gateIndex].position.x + 155, gateData[gateIndex].position.y + 49};
        break;
        case INPUTGATE:
            gateData[gateIndex].connectionPoints[0].point = {gateData[gateIndex].position.x + 130, gateData[gateIndex].position.y + 25};
        break;
        case OUTPUTGATE:
            gateData[gateIndex].connectionPoints[0].point = {gateData[gateIndex].position.x + 75, gateData[gateIndex].position.y + 28};
        break;
    }
}



//Creates a callback to listen for the escape key, it will work on press down or up (down in this case)
void KeyCallback (GLFWwindow* window, int key, int scancode, int action, int mods) {
    if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS) {
        glfwSetWindowShouldClose (window, GL_TRUE);
    }
}



static void CursorCallback (GLFWwindow* window, double x, double y) {
    rawMouseX = (int) x;
    rawMouseY = (int) screenHeight - y;
    mouseX = (int) x;
    mouseY = (int) screenHeight - y;
    isOverGateConnection = false;
    isOverInputConnection = false;
    isOverManualInput = false;
    gateDataHoverIndex = 0;
    gateConnectionIndex = 0;
    isOverGate = false;

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
                    isOverInputConnection = true;
                    gateDataHoverIndex = i;
                    gateConnectionIndex = 0;
                }
            break;
            case AND:
                if ((rawMouseX <= gateData[i].position.x + 70 && rawMouseX >= gateData[i].position.x + 40) && (rawMouseY >= gateData[i].position.y && rawMouseY <= gateData[i].position.y + 50)) {
                    //Mouse over input A
                    isOverGateConnection = true;
                    isOverInputConnection = true;
                    gateDataHoverIndex = i;
                    gateConnectionIndex = 0;
                }
                if ((rawMouseX <= gateData[i].position.x + 70 && rawMouseX >= gateData[i].position.x + 40) && (rawMouseY >= gateData[i].position.y + 55 && rawMouseY <= gateData[i].position.y + 105)) {
                    //Mouse over input B
                    isOverGateConnection = true;
                    isOverInputConnection = true;
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
            case INPUTGATE: case INPUTGATEON:
                if ((rawMouseX <= gateData[i].position.x + 140 && rawMouseX >= gateData[i].position.x + 110) && (rawMouseY >= gateData[i].position.y && rawMouseY <= gateData[i].position.y + 50)) {
                    //Mouse over output
                    isOverGateConnection = true;
                    gateDataHoverIndex = i;
                    gateConnectionIndex = 0;
                }
                if ((rawMouseX <= gateData[i].position.x + 110 && rawMouseX >= gateData[i].position.x + 75) && (rawMouseY >= gateData[i].position.y && rawMouseY <= gateData[i].position.y + 50)) {
                    //Mouse over gate
                    isOverManualInput = true;
                    gateDataHoverIndex = i;
                }
            break;
            case OUTPUTGATE: case OUTPUTGATEON:
                if ((rawMouseX <= gateData[i].position.x + 90 && rawMouseX >= gateData[i].position.x + 60) && (rawMouseY >= gateData[i].position.y && rawMouseY <= gateData[i].position.y + 50)) {
                    //Mouse over output
                    isOverGateConnection = true;
                    isOverInputConnection = true;
                    gateDataHoverIndex = i;
                    gateConnectionIndex = 0;
                }
            break;
        }

        //Check for gate hover
        if ((rawMouseX <= gateData[i].position.x + 125 && rawMouseX >= gateData[i].position.x + 75) && (rawMouseY >= gateData[i].position.y + 15 && rawMouseY <= gateData[i].position.y + 85) && !placingGate) {
            isOverGate = true;
            gateDragIndex = i;
        }
    }
}



static void MouseButtonCallback (GLFWwindow* window, int button, int action, int mods) {
    bool registerOneClick = false;

    //Place the gate
    if (button == GLFW_MOUSE_BUTTON_LEFT && action == GLFW_PRESS && placingGate && !registerOneClick) {
        placingGate = false;
        //Set connection location data
        UpdateConnectionPoints (gateData.size () - 1);
        registerOneClick = true;
    }

    //Start a gate connection
    if (button == GLFW_MOUSE_BUTTON_LEFT && action == GLFW_PRESS && !isConnectingGates && !placingGate && !registerOneClick && isOverGateConnection && !isOverInputConnection) {
        isConnectingGates = true;
        connectionPoint = {gateDataHoverIndex, gateConnectionIndex};
        //Store gate index to prevent connecting to yourself
        gateDataConnectionStartIndex = gateDataHoverIndex;
        registerOneClick = true;
    }

    //End a gate connection
    if (button == GLFW_MOUSE_BUTTON_LEFT && action == GLFW_PRESS && isConnectingGates && !registerOneClick && isOverGateConnection && isOverInputConnection) {
        isConnectingGates = false;
        if (!gateData[gateDataHoverIndex].connectionPoints[gateConnectionIndex].connected && gateDataHoverIndex != gateDataConnectionStartIndex) {
            //First change output gate, then input gate
            gateData[connectionPoint.x].connectionPoints[connectionPoint.y] = {gateData[connectionPoint.x].connectionPoints[connectionPoint.y].point, {gateDataHoverIndex, gateConnectionIndex}, false, true};
            gateData[gateDataHoverIndex].connectionPoints[gateConnectionIndex] = {gateData[gateDataHoverIndex].connectionPoints[gateConnectionIndex].point, {connectionPoint.x, connectionPoint.y}, true, true};
        }
        registerOneClick = true;
    } else if (button == GLFW_MOUSE_BUTTON_LEFT && action == GLFW_PRESS && isConnectingGates && !registerOneClick && (!isOverGateConnection || !isOverInputConnection)) {
        isConnectingGates = false;
        registerOneClick = true;
    }

    //Toggling a manual input
    if (button == GLFW_MOUSE_BUTTON_RIGHT && action == GLFW_PRESS && !isConnectingGates && !placingGate && !registerOneClick && isOverManualInput && !isDraggingGate) {
        if (gateData[gateDataHoverIndex].gateType == INPUTGATE) {
            gateData[gateDataHoverIndex].gateType = INPUTGATEON;
            redrawSprites = true;
        } else if (gateData[gateDataHoverIndex].gateType == INPUTGATEON) {
            gateData[gateDataHoverIndex].gateType = INPUTGATE;
            redrawSprites = true;
        }
    }

    //Starting to drag gate
    if (button == GLFW_MOUSE_BUTTON_LEFT && action == GLFW_PRESS && isOverGate && !registerOneClick && !isDraggingGate) {
        isDraggingGate = true;
        oldGateDragIndex = gateDragIndex;
    }

    //Ending a drag
    if (button == GLFW_MOUSE_BUTTON_LEFT && action == GLFW_RELEASE && !registerOneClick && isDraggingGate) {
        isDraggingGate = false;
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

    
    //Make app work on second monitor only
    int count;
    GLFWmonitor** monitors = glfwGetMonitors (&count);
    glfwSetWindowMonitor (window, monitors[1], 0, 0, screenWidth, screenHeight, 155);
    

    //Force window to be fullscreen on the main monitor
    //glfwSetWindowMonitor (window, glfwGetPrimaryMonitor (), 0, 0, screenWidth, screenHeight, 155);

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
            //Account for offest due to different size sprites
            switch (gateData.back ().gateType) {
                case NOT: case AND:
                    gateData.back () = {mouseX - 100, mouseY - 50, gateData.back ().gateType, gateData.back ().connectionPoints};
                break;
                case INPUTGATE: case OUTPUTGATE:
                    gateData.back () = {mouseX - 100, mouseY - 27, gateData.back ().gateType, gateData.back ().connectionPoints};
                break;
            }
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
        glLineWidth (4); 
        glColor3f (1, 0, 0);

        //Show existing connections
        for (int i = 0; i < gateData.size (); i++) {
            glBegin (GL_LINES);
            for (int j = 0; j < gateData[i].connectionPoints.size (); j++) {
                //Ignore if gate data is 0s and ignore if connection is input and if connection id doesn't exist
                if (gateData[i].connectionPoints[j].connectedGateData.x == -1) {
                    continue;
                }
                if ((gateData[i].connectionPoints[j].point.x == 0 && gateData[i].connectionPoints[j].point.y == 0) || (gateData[gateData[i].connectionPoints[j].connectedGateData.x].connectionPoints[gateData[i].connectionPoints[j].connectedGateData.y].point.x == 0 && gateData[gateData[i].connectionPoints[j].connectedGateData.x].connectionPoints[gateData[i].connectionPoints[j].connectedGateData.y].point.y == 0)) {
                    continue;
                }
                if (gateData[i].connectionPoints[j].input) {
                    continue;
                }
                glVertex3f (gateData[i].connectionPoints[j].point.x, gateData[i].connectionPoints[j].point.y, 0);
                glVertex3f (gateData[i].connectionPoints[j].point.x + abs (gateData[i].connectionPoints[j].point.x - gateData[gateData[i].connectionPoints[j].connectedGateData.x].connectionPoints[gateData[i].connectionPoints[j].connectedGateData.y].point.x) / 2, gateData[i].connectionPoints[j].point.y, 0);
                glVertex3f (gateData[i].connectionPoints[j].point.x + abs (gateData[i].connectionPoints[j].point.x - gateData[gateData[i].connectionPoints[j].connectedGateData.x].connectionPoints[gateData[i].connectionPoints[j].connectedGateData.y].point.x) / 2, gateData[i].connectionPoints[j].point.y, 0);
                glVertex3f (gateData[i].connectionPoints[j].point.x + abs (gateData[i].connectionPoints[j].point.x - gateData[gateData[i].connectionPoints[j].connectedGateData.x].connectionPoints[gateData[i].connectionPoints[j].connectedGateData.y].point.x) / 2, gateData[gateData[i].connectionPoints[j].connectedGateData.x].connectionPoints[gateData[i].connectionPoints[j].connectedGateData.y].point.y, 0);
                glVertex3f (gateData[i].connectionPoints[j].point.x + abs (gateData[i].connectionPoints[j].point.x - gateData[gateData[i].connectionPoints[j].connectedGateData.x].connectionPoints[gateData[i].connectionPoints[j].connectedGateData.y].point.x) / 2, gateData[gateData[i].connectionPoints[j].connectedGateData.x].connectionPoints[gateData[i].connectionPoints[j].connectedGateData.y].point.y, 0);
                glVertex3f (gateData[gateData[i].connectionPoints[j].connectedGateData.x].connectionPoints[gateData[i].connectionPoints[j].connectedGateData.y].point.x, gateData[gateData[i].connectionPoints[j].connectedGateData.x].connectionPoints[gateData[i].connectionPoints[j].connectedGateData.y].point.y, 0);
            }
            glEnd ();
        }

        //Starting a connection, draw straight line from point to cursor
        if (isConnectingGates) {
            glBegin (GL_LINES);
            glVertex3f (gateData[connectionPoint.x].connectionPoints[connectionPoint.y].point.x, gateData[connectionPoint.x].connectionPoints[connectionPoint.y].point.y, 0);
            glVertex3f (rawMouseX, rawMouseY, 0);
            glEnd ();
        }

        if (showGateConnectionBoxes) {
            DrawConnectionBoxes (gateData);
        }

        if (isDraggingGate) {
            //Prevent bug which lets users drag gates unintentionally
            if (gateDragIndex != oldGateDragIndex) {
                gateDragIndex = oldGateDragIndex;
            }
            //Prevent dragging gate offscreen
            if (mouseX >= screenWidth - 75) {
                mouseX = screenWidth - 75;
            }
            if (mouseX <= 75) {
                mouseX = 75;
            }
            if (mouseY >= screenHeight - 50) {
                mouseY = screenHeight - 50;
            }
            if (mouseY <= 50) {
                mouseY = 50;
            }
            switch (gateData[gateDragIndex].gateType) {
                case NOT: case AND:
                    gateData[gateDragIndex].position = {mouseX - 100, mouseY - 50};
                break;
                case INPUTGATE: case OUTPUTGATE: case INPUTGATEON: case OUTPUTGATEON:
                    gateData[gateDragIndex].position = {mouseX - 100, mouseY - 27};
                break;
            }
            UpdateConnectionPoints (gateDragIndex);
            for (int i = 0; i < gateData[gateDragIndex].connectionPoints.size (); i++) {
                if (gateData[gateDragIndex].connectionPoints[i].connectedGateData.x != -1) {
                    UpdateConnectionPoints (gateData[gateDragIndex].connectionPoints[i].connectedGateData.x);
                }
            }
            redrawSprites = true;
        }

        //IMGUI runs here
        ImGui_ImplOpenGL3_NewFrame ();
        ImGui_ImplGlfw_NewFrame ();
        ImGui::NewFrame ();

        DebugWindow (gateData, redrawSprites);

        ImGui::Begin ("Place Gates", &trueBool, ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoMove);
        ImGui::SetWindowSize (ImVec2 ((float)150.0f, (float)130.0f));
        ImGui::SetWindowPos (ImVec2 (-1, 0));
        ImGui::Text ("Place Gates");
        if (ImGui::Button ("NOT")) {
            gateData.push_back ({0, -100, NOT, std::vector<ConnectorData> {{{0, 0}, {-1, 0}, true, false}, {{0, 0}, {-1, 0}, false, false}}, false});
            gatesToDraw++;
            placingGate = true;
            redrawSprites = true;
        }
        if (ImGui::Button ("AND")) {
            gateData.push_back ({0, -100, AND, std::vector<ConnectorData> {{{0, 0}, {-1, 0}, true, false}, {{0, 0}, {-1, 0}, true, false}, {{0, 0}, {-1, 0}, false, false}}, false});
            gatesToDraw++;
            placingGate = true;
            redrawSprites = true;
        }
        if (ImGui::Button ("MANUAL INPUT LINE")) {
            gateData.push_back ({0, -100, INPUTGATE, std::vector<ConnectorData> {{{0, 0}, {-1, 0}, false, false}}, false});
            gatesToDraw++;
            placingGate = true;
            redrawSprites = true;
        }
        if (ImGui::Button ("READ OUTPUT LINE")) {
            gateData.push_back ({0, -100, OUTPUTGATE, std::vector<ConnectorData> {{{0, 0}, {-1, 0}, true, false}}, false});
            gatesToDraw++;
            placingGate = true;
            redrawSprites = true;
        }
        ImGui::End ();

        ImGui::Begin ("Control Deck", &trueBool, ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoMove);
        ImGui::SetWindowSize (ImVec2 ((float)210.0f, (float)60.0f));
        ImGui::SetWindowPos (ImVec2 ((screenWidth / 2) - 105.0f, 0));
        ImGui::Text ("Simulate");
        if (ImGui::Button ("Run One Cycle")) {
            //Connect to gate logic
        }
        ImGui::SameLine ();
        if (ImGui::Button ("Reset Board")) {
            ResetOutputs (gateData, redrawSprites);
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