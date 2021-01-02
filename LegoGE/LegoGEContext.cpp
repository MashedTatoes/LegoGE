#include "LegoGEContext.h"
namespace LGE
{
    LGE_RESULT LegoGEContext::Init()
    {
        GLFWwindow* window;
        m_error = LGE_OK;
        /* Initialize the library */
        if (glfwInit() == GLFW_FALSE)
            //m_error = LGE_INIT_FAILED;
            return LGE_INIT_FAILED;

        

        /* Create a windowed mode window and its OpenGL context */
        window = glfwCreateWindow(640, 480, "Lego Graphics Engine!", NULL, NULL);
        if (!window)
        {
            glfwTerminate();
            m_error = LGE_INIT_FAILED;
            return m_error;
        }

        glfwMakeContextCurrent(window);
        glewInit();
        glEnable(GL_DEBUG_OUTPUT);

        glDebugMessageCallback(OpenGLDebugMessage, nullptr);

        quad = new Quad2D();
        
        unsigned int* indices = quad->GetIndices();
        
        glGenVertexArrays(1, &vao);
        glBindVertexArray(vao);

        quad->GenerateVertexBuffer();

        glEnableVertexAttribArray(0);
        glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(float) * LGE_2DVERTEX_SIZE, 0);
        quad->GenerateIndexBuffer();

        glBindBuffer(GL_ARRAY_BUFFER, 0);
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
        glUseProgram(0);

        
        glBindVertexArray(0);

        shaderProgram = new ShaderProgram("res/shader/basic.shader");

        LGE_RESULT result = shaderProgram->Compile();
        
        
        std::cout << "OpenGL Version: " << glGetString(GL_VERSION) << std::endl;
        this->glWindow = window;
        this->m_isRunning = true;
        return LGE_OK;
    }

    LGE_RESULT LegoGEContext::Render()
    {
        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        UseShader(shaderProgram);
        int location = glGetUniformLocation(shaderProgram->GetProgram(), "u_color");
        
        glUniform4f(location, 0.5, 0.0f, 0.25f, 1.0f);
        glBindVertexArray(vao);
        
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ibo);

        glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, nullptr);
        
        
        glfwSwapBuffers(this->glWindow);
        return LGE_OK;
    }

    LGE_RESULT LegoGEContext::Update()
    {
        
        if (glfwWindowShouldClose(this->glWindow)) {

            return LGE_EXIT;
        }
        
        return LGE_OK;
    }

    LGE_RESULT LegoGEContext::UseShader(ShaderProgram* shader)
    {
        if (shader->GetProgram() == LGE_SHADER_NOTCOMPILED) {
            std::cout << "Shader not compiled\n";
            m_error = LGE_SHADER_NOTCOMPILED;
            return LGE_SHADER_NOTCOMPILED;
        }
        else {
            glUseProgram(shader->GetProgram());
        }


    }

    

    void LegoGEContext::GLClearError() {
        while (glGetError() != GL_NO_ERROR) {

        }
    }

    void LegoGEContext::GLCheckError() {
        while (GLenum error = glGetError()) {
            std::cout << "[OpenGL Error] (" << error <<  ")" << std::endl;
        }
    }
}

