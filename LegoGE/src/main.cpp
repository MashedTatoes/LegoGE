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
    //Mesh* triangle = Mesh::triangle();
    /* Mesh* triangle = Mesh::triangle();*/

    Texture* t = new Texture("res/person.png");
    t->Bind();
    mesh->SetTexture(t);
    context->QueueMesh(mesh);

    //context->QueueMesh(triangle);

    lge->BindRenderContext(context);
    
    float clr = 0;
   

    while (lge->Update() > -1)
    {
        mesh->GetTransform()->Translate(1.0f,0.0f);
        /*clr += 0.01f;
        if (clr > 1.0f)
        {
            clr = 0.0f;
        }

        mesh->SetColor(new unsigned int[2] {3, 4}, 2, LGEColor(clr, 0.5f, 0.5f, 1.0f));*/

        
        //triangle->GetTransform()->Translate(1.5f, -1.0f);
        lge->Render();

        /* Poll for and process events */
        glfwPollEvents();
    }
    std::cout << "LegoGE Closing\n";

    glfwTerminate();
    return 0;
}