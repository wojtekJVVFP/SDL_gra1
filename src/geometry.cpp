#include "geometry.h"
#include <math.h>
#include <iostream>


int points_distance(int x1, int y1, int x2, int y2)
{
    //std::cout<<"x1, x2, y1, y2"<<x1<<", "<<x2<<", "<<y1<<", "<<y2<<", "<<"x1-x2: "<<x1-x2<<", y1-y2: "<<y1-y2<<"\n";

    return sqrt(pow((x1-x2),2) + pow((y1-y2),2));
}
