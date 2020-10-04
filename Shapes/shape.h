/*Jonathan Collins
Shape Header File
Homework 6 CS312 Principles
Declares a header file for a Shape class which is extended for three different 3D shapes*/


#ifndef SHAPE_H
#define SHAPE_H

#include<string>
#include"point.h"

using namespace std;

class Shape {

	protected:
		string color;
		Point loc;
		string type;

	public:
		Shape *next;
		Shape(string type, string color, Point loc);
		virtual void print_color(void);
		virtual double compute_volume(void);
		void print_type(void);
		void print_loc(void);

};


#endif