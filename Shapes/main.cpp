/*Jonathan Collins
Main Function
Homework 6 CS312 Principles
This is the main function which reads in the values for several different shapes and then prints them. */

#include<iostream>
#include<string>
#include"point.h"
#include"shape.h"
#include"cone.h"
#include"box.h"
#include"sphere.h"

using namespace std;


void read_objs (Shape **list){


   Shape *node;
   double x, y, z, radius, xx, yy, zz;
   string type, color, bcolor;

   // initialize list
   *list = NULL;

   while (cin >> type) {

      	if (type.compare ("sphere") == 0) {

		cin >> x >> y >> z >> radius >> color;

		node = new Sphere(type, color, Point(x, y, z), radius);
	}

	else if (type.compare ("box") == 0) {

		cin >> xx >> yy >> zz >> x >> y >> z >> color >> bcolor;
	
		node = new Box(type, color, bcolor, xx, yy, zz, Point(x, y, z));
	}
   
	else if (type.compare ("cone") == 0) {

		cin >> x >> y >> z >> xx >> yy >> zz >> radius >> color >> bcolor;

		node = new Cone (type, color, bcolor, Point (x, y, z), Point (xx, yy, zz), radius);
      }

	
	node->next = *list;
	*list = node;
   }
}

void print_objs(Shape *list){

	Shape *curr = list;

	cout << "Objects:" << endl << endl;

	while (curr != NULL) {

		curr->print_type();
		curr->print_color();
		curr->print_loc();
		cout << "Volume: " << curr->compute_volume() << endl << endl;

		curr = curr->next;
	}
}
		

int main() {

	Shape *list;

	read_objs(&list);
	print_objs(list);
	

	return 0;

}

