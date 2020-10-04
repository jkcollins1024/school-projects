/*Jonathan Collins
Point Header File
Homework 6 CS312 Principles
Declares a header file for a Point class which is used to implement all the Shape classes*/

#ifndef POINT_H
#define POINT_H

class Point {

	private:
		double x, y, z;

	public:
		Point() { };
		Point(double x, double y, double z) { set(x,y,z); };
		void set(double x, double y, double z) { this->x = x; this->y = y; this->z = z; }
		double length(void);
		Point operator-(Point p);
		void print(void);
};





#endif