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
    /*if (gateData.size () > 0) {
        std::stringstream strs;
        //Its reading from the extra connection point
        strs << gateData[0].connectionPoints[1].input;
        std::string temp_str = strs.str ();
        char* char_type = (char*) temp_str.c_str ();
        ImGui::Text (char_type);
    }*/
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
void DrawConnectionBoxes (std::vector<Gate> gateData) {
    glPointSize (10);
    glLineWidth (2.5);
    glColor3f (1, 1, 0);

    clickableAreaBoxes.clear ();
    for (int i = 0; i < gateData.size (); i++) {
        switch (gateData[i].gateType) {
            case NOT:
                //NOT input
                clickableAreaBoxes.push_back ({gateData[i].position.x + 50, gateData[i].position.y + 75});
                clickableAreaBoxes.push_back ({gateData[i].position.x + 80, gateData[i].position.y + 75});
                clickableAreaBoxes.push_back ({gateData[i].position.x + 80, gateData[i].position.y + 75});
                clickableAreaBoxes.push_back ({gateData[i].position.x + 80, gateData[i].position.y + 25});
                clickableAreaBoxes.push_back ({gateData[i].position.x + 80, gateData[i].position.y + 25});
                clickableAreaBoxes.push_back ({gateData[i].position.x + 50, gateData[i].position.y + 25});
                clickableAreaBoxes.push_back ({gateData[i].position.x + 50, gateData[i].position.y + 25});
                clickableAreaBoxes.push_back ({gateData[i].position.x + 50, gateData[i].position.y + 75});

                //NOT output
                clickableAreaBoxes.push_back ({gateData[i].position.x + 130, gateData[i].position.y + 75});
                clickableAreaBoxes.push_back ({gateData[i].position.x + 160, gateData[i].position.y + 75});
                clickableAreaBoxes.push_back ({gateData[i].position.x + 160, gateData[i].position.y + 75});
                clickableAreaBoxes.push_back ({gateData[i].position.x + 160, gateData[i].position.y + 25});
                clickableAreaBoxes.push_back ({gateData[i].position.x + 160, gateData[i].position.y + 25});
                clickableAreaBoxes.push_back ({gateData[i].position.x + 130, gateData[i].position.y + 25});
                clickableAreaBoxes.push_back ({gateData[i].position.x + 130, gateData[i].position.y + 25});
                clickableAreaBoxes.push_back ({gateData[i].position.x + 130, gateData[i].position.y + 75});
            break;
            case AND:
                //AND A input
                clickableAreaBoxes.push_back ({gateData[i].position.x + 40, gateData[i].position.y + 50});
                clickableAreaBoxes.push_back ({gateData[i].position.x + 70, gateData[i].position.y + 50});
                clickableAreaBoxes.push_back ({gateData[i].position.x + 70, gateData[i].position.y + 50});
                clickableAreaBoxes.push_back ({gateData[i].position.x + 70, gateData[i].position.y});
                clickableAreaBoxes.push_back ({gateData[i].position.x + 70, gateData[i].position.y});
                clickableAreaBoxes.push_back ({gateData[i].position.x + 40, gateData[i].position.y});
                clickableAreaBoxes.push_back ({gateData[i].position.x + 40, gateData[i].position.y});
                clickableAreaBoxes.push_back ({gateData[i].position.x + 40, gateData[i].position.y + 50});
                //AND B input
                clickableAreaBoxes.push_back ({gateData[i].position.x + 40, gateData[i].position.y + 105});
                clickableAreaBoxes.push_back ({gateData[i].position.x + 70, gateData[i].position.y + 105});
                clickableAreaBoxes.push_back ({gateData[i].position.x + 70, gateData[i].position.y + 105});
                clickableAreaBoxes.push_back ({gateData[i].position.x + 70, gateData[i].position.y + 55});
                clickableAreaBoxes.push_back ({gateData[i].position.x + 70, gateData[i].position.y + 55});
                clickableAreaBoxes.push_back ({gateData[i].position.x + 40, gateData[i].position.y + 55});
                clickableAreaBoxes.push_back ({gateData[i].position.x + 40, gateData[i].position.y + 55});
                clickableAreaBoxes.push_back ({gateData[i].position.x + 40, gateData[i].position.y + 105});
                //AND output
                clickableAreaBoxes.push_back ({gateData[i].position.x + 140, gateData[i].position.y + 75});
                clickableAreaBoxes.push_back ({gateData[i].position.x + 170, gateData[i].position.y + 75});
                clickableAreaBoxes.push_back ({gateData[i].position.x + 170, gateData[i].position.y + 75});
                clickableAreaBoxes.push_back ({gateData[i].position.x + 170, gateData[i].position.y + 25});
                clickableAreaBoxes.push_back ({gateData[i].position.x + 170, gateData[i].position.y + 25});
                clickableAreaBoxes.push_back ({gateData[i].position.x + 140, gateData[i].position.y + 25});
                clickableAreaBoxes.push_back ({gateData[i].position.x + 140, gateData[i].position.y + 25});
                clickableAreaBoxes.push_back ({gateData[i].position.x + 140, gateData[i].position.y + 75});
            break;
            case INPUTGATE:
                //INPUT output
                clickableAreaBoxes.push_back ({gateData[i].position.x + 110, gateData[i].position.y + 50});
                clickableAreaBoxes.push_back ({gateData[i].position.x + 140, gateData[i].position.y + 50});
                clickableAreaBoxes.push_back ({gateData[i].position.x + 140, gateData[i].position.y + 50});
                clickableAreaBoxes.push_back ({gateData[i].position.x + 140, gateData[i].position.y});
                clickableAreaBoxes.push_back ({gateData[i].position.x + 140, gateData[i].position.y});
                clickableAreaBoxes.push_back ({gateData[i].position.x + 110, gateData[i].position.y});
                clickableAreaBoxes.push_back ({gateData[i].position.x + 110, gateData[i].position.y});
                clickableAreaBoxes.push_back ({gateData[i].position.x + 110, gateData[i].position.y + 50});
            break;
            case OUTPUTGATE:
                //INPUT output
                clickableAreaBoxes.push_back ({gateData[i].position.x + 60, gateData[i].position.y + 50});
                clickableAreaBoxes.push_back ({gateData[i].position.x + 90, gateData[i].position.y + 50});
                clickableAreaBoxes.push_back ({gateData[i].position.x + 90, gateData[i].position.y + 50});
                clickableAreaBoxes.push_back ({gateData[i].position.x + 90, gateData[i].position.y});
                clickableAreaBoxes.push_back ({gateData[i].position.x + 90, gateData[i].position.y});
                clickableAreaBoxes.push_back ({gateData[i].position.x + 60, gateData[i].position.y});
                clickableAreaBoxes.push_back ({gateData[i].position.x + 60, gateData[i].position.y});
                clickableAreaBoxes.push_back ({gateData[i].position.x + 60, gateData[i].position.y + 50});
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