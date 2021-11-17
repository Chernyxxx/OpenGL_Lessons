#include <GLFW/glfw3.h>
#include <math.h>

void ShowTr();

int main(void)
{
    float theta = 0.0f;
    GLFWwindow* window;

    /* Initialize the library */
    if (!glfwInit())
        return -1;

    /* Create a windowed mode window and its OpenGL context */
    window = glfwCreateWindow(700, 700, "Lesson 3 - Translate, Rotate, Scale", NULL, NULL);
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
        glClearColor(0.7f, 0.7f, 1.0f, 0.0f); 
        glClear(GL_COLOR_BUFFER_BIT);
        
        glLoadIdentity();                   // Возврат матрицы в начальное положение
        glScalef(0.3, 0.3, 1);              // Масштабирование
        glTranslatef(0.0, 2, 0.0);          // Сдвиг
        
        for (int i = 0; i < 8; i++)
        {
            glPushMatrix();                 // Загружает текущую матрицу в стэк
            glRotatef(45 * i, 0, 0, 1);     // Поворот оси х на 45 каждую итер
            glTranslatef(0.2, 0.0, 0.0);    // Сдвиг
            ShowTr();
            glPopMatrix();                  // Выгружает матрицу из стэка
        }

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

void ShowTr()
{
    glBegin(GL_TRIANGLES);
        glColor3f(0.0, 0.0, 0.0); glVertex2f(0.0, 0.0);
        glColor3f(1.0, 0.0, 0.0); glVertex2f(0.4, 0.0);
        glColor3f(0.0, 1.0, 0.0); glVertex2f(0.4, 0.3);
    glEnd();
}