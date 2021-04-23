#ifndef CALCULATE_H
#define CALCULATE_H

#include <iostream>
#include <cstdlib>
#include <cmath>

typedef struct point point_t;
typedef struct point vector_t;
typedef struct triangle triangle_t;
typedef double real_t;
typedef double angle_t;


struct point
{
	real_t x; 
	real_t y;
};

struct triangle
{
	point_t a;
	point_t b;
	point_t c;
};


#endif