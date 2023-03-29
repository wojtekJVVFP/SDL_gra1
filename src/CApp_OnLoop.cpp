#include "CApp.h"
#include <time.h>
#include <iostream>


bool CApp::timer()
{
    #define FREQ 100
    #define DESIRED_DELAY 1000/FREQ

    clock_t diff=0;
    static clock_t old_t = clock(); //first value of time while running the program
    static clock_t sum_t = 0;
    diff = clock() - old_t;
    //sum_t += diff;
    float time_ms = ((float)diff)/CLOCKS_PER_SEC*1000; //value of difference

    if(time_ms > DESIRED_DELAY)
    {
       old_t = clock();
       //sum_t = 0;
       std::cout<<time_ms<<std::endl;
       //time_ms = 0;
       //diff = 0;
       return true;
    }
    else
    {
        return false;
    }
}


void CApp::OnLoop()
{


    static int loop = 0;


    if(timer())
    {
        n.pos_x = n.get_x() + 1;
    }

}
