#include <GLFW/glfw3.h>
#include <Windows.h>

const int screenWidth = 1920;
const int screenHeight = 1080;
const char windowName[] = "Processor Designer";

const int squareSize = 50;

//Each pixel has a position and 3 values for RGB
float *pixels = new float[screenWidth * screenHeight * 3];



void draw () {
    //Draw centered square and then fill in all other pixels
    //Loop scans from bottom to top, left to right (One row at a time)
    for (int i = 0; i < screenHeight; i++) {
        for (int j = 0; j < screenWidth; j++) {
            if (i >= (screenHeight / 2) - squareSize && i <= (screenHeight / 2) + squareSize && j >= (screenWidth / 2) - squareSize && j <= (screenWidth / 2) + squareSize) {
                pixels[(j + i * screenWidth) * 3] = 0.0f;
                pixels[(j + i * screenWidth) * 3 + 1] = 0.0f;
                pixels[(j + i * screenWidth) * 3 + 2] = 1.0f;
            } else {
                pixels[(j + i * screenWidth) * 3] = 0.0f;
                pixels[(j + i * screenWidth) * 3 + 1] = 1.0f;
                pixels[(j + i * screenWidth) * 3 + 2] = 0.0f;
            }
        }
    }
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

    //Create a window and set the OpenGL context
    window = glfwCreateWindow (screenWidth, screenHeight, windowName, NULL, NULL);
    //Force window to be fullscreen on the main monitor
    glfwSetWindowMonitor (window, glfwGetPrimaryMonitor (), 0, 0, screenWidth, screenHeight, 60);
    if (!window) {
        glfwTerminate ();
        return -1;
    }

    //Set window context to current
    glfwMakeContextCurrent (window);

    //Grabs the callback set earlier, only runs if pollEvents is running
    glfwSetKeyCallback (window, KeyCallback);

    //Loop until window is closed
    while (!glfwWindowShouldClose (window)) {
        //Render here
        glClear (GL_COLOR_BUFFER_BIT);

        draw ();

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