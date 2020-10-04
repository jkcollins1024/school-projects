/*Vector type header file, by Jonathan Collins
CS304 Computer Organization Homework 5
This header file contains the declaration of a vector type, with x, y, and z fields, as well as the declaration of two functions to be used with the vector type that will be implemented in the corresponding c file. */

#ifndef VEC_H
#define VEC_H

typedef struct{
	double x;
	double y;
	double z;
}VEC_T;

VEC_T normalize(VEC_T v);

double dot(VEC_T v1, VEC_T v2);




#endif