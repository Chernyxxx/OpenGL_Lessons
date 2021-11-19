#include <GLFW/glfw3.h>
#include <math.h>
#include <iostream>

void ShowSun(float x, float y, float r);
void ShowGrass();
void ShowHouse(float attachPointX, float attachPointY, float scale);
void ShowMoon(float radius);

struct RotateCoords
{
    float x;
    float y;
    float alfa;                             // Current angle
    const float PI = 3.14159265358979;
    enum Direction                          // Rotation clockwise or counterclockwise
    {
        CCW = 1,
        CW = -1
    };

     RotateCoords(double radius, double diff, Direction CW_CCW)
    {
        static int count = 0;

        if (count > ((360 / diff) - 1))
        {
            count = 0;
        }

        alfa = diff * count;
        if (alfa > 360) { alfa = diff; }
        if (alfa < 0) { alfa = 360 - diff; }
        x = CW_CCW*radius * cos(alfa * PI / 180);
        y = radius * sin(alfa * PI / 180);
        count++;
    }

};

int main(void)
{
   
    GLFWwindow* window;

    /* Initialize the library */
    if (!glfwInit())
        return -1;

    /* Create a windowed mode window and its OpenGL context */
    window = glfwCreateWindow(700, 700, "Lesson 3 - Homework", NULL, NULL);
    if (!window)
    {
        glfwTerminate();
        return -1;
    }

    /* Make the window's context current */
    glfwMakeContextCurrent(window);

    float light=1;                          // Day and night changeover

    /* Loop until the user closes the window */
    while (!glfwWindowShouldClose(window))
    {
        
        /* Render here */
        glClearColor(0.0f, light*0.5f, light * 0.7f, 0.0f);        // Color of sky
        glClear(GL_COLOR_BUFFER_BIT);
  
        //SUN
        glPushMatrix();
        double radius = 1.6;            // Parametrs of rotating Sun
        double diff = 1;
        RotateCoords coord(radius, diff, RotateCoords::Direction::CW);
        glTranslatef(coord.x, coord.y, 0);

        float cntrX = 0.0;              // Parametrs of Sun
        float cntrY = -0.8;
        float r = 0.2;
        ShowSun(cntrX, cntrY, r);
        glPopMatrix();

        const float PI = 3.14159265358979;
        light = sin(coord.alfa * PI / 180) * 0.45 + 0.5;

        // MOON
        glPushMatrix();
        static float alfa = 0;
        alfa--;
        glTranslatef(0.0, -0.6, 0.0);
        glRotatef(alfa, 0, 0, 1);
        glTranslatef(1.2, 0.0,  0.0);
        ShowMoon(0.05);
        glPopMatrix();
        
        // GRASS
        ShowGrass();

        // HOUSES
        ShowHouse(-0.7, -0.6, 0.5);
        ShowHouse(-0.1, -0.3, 0.3);
        ShowHouse(0.5, -0.7, 0.6);

        /* Swap front and back buffers */
        glfwSwapBuffers(window);
        /* Poll for and process events */
        glfwPollEvents();
    }

    glfwTerminate();
    return 0;
}

void ShowSun(float cntrX, float cntrY, float r)
{
    const float PI = 3.14159265358979;
    float x, y;
    float n = 20;
    float alfa = 2 * PI / n;
    glBegin(GL_TRIANGLE_FAN);
    glColor3f(1.0f, 0.9f, 0.0f);
    glVertex2f(cntrX, cntrY);
    for (int i = 0; i <= n; i++)
    {
        x = r * cos(alfa * i);
        y = r * sin(alfa * i);
        glVertex2f(cntrX + x, cntrY + y);
    }
    glEnd();
    float x1, y1;
    float r1 = 0.3;
    float r2 = 0.2;
    float n1 = 8;
    float alfa1 = 2 * PI / n1;
    glLineWidth(5);
    glBegin(GL_LINES);
    glColor3f(1.0f, 0.9f, 0.0f);

    glVertex2f(cntrX, cntrY);
    glVertex2f(cntrX, cntrY + r1);
    glVertex2f(cntrX, cntrY);
    glVertex2f(cntrX, cntrY - r1);
    glVertex2f(cntrX, cntrY);
    glVertex2f(cntrX + r1, cntrY);
    glVertex2f(cntrX, cntrY);
    glVertex2f(cntrX - r1, cntrY);
    glVertex2f(cntrX, cntrY);
    glVertex2f(cntrX + r2, cntrY + r2);
    glVertex2f(cntrX, cntrY);
    glVertex2f(cntrX - r2, cntrY - r2);
    glVertex2f(cntrX, cntrY);
    glVertex2f(cntrX - r2, cntrY + r2);
    glEnd();
    glEnable(GL_LINE_STIPPLE);
    glLineStipple(1, 0x00ff);
    glBegin(GL_LINES);
    glVertex2f(cntrX, cntrY);
    glVertex2f(cntrX + 2 * r2, cntrY - 2 * r2);
    glEnd();
    glDisable(GL_LINE_STIPPLE);
}

void ShowGrass()
{
    glBegin(GL_TRIANGLE_FAN);
    glColor3f(0.0f, 0.5f, 0.0f);
    glVertex2f(-1.0, -1.0);
    glVertex2f(1.0, -1.0);
    glVertex2f(1.0, -0.2);
    glVertex2f(-1.0, -0.2);
    glEnd();
}

void ShowHouse(float attachPointX, float attachPointY, float scale)
{
    glPushMatrix();
    glTranslatef(attachPointX, attachPointY, 1);
    glScalef(scale, scale, 1);
    glBegin(GL_TRIANGLE_FAN);                               // Walls
    glColor3f(0.9f, 0.2f, 0.2f);
    glVertex2f(0.0, 0.0);
    glVertex2f(0.6, 0.0);
    glVertex2f(0.6, 0.6);
    glVertex2f(0.0, 0.6);
    glEnd();
    glBegin(GL_TRIANGLE_FAN);                               // Roof
    glColor3f(0.9f, 0.5f, 0.9f);
    glVertex2f(-0.1, 0.6);
    glVertex2f(0.7, 0.6);
    glVertex2f(0.3, 0.8);
    glEnd();
    glBegin(GL_TRIANGLE_FAN);                               // Window
    glColor3f(1.0f, 0.8f, 0.0f);
    glVertex2f(0.2, 0.2);
    glVertex2f(0.4, 0.2);
    glVertex2f(0.4, 0.4);
    glVertex2f(0.2, 0.4);
    glEnd();
    glPopMatrix();
}

void ShowMoon(float radius)
{
    float x, y;
    float n = 20;
    const float PI = 3.14159265358979;
    float alfa = 2 * PI / n;
   
    glBegin(GL_TRIANGLE_FAN);       // При добавлении вершины добавляет ещё 1 треуг
    glColor3f(1.0f, 1.0f, 1.0f);    // При этом точки 1 и 3 становятся общими 
    glVertex2f(0.0f, 0.0f);
    for (int i = 0; i <= n; i++)
    {
        x = radius * cos(alfa * i);
        y = radius * sin(alfa * i);
        glVertex2f(x, y);
    }

    glEnd();
}

