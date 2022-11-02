#ifndef designerHeader
#define designerHeader
#endif

bool showDebugLine = false;
bool showGateConnectionBoxes = false;
bool turnOnInputs = false;
bool turnOnOutputs = false;
std::vector<Point> clickableAreaBoxes;
bool trueBool = true;



//Handles debug window logic and layout
void DebugWindow (std::vector<Gate>& gateData, bool& redrawSprites) {
    ImGui::Begin ("Debug Window");
    ImGui::Text ("Debug and Testing Data");
    //Show something in gateData
    /*if (gateData.size () > 2) {
        std::stringstream strs;
        strs << gateData[2].connectionPoints[0].connectedGateData.y;
        std::string temp_str = strs.str ();
        char* char_type = (char*) temp_str.c_str ();
        ImGui::Text (char_type);
    }*/
    //std::cout << "test1" << std::endl;
    if (showGateConnectionBoxes) {
        if (ImGui::Button ("Hide clickable area over gate connections")) {
            showGateConnectionBoxes = false;
        }
    } else {
        if (ImGui::Button ("Show clickable area over gate connections")) {
            showGateConnectionBoxes = true;
        }
    }
    if (turnOnInputs) {
        if (ImGui::Button ("Turn off every manual input")) {
            turnOnInputs = false;
            for (int i = 0; i < gateData.size (); i++) {
                if (gateData[i].gateType == INPUTGATEON) {
                    gateData[i].gateType = INPUTGATE;
                    gateData[i].isOn = false;
                    redrawSprites = true;
                }
            }
        }
    } else {
        if (ImGui::Button ("Turn on every manual input")) {
            turnOnInputs = true;
            for (int i = 0; i < gateData.size (); i++) {
                if (gateData[i].gateType == INPUTGATE) {
                    gateData[i].gateType = INPUTGATEON;
                    gateData[i].isOn = true;
                    redrawSprites = true;
                }
            }
        }
    }
    if (turnOnOutputs) {
        if (ImGui::Button ("Turn off every manual output")) {
            turnOnOutputs = false;
            for (int i = 0; i < gateData.size (); i++) {
                if (gateData[i].gateType == OUTPUTGATEON) {
                    gateData[i].gateType = OUTPUTGATE;
                    redrawSprites = true;
                }
            }
        }
    } else {
        if (ImGui::Button ("Turn on every manual output")) {
            turnOnOutputs = true;
            for (int i = 0; i < gateData.size (); i++) {
                if (gateData[i].gateType == OUTPUTGATE) {
                    gateData[i].gateType = OUTPUTGATEON;
                    redrawSprites = true;
                }
            }
        }
    }
    ImGui::End ();
}



//Sets all outputs to off
void ResetOutputs (std::vector<Gate>& gateData, bool& redrawSprites) {
    for (int i = 0; i < gateData.size (); i++) {
        if (gateData[i].gateType == OUTPUTGATEON) {
            gateData[i].gateType = OUTPUTGATE;
            redrawSprites = true;
        }
    }
    turnOnOutputs = false;
}



//Draw clickable areas
void DrawConnectionBoxes (std::vector<Gate> gateData, float scaleFactor) {
    glPointSize (10);
    glLineWidth (2.5);
    glColor3f (1, 1, 0);

    clickableAreaBoxes.clear ();
    for (int i = 0; i < gateData.size (); i++) {
        switch (gateData[i].gateType) {
            case NOT:
                //NOT input
                clickableAreaBoxes.push_back ({gateData[i].position.x + 50 * scaleFactor, gateData[i].position.y + 75 * scaleFactor});
                clickableAreaBoxes.push_back ({gateData[i].position.x + 80 * scaleFactor, gateData[i].position.y + 75 * scaleFactor});
                clickableAreaBoxes.push_back ({gateData[i].position.x + 80 * scaleFactor, gateData[i].position.y + 75 * scaleFactor});
                clickableAreaBoxes.push_back ({gateData[i].position.x + 80 * scaleFactor, gateData[i].position.y + 25 * scaleFactor});
                clickableAreaBoxes.push_back ({gateData[i].position.x + 80 * scaleFactor, gateData[i].position.y + 25 * scaleFactor});
                clickableAreaBoxes.push_back ({gateData[i].position.x + 50 * scaleFactor, gateData[i].position.y + 25 * scaleFactor});
                clickableAreaBoxes.push_back ({gateData[i].position.x + 50 * scaleFactor, gateData[i].position.y + 25 * scaleFactor});
                clickableAreaBoxes.push_back ({gateData[i].position.x + 50 * scaleFactor, gateData[i].position.y + 75 * scaleFactor});

                //NOT output
                clickableAreaBoxes.push_back ({gateData[i].position.x + 130 * scaleFactor, gateData[i].position.y + 75 * scaleFactor});
                clickableAreaBoxes.push_back ({gateData[i].position.x + 160 * scaleFactor, gateData[i].position.y + 75 * scaleFactor});
                clickableAreaBoxes.push_back ({gateData[i].position.x + 160 * scaleFactor, gateData[i].position.y + 75 * scaleFactor});
                clickableAreaBoxes.push_back ({gateData[i].position.x + 160 * scaleFactor, gateData[i].position.y + 25 * scaleFactor});
                clickableAreaBoxes.push_back ({gateData[i].position.x + 160 * scaleFactor, gateData[i].position.y + 25 * scaleFactor});
                clickableAreaBoxes.push_back ({gateData[i].position.x + 130 * scaleFactor, gateData[i].position.y + 25 * scaleFactor});
                clickableAreaBoxes.push_back ({gateData[i].position.x + 130 * scaleFactor, gateData[i].position.y + 25 * scaleFactor});
                clickableAreaBoxes.push_back ({gateData[i].position.x + 130 * scaleFactor, gateData[i].position.y + 75 * scaleFactor});
            break;
            case AND:
                //AND A input
                clickableAreaBoxes.push_back ({gateData[i].position.x + 40 * scaleFactor, gateData[i].position.y + 50 * scaleFactor});
                clickableAreaBoxes.push_back ({gateData[i].position.x + 70 * scaleFactor, gateData[i].position.y + 50 * scaleFactor});
                clickableAreaBoxes.push_back ({gateData[i].position.x + 70 * scaleFactor, gateData[i].position.y + 50 * scaleFactor});
                clickableAreaBoxes.push_back ({gateData[i].position.x + 70 * scaleFactor, gateData[i].position.y});
                clickableAreaBoxes.push_back ({gateData[i].position.x + 70 * scaleFactor, gateData[i].position.y});
                clickableAreaBoxes.push_back ({gateData[i].position.x + 40 * scaleFactor, gateData[i].position.y});
                clickableAreaBoxes.push_back ({gateData[i].position.x + 40 * scaleFactor, gateData[i].position.y});
                clickableAreaBoxes.push_back ({gateData[i].position.x + 40 * scaleFactor, gateData[i].position.y + 50 * scaleFactor});
                //AND B input
                clickableAreaBoxes.push_back ({gateData[i].position.x + 40 * scaleFactor, gateData[i].position.y + 105 * scaleFactor});
                clickableAreaBoxes.push_back ({gateData[i].position.x + 70 * scaleFactor, gateData[i].position.y + 105 * scaleFactor});
                clickableAreaBoxes.push_back ({gateData[i].position.x + 70 * scaleFactor, gateData[i].position.y + 105 * scaleFactor});
                clickableAreaBoxes.push_back ({gateData[i].position.x + 70 * scaleFactor, gateData[i].position.y + 55 * scaleFactor});
                clickableAreaBoxes.push_back ({gateData[i].position.x + 70 * scaleFactor, gateData[i].position.y + 55 * scaleFactor});
                clickableAreaBoxes.push_back ({gateData[i].position.x + 40 * scaleFactor, gateData[i].position.y + 55 * scaleFactor});
                clickableAreaBoxes.push_back ({gateData[i].position.x + 40 * scaleFactor, gateData[i].position.y + 55 * scaleFactor});
                clickableAreaBoxes.push_back ({gateData[i].position.x + 40 * scaleFactor, gateData[i].position.y + 105 * scaleFactor});
                //AND output
                clickableAreaBoxes.push_back ({gateData[i].position.x + 140 * scaleFactor, gateData[i].position.y + 75 * scaleFactor});
                clickableAreaBoxes.push_back ({gateData[i].position.x + 170 * scaleFactor, gateData[i].position.y + 75 * scaleFactor});
                clickableAreaBoxes.push_back ({gateData[i].position.x + 170 * scaleFactor, gateData[i].position.y + 75 * scaleFactor});
                clickableAreaBoxes.push_back ({gateData[i].position.x + 170 * scaleFactor, gateData[i].position.y + 25 * scaleFactor});
                clickableAreaBoxes.push_back ({gateData[i].position.x + 170 * scaleFactor, gateData[i].position.y + 25 * scaleFactor});
                clickableAreaBoxes.push_back ({gateData[i].position.x + 140 * scaleFactor, gateData[i].position.y + 25 * scaleFactor});
                clickableAreaBoxes.push_back ({gateData[i].position.x + 140 * scaleFactor, gateData[i].position.y + 25 * scaleFactor});
                clickableAreaBoxes.push_back ({gateData[i].position.x + 140 * scaleFactor, gateData[i].position.y + 75 * scaleFactor});
            break;
            case INPUTGATE:
                //INPUT output
                clickableAreaBoxes.push_back ({gateData[i].position.x + 110 * scaleFactor, gateData[i].position.y + 50 * scaleFactor});
                clickableAreaBoxes.push_back ({gateData[i].position.x + 140 * scaleFactor, gateData[i].position.y + 50 * scaleFactor});
                clickableAreaBoxes.push_back ({gateData[i].position.x + 140 * scaleFactor, gateData[i].position.y + 50 * scaleFactor});
                clickableAreaBoxes.push_back ({gateData[i].position.x + 140 * scaleFactor, gateData[i].position.y});
                clickableAreaBoxes.push_back ({gateData[i].position.x + 140 * scaleFactor, gateData[i].position.y});
                clickableAreaBoxes.push_back ({gateData[i].position.x + 110 * scaleFactor, gateData[i].position.y});
                clickableAreaBoxes.push_back ({gateData[i].position.x + 110 * scaleFactor, gateData[i].position.y});
                clickableAreaBoxes.push_back ({gateData[i].position.x + 110 * scaleFactor, gateData[i].position.y + 50 * scaleFactor});
            break;
            case OUTPUTGATE:
                //INPUT output
                clickableAreaBoxes.push_back ({gateData[i].position.x + 60 * scaleFactor, gateData[i].position.y + 50 * scaleFactor});
                clickableAreaBoxes.push_back ({gateData[i].position.x + 90 * scaleFactor, gateData[i].position.y + 50 * scaleFactor});
                clickableAreaBoxes.push_back ({gateData[i].position.x + 90 * scaleFactor, gateData[i].position.y + 50 * scaleFactor});
                clickableAreaBoxes.push_back ({gateData[i].position.x + 90 * scaleFactor, gateData[i].position.y});
                clickableAreaBoxes.push_back ({gateData[i].position.x + 90 * scaleFactor, gateData[i].position.y});
                clickableAreaBoxes.push_back ({gateData[i].position.x + 60 * scaleFactor, gateData[i].position.y});
                clickableAreaBoxes.push_back ({gateData[i].position.x + 60 * scaleFactor, gateData[i].position.y});
                clickableAreaBoxes.push_back ({gateData[i].position.x + 60 * scaleFactor, gateData[i].position.y + 50 * scaleFactor});
            break;
            case OR:
                //OR A input
                clickableAreaBoxes.push_back ({gateData[i].position.x + 40 * scaleFactor, gateData[i].position.y + 50 * scaleFactor});
                clickableAreaBoxes.push_back ({gateData[i].position.x + 70 * scaleFactor, gateData[i].position.y + 50 * scaleFactor});
                clickableAreaBoxes.push_back ({gateData[i].position.x + 70 * scaleFactor, gateData[i].position.y + 50 * scaleFactor});
                clickableAreaBoxes.push_back ({gateData[i].position.x + 70 * scaleFactor, gateData[i].position.y});
                clickableAreaBoxes.push_back ({gateData[i].position.x + 70 * scaleFactor, gateData[i].position.y});
                clickableAreaBoxes.push_back ({gateData[i].position.x + 40 * scaleFactor, gateData[i].position.y});
                clickableAreaBoxes.push_back ({gateData[i].position.x + 40 * scaleFactor, gateData[i].position.y});
                clickableAreaBoxes.push_back ({gateData[i].position.x + 40 * scaleFactor, gateData[i].position.y + 50 * scaleFactor});
                //OR B input
                clickableAreaBoxes.push_back ({gateData[i].position.x + 40 * scaleFactor, gateData[i].position.y + 105 * scaleFactor});
                clickableAreaBoxes.push_back ({gateData[i].position.x + 70 * scaleFactor, gateData[i].position.y + 105 * scaleFactor});
                clickableAreaBoxes.push_back ({gateData[i].position.x + 70 * scaleFactor, gateData[i].position.y + 105 * scaleFactor});
                clickableAreaBoxes.push_back ({gateData[i].position.x + 70 * scaleFactor, gateData[i].position.y + 55 * scaleFactor});
                clickableAreaBoxes.push_back ({gateData[i].position.x + 70 * scaleFactor, gateData[i].position.y + 55 * scaleFactor});
                clickableAreaBoxes.push_back ({gateData[i].position.x + 40 * scaleFactor, gateData[i].position.y + 55 * scaleFactor});
                clickableAreaBoxes.push_back ({gateData[i].position.x + 40 * scaleFactor, gateData[i].position.y + 55 * scaleFactor});
                clickableAreaBoxes.push_back ({gateData[i].position.x + 40 * scaleFactor, gateData[i].position.y + 105 * scaleFactor});
                //OR output
                clickableAreaBoxes.push_back ({gateData[i].position.x + 140 * scaleFactor, gateData[i].position.y + 75 * scaleFactor});
                clickableAreaBoxes.push_back ({gateData[i].position.x + 170 * scaleFactor, gateData[i].position.y + 75 * scaleFactor});
                clickableAreaBoxes.push_back ({gateData[i].position.x + 170 * scaleFactor, gateData[i].position.y + 75 * scaleFactor});
                clickableAreaBoxes.push_back ({gateData[i].position.x + 170 * scaleFactor, gateData[i].position.y + 25 * scaleFactor});
                clickableAreaBoxes.push_back ({gateData[i].position.x + 170 * scaleFactor, gateData[i].position.y + 25 * scaleFactor});
                clickableAreaBoxes.push_back ({gateData[i].position.x + 140 * scaleFactor, gateData[i].position.y + 25 * scaleFactor});
                clickableAreaBoxes.push_back ({gateData[i].position.x + 140 * scaleFactor, gateData[i].position.y + 25 * scaleFactor});
                clickableAreaBoxes.push_back ({gateData[i].position.x + 140 * scaleFactor, gateData[i].position.y + 75 * scaleFactor});
            break;
        }
    }

    int drawingIndex = 0;
    for (int i = 0; i < clickableAreaBoxes.size () / 2; i++) {
        glBegin (GL_LINES);
        glVertex3f (clickableAreaBoxes[drawingIndex].x, clickableAreaBoxes[drawingIndex].y, 0);
        glVertex3f (clickableAreaBoxes[drawingIndex + 1].x, clickableAreaBoxes[drawingIndex + 1].y, 0);
        glEnd ();
        drawingIndex += 2;
    }
}