#include <GLFW/glfw3.h>

const int screenWidth = 1280;
const int screenHeight = 720;
const char windowName[] = "Processor Designer";

//Each pixel has a position and 3 values for RGB
float *pixels = new float[screenWidth * screenHeight * 3];



void draw () {
    //Make all pixels blue
    for (int i = 0; i < screenWidth; i++) {
        for (int j = 0; j < screenHeight; j++) {
            pixels[(j + screenHeight * i) * 3] = 0.0f;
            pixels[(j + screenHeight * i) * 3 + 1] = 0.0f;
            pixels[(j + screenHeight * i) * 3 + 2] = 1.0f;
        }
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
    if (!window) {
        glfwTerminate ();
        return -1;
    }

    //Set window context to current
    glfwMakeContextCurrent (window);

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