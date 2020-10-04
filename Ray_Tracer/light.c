/*Light class C file, Jonathan Collins
CS304 Homework 8
This class implements the illuminate function to aggregate ambient, diffuse, and specular lighting*/

#include"rt.h"
#include"obj.h"
#include"vec.h"
#include"light.h"
#include<math.h>
#include<stdlib.h>

COLOR_T illuminate (RAY_T ray, LIGHT_T light, OBJ_T *list, COLOR_T surface_col, VEC_T int_pt, VEC_T normal){
	
	//declare new variables needed for the function
	COLOR_T color;
	VEC_T light_vector, R;
	double cosine;

	//start with ambient light and our fudge factor
	color.r = .2 * surface_col.r;
	color.g = .2 * surface_col.g;
	color.b = .2 * surface_col.b;

	if (!shadow_test(light, list, int_pt)){
	
		//calculate the vector from source to intersection for diffuse light
		light_vector.x = light.loc.x - int_pt.x;
		light_vector.y = light.loc.y - int_pt.y;
		light_vector.z = light.loc.z - int_pt.z;

		//normalize the light vector and normal vector so 
		//that they can be used to find the cosine easily
		light_vector = normalize(light_vector);
		normal = normalize(normal);

		//get the cosine of the angle between the light vector and
		//the normal vector and use it to add the diffuse light
		cosine = dot(light_vector, normal);
		if (cosine > 0){
			color.r += cosine * surface_col.r;
			color.g += cosine * surface_col.g;
			color.b += cosine * surface_col.b;
		}

		R.x = light_vector.x - 2 * cosine * normal.x;
		R.y = light_vector.y - 2 * cosine * normal.y;
		R.z = light_vector.z - 2 * cosine * normal.z;
	
		if (cosine > 0 && dot(R, ray.dir) > 0) {
			color.r += pow(dot(R, ray.dir), 200);
			color.g += pow(dot(R, ray.dir), 200);
			color.b += pow(dot(R, ray.dir), 200);
		}	
	}
	return color;
}

static int shadow_test(LIGHT_T light, OBJ_T *list, VEC_T int_t){

	//declare some placeholders
	OBJ_T *curr;
	double t;
	VEC_T int_pt, normal;
	RAY_T ray;

	ray.origin = int_t;
	ray.dir.x = light.loc.x - int_t.x;
	ray.dir.y = light.loc.y - int_t.y;
	ray.dir.z = light.loc.z - int_t.z;
	ray.dir = normalize(ray.dir);

	//iterate through our *list and if there is an intersection, return 1
	for (curr = list; curr != NULL; curr = curr->next){
		if (intersect_sphere(ray, curr->sphere, &t, &int_pt, &normal)){
			if (t > .001){
				return 1;
			}
		}
	}

	//if nothing returns in the loop, there is no shadow
	//in this case, return 0

	return 0;
}