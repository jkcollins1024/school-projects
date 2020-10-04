/*Vector type C file, by Jonathan Collins
CS304 Computer Organization Homework 5
This file contains the implementations of two functions meant to work with the vector type declared in the header file. */


#include "vec.h"
#include <math.h>

VEC_T normalize(VEC_T v){
	double root = sqrt((v.x * v.x) + (v.y * v.y) + (v.z * v.z));
	VEC_T return_vec;
	return_vec.x = v.x / root;
	return_vec.y = v.y / root;
	return_vec.z = v.z / root;
	return return_vec;
}

double dot(VEC_T v1, VEC_T v2){
	double dot_product = ((v1.x * v2.x) + (v1.y * v2.y) + (v1.z * v2.z));
	return dot_product;

}