#include "CApp.h"

void CApp::OnLoop()
{
    static int loop = 0;
    if(loop++ == 100)
    {
        loop = 0;
        n.pos_x = n.get_x() + 1;
    }

}
