#ifndef VEC_H
#define VEC_H

#include <cmath>
#include <iostream>


class vec3 {

public:

	double vec[3];

	vec3() : vec{ 0,0,0 } {}
	vec3(double x, double y, double z) : vec{ x, y, z } {}

	//Returns the value at said index
	double x() const { return vec[0]; }
	double y() const { return vec[1]; }
	double z() const { return vec[2]; }

	vec3 operator -() const { // negative vector
		
		return (vec3(-vec[0], -vec[1], -vec[2]));
	}

	double operator[](int i) const {
		
		return vec[i];
	}
	double& operator[](int i) {

		return vec[i];
	}

	vec3& operator+=(const vec3& v) {

		vec[0] += v.vec[0];
		vec[1] += v.vec[1];
		vec[2] += v.vec[2];
	}

	//t is a scalar
	vec3& operator *=(double t) {
		vec[0] *= t;
		vec[1] *= t;
		vec[2] *= t;
		return *this;
	}
	vec3& operator /= (double t) {
		return *this *= 1 / t;
	}

	double magnitude() const {

		return sqrt(vec[0] * vec[0] + vec[1] * vec[1] + vec[2] * vec[2]);
	}


};

//just a alias for vec3
using point3 = vec3;

//Utility functions

//Gives ostream the ability to handle vec3 types using left shift
inline std::ostream& operator<< (std::ostream & out, const vec3 & v) {
	
	return out << v.vec[0] << ' ' << v.vec[1] << ' ' << v.vec[2];
}

//operator +
inline vec3 operator+(const vec3 u, const vec3 v) {

	return vec3(u.vec[0] + v.vec[0],
				u.vec[1] + v.vec[1],
				u.vec[2] + v.vec[2]);

}


//operator - 
inline vec3 operator-(const vec3& u, const vec3& v) {

	return vec3(u.vec[0] - v.vec[0],
				u.vec[1] - v.vec[1],
				u.vec[2] - v.vec[2]);
}


//operator *
inline vec3 operator*(const vec3& u, const vec3& v) {

	return vec3(u.vec[0] * v.vec[0],
				u.vec[1] * v.vec[1],
				u.vec[2] * v.vec[2]);

}

//operator * with a scalar
inline vec3 operator*(const vec3& v, double t){

	return vec3(v.vec[0] * t, v.vec[1] * t, v.vec[2] * t);
}
//operator * a whole vector with a scalar
inline vec3 operator*(double t, const vec3& v) {
	
	return v * t;
}
//operator / to divide the scalar by 1 before used for muitl
inline vec3 operator/(const vec3& v, double t) {

	t = 1 / t;

	return v * t;
}

//dot product
inline double dot(const vec3& u, const vec3& v) {

	return u.vec[0] * v.vec[0] 
		+ u.vec[1] * v.vec[1] 
		+ u.vec[2] * v.vec[2];

}

//cross product
inline vec3 cross(const vec3& u, const vec3& v) {

	return vec3(u.vec[1] * v.vec[2] - u.vec[2] * v.vec[1],
		u.vec[2] * v.vec[0] - u.vec[0] * v.vec[2],
		u.vec[0] * v.vec[1] - u.vec[1] * v.vec[0]);

}

//unit vector
inline vec3 UnitVector(const vec3& v) {

	return v / v.magnitude();
}
#endif
