#ifndef designerHeader
#define designerHeader
#endif



void KeyboardCallback (GLFWwindow* window, int key, int action, bool isOverGate, bool isDraggingGate, std::vector<Gate>& gateData, int gateDragIndex, bool& redrawSprites, bool& isResetPanning, bool& isPanningScreen) {
    //Closing the program
    if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS) {
        glfwSetWindowShouldClose (window, GL_TRUE);
    }

    //Deleting a gate
    if ((key == GLFW_KEY_DELETE || key == GLFW_KEY_BACKSPACE) && action == GLFW_PRESS && isOverGate && !isDraggingGate) {
        //Remove connection for gates that connect to it
        for (int i = 0; i < gateData[gateDragIndex].connectionPoints.size (); i++) {
            //Get gate connected to this gate and remove the connection, either delete it or clear it
            if (gateData[gateDragIndex].connectionPoints[i].connectedGateData.x > -1) {
                if (gateData[gateDragIndex].connectionPoints[i].connectedGateData.y > gateData[gateData[gateDragIndex].connectionPoints[i].connectedGateData.x].initialConnections - 1) {
                    gateData[gateData[gateDragIndex].connectionPoints[i].connectedGateData.x].connectionPoints.erase (gateData[gateData[gateDragIndex].connectionPoints[i].connectedGateData.x].connectionPoints.begin () + gateData[gateDragIndex].connectionPoints[i].connectedGateData.y);

                    if (gateData[gateDragIndex].connectionPoints[i].connectedGateData.y < gateData[gateData[gateDragIndex].connectionPoints[i].connectedGateData.x].connectionPoints.size()) {
                        int connectorIndex = gateData[gateDragIndex].connectionPoints[i].connectedGateData.y;
                        for (int g = 0; g < gateData.size (); g++) {
                            for (int j = 0; j < gateData[g].connectionPoints.size (); j++) {
                                if (gateData[g].connectionPoints[j].connectedGateData.x == -1) {
                                    continue;
                                }
                                if (gateData[g].connectionPoints[j].connectedGateData.x == gateData[gateDragIndex].connectionPoints[i].connectedGateData.x && gateData[g].connectionPoints[j].connectedGateData.y > connectorIndex) {
                                    gateData[g].connectionPoints[j].connectedGateData.y--;
                                }
                            }
                        }
                    }
                } else {
                    //NOTICE deleting specifically the input gate when connected to an AND gate, it doesn't matter what's happening to it
                    gateData[gateData[gateDragIndex].connectionPoints[i].connectedGateData.x].connectionPoints[gateData[gateDragIndex].connectionPoints[i].connectedGateData.y].connectedGateData = {-1, 0};
                    gateData[gateData[gateDragIndex].connectionPoints[i].connectedGateData.x].connectionPoints[gateData[gateDragIndex].connectionPoints[i].connectedGateData.y].connected = false;
                }
            }
        }
        gateData.erase (gateData.begin () + gateDragIndex);
        redrawSprites = true;
        if (gateData.size () == gateDragIndex) {
            return;
        }
        for (int i = 0; i < gateData.size (); i++) {
            for (int j = 0; j < gateData[i].connectionPoints.size (); j++) {
                if (gateData[i].connectionPoints[j].connectedGateData.x == -1) {
                    continue;
                }
                if (gateData[i].connectionPoints[j].connectedGateData.x > gateDragIndex) {
                    gateData[i].connectionPoints[j].connectedGateData.x--;
                }
            }
        }
    }

    //Recenter the screen
    if (key == GLFW_KEY_C && action == GLFW_PRESS) {
        isResetPanning = true;
        isPanningScreen = true;
    }
}



void MouseCallback (double x, double y, int& rawMouseX, int& rawMouseY, int& mouseX, int& mouseY, bool& isOverGateConnection, bool& isOverInputConnection, bool& isOverManualInput, int& gateDataHoverIndex, int& gateConnectionIndex, bool& isOverGate, int screenHeight, std::vector<Gate>& gateData, bool& placingGate, int& gateDragIndex, float scaleFactor) {
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
                if ((rawMouseX <= gateData[i].position.x + 160 * scaleFactor && rawMouseX >= gateData[i].position.x + 130 * scaleFactor) && (rawMouseY >= gateData[i].position.y + 25 * scaleFactor && rawMouseY <= gateData[i].position.y + 75 * scaleFactor)) {
                    //Mouse over output
                    isOverGateConnection = true;
                    gateDataHoverIndex = i;
                    gateConnectionIndex = 1;
                }
                if ((rawMouseX <= gateData[i].position.x + 80 * scaleFactor && rawMouseX >= gateData[i].position.x + 50 * scaleFactor) && (rawMouseY >= gateData[i].position.y + 25 * scaleFactor && rawMouseY <= gateData[i].position.y + 75 * scaleFactor)) {
                    //Mouse over input
                    isOverGateConnection = true;
                    isOverInputConnection = true;
                    gateDataHoverIndex = i;
                    gateConnectionIndex = 0;
                }
            break;
            case AND: case OR:
                if ((rawMouseX <= gateData[i].position.x + 70 * scaleFactor && rawMouseX >= gateData[i].position.x + 40 * scaleFactor) && (rawMouseY >= gateData[i].position.y && rawMouseY <= gateData[i].position.y + 50 * scaleFactor)) {
                    //Mouse over input A
                    isOverGateConnection = true;
                    isOverInputConnection = true;
                    gateDataHoverIndex = i;
                    gateConnectionIndex = 0;
                }
                if ((rawMouseX <= gateData[i].position.x + 70 * scaleFactor && rawMouseX >= gateData[i].position.x + 40 * scaleFactor) && (rawMouseY >= gateData[i].position.y + 55 * scaleFactor && rawMouseY <= gateData[i].position.y + 105 * scaleFactor)) {
                    //Mouse over input B
                    isOverGateConnection = true;
                    isOverInputConnection = true;
                    gateDataHoverIndex = i;
                    gateConnectionIndex = 1;
                }
                if ((rawMouseX <= gateData[i].position.x + 170 * scaleFactor && rawMouseX >= gateData[i].position.x + 140 * scaleFactor) && (rawMouseY >= gateData[i].position.y + 25 * scaleFactor && rawMouseY <= gateData[i].position.y + 75 * scaleFactor)) {
                    //Mouse over output
                    isOverGateConnection = true;
                    gateDataHoverIndex = i;
                    gateConnectionIndex = 2;
                }
            break;
            case INPUTGATE: case INPUTGATEON:
                if ((rawMouseX <= gateData[i].position.x + 140 * scaleFactor && rawMouseX >= gateData[i].position.x + 110 * scaleFactor) && (rawMouseY >= gateData[i].position.y && rawMouseY <= gateData[i].position.y + 50 * scaleFactor)) {
                    //Mouse over output
                    isOverGateConnection = true;
                    gateDataHoverIndex = i;
                    gateConnectionIndex = 0;
                }
                if ((rawMouseX <= gateData[i].position.x + 110 * scaleFactor && rawMouseX >= gateData[i].position.x + 75 * scaleFactor) && (rawMouseY >= gateData[i].position.y && rawMouseY <= gateData[i].position.y + 50 * scaleFactor)) {
                    //Mouse over gate
                    isOverManualInput = true;
                    gateDataHoverIndex = i;
                }
            break;
            case OUTPUTGATE: case OUTPUTGATEON:
                if ((rawMouseX <= gateData[i].position.x + 90 * scaleFactor && rawMouseX >= gateData[i].position.x + 60 * scaleFactor) && (rawMouseY >= gateData[i].position.y && rawMouseY <= gateData[i].position.y + 50 * scaleFactor)) {
                    //Mouse over output
                    isOverGateConnection = true;
                    isOverInputConnection = true;
                    gateDataHoverIndex = i;
                    gateConnectionIndex = 0;
                }
            break;
        }

        //Check for gate hover
        if ((rawMouseX <= gateData[i].position.x + 125 * scaleFactor && rawMouseX >= gateData[i].position.x + 75 * scaleFactor) && (rawMouseY >= gateData[i].position.y - 10 * scaleFactor && rawMouseY <= gateData[i].position.y + 60 * scaleFactor) && !placingGate) {
            isOverGate = true;
            gateDragIndex = i;
        }
    }
}



void MouseButtonsCallback (int button, int action, bool& placingGate, bool& isConnectingGates, bool& isOverGateConnection, bool& isOverInputConnection, Point& connectionPoint, int& gateDataConnectionStartIndex, int& gateDataHoverIndex, int& gateConnectionIndex, bool isOverManualInput, bool& isDraggingGate, bool& redrawSprites, bool& isOverGate, int& oldGateDragIndex, int& gateDragIndex, bool& isPanningScreen, Point& mousePositionOnStartDrag, int& updateConnectionPointIndex, std::vector<Gate>& gateData, int mouseX, int mouseY) {
    bool registerOneClick = false;

    //Place the gate
    if (button == GLFW_MOUSE_BUTTON_LEFT && action == GLFW_PRESS && placingGate && !registerOneClick) {
        placingGate = false;
        //Set connection location data
        updateConnectionPointIndex = gateData.size () - 1;
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
            if (gateData[connectionPoint.x].connectionPoints[gateData[connectionPoint.x].initialConnections - 1].connectedGateData.x == -1) {
                gateData[connectionPoint.x].connectionPoints[connectionPoint.y] = {gateData[connectionPoint.x].connectionPoints[connectionPoint.y].point, {gateDataHoverIndex, gateConnectionIndex}, false, true};
            } else {
                gateData[connectionPoint.x].connectionPoints.push_back ({gateData[connectionPoint.x].connectionPoints[connectionPoint.y].point, {gateDataHoverIndex, gateConnectionIndex}, false, true});
            }
            gateData[gateDataHoverIndex].connectionPoints[gateConnectionIndex] = {gateData[gateDataHoverIndex].connectionPoints[gateConnectionIndex].point, {connectionPoint.x, gateData[connectionPoint.x].connectionPoints.size() - 1}, true, true};
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
            gateData[gateDataHoverIndex].isOn = true;
            redrawSprites = true;
        } else if (gateData[gateDataHoverIndex].gateType == INPUTGATEON) {
            gateData[gateDataHoverIndex].gateType = INPUTGATE;
            gateData[gateDataHoverIndex].isOn = false;
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

    //Pick up a gate connection
    if (button == GLFW_MOUSE_BUTTON_LEFT && action == GLFW_PRESS && !registerOneClick && !isDraggingGate && !isConnectingGates && !placingGate && isOverGateConnection && isOverInputConnection) {
        //See if there is a connection
        if (gateData[gateDataHoverIndex].connectionPoints[gateConnectionIndex].connectedGateData.x == -1) {
            return;
        }
        isConnectingGates = true;
        //Output gate id
        int outId = gateData[gateDataHoverIndex].connectionPoints[gateConnectionIndex].connectedGateData.x;
        int outConnectionIndex = gateData[gateDataHoverIndex].connectionPoints[gateConnectionIndex].connectedGateData.y;
        connectionPoint = {outId, outConnectionIndex};
        //Delete gate connection or reset it if its not extra (output gate)
        //Loop through every output connection and see which one is the one being removed
        for (int i = 0; i < gateData[outId].connectionPoints.size (); i++) {
            if (gateData[outId].connectionPoints[i].connectedGateData.x == gateDataHoverIndex && gateData[outId].connectionPoints[i].connectedGateData.y == gateConnectionIndex) {
                if (outConnectionIndex > gateData[outId].connectionPoints.size ()) {
                    gateData[outId].connectionPoints.erase (gateData[outId].connectionPoints.begin () + i);
                } else {
                    gateData[outId].connectionPoints[i] = {gateData[outId].connectionPoints[i].point, {-1, 0}, false, false};
                }
            }
        }
        //Delete input gate data or reset it
        if (gateData[gateDataHoverIndex].connectionPoints.size () > gateData[gateDataHoverIndex].initialConnections) {
            gateData[gateDataHoverIndex].connectionPoints.erase (gateData[gateDataHoverIndex].connectionPoints.begin () + gateConnectionIndex);
        } else {
            gateData[gateDataHoverIndex].connectionPoints[gateConnectionIndex] = {gateData[gateDataHoverIndex].connectionPoints[gateConnectionIndex].point, {-1, 0}, true, false};
        }
        //Store gate index to prevent connecting to yourself
        gateDataConnectionStartIndex = gateDataHoverIndex;
        registerOneClick = true;
    }

    //Starting to pan screen
    if (button == GLFW_MOUSE_BUTTON_LEFT && action == GLFW_PRESS && !isOverGate && !registerOneClick && !isPanningScreen && gateData.size () > 0) {
        isPanningScreen = true;
        mousePositionOnStartDrag = {mouseX, mouseY};
    }

    //Stop panning screen
    if (button == GLFW_MOUSE_BUTTON_LEFT && action == GLFW_RELEASE && !registerOneClick && isPanningScreen) {
        isPanningScreen = false;
    }
}

void ScrollingCallback (double yOffset, bool& redrawSprites, float& scaleFactor) {
    scaleFactor -= yOffset * 3;
    redrawSprites = true;

    //Set limits to zooming
    if (scaleFactor < 0.4f) {
        scaleFactor = 0.4f;
    } else if (scaleFactor > 2.0f) {
        scaleFactor = 2.0f;
    }
}