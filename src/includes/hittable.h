#ifndef HITTABLE_H
#define HITTABLE_H

#include "Ray.h"

class hit_record {
public:
	
	point3 intersect_point;
	vec3 normal;
	double t;
	bool front_face;

	void set_face_normal(const ray& r,const vec3& outward_normal) {

		//Set the hit record normal vector
		//The paramter out_ward is assumed to have unit lenght/

		front_face = dot(r.direction(), outward_normal) < 0;

		normal = front_face ? outward_normal : -outward_normal;
	}

};

class hittable {

public:

	virtual ~hittable() = default;

	virtual bool hit(const ray& r, double ray_tmin, double ray_tmax, hit_record& rec) const = 0;
};

#endif // !_HITTABLE_H
