#include "glew/include/GL/glew.h"
#include <GLFW/glfw3.h>
#include "soil/include/soil/SOIL.h"

#include <iostream>
#include <cstdlib>
#include <cmath>
#include <vector>

struct Point {int x, y;};
struct ConnectionData {Point start, end;};
struct Texture {unsigned short width, height; float u1, v1, u2, v2;};
struct Object  {int x, y; Texture texture;};
enum gateType {   
    NOT = 0, 
    AND = 1, 
    OR = 2,
    XOR = 3
};
struct ConnectorData {Point point; bool input, connected;};
struct GateData {Point position; gateType gateType; std::vector<ConnectorData> connectionPoints;};