/*Sphere Type C file, Jonathan Collins
CS304 Homework 8
This C file gives the implementation of the intersect_sphere function defined in the header file*/


#include"sphere.h"
#include"rt.h"
#include<math.h>
#include"vec.h"

int intersect_sphere(RAY_T ray, SPHERE_T sphere, double *t, VEC_T *int_pt, VEC_T *normal){

	//creating all the placeholder variables we will need
	double a, b, c, t0, t1;

	//creating a new vector and initializing it to be the ray origin minus
	//the sphere center; this will make computing a, b, and c easier
	VEC_T vector;
	vector.x = ray.origin.x - sphere.center.x;
	vector.y = ray.origin.y - sphere.center.y;
	vector.z = ray.origin.z - sphere.center.z;

	//set a, b, and c for the formula
	a = 1;
	b = 2 * dot(ray.dir, vector);
	c = dot(vector, vector) - (sphere.radius * sphere.radius);

	//use the quadratic formula on a, b, and c if the discriminant is positive
	if ((b * b - (4 * a * c)) >= 0 ){
		t0 = (-b + sqrt(b * b - (4 * a * c))) / (2 * a);
		t1 = (-b - sqrt(b * b - (4 * a * c))) / (2 * a);
	}
	else{
		t0 = t1 = -1;
	}

	//check to see which one is smaller (and positive) and set the value
	//which is pointed to by t to be that one and return true (1)
	//If neither is positive, return false (0)
	if (t1 > 0 && t0 > 0){
		if (t1 < t0){
			*t = t1;
			int_pt->x = ray.origin.x + ray.dir.x * t1;
			int_pt->y = ray.origin.y + ray.dir.y * t1;
			int_pt->z = ray.origin.z + ray.dir.z * t1;
			normal->x = int_pt->x - sphere.center.x;
			normal->y = int_pt->y - sphere.center.y;
			normal->z = int_pt->z - sphere.center.z;
			return 1;
		}
		else{
			*t = t0;
			int_pt->x = ray.origin.x + ray.dir.x * t0;
			int_pt->y = ray.origin.y + ray.dir.y * t0;
			int_pt->z = ray.origin.z + ray.dir.z * t0;
			normal->x = int_pt->x - sphere.center.x;
			normal->y = int_pt->y - sphere.center.y;
			normal->z = int_pt->z - sphere.center.z;
			return 1;
		}
	}
	else if (t0 > 0){
		*t = t0;
		int_pt->x = ray.origin.x + ray.dir.x * t0;
		int_pt->y = ray.origin.y + ray.dir.y * t0;
		int_pt->z = ray.origin.z + ray.dir.z * t0;
		normal->x = int_pt->x - sphere.center.x;
		normal->y = int_pt->y - sphere.center.y;
		normal->z = int_pt->z - sphere.center.z;
		return 1;
	}
	else if (t1 > 0){
		*t = t1;
		int_pt->x = ray.origin.x + ray.dir.x * t1;
		int_pt->y = ray.origin.y + ray.dir.y * t1;
		int_pt->z = ray.origin.z + ray.dir.z * t1;
		normal->x = int_pt->x - sphere.center.x;
		normal->y = int_pt->y - sphere.center.y;
		normal->z = int_pt->z - sphere.center.z;
		return 1;
	}
	else {
		return 0;
	}	
}