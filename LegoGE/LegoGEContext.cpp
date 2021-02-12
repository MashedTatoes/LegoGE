#include "LegoGEContext.h"
namespace LGE
{
    LGE_RESULT LegoGEContext::Init(int windowWidth, int windowHeight)
    {
        GLFWwindow* window;
        m_error = LGE_OK;
        /* Initialize the library */
        if (glfwInit() == GLFW_FALSE)
            //m_error = LGE_INIT_FAILED;
            return LGE_INIT_FAILED;

        glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
        glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
        glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

        /* Create a windowed mode window and its OpenGL context */
        window = glfwCreateWindow(windowWidth, windowHeight, "Lego Graphics Engine!", NULL, NULL);
        if (!window)
        {
            glfwTerminate();
            m_error = LGE_INIT_FAILED;
            return m_error;
        }

        glfwMakeContextCurrent(window);
        glewInit();
        glEnable(GL_DEBUG_OUTPUT);

        glDebugMessageCallback(OpenGLDebugMessage, (void*)DebugMessageStrictness::HIGH);

        /*glGenVertexArrays(1, &vao);
        glBindVertexArray(vao);
        m_vertexBuffer = new VertexBuffer();
        quad->LoadIntoVertexBuffer(m_vertexBuffer, 0);
        //triangle->LoadIntoVertexBuffer(m_vertexBuffer, 0);

        glEnableVertexAttribArray(0);
        glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(float) * LGE_2DVERTEX_SIZE, 0);
        m_indexBuffer = new IndexBuffer();
        quad->LoadIntoIndexBuffer(m_indexBuffer, 0);
        //triangle->LoadIntoIndexBuffer(m_indexBuffer, 0);


        shaderProgram = new ShaderProgram("res/shader/basic.shader");
        LGE_RESULT result = shaderProgram->Compile();

        

        glBindBuffer(GL_ARRAY_BUFFER, 0);
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
        
        glUseProgram(0);
        glBindVertexArray(0);*/



        std::cout << "OpenGL Version: " << glGetString(GL_VERSION) << std::endl;
        this->glWindow = window;
        this->m_isRunning = true;
        return LGE_OK;
    }

    LGE_RESULT LegoGEContext::Render()
    {
        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);
        
        
       
        //glBindVertexArray(vao);
        //m_indexBuffer->Bind();

        //glDrawElements(GL_TRIANGLES, 3, GL_UNSIGNED_INT, (void*)(sizeof(GLuint) * 6));

        if (m_renderer != nullptr)
        {
            m_renderer->Draw();


        }

        
        
        
        //glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ibo);
        
        
        glfwSwapBuffers(this->glWindow);
        glBindVertexArray(0);
        m_renderer->LoadMeshQueue();
        return LGE_OK;
    }

    LGE_RESULT LegoGEContext::Update()
    {
       
        
        if (glfwWindowShouldClose(this->glWindow)) {

            return LGE_EXIT;
        }
        
        

        return LGE_OK;
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

