/*Jonathan Collins
Sphere class C++ file
Homework 6 CS312 Principles
Implementation for a Sphere class which extends the Shape class*/

#include<string>
#include<iostream>
#include"shape.h"
#include"point.h"
#include"sphere.h"

using namespace std;

Sphere::Sphere(string type, string color, Point center, double radius) : Shape(type, color, center){

	this->center = center;
	this->radius = radius;
	this->type = type;
	this->color = color;

}

double Sphere::compute_volume(void){

	return (4 * (3.14159 * radius * radius * radius) / 3);

}

