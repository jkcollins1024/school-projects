/*Jonathan Collins
Box Header File
Homework 6 CS312 Principles
Declares a header file for a Box class which is extends the Shape class*/

#ifndef BOX_H
#define BOX_H

#include<string>
#include"point.h"
#include"shape.h"

using namespace std;

class Box : public Shape {

	private:
		double length, width, height;

	protected:
		string tbcolor;

	public:
		Box(string type, string color, string tbcolor, double length, double width, double height, Point loc);
		double compute_volume(void);
		void print_color(void);
		void print_type(void) { cout << "should never be called" << endl; }

};

#endif