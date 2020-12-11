#include <iostream>

#include "LegoGEContext.h"
#include "Quad2D.h"
using namespace LGE;
int main(void)
{
    
    LegoGEContext* lge = new LegoGEContext();
    if (lge->Init() < 1) {
        return -1;
    }
    
    while (lge->Update() > -1)
    {
        /* Render here */
        lge->Render();

        /* Poll for and process events */
        glfwPollEvents();
    }
    std::cout << "LegoGE Closing\n";

    glfwTerminate();
    return 0;
}