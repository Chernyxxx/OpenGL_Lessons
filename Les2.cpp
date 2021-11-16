
// Код с сайта GLFW+канал Begin End
// 
//#include <Windows.h>
#include <GLFW/glfw3.h>
#include <math.h>
#include <iostream>
//#include <gl/GL.h>

int main(void)
{
    float theta=0.0f;
    GLFWwindow* window;   

    /* Initialize the library */
    if (!glfwInit())
        return -1;

    /* Create a windowed mode window and its OpenGL context */
    window = glfwCreateWindow(700, 700, "Lesson 2", NULL, NULL);
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
        glClearColor(0.7f, 1.0f, 0.7f, 0.0f); // Цвет фона
        glClear(GL_COLOR_BUFFER_BIT); 
        glPushMatrix();
        //glRotatef(theta, 0.0f, 0.0f, 1.0f);  
        
        // ТОЧКА

        glPointSize(10);
        glBegin(GL_POINTS);
        glColor3f(0.0f, 0.0f, 0.0f);
        glVertex2f(-0.5, 0.5);
        glEnd();

        
        //ТРЕУГОЛЬНИК

        glBegin(GL_TRIANGLES);
        glColor3f(1.0f,0.0f,0.0f); glVertex2f(0.5f, 0.5f);
        glColor3f(0.0f, 1.0f, 0.0f); glVertex2f(0.9f, 0.5f);
        glColor3f(0.0f, 0.0f, 1.0f); glVertex2f(0.7f, 0.8f);
        glEnd();

        glBegin(GL_TRIANGLE_FAN);       // При добавлении вершины добавляет ещё 1 треуг
        glColor3f(1.0f, 0.0f, 0.0f);    // При этом точки 1 и 3 становятся общими 
        glVertex2f(0.5f, 0.1f);
        glVertex2f(0.9f, 0.1f);
        glVertex2f(0.5f, 0.4f);
        glColor3f(0.0f, 1.0f, 0.0f);
        glVertex2f(0.1f, 0.4f);         // Новая вершина
        glEnd();

        glBegin(GL_TRIANGLE_STRIP);     // При добавлении вершины добавляет ещё 1 треуг
        glColor3f(0.0f, 0.0f, 0.6f);    // При этом точки 2 и 3 становятся общими 
        glVertex2f(0.0f, 0.6f);
        glVertex2f(0.3f, 0.6f);
        glVertex2f(0.0f, 0.9f);
        glColor3f(0.5f, 0.0f, 0.0f);
        glVertex2f(0.3f, 0.9f);         // Новая вершина
        glEnd();

        // ЛИНИИ
        
        glEnable(GL_LINE_STIPPLE);  // Включает режим пунктирной отрисовки
        glLineStipple(1, 0x0fff);    // Процедура задаёт параметры штрихов
        glLineWidth(5);             // Толщина
       // glBegin(GL_LINES);        // Линия между двумя точками
        //glBegin(GL_LINE_STRIP);   // Последоват соедин все точки кроме первой и посл
        glBegin(GL_LINE_LOOP);      // Линия последовательно соединяет все точки
        glColor3f(0.0f, 0.0f, 0.0f);

        glVertex2f(-0.2, -0.2); 
        glVertex2f(-0.8, -0.2); 
        glVertex2f(-0.8, -0.8);
        glVertex2f(-0.2, -0.8);
        glEnd();
        
        // КРУГ
        
        float x, y;
        float n = 20;
        const float PI = 3.14159265358979;
        float alfa = 2*PI / n; 
        float r = 0.3;
        glBegin(GL_TRIANGLE_FAN);       // При добавлении вершины добавляет ещё 1 треуг
        glColor3f(1.0f, 0.0f, 0.0f);    // При этом точки 1 и 3 становятся общими 
        glVertex2f(0.0f, 0.0f);
        
        
        for (int i = 0; i <= n; i++)
        {
             x = r*cos(alfa*i);
             y = r*sin(alfa*i);
            glVertex2f(x, y);
           
        }
      
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