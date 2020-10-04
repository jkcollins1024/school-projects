/*Ray Tracer Header File by Jonathan Collins
Homework 5, CS304 Computer Organization
This header file declares two types: One for a ray type and one for a color type. It also contains prototypes for two necessary functions, read_objs and trace
*/


#ifndef RT_H
#define RT_H

#include"vec.h"

typedef struct{
	VEC_T origin;
	VEC_T dir;
}RAY_T;

typedef struct{
	double r;
	double g;
	double b;
}COLOR_T;


#endif