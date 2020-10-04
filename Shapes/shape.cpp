/*Jonathan Collins
Shape class C++ file
Homework 6 CS312 Principles
Implementation for a general shape class that is extended in more specificity by three other shapes*/

#include<string>
#include<iostream>
#include"shape.h"
#include"point.h"

using namespace std;

Shape::Shape(string type, string color, Point loc){

	this->type = type;
	this->color = color;
	this->loc = loc;
	this->next = NULL;

}

void Shape::print_color(){

	cout << "Color: " << color << endl;

}

double Shape::compute_volume(){
	return 0;
}

void Shape::print_type(){

	cout << "Name: " << this->type << endl;

}

void Shape::print_loc(){

	cout << "Location: ";
	this->loc.print();
	cout << endl;

}