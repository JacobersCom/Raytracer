#ifndef SPHERE_H
#define SPHERE_H

#include "hittable.h"
#include "vec3.h"

class sphere : public hittable {
public:

	sphere(const point3& center, double radius) : center(center), radius(std::fmax(0, radius)){}

	//Checks if the ray hit something and changes the vector to face outward point of intersection
	bool hit(const ray& r, double ray_tmin, double ray_tmax, hit_record& rec) const override {

		vec3 cen_org = center - r.origin();
		auto a = r.direction().magnitude();
		auto h = dot(r.direction(), cen_org);
		auto c = cen_org.magnitude() - radius * radius;
		
		//quadratic equation return result
		auto discriminant = h * h - a * c;

		//At least one real solution
		if (discriminant < 0)
			return false; // no hit

		auto sqtrd = std::sqrt(discriminant);

		// first intersection. The nearest point
		auto intersect_point = (h - sqtrd) / a;
		
		//Is the point of intersection behind the camera or past the max distance. if so not valid.
		if (intersect_point <= ray_tmin || ray_tmax <= intersect_point) {
			
			//If the first intersection was not valid try the next intersection point.
			intersect_point = (h + sqtrd) / a;
			if (intersect_point <= ray_tmin || ray_tmax <= intersect_point)	
				return false;
		}

		rec.t = intersect_point;
		rec.intersect_point = r.at(rec.t);

		//Creates a vector from the center of the sphere to the intersect_point 
		vec3 outward_normal = (rec.intersect_point - center);

		//Normalizes the outward vector
		outward_normal = outward_normal / radius;

		//Sets the normal face based on the dot product of the ray direction and the outward vector
		rec.set_face_normal(r, outward_normal);

		return true;
	}

private:

	point3 center;
	double radius;
};
#endif // !SPHERE_H
