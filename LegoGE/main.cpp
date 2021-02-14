#include <iostream>

#include "LegoGEContext.h"


using namespace LGE;
int main(void)
{
    
    LegoGEContext* lge = new LegoGEContext();
    

    if (lge->Init(960,540) < 1) {
        return -1;
    }

    RenderContext* context = new RenderContext(lge->GetProjector());
    Mesh2D* mesh = Mesh2D::quad();


    context->QueueMesh(mesh);
 

    lge->BindRenderContext(context);
    
    while (lge->Update() > -1)
    {
        mesh->GetTransform()->Translate(1.0f,0.0f);
        

       
        lge->Render();

        /* Poll for and process events */
        glfwPollEvents();
    }
    std::cout << "LegoGE Closing\n";

    glfwTerminate();
    return 0;
}