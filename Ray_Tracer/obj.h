/*Object Header File, Jonathan Collins
CS304 Homework 8
This header file defines OBJ_T, which is necessary for storing each sphere along with its color.*/

#include"sphere.h"
#include"rt.h"

#ifndef OBJ_H
#define OBJ_H

typedef struct NODE{
	SPHERE_T sphere;
	COLOR_T color;
	struct NODE * next;
}OBJ_T;

#endif