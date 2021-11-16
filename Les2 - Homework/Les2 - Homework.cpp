
#include <GLFW/glfw3.h>
#include <math.h>
#include <iostream>


int main(void)
{
    float theta = 0.0f;
    GLFWwindow* window;

    /* Initialize the library */
    if (!glfwInit())
        return -1;

    /* Create a windowed mode window and its OpenGL context */
    window = glfwCreateWindow(700, 700, "Lesson 2 - Homework", NULL, NULL);
    if (!window)
    {
        glfwTerminate();
        return -1;
    }

    /* Make the window's context current */
    glfwMakeContextCurrent(window);

    /* Loop until the user closes the window */
    while (!glfwWindowShouldClose(window))
    {
        /* Render here */
        glClearColor(0.0f, 0.5f, 0.7f, 0.0f); // Color of sky
        glClear(GL_COLOR_BUFFER_BIT);
      
        //Make the Sun

        float x, y;
        float n = 20;
        const float PI = 3.14159265358979;
        float alfa = 2 * PI / n;
        float r = 0.1;
        float cntrX = -0.6;
        float cntrY = 0.6;
        glBegin(GL_TRIANGLE_FAN);      
            glColor3f(1.0f, 0.8f, 0.0f);   
            glVertex2f(cntrX, cntrY);
            for (int i = 0; i <= n; i++)
            {
                x = r * cos(alfa * i);
                y = r * sin(alfa * i);
                glVertex2f(cntrX+x, cntrY+y);
            }
        glEnd();

        float x1, y1;
        float r1 = 0.3;
        float r2 = 0.2;
        float n1 = 8;
        float alfa1 = 2 * PI / n1;
        glLineWidth(5); 
        glBegin(GL_LINES);
            glColor3f(1.0f, 0.8f, 0.0f);

            glVertex2f(cntrX, cntrY);
            glVertex2f(cntrX, cntrY + r1);
            glVertex2f(cntrX, cntrY);
            glVertex2f(cntrX, cntrY - r1);
            glVertex2f(cntrX, cntrY);
            glVertex2f(cntrX+r1, cntrY);
            glVertex2f(cntrX, cntrY);
            glVertex2f(cntrX - r1, cntrY);
            glVertex2f(cntrX, cntrY);
            glVertex2f(cntrX + r2, cntrY+r2);
            glVertex2f(cntrX, cntrY);
            glVertex2f(cntrX - r2, cntrY-r2);
            glVertex2f(cntrX, cntrY);
            glVertex2f(cntrX -r2, cntrY+r2);
        glEnd();
            glEnable(GL_LINE_STIPPLE);
            glLineStipple(1, 0x00ff);
        glBegin(GL_LINES);
            glVertex2f(cntrX, cntrY);
            glVertex2f(cntrX + 2*r2, cntrY - 2*r2);
        glEnd();
            glDisable(GL_LINE_STIPPLE);

        // Make à grass

        glBegin(GL_TRIANGLE_FAN);
            glColor3f(0.0f, 0.5f, 0.0f);
            glVertex2f(-1.0, -1.0);
            glVertex2f(1.0, -1.0);
            glVertex2f(1.0, -0.2);
            glVertex2f(-1.0, -0.2);
        glEnd();

        // Make a house
        glBegin(GL_TRIANGLE_FAN);
            glColor3f(0.5f, 0.0f, 0.5f);
            glVertex2f(0.2, -0.3);
            glVertex2f(0.2, -0.7);
            glVertex2f(0.7, -0.7);
            glVertex2f(0.7, -0.3);
        glEnd();
        glBegin(GL_TRIANGLE_FAN);
            glColor3f(0.5f, 0.0f, 0.2f);
            glVertex2f(0.1, -0.3);
            glVertex2f(0.8, -0.3);
            glVertex2f(0.45, -0.1);
        glEnd();
        glBegin(GL_TRIANGLE_FAN);
            glColor3f(1.0f, 0.8f, 0.0f);
            glVertex2f(0.4, -0.4);
            glVertex2f(0.4, -0.5);
            glVertex2f(0.5, -0.5);
            glVertex2f(0.5, -0.4);
        glEnd();



        /* Swap front and back buffers */
        glfwSwapBuffers(window);

        //theta += 0.01f;
        // Sleep(1);

         /* Poll for and process events */
        glfwPollEvents();
    }

    glfwTerminate();
    return 0;
}