#ifndef COLOR_H
#define COLOR_H

#include "vec3.h"

//Alais for vec3
using color = vec3;

//Creates a raster image
void WriteColor(std::ostream& out, const color& pixelColor) {

	//returns value of x
	auto r = pixelColor.x();
	//returns value of y
	auto g = pixelColor.y();
	//returns value of z
	auto b = pixelColor.z();

	//Translate the [0,1] values to a byte range of [0,255];
	int rbyte = int(255.999 * r);
	int gbyte = int(255.999 * g);
	int bbyte = int(255.999 * b);

	//Write out the pixel color componenets
	std::cout << rbyte << ' ' << gbyte << ' ' << bbyte << '\n';

}
#endif // !COLOR_H
