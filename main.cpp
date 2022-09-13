#include <GLFW/glfw3.h>
#include <cstdlib>
#include <cmath>

//Window doesn't scale, resolution is hardcoded
const int screenWidth = 1920;
const int screenHeight = 1080;
const char windowName[] = "Processor Designer";
const float pi = 3.141592653598793f;

//Each pixel has a position and 3 values for RGB
//Position is x + (y * screenWidth)
float* pixels = new float[screenWidth * screenHeight * 3];



void DrawSquare (int xPos, int yPos, int width, float r, float g, float b) {
    for (int i = yPos - (width / 2); i < yPos + (width / 2); i++) {
        for (int j = xPos - (width / 2); j < xPos + (width / 2); j++) {
            pixels[(j + i * screenWidth) * 3] = r;
            pixels[(j + i * screenWidth) * 3 + 1] = g;
            pixels[(j + i * screenWidth) * 3 + 2] = b;
        }
    }
}



void SetPixel (int x, int y, float r, float g, float b) {
    if ((x + y * screenWidth) * 3 < screenWidth * screenHeight * 3) {
        pixels[(x + y * screenWidth) * 3] = r;
        pixels[(x + y * screenWidth) * 3 + 1] = g;
        pixels[(x + y * screenWidth) * 3 + 2] = b;
    }
}



void DrawCircle (int xPos, int yPos, int radius, float r, float g, float b) {
    float angle, x1, y1, i, rad;
    for (int j = 0; j < radius; j++) {
        rad = j;
        for (i = 0; i < 360; i += 0.1f) {
            angle = i;
            x1 = rad * cos (angle * pi / 180.0f);
            y1 = rad * sin (angle * pi / 180.0f);
            SetPixel (xPos + x1, yPos + y1, r, g, b);
        }
    }
}



void Draw () {
    //Draw centered square and then fill in all other pixels
    //Loop scans from bottom to top, left to right (One row at a time)
    for (int i = 0; i < screenHeight; i++) {
        for (int j = 0; j < screenWidth; j++) {
            pixels[(j + i * screenWidth) * 3] = 0.0f;
            pixels[(j + i * screenWidth) * 3 + 1] = 0.0f;
            pixels[(j + i * screenWidth) * 3 + 2] = 1.0f;
        }
    }

    SetPixel (1200, 800, 1.0f, 1.0f, 1.0f);
    DrawSquare (960, 540, 50, 0.0f, 1.0f, 0.0f);
    DrawCircle (500, 500, 20, 1.0f, 0.0f, 0.0f);
}



//Creates a callback to listen for the escape key, it will work on press down or up (down in this case)
void KeyCallback (GLFWwindow* window, int key, int scancode, int action, int mods) {
    if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS) {
        glfwSetWindowShouldClose (window, GL_TRUE);
    }
}



int main (void) {
    GLFWwindow* window;

    //Setup GLFW
    if (!glfwInit ()) {
        return -1;
    }

    if (!window) {
        glfwTerminate ();
        return -1;
    }

    //Create a window and set the OpenGL context
    window = glfwCreateWindow (screenWidth, screenHeight, windowName, NULL, NULL);
    
    /*
    //Make app work on second monitor only
    int count;
    GLFWmonitor** monitors = glfwGetMonitors (&count);
    glfwSetWindowMonitor (window,  monitors[1], 0, 0, screenWidth, screenHeight, 30);
    */

    //Force window to be fullscreen on the main monitor
    glfwSetWindowMonitor (window,  glfwGetPrimaryMonitor (), 0, 0, screenWidth, screenHeight, 60);

    //Set window context to current
    glfwMakeContextCurrent (window);

    //Grabs the callback set earlier, only runs if pollEvents is running
    glfwSetKeyCallback (window, KeyCallback);

    //Loop until window is closed
    while (!glfwWindowShouldClose (window)) {
        //Render here
        glClear (GL_COLOR_BUFFER_BIT);

        Draw ();

        //Draw pixels to frame buffer (Khronos has amazing documentation)
        glDrawPixels (screenWidth, screenHeight, GL_RGB, GL_FLOAT, pixels);

        //Swap front and back buffers
        glfwSwapBuffers (window);

        //Poll and process events
        glfwPollEvents ();
    }

    //Memory cleanup
    glfwTerminate ();
    delete[] pixels;

    return 0;
}