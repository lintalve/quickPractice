#include <stdio.h>
#include <stdbool.h>
#include "point.h"
#define  ALL_QUADS 4
typedef struct Polygon{
    int ID;
    char* name;
    point points[ALL_QUADS];
    bool closed;

}poly;