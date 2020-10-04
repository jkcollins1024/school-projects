/*Jonathan Collins
Point class C++ file
Homework 6 CS312 Principles
Implementation for a Point class which is used in all Shape classes*/

#include<cmath>
#include<iostream>
#include"point.h"

using namespace std;

double Point::length(void){

	return (sqrt((this->x * this->x) + (this->y * this->y) + (this->z * this->z)));

}

Point Point::operator-(Point p){

	this->x -= p.x;
	this->y -= p.y;
	this->z -= p.z;
	return *this;

}

void Point::print(void){

	cout << "x: " << this->x << " y: " << this->y << " z: " << this->z;

}