#include <glad/glad.h> 
#include <GLFW/glfw3.h>
#include <iostream>

void framebuffer_size_callback(GLFWwindow* window, int width, int height);

void processInput(GLFWwindow* window);

int main()
{
    // Инициализация и конфигурирование библиотеки GLFW

    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
   
    // Создание окна

    GLFWwindow* window = glfwCreateWindow(800, 600, "LearnOpenGL", NULL, NULL);
    if (window == NULL)
    {
        std::cout << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
        return -1;
    }
    glfwMakeContextCurrent(window);
    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

    // Инициализация библиотеки GLAD - загрузка всех указателей на OpenGL функции

    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        std::cout << "Failed to initialize GLAD" << std::endl;
        return -1;
    }

    

    
    // Цикл рендеринга

    while (!glfwWindowShouldClose(window))
    {
        // Обработка ввода
        processInput(window);

        // Выполнение команд рендеринга
        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        // Перемена буферов
        glfwSwapBuffers(window);

        // Отслеживание событий ввода/вывода (нажата/отпущена кнопка, курсор и т.д.)
        glfwPollEvents();
    }

    // Очистка ресурсов после закрытия окна

    glfwTerminate();

    return 0;
}

// При изменении размера окна
void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
    // Размер видимой области окна

    glViewport(0, 0, width, height);
}

// Обработка событий ввода/вывода
void processInput(GLFWwindow* window)
{
    if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
        glfwSetWindowShouldClose(window, true);
}