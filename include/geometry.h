#ifndef GEOMETRY_H
#define GEOMETRY_H

#include <math.h>
#include <iostream>

#define PI 3.1415926535897

struct Increments
{
    double dx;
    double dy;

};

int points_distance(int x1, int y1, int x2, int y2);
struct Increments ang_to_inc(double degrees);
double inc_to_ang(Increments in);


#endif // GEOMETRY_H
