// include all necessary libraries
#include <iostream>

// use the std namespace to avoid having to type "std::" in front of output functions
using namespace std;

// define pi here
const float pi = 3.14;
	
// function declarations for user-defined functions
// the full function definitions should appear below the main program

// This function will calculate and return the circumference of a circle 
double circum (float radius);

// This function will calculate the area of a circle
void area (float radius, double &the_area);

// This function will calculate BOTH the circumference and area of a circle
void calc_circle_geometry(float radius, double * ptr_circum, double * ptr_area);

int main() {

	// declare and initialize necessary variables
    float radius = 5.0;
	
	// call the function circum and print its output
	double cir = circum(radius);
	cout << "The circumference is: " << cir << endl;
	// don't forget to also tell the user what value you are using for the radius!

	
	// call the function area
	double finalArea;
	area(radius, finalArea);
	cout << "The area is: " <<  finalArea << endl;


	// call the function calc_circle-geometry
	calc_circle_geometry(radius, &cir, &finalArea);
    cout << "The geometry of the circle is: " << "Radius: " << finalArea << " Circumference: " << cir << endl;
	
	
	// write a loop that iterates from radius = 1 to 10 and prints the values of
	// radius, area, and circumference for each radius
	
	printf ("%7s  %7s   %7s\n", "radius", "Area", "circumference");

	
	for (int i = 1; i <=10; i++){
		radius = i;
		cir = circum(radius);
		area(radius, finalArea);
		calc_circle_geometry(radius, &cir, &finalArea);
		printf ("%7.1lf  %7.1lf   %7.1lf\n", radius, finalArea, cir);
	}

	return 0;
}


// This function will calculate the circumference of a circle 
double circum (float radius) {
    
    // Circumference Formula: C = 2 * π * r

    double circumference = 2 * pi * radius;

	return circumference;  
}

// This function will calculate the area of a circle 
void area (float radius, double &the_area) {
	// complete this function using the reference to "return" the calculated value area

    // Area Formula: C = 2 * r^2
    the_area = pi * radius * radius;
}

// This function will calculate BOTH the circumference and area of a circle
void calc_circle_geometry(float radius, double * ptr_circum, double * ptr_area) {
	// complete this function using pointers to "return" the calculated values
    
	*ptr_circum = 2.0 * pi * radius;

    *ptr_area = pi * radius * radius;

}
