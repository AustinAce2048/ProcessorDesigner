#include "glew/include/GL/glew.h"
#include <GLFW/glfw3.h>
#include "soil/include/soil/SOIL.h"

#include <iostream>
#include <cstdlib>
#include <cmath>
#include <vector>

//Used for debugging
#include <sstream>
#include <string.h>

struct Point {int x, y;};
//Actual connection position, x index of connected gate | y is connectionIndex of gate, input, connected
struct ConnectorData {Point point, connectedGateData; bool input, connected;};
enum gateType {   
    NOT = 0, 
    AND = 1, 
    INPUTGATE = 2,
    INPUTGATEON = 3,
    OUTPUTGATE = 4,
    OUTPUTGATEON = 5,
    OR = 6
};
//ConnectorData is ordered inputs first, then ordered outputs
struct Gate {Point position; gateType gateType; std::vector<ConnectorData> connectionPoints; bool isOn; int initialConnections;};
struct Texture {unsigned short width, height; float u1, v1, u2, v2;};
struct Object  {int x, y; Texture texture;};