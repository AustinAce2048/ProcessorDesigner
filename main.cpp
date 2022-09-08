#include <GLFW/glfw3.h>

int main (void) {
    GLFWwindow* window;

    //Setup GLFW
    if (!glfwInit ()) {
        return -1;
    }

    //Create a window and set OpenGL context
    window = glfwCreateWindow (1280, 720, "Processor Designer", NULL, NULL);
    if (!window) {
        glfwTerminate ();
        return -1;
    }

    //Set window context to current
    glfwMakeContextCurrent (window);

    //Loop until window is closed
    while (!glfwWindowShouldClose (window)) {
        //Render
        glClear (GL_COLOR_BUFFER_BIT);

        //Swap front and back buffers
        glfwSwapBuffers (window);

        //Poll and process events
        glfwPollEvents ();
    }

    glfwTerminate ();
    return 0;
}