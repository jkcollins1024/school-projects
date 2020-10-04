/*Ray Tracer C File by Jonathan Collins
Homework 8, CS304 Computer Organization
This file includes several functions essential for ray tracing including the main function, which will run to actually produce the file depicting the spheres.  It reads in spheres from an input file, then goes on to loop through all the pixels, set the corresponding ray, and determine whether the ray intersects with a sphere, then setting the appropriate color and printing the pixel to the .ppm file.
*/


#include"rt.h"
#include"vec.h"
#include"sphere.h"
#include"light.h"
#include"obj.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

void read_objs(OBJ_T **list){

	//declare placeholder variables and initialize *list to null
	double x, y, z, rad, r, g, b;
	int flag;
	*list = NULL;

	//loops through input until it reaches the end of the file containing spheres,
	//adding the spheres as objects to the linked list as they are read in
	do{

	//allocate space for the new node
	OBJ_T *node = (OBJ_T *) malloc(sizeof(OBJ_T));

	//read in the values for this sphere
	flag = scanf("%lf %lf %lf %lf %lf %lf %lf", &x, &y, &z, &rad, &r, &g, &b);

	//set the attributes of the node according to what was passed in
	node->sphere.center.x = x;
	node->sphere.center.y = y;
	node->sphere.center.z = z;
	node->sphere.radius = rad;
	node->color.r = r;
	node->color.g = g;
	node->color.b = b;

	//add the node to the head of the list
	node->next = *list;
	*list = node;
	}while(flag != EOF);
}

COLOR_T trace(RAY_T ray, OBJ_T *list, LIGHT_T light){

	//creating a placeholder color variable to be returned, as well as
	//a placeholder object pointer to represent the current object and a
	//double to hold the distance to the closest sphere and a double to hold
	//the distance to the current sphere
	COLOR_T color;
	OBJ_T *curr;
	double t, min_t = 1000;
	VEC_T min_int_pt, int_pt, normal, min_normal;

	//set the initial color to be the black background, in case it does not
	//intersect with any spheres
	color.r = 0.0;
	color.g = 0.0;
	color.b = 0.0;

	//iterate through the list of spheres, continually updating if one intersects
	//with the ray and is closer than the previous closest
	for (curr = list; curr != NULL; curr = curr->next){
		if (intersect_sphere(ray, curr->sphere, &t, &int_pt, &normal)){
			if(t < min_t){
				color = curr->color;
				min_t = t;
				min_int_pt = int_pt;
				min_normal = normal;
			}
		}
	}
	if (min_t < 1000){
		color = illuminate(ray, light, list, color, min_int_pt, min_normal);
	}

	return color;
}

int main(){

	//creating all necessary placeholder variables
	RAY_T ray;
	COLOR_T color;
	unsigned char r, g, b;
	OBJ_T *list;
	int x, y;
	OBJ_T *temp;
	LIGHT_T light;

	//initializing the placeholder ray origin to be (0,0,0) - it will never
	//change, so initialization can be done here
	ray.origin.x = 0;
	ray.origin.y = 0;
	ray.origin.z = 0;
	
	//initialize the location of the light
	light.loc.x = 5;
	light.loc.y = 10;
	light.loc.z = 0;

	//Header needed for the ppm file
	printf("P6\n");
	printf("1000 1000 \n");
	printf("255\n");
	
	//read all the spheres and their attributes into the linked list of objects
	read_objs(&list);

	//double loop to set each pixel to what it should be
	for (y = 0; y < 1000; y++){


		for (x = 0; x < 1000; x++){

			//sets the ray direction to the proper pixel in 3D space,
			//then normalizes it to represent the direction only
			ray.dir.x = -.5 + ((double)x / 1000);
			ray.dir.y = .5 - ((double)y / 1000);
			ray.dir.z = 1;

			ray.dir = normalize(ray.dir);

			//uses cast() to find the color for the pixel, then casts the color
			//to an unsigned char to be printed to the ppm file
			color = trace(ray, list, light);
			if (color.r > 1.0) {
				color.r = 1.0;
			}
			if (color.g > 1.0) {
				color.g = 1.0;
			}
			if (color.b > 1.0) {
				color.b = 1.0;
			}
			r = (unsigned char)(color.r * 255);
			g = (unsigned char)(color.g * 255);
			b = (unsigned char)(color.b * 255);

			printf("%c%c%c", r, g, b);
			

		}
	}
	//iterates through the linked list, freeing all allocated space
	while (list != NULL){
		temp = list;
		list = list->next;
		free(temp);
	}
}