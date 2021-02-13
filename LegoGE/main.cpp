#include <iostream>

#include "LegoGEContext.h"


using namespace LGE;
int main(void)
{
    
    LegoGEContext* lge = new LegoGEContext();
    

    if (lge->Init(720,480) < 1) {
        return -1;
    }

    RenderContext* context = new RenderContext();
    Mesh2D* mesh = Mesh2D::quad();
    Mesh2D* triangle = Mesh2D::triangle();
    context->QueueMesh(mesh);
    context->QueueMesh(triangle);

    lge->BindRenderContext(context);
    
    while (lge->Update() > -1)
    {
        mesh->SetPosition(Vector2(mesh->GetPosition().x + 0.01, mesh->GetPosition().y));
       
        /* Render here */
        lge->Render();

        /* Poll for and process events */
        glfwPollEvents();
    }
    std::cout << "LegoGE Closing\n";

    glfwTerminate();
    return 0;
}