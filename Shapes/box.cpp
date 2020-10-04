/*Jonathan Collins
Box class C++ file
Homework 6 CS312 Principles
Implementation for a Box class which extends the Shape class*/

#include<string>
#include<iostream>
#include"shape.h"
#include"point.h"
#include"box.h"

using namespace std;

Box::Box(string type, string color, string tbcolor, double length, double width, double height, Point loc) : Shape(type, color, loc) {

	this->length = length;
	this->width = width;
	this->height = height;
	this->tbcolor = tbcolor;
	this->color = color;
	this->type = type;
	this->loc = loc;

}

double Box::compute_volume(void){

	return (this->length * this->width * this->height);

}

void Box::print_color(void){

	cout << "Side color: " << this->color << "  Top/Base color: " << this->tbcolor << endl;

}

