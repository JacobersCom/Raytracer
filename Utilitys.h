#ifndef UTILITYS_H
#define UTILITYS_H

#include <cmath>
#include <iostream>
#include <limits>
#include <memory>


//Constants

const double infinity = std::numeric_limits<double>::infinity();
const double pi = 3.141592653897932385;

//Utility functions

inline double degress_to_radians(double degrees) {

	return degrees * pi / 180.0;
}

//Common Headers

#include "color.h"
#include "Ray.h"
#include "vec3.h"

#endif // !UTILITYS_H
