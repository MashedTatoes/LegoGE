#include <iostream>

#include "LegoGEContext.h"
#include "Mesh.h"

using namespace LGE;
int main(void)
{
    
    LegoGEContext* lge = new LegoGEContext();
    

    if (lge->Init(960,540) < 1) {
        return -1;
    }

    RenderContext* context = new RenderContext(lge->GetProjector());
    Mesh* mesh = Mesh::quad();


    Texture* t = new Texture("res/person.png");
    
    t->ToggleFlag(ImageSettings::LinearFilter);
    t->Reload();
    t->Bind();
    
    mesh->SetTexture(t);
    context->QueueMesh(mesh);

    lge->BindRenderContext(context);
    
    float clr = 0;
   

    while (lge->Update() > -1)
    {
     //   mesh->GetTransform()->Translate(1.0f,0.0f);
       
        lge->Render();

        /* Poll for and process events */
        glfwPollEvents();
    }
    std::cout << "LegoGE Closing\n";

    glfwTerminate();
    return 0;
}