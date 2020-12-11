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

        Quad2D* quad = new Quad2D();
        
        quad->SetColor(LGEColor(0.0,0.25,0.50,1.0f));
        quad->SetColor(LGEColor(1.0, 0.0, 0.5, 1.0f), 2);
        quad->SetColor(LGEColor(1.0, 0.75, 0.5, 1.0f), 3);
        
        size_t size = 0;
        float* vertices = quad->SerialzeToBuffer(&size);
        
        unsigned int* indices = quad->GetIndices();


        glGenBuffers(1, &buffer);
        glBindBuffer(GL_ARRAY_BUFFER, buffer);
        glBufferData(GL_ARRAY_BUFFER, sizeof(float) * size, vertices, GL_STATIC_DRAW);
        glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(float) * LGE_2DVERTEX_SIZE, 0);
        glVertexAttribPointer(1, 4, GL_FLOAT, GL_FALSE, sizeof(float) * LGE_2DVERTEX_SIZE, (void*)(3 * sizeof(float)));
        glEnableVertexAttribArray(0);
        glEnableVertexAttribArray(1);
        unsigned int ibo;

        glGenBuffers(1, &ibo);
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ibo);
        glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(unsigned int) * quad->GetNumIndices(), indices, GL_STATIC_DRAW);

        shaderProgram = new ShaderProgram("res/shader/basic.shader");

        LGE_RESULT result = shaderProgram->Compile();
        UseShader(shaderProgram);
        int location = glGetUniformLocation(shaderProgram->GetProgram(), "u_colorMix");
        
        glUniform4f(location, 1.0, 1.0, 1.0, 1.0);
        int location2 = glGetUniformLocation(shaderProgram->GetProgram(), "u_mixIntensity");
        glUniform1f(location2, 0.0);
        std::cout << "OpenGL Version: " << glGetString(GL_VERSION) << std::endl;
        this->glWindow = window;
        this->m_isRunning = true;
        return LGE_OK;
    }



    LGE_RESULT LegoGEContext::Render()
    {
        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);
        
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

