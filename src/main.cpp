#include "renderer.h"
#include "shader.h"

int main(int argc, char const *argv[])
{
    Renderer r(1024, 768);

    GLFWwindow *m_window = r.getWindow();

    float position[9] = {
        -0.5, -0.5, 0,
        0.5, -0.5, 0,
        0, 0.5, 0};

    GLuint vertexArrayID;
    glGenVertexArrays(1, &vertexArrayID);
    glBindVertexArray(vertexArrayID);

    GLuint vertexBufferID;
    glCreateBuffers(1, &vertexBufferID);
    glBindBuffer(GL_ARRAY_BUFFER, vertexBufferID);
    glBufferData(GL_ARRAY_BUFFER, 9 * sizeof(float), position, GL_STATIC_DRAW);

    glEnableVertexAttribArray(0);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), 0);

    Shader shader;
    shader.init();
    glUseProgram(shader.getProgramId());

    float red = 1;
    float increment = -0.05;

    GLint location = glGetUniformLocation(shader.getProgramId(), "u_red");

    glfwSetInputMode(m_window, GLFW_STICKY_KEYS, GL_TRUE);
    do
    {
        if(red > 1.0){
            increment = -0.05;
        }else if (red < 0.0)
        {
            increment = 0.05;
        }

        red += increment;

        glUniform1f(location, red);
        
        /* Render here */
        glClear(GL_COLOR_BUFFER_BIT);

        glDrawArrays(GL_TRIANGLES, 0, 3);

        //cout << "in" << endl;

        // Swap buffers
        glfwSwapBuffers(m_window);
        glfwPollEvents();

    } // Vérifie si on a appuyé sur la touche échap (ESC) ou si la fenêtre a été fermée
    while (glfwGetKey(m_window, GLFW_KEY_ESCAPE) != GLFW_PRESS && glfwWindowShouldClose(m_window) == 0);

    return 0;
}