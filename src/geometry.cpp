#include "geometry.h"
#include <math.h>


int points_distance(int x1, int y1, int x2, int y2)
{
    return sqrt((x1-x2)^2 + (y1-y2)^2);
}
