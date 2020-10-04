/*Sphere Type header file, Jonathan Collins
CS304 Homework 8
This header file defines the SPHERE_T structure, as well as the intersect_sphere function, both of which are crucial to the ray tracer implementation*/

#include"vec.h"
#include"rt.h"

#ifndef SPHERE_H
#define SPHERE_H

typedef struct{
	VEC_T center;
	double radius;
}SPHERE_T;

int intersect_sphere(RAY_T ray, SPHERE_T sphere, double *t, VEC_T *int_pt, VEC_T *normal);


#endif