/*Jonathan Collins
Sphere Header File
Homework 6 CS312 Principles
Declares a header file for a Sphere class which is extends the Shape class*/

#ifndef SPHERE_H
#define SPHERE_H

#include<string>
#include"point.h"
#include"shape.h"

using namespace std;

class Sphere : public Shape {

	private:
		Point center;
		double radius;

	public:
		Sphere(string type, string color, Point center, double radius);
		double compute_volume(void);
		void print_type (void) { cout << "should never be called" << endl; }

};

#endif