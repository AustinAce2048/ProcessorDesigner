#ifndef designerHeader
#define designerHeader
#endif

bool showDebugLine = false;
bool showGateConnectionBoxes = false;
std::vector<Point> clickableAreaBoxes;



void DrawConnectionBoxes (std::vector<GateData> gateData) {
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