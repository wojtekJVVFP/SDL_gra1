#include "geometry.h"



int points_distance(int x1, int y1, int x2, int y2)
{
    //std::cout<<"x1, x2, y1, y2"<<x1<<", "<<x2<<", "<<y1<<", "<<y2<<", "<<"x1-x2: "<<x1-x2<<", y1-y2: "<<y1-y2<<"\n";

    return sqrt(pow((x1-x2),2) + pow((y1-y2),2));
}

struct Increments ang_to_inc(double degrees)
{
    Increments out = {0,0};
    double rad = degrees/180 * PI;
    out.dx = cos(rad);
    out.dy = sin(rad);
    return out;
};

double inc_to_ang(Increments in)
{
    double out;
    if(in.dx != 0)
    {
        out = atan(in.dy/in.dx) / PI * 180;
    }
    else
    {
        const double x0 = 0.000001; //this is to replace dx which is zero
        out = atan(in.dy/x0) / PI * 180;
    }
    return out;
}
//double rad = math.atan(out.dy/out.dx);
//zamiana przyrostów na kąt i na odwrót
