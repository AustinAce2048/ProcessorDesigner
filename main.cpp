#include "imgui/imgui.h"
#include "imgui/imgui.cpp"
#include "imgui/imgui_impl_glfw.h"
#include "imgui/imgui_impl_opengl3.h"
#include "imgui/misc/cpp/imgui_stdlib.h"

#ifndef designerHeader
#define designerHeader
#endif
#include "graphics.cpp"
#include "callbacks.cpp"
#include "loader.cpp"
#include "debug.cpp"

//Window doesn't scale, resolution is hardcoded
int screenWidth = 1920;
int screenHeight = 1080;
const char windowName[] = "Processor Designer";
bool isEscapePressed = false;
bool redrawSprites = true;
bool placingGate = false;
int mouseX;
int mouseY;
int rawMouseX;
int rawMouseY;
bool isMouseHoveringUI = false;
bool isTypingInUI = false;
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
bool isPanningScreen = false;
int xPanOffset = 0;
int yPanOffset = 0;
int masterXPanOffset = 0;
int masterYPanOffset = 0;
Point mousePositionOnStartDrag;
bool isResetPanning = false;
float scaleFactor = 1.0f;
int updateConnectionPointIndex = -1;
int isOrderGatesIndex = -1;
int secondOrderGates = -1;
bool isCreatingFunction = false;
Point functionPointA;
Point functionPointB;
std::string functionName;
std::vector<Function> functions;
bool placingFunction = false;
int functionLength;
int functionID;
std::vector<Point> oldGatePositions;



void OrderGates(int dependent, int independent) {
    //Already in the right order
    if (dependent > independent) return;
    
    for (int i = 0; i < gateData.size(); ++i) {
        for (int j = 0; j < gateData[i].connectionPoints.size(); ++j) {
            std::cout << i << " " << gateData[i].gateType << ": " << gateData[i].connectionPoints[j].connectedGateData.x << " " << gateData[i].connectionPoints[j].connectedGateData.y << " " << gateData[gateData[i].connectionPoints[j].connectedGateData.x].gateType << std::endl;
        }
        std::cout << std::endl;
    }

    //Only change the order of elements between dependent and independent
    for (int n = 0; n < independent - dependent + 1; ++n) {
        //The element might move to the end of the sequence
        for (int i = dependent; i < independent; ++i) {
            //Check if the current element's index is less than other elements that it's dependent on
            for (int k = 0; k < gateData[i].connectionPoints.size(); ++k) {
                if (gateData[i].connectionPoints[k].input == true && i < gateData[i].connectionPoints[k].connectedGateData.x) {
                    //Update all elements connected to the i-th element with new index (i + 1) before swapping
                    for (k = 0; k < gateData[i].connectionPoints.size(); ++k) {
                        //Check that this is a connected gate point
                        if (gateData[i].connectionPoints[k].connectedGateData.x > -1) {
                            if (gateData[i].connectionPoints[k].connectedGateData.x == i) {
                                gateData[i].connectionPoints[k].connectedGateData.x = i + 1;
                            } else if (gateData[i].connectionPoints[k].connectedGateData.x == i + 1) {
                                gateData[i].connectionPoints[k].connectedGateData.x = i;
                            } else {
                                gateData[gateData[i].connectionPoints[k].connectedGateData.x].connectionPoints[gateData[i].connectionPoints[k].connectedGateData.y].connectedGateData.x = i + 1;
                            }
                        }
                    }
                    //Update all elements connected to the (i + 1)-th element with new index (i) before swapping
                    for (k = 0; k < gateData[i + 1].connectionPoints.size(); ++k) {
                        //Check that this is a connected gate point
                        if (gateData[i + 1].connectionPoints[k].connectedGateData.x > -1) {
                            if (gateData[i + 1].connectionPoints[k].connectedGateData.x == i) {
                                gateData[i + 1].connectionPoints[k].connectedGateData.x = i + 1;
                            } else if (gateData[i + 1].connectionPoints[k].connectedGateData.x == i + 1) {
                                gateData[i + 1].connectionPoints[k].connectedGateData.x = i;
                            } else {
                                gateData[gateData[i + 1].connectionPoints[k].connectedGateData.x].connectionPoints[gateData[i + 1].connectionPoints[k].connectedGateData.y].connectedGateData.x = i;
                            }
                        }
                    }
                    std::swap(gateData[i], gateData[i + 1]);
                    break;
                }
            }
        }
        for (int i = 0; i < gateData.size(); ++i) {
            for (int j = 0; j < gateData[i].connectionPoints.size(); ++j) {
                std::cout << i << " " << gateData[i].gateType << ": " << gateData[i].connectionPoints[j].connectedGateData.x << " " << gateData[i].connectionPoints[j].connectedGateData.y << " " << gateData[gateData[i].connectionPoints[j].connectedGateData.x].gateType << std::endl;
            }
            std::cout << std::endl;
        }
    }
}



void OneSimulation () {
    for (int i = 0; i < gateData.size(); ++i) {
        switch (gateData[i].gateType) {
            case NOT:
                gateData[i].isOn = !gateData[gateData[i].connectionPoints[0].connectedGateData.x].isOn;
            break;
            case AND:
                gateData[i].isOn = gateData[gateData[i].connectionPoints[0].connectedGateData.x].isOn && gateData[gateData[i].connectionPoints[1].connectedGateData.x].isOn;
            break;
            case OR:
                gateData[i].isOn = gateData[gateData[i].connectionPoints[0].connectedGateData.x].isOn || gateData[gateData[i].connectionPoints[1].connectedGateData.x].isOn;
            break;
            case OUTPUTGATE: case OUTPUTGATEON:
                gateData[i].isOn = gateData[gateData[i].connectionPoints[0].connectedGateData.x].isOn;
                if (gateData[i].isOn == true) gateData[i].gateType = OUTPUTGATEON;
                else gateData[i].gateType = OUTPUTGATE;
            break;
            default:
                gateData[i].isOn = gateData[i].isOn;
        }
    }
    redrawSprites = true;
}



void UpdateConnectionPoints (int gateIndex) {
    switch (gateData[gateIndex].gateType) {
        case NOT:
            gateData[gateIndex].connectionPoints[0].point = {(int)(gateData[gateIndex].position.x + 65 * scaleFactor), (int)(gateData[gateIndex].position.y + 50 * scaleFactor)};
            //For every output connection
            for (int i = 1; i < gateData[gateIndex].connectionPoints.size (); i++) {
                gateData[gateIndex].connectionPoints[i].point = {(int)(gateData[gateIndex].position.x + 145 * scaleFactor), (int)(gateData[gateIndex].position.y + 50 * scaleFactor)};
            }
            gateData[gateIndex].initialConnections = 2;
        break;
        case AND:
            gateData[gateIndex].connectionPoints[0].point = {(int)(gateData[gateIndex].position.x + 55 * scaleFactor), (int)(gateData[gateIndex].position.y + 31 * scaleFactor)};
            gateData[gateIndex].connectionPoints[1].point = {(int)(gateData[gateIndex].position.x + 55 * scaleFactor), (int)(gateData[gateIndex].position.y + 63 * scaleFactor)};
            //For every output connection
            for (int i = 2; i < gateData[gateIndex].connectionPoints.size (); i++) {
                gateData[gateIndex].connectionPoints[i].point = {(int)(gateData[gateIndex].position.x + 155 * scaleFactor), (int)(gateData[gateIndex].position.y + 47 * scaleFactor)};
            }
            gateData[gateIndex].initialConnections = 3;
        break;
        case OR:
            gateData[gateIndex].connectionPoints[0].point = {(int)(gateData[gateIndex].position.x + 60 * scaleFactor), (int)(gateData[gateIndex].position.y + 25 * scaleFactor)};
            gateData[gateIndex].connectionPoints[1].point = {(int)(gateData[gateIndex].position.x + 60 * scaleFactor), (int)(gateData[gateIndex].position.y + 75 * scaleFactor)};
            //For every output connection
            for (int i = 2; i < gateData[gateIndex].connectionPoints.size (); i++) {
                gateData[gateIndex].connectionPoints[i].point = {(int)(gateData[gateIndex].position.x + 155 * scaleFactor), (int)(gateData[gateIndex].position.y + 49 * scaleFactor)};
            }
            gateData[gateIndex].initialConnections = 3;
        break;
        case INPUTGATE: case INPUTGATEON:
            gateData[gateIndex].connectionPoints[0].point = {(int)(gateData[gateIndex].position.x + 130 * scaleFactor), (int)(gateData[gateIndex].position.y + 25 * scaleFactor)};
            //For every output connection
            for (int i = 1; i < gateData[gateIndex].connectionPoints.size (); i++) {
                gateData[gateIndex].connectionPoints[i].point = {(int)(gateData[gateIndex].position.x + 130 * scaleFactor), (int)(gateData[gateIndex].position.y + 25 * scaleFactor)};
            }
            gateData[gateIndex].initialConnections = 1;
        break;
        case OUTPUTGATE: case OUTPUTGATEON:
            gateData[gateIndex].connectionPoints[0].point = {(int)(gateData[gateIndex].position.x + 75 * scaleFactor), (int)(gateData[gateIndex].position.y + 28 * scaleFactor)};
            gateData[gateIndex].initialConnections = 1;
        break;
        case EIGHTBUS:
            gateData[gateIndex].connectionPoints[0].point = {(int)(gateData[gateIndex].position.x + 55 * scaleFactor), (int)(gateData[gateIndex].position.y + 237 * scaleFactor)};
            gateData[gateIndex].connectionPoints[1].point = {(int)(gateData[gateIndex].position.x + 55 * scaleFactor), (int)(gateData[gateIndex].position.y + 208 * scaleFactor)};
            gateData[gateIndex].connectionPoints[2].point = {(int)(gateData[gateIndex].position.x + 55 * scaleFactor), (int)(gateData[gateIndex].position.y + 178 * scaleFactor)};
            gateData[gateIndex].connectionPoints[3].point = {(int)(gateData[gateIndex].position.x + 55 * scaleFactor), (int)(gateData[gateIndex].position.y + 148 * scaleFactor)};
            gateData[gateIndex].connectionPoints[4].point = {(int)(gateData[gateIndex].position.x + 55 * scaleFactor), (int)(gateData[gateIndex].position.y + 118 * scaleFactor)};
            gateData[gateIndex].connectionPoints[5].point = {(int)(gateData[gateIndex].position.x + 55 * scaleFactor), (int)(gateData[gateIndex].position.y + 88 * scaleFactor)};
            gateData[gateIndex].connectionPoints[6].point = {(int)(gateData[gateIndex].position.x + 55 * scaleFactor), (int)(gateData[gateIndex].position.y + 58 * scaleFactor)};
            gateData[gateIndex].connectionPoints[7].point = {(int)(gateData[gateIndex].position.x + 55 * scaleFactor), (int)(gateData[gateIndex].position.y + 28 * scaleFactor)};
            //For every output connection
            for (int i = 8; i < gateData[gateIndex].connectionPoints.size (); i++) {
                gateData[gateIndex].connectionPoints[i].point = {(int)(gateData[gateIndex].position.x + 115 * scaleFactor), (int)(gateData[gateIndex].position.y + 237 * scaleFactor)};
            }
            gateData[gateIndex].initialConnections = 9;
        break;
        case EIGHTBUSOUT:
            gateData[gateIndex].connectionPoints[0].point = {(int)(gateData[gateIndex].position.x + 85 * scaleFactor), (int)(gateData[gateIndex].position.y + 35 * scaleFactor)};
            //For every output connection
            for (int i = 1; i < gateData[gateIndex].connectionPoints.size (); i++) {
                gateData[gateIndex].connectionPoints[i].point = {(int)(gateData[gateIndex].position.x + 145 * scaleFactor), (int)(gateData[gateIndex].position.y + (i * 30) * scaleFactor)};
            }
            gateData[gateIndex].initialConnections = 9;
        break;
        case XOR:
            gateData[gateIndex].connectionPoints[0].point = {(int)(gateData[gateIndex].position.x + 55 * scaleFactor), (int)(gateData[gateIndex].position.y + 29 * scaleFactor)};
            gateData[gateIndex].connectionPoints[1].point = {(int)(gateData[gateIndex].position.x + 55 * scaleFactor), (int)(gateData[gateIndex].position.y + 79 * scaleFactor)};
            //For every output connection
            for (int i = 2; i < gateData[gateIndex].connectionPoints.size (); i++) {
                gateData[gateIndex].connectionPoints[i].point = {(int)(gateData[gateIndex].position.x + 150 * scaleFactor), (int)(gateData[gateIndex].position.y + 54 * scaleFactor)};
            }
            gateData[gateIndex].initialConnections = 3;
        break;
    }
}



void UpdatePanningPosition () {
    if (isResetPanning) {
        for (int i = 0; i < gateData.size (); i++) {
            gateData[i].position.x = gateData[i].position.x - masterXPanOffset;
            gateData[i].position.y = gateData[i].position.y - masterYPanOffset;
            UpdateConnectionPoints (i);
        }
        masterXPanOffset = 0;
        masterYPanOffset = 0;
        xPanOffset = 0;
        yPanOffset = 0;
        redrawSprites = true;
        isPanningScreen = false;
    } else {
        xPanOffset = mouseX - mousePositionOnStartDrag.x;
        yPanOffset = mouseY - mousePositionOnStartDrag.y;
        masterXPanOffset = masterXPanOffset + xPanOffset;
        masterYPanOffset = masterYPanOffset + yPanOffset;

        for (int i = 0; i < gateData.size (); i++) {
            gateData[i].position.x = gateData[i].position.x + xPanOffset;
            gateData[i].position.y = gateData[i].position.y + yPanOffset;
            mousePositionOnStartDrag = {mouseX, mouseY};
            UpdateConnectionPoints (i);
        }
        redrawSprites = true;
    }
    isResetPanning = false;
}



//Creates a callback to listen for the escape key, it will work on press down or up (down in this case)
void KeyCallback (GLFWwindow* window, int key, int scancode, int action, int mods) {
    if (isTypingInUI) {
        return;
    }
    KeyboardCallback (window, key, action, isOverGate, isDraggingGate, gateData, gateDragIndex, redrawSprites, isResetPanning, isPanningScreen);
}



static void CursorCallback (GLFWwindow* window, double x, double y) {
    MouseCallback (x, y, rawMouseX, rawMouseY, mouseX, mouseY, isOverGateConnection, isOverInputConnection, isOverManualInput, gateDataHoverIndex, gateConnectionIndex, isOverGate, screenHeight, gateData, placingGate, gateDragIndex, scaleFactor);
}



static void MouseButtonCallback (GLFWwindow* window, int button, int action, int mods) {
    if (isMouseHoveringUI) {
        return;
    }
    MouseButtonsCallback (button, action, placingGate, isConnectingGates, isOverGateConnection, isOverInputConnection, connectionPoint, gateDataConnectionStartIndex, gateDataHoverIndex, gateConnectionIndex, isOverManualInput, isDraggingGate, redrawSprites, isOverGate, oldGateDragIndex, gateDragIndex, isPanningScreen, mousePositionOnStartDrag, updateConnectionPointIndex, gateData, isOrderGatesIndex, secondOrderGates, mouseX, mouseY, isCreatingFunction, functionPointA, functionPointB, placingFunction);
}



void ScrollCallback (GLFWwindow* window, double xOffset, double yOffset) {
    if (!isCreatingFunction && !isMouseHoveringUI) {
        ScrollingCallback (yOffset, redrawSprites, scaleFactor);
    }
}



int main () {
    GLFWwindow* window;
    //Setup GLFW
    glfwInit ();
    glfwWindowHint (GLFW_RESIZABLE, GL_FALSE);

    window = glfwCreateWindow (screenWidth, screenHeight, windowName, NULL, NULL);
    if (!window) {
        glfwTerminate ();
        return -1;
    }
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
    unsigned char* image = SOIL_load_image ("gates.png", &width, &height, 0, SOIL_LOAD_RGBA);
    glTexImage2D (GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, image);
    if (image == 0) {
        exit (1);
    } else {
        SOIL_free_image_data (image);
    }

    //Make app work on second monitor only
    /*int count;
    GLFWmonitor** monitors = glfwGetMonitors (&count);
    glfwSetWindowMonitor (window, monitors[1], 0, 0, screenWidth, screenHeight, 155);*/

    //Force window to be fullscreen on the main monitor
    glfwSetWindowMonitor (window, glfwGetPrimaryMonitor (), 0, 0, screenWidth, screenHeight, 155);

    //Setup callbacks
    glfwSetKeyCallback (window, KeyCallback);
    glfwSetMouseButtonCallback (window, MouseButtonCallback);
    glfwSetCursorPosCallback (window, CursorCallback);
    glfwSetScrollCallback (window, ScrollCallback);

    //Load pre-saved functions
    LoadPreSavedFunctions (functions);

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
            std::vector<Object> objects (gateData.size (), {0, 0, 0});
            std::vector<short> vertices (gateData.size () * 12, 0);
            std::vector<float> uvs (gateData.size () * 12, 0.0f);
            for (int i = 0; i < gateData.size (); i++) {
                UpdateConnectionPoints (i);
            }
            DrawSprites (objects, vertices, uvs, gateData, scaleFactor);
            glBufferSubData (GL_ARRAY_BUFFER, 0, vertices.size () * sizeof (short), &vertices[0]);
            redrawSprites = false;
        }

        //Used to call main functions from other files
        if (updateConnectionPointIndex != -1) {
            UpdateConnectionPoints (updateConnectionPointIndex);
            updateConnectionPointIndex = -1;
        }

        if (placingGate) {
            //Account for offest due to different size sprites
            switch (gateData.back ().gateType) {
                case NOT: case AND: case OR: case XOR:
                    gateData.back () = {mouseX - 100, mouseY - 50, gateData.back ().gateType, gateData.back ().connectionPoints};
                break;
                case INPUTGATE: case OUTPUTGATE:
                    gateData.back () = {mouseX - 100, mouseY - 27, gateData.back ().gateType, gateData.back ().connectionPoints};
                break;
                case EIGHTBUS: case EIGHTBUSOUT:
                    gateData.back () = {mouseX - 100, mouseY - 135, gateData.back ().gateType, gateData.back ().connectionPoints};
                break;
            }
            redrawSprites = true;
        }

        if (placingFunction) {
            //Create a rough offset that accounts for total width and height of function
            //Apply that offset to all gates in the function
            if (oldGatePositions.size () == 0) {
                for (int i = 0; i < functionLength; i++) {
                    oldGatePositions.push_back (gateData[gateData.size () - 1 - i].position);
                }
            }
            for (int i = 0; i < functionLength; i++) {
                gateData[gateData.size () - 1 - i].position = {mouseX + oldGatePositions[i].x - functions[functionID].pointA.x - (functions[functionID].middle.x / 2), mouseY + oldGatePositions[i].y - functions[functionID].pointA.y - (functions[functionID].middle.y / 2)};
            }
            //Fix for when function only has one gate
            if (functionLength == 1) {
                gateData[gateData.size () - 1].position = {mouseX - 100, mouseY - 38};
            }
            redrawSprites = true;
        }

        //Set background
        glClearColor (0.2f, 0.2f, 0.3f, 1.0f);
        glClear (GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        //Note, line drawing doesn't work when blending is enabled
        glDisable (GL_BLEND);
        glColor3f (0.0f, 0.0f, 0.0f);

        if (showGateConnectionBoxes) {
            DrawConnectionBoxes (gateData, scaleFactor);
        }

        //Grid lines
        /*glPointSize (1);
        glLineWidth (1); 
        for (int i = -screenWidth; i < screenWidth * 10 / 50; i++) {
            glBegin (GL_LINES);
            glVertex3f (i * (50 * scaleFactor) + masterXPanOffset, 0, 0);
            glVertex3f (i * (50 * scaleFactor) + masterXPanOffset, screenHeight, 0);
            glEnd ();
        }
        for (int i = -screenHeight; i < screenHeight * 10 / 50; i++) {
            glBegin (GL_LINES);
            glVertex3f (0, i * (50 * scaleFactor) + masterYPanOffset, 0);
            glVertex3f (screenWidth, i * (50 * scaleFactor) + masterYPanOffset, 0);
            glEnd ();
        }*/

        //Change line settings
        glPointSize (10);
        glLineWidth (4 * scaleFactor);

        //Draw function lines
        if (isCreatingFunction && functionPointA.x != -1) {
            if (functionPointB.x == -1) {
                glBegin (GL_LINES);
                glVertex3f (functionPointA.x * scaleFactor, functionPointA.y * scaleFactor, 0);
                glVertex3f (mouseX, functionPointA.y * scaleFactor, 0);
                glVertex3f (mouseX, functionPointA.y * scaleFactor, 0);
                glVertex3f (mouseX, mouseY, 0);
                glVertex3f (mouseX, mouseY, 0);
                glVertex3f (functionPointA.x * scaleFactor, mouseY, 0);
                glVertex3f (functionPointA.x * scaleFactor, mouseY, 0);
                glVertex3f (functionPointA.x * scaleFactor, functionPointA.y * scaleFactor, 0);
                glEnd ();
            } else {
                glBegin (GL_LINES);
                glVertex3f (functionPointA.x * scaleFactor, functionPointA.y * scaleFactor, 0);
                glVertex3f (functionPointB.x, functionPointA.y * scaleFactor, 0);
                glVertex3f (functionPointB.x, functionPointA.y * scaleFactor, 0);
                glVertex3f (functionPointB.x, functionPointB.y, 0);
                glVertex3f (functionPointB.x, functionPointB.y, 0);
                glVertex3f (functionPointA.x * scaleFactor, functionPointB.y, 0);
                glVertex3f (functionPointA.x * scaleFactor, functionPointB.y, 0);
                glVertex3f (functionPointA.x * scaleFactor, functionPointA.y * scaleFactor, 0);
                glEnd ();
            }
        }

        //Show existing connections
        for (int i = 0; i < gateData.size (); i++) {
            glBegin (GL_LINES);
            for (int j = 0; j < gateData[i].connectionPoints.size (); j++) {
                //Ignore if gate data is 0s and ignore if connection is input and if connection id doesn't exist
                if (gateData[i].connectionPoints[j].connectedGateData.x == -1) {
                    //Connection id check
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

        //If you had to unbind VAO bind it again
        //glBindVertexArray (vao);
        glEnable (GL_BLEND);
        glDrawArrays (GL_TRIANGLES, 0, gateData.size () * 6);

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
                case NOT: case AND: case OR: case XOR:
                    gateData[gateDragIndex].position = {mouseX - 100, mouseY - 50};
                break;
                case INPUTGATE: case OUTPUTGATE: case INPUTGATEON: case OUTPUTGATEON:
                    gateData[gateDragIndex].position = {mouseX - 100, mouseY - 27};
                break;
                case EIGHTBUS: case EIGHTBUSOUT:
                    gateData[gateDragIndex].position = {mouseX - 100, mouseY - 135};
                break;
            }
            for (int i = 0; i < gateData[gateDragIndex].connectionPoints.size (); i++) {
                if (gateData[gateDragIndex].connectionPoints[i].connectedGateData.x != -1) {
                    UpdateConnectionPoints (gateData[gateDragIndex].connectionPoints[i].connectedGateData.x);
                }
            }
            UpdateConnectionPoints (gateDragIndex);
            redrawSprites = true;
        }

        if (isPanningScreen) {
            UpdatePanningPosition ();
        }

        //IMGUI runs here
        ImGui_ImplOpenGL3_NewFrame ();
        ImGui_ImplGlfw_NewFrame ();
        ImGui::NewFrame ();

        //Stop GLFW from reading mouse and/or keyboard if ImGUI is reading it
        if (io.WantCaptureMouse) {
            isMouseHoveringUI = true;
        } else {
            isMouseHoveringUI = false;
        }
        if (io.WantCaptureKeyboard) {
            isTypingInUI = true;
        } else {
            isTypingInUI = false;
        }

        DebugWindow (gateData, redrawSprites);

        ImGui::Begin ("Place Gates", &trueBool, ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoMove);
        ImGui::SetWindowSize (ImVec2 ((float)150.0f, (float)240.0f));
        ImGui::SetWindowPos (ImVec2 (-1, 0));
        ImGui::Text ("Place Gates");
        if (ImGui::Button ("NOT")) {
            gateData.push_back ({{0, -100}, NOT, std::vector<ConnectorData> {{{0, 0}, {-1, 0}, true, false}, {{0, 0}, {-1, 0}, false, false}}, false, 2});
            placingGate = true;
            redrawSprites = true;
        }
        if (ImGui::Button ("AND")) {
            gateData.push_back ({{0, -100}, AND, std::vector<ConnectorData> {{{0, 0}, {-1, 0}, true, false}, {{0, 0}, {-1, 0}, true, false}, {{0, 0}, {-1, 0}, false, false}}, false, 3});
            placingGate = true;
            redrawSprites = true;
        }
        if (ImGui::Button ("MANUAL INPUT LINE")) {
            gateData.push_back ({{0, -100}, INPUTGATE, std::vector<ConnectorData> {{{0, 0}, {-1, 0}, false, false}}, false, 1});
            placingGate = true;
            redrawSprites = true;
        }
        if (ImGui::Button ("READ OUTPUT LINE")) {
            gateData.push_back ({{0, -100}, OUTPUTGATE, std::vector<ConnectorData> {{{0, 0}, {-1, 0}, true, false}}, false, 1});
            placingGate = true;
            redrawSprites = true;
        }
        if (ImGui::Button ("OR")) {
            gateData.push_back ({{0, -100}, OR, std::vector<ConnectorData> {{{0, 0}, {-1, 0}, true, false}, {{0, 0}, {-1, 0}, true, false}, {{0, 0}, {-1, 0}, false, false}}, false, 3});
            placingGate = true;
            redrawSprites = true;
        }
        if (ImGui::Button ("8-BIT BUS INPUT")) {
            gateData.push_back ({{0, -100}, EIGHTBUS, std::vector<ConnectorData> {{{0, 0}, {-1, 0}, true, false}, {{0, 0}, {-1, 0}, true, false}, {{0, 0}, {-1, 0}, true, false}, {{0, 0}, {-1, 0}, true, false}, {{0, 0}, {-1, 0}, true, false}, {{0, 0}, {-1, 0}, true, false}, {{0, 0}, {-1, 0}, true, false}, {{0, 0}, {-1, 0}, true, false}, {{0, 0}, {-1, 0}, false, false}}, false, 9});
            placingGate = true;
            redrawSprites = true;
        }
        if (ImGui::Button ("8-BIT BUS OUTPUT")) {
            gateData.push_back ({{0, -100}, EIGHTBUSOUT, std::vector<ConnectorData> {{{0, 0}, {-1, 0}, true, false}, {{0, 0}, {-1, 0}, false, false}, {{0, 0}, {-1, 0}, false, false}, {{0, 0}, {-1, 0}, false, false}, {{0, 0}, {-1, 0}, false, false}, {{0, 0}, {-1, 0}, false, false}, {{0, 0}, {-1, 0}, false, false}, {{0, 0}, {-1, 0}, false, false}, {{0, 0}, {-1, 0}, false, false}}, false, 9});
            placingGate = true;
            redrawSprites = true;
        }
        if (ImGui::Button ("XOR")) {
            gateData.push_back ({{0, -100}, XOR, std::vector<ConnectorData> {{{0, 0}, {-1, 0}, true, false}, {{0, 0}, {-1, 0}, true, false}, {{0, 0}, {-1, 0}, false, false}}, false, 3});
            placingGate = true;
            redrawSprites = true;
        }
        ImGui::End ();

        ImGui::Begin ("Function Creation", &trueBool, ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoMove);
        ImGui::SetWindowSize (ImVec2 ((float)220.0f, (float)120.0f));
        ImGui::SetWindowPos (ImVec2 (-1, 300));
        ImGui::Text ("Function Creation");
        if (isCreatingFunction) {
            ImGui::SetWindowSize (ImVec2 ((float)300.0f, (float)120.0f));
            ImGui::InputText ("Function Name", &functionName);
            if (ImGui::Button ("Save Function")) {
                if (functionName != "") {
                    //Check if function name already exists
                    bool exists = false;
                    for (int i = 0; i < functions.size (); i++) {
                        if (functionName == functions[i].name) {
                            exists = true;
                            break;
                        }
                    }
                    if (!exists) {
                        isCreatingFunction = false;
                        std::vector<Gate> g;
                        //X = gateID, Y = gate index in function
                        std::vector<Point> gateIDs;
                        int functionID = 0;
                        //Scan inside of box for gates and save them
                        for (int i = 0; i < gateData.size (); i++) {
                            if (gateData[i].position.x >= functionPointA.x && gateData[i].position.x <= functionPointB.x) {
                                if (gateData[i].position.y <= functionPointA.y && gateData[i].position.y >= functionPointB.y) {
                                    g.push_back (gateData[i]);
                                    gateIDs.push_back ({i, functionID});
                                    functionID++;
                                }
                            }
                        }
                        //Check connections and remove those that leave the function
                        for (int i = 0; i < g.size (); i++) {
                            for (int j = 0; j < g[i].connectionPoints.size (); j++) {
                                bool found = false;
                                for (int k = 0; k < gateIDs.size (); k++) {
                                    if (g[i].connectionPoints[j].connectedGateData.x == gateIDs[k].x) {
                                        found = true;
                                        //Change id to be based off of function index
                                        //Makes it possible to keep gates connected when placing later
                                        g[i].connectionPoints[j].connectedGateData.x = gateIDs[k].y;
                                        break;
                                    }
                                }
                                if (!found) {
                                    g[i].connectionPoints[j].connectedGateData = {-1, 0};
                                }
                            }
                        }
                        functions.push_back ({functionName, g, functionPointA, {functionPointB.x - functionPointA.x, functionPointB.y - functionPointA.y}});
                    }
                }
            }
            if (ImGui::Button ("Cancel Function")) {
                isCreatingFunction = false;
            }
        } else {
            if (ImGui::Button ("Create Function")) {
                isCreatingFunction = true;
                functionPointA = {-1, -1};
                functionPointB = {-1, -1};
                functionName = "";
            }
        }
        ImGui::End ();

        ImGui::Begin ("Functions", &trueBool, ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoMove);
        ImGui::SetWindowSize (ImVec2 ((float)220.0f, (float)150.0f));
        ImGui::SetWindowPos (ImVec2 (-1, 430));
        ImGui::Text ("Saved Functions");
        for (int i = 0; i < functions.size (); i++) {
            if (ImGui::Button (functions[i].name.c_str ())) {
                functionLength = functions[i].gates.size ();
                functionID = i;
                for (int j = 0; j < functionLength; j++) {
                    gateData.push_back (functions[i].gates[j]);
                }
                //Update connection points that are being placed to only point to gates inside the function
                for (int j = 0; j < functionLength; j++) {
                    for (int k = 0; k < gateData [gateData.size () - functionLength + j].connectionPoints.size (); k++) {
                        if (gateData [gateData.size () - functionLength + j].connectionPoints[k].connectedGateData.x != -1) {
                            gateData [gateData.size () - functionLength + j].connectionPoints[k].connectedGateData.x = gateData.size () - functionLength + gateData[gateData.size () - functionLength + j].connectionPoints[k].connectedGateData.x;
                        }
                    }
                }
                placingFunction = true;
                oldGatePositions.clear ();
                redrawSprites = true;
            }
        }
        ImGui::End ();

        ImGui::Begin ("Control Deck", &trueBool, ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoMove);
        ImGui::SetWindowSize (ImVec2 ((float)210.0f, (float)60.0f));
        ImGui::SetWindowPos (ImVec2 ((screenWidth / 2) - 105.0f, 0));
        ImGui::Text ("Simulate");
        if (ImGui::Button ("Run One Cycle")) {
            //Connect to gate logic
            OrderGates(0, gateData.size() - 1);
            OneSimulation();
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