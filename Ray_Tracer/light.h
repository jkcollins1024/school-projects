/*Light Class Header file, Jonathan Collins
CS304 Homework 8
This header file defines a light type along with two function prototypes, illuminate and shadow_test*/

#include"vec.h"
#include"rt.h"
#include"obj.h"

#ifndef LIGHT_H
#define LIGHT_H

typedef struct{
	VEC_T loc;
}LIGHT_T;

COLOR_T illuminate (RAY_T ray, LIGHT_T light, OBJ_T *list, COLOR_T surface_col, VEC_T int_pt, VEC_T normal);

static int shadow_test (LIGHT_T light, OBJ_T *list, VEC_T int_pt);

#endif