
// ��� � ����� GLFW+����� Begin End
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
        glClearColor(0.7f, 1.0f, 0.7f, 0.0f); // ���� ����
        glClear(GL_COLOR_BUFFER_BIT); 
        glPushMatrix();
        //glRotatef(theta, 0.0f, 0.0f, 1.0f);  
        
        // �����

        glPointSize(10);
        glBegin(GL_POINTS);
        glColor3f(0.0f, 0.0f, 0.0f);
        glVertex2f(-0.5, 0.5);
        glEnd();

        
        //�����������

        glBegin(GL_TRIANGLES);
        glColor3f(1.0f,0.0f,0.0f); glVertex2f(0.5f, 0.5f);
        glColor3f(0.0f, 1.0f, 0.0f); glVertex2f(0.9f, 0.5f);
        glColor3f(0.0f, 0.0f, 1.0f); glVertex2f(0.7f, 0.8f);
        glEnd();

        glBegin(GL_TRIANGLE_FAN);       // ��� ���������� ������� ��������� ��� 1 �����
        glColor3f(1.0f, 0.0f, 0.0f);    // ��� ���� ����� 1 � 3 ���������� ������ 
        glVertex2f(0.5f, 0.1f);
        glVertex2f(0.9f, 0.1f);
        glVertex2f(0.5f, 0.4f);
        glColor3f(0.0f, 1.0f, 0.0f);
        glVertex2f(0.1f, 0.4f);         // ����� �������
        glEnd();

        glBegin(GL_TRIANGLE_STRIP);     // ��� ���������� ������� ��������� ��� 1 �����
        glColor3f(0.0f, 0.0f, 0.6f);    // ��� ���� ����� 2 � 3 ���������� ������ 
        glVertex2f(0.0f, 0.6f);
        glVertex2f(0.3f, 0.6f);
        glVertex2f(0.0f, 0.9f);
        glColor3f(0.5f, 0.0f, 0.0f);
        glVertex2f(0.3f, 0.9f);         // ����� �������
        glEnd();

        // �����
        
        glEnable(GL_LINE_STIPPLE);  // �������� ����� ���������� ���������
        glLineStipple(1, 0x0fff);    // ��������� ����� ��������� �������
        glLineWidth(5);             // �������
       // glBegin(GL_LINES);        // ����� ����� ����� �������
        //glBegin(GL_LINE_STRIP);   // ���������� ������ ��� ����� ����� ������ � ����
        glBegin(GL_LINE_LOOP);      // ����� ��������������� ��������� ��� �����
        glColor3f(0.0f, 0.0f, 0.0f);

        glVertex2f(-0.2, -0.2); 
        glVertex2f(-0.8, -0.2); 
        glVertex2f(-0.8, -0.8);
        glVertex2f(-0.2, -0.8);
        glEnd();
        
        // ����
        
        float x, y;
        float n = 20;
        const float PI = 3.14159265358979;
        float alfa = 2*PI / n; 
        float r = 0.3;
        glBegin(GL_TRIANGLE_FAN);       // ��� ���������� ������� ��������� ��� 1 �����
        glColor3f(1.0f, 0.0f, 0.0f);    // ��� ���� ����� 1 � 3 ���������� ������ 
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