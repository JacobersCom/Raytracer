#ifndef SPHERE_H
#define SPHERE_H

#include "hittable.h"
#include "vec3.h"

class sphere : public hittable {
public:

	sphere(const point3& center, double radius) : center(center), radius(std::fmax(0, radius)){}

	bool hit(const ray& r, double ray_tmin, double ray_tmax, hit_record& rec) const override {

		vec3 cen_org = center - r.origin();
		auto a = r.direction().magnitude();
		auto h = dot(r.direction(), cen_org);
		auto c = cen_org.magnitude() - radius * radius;
		
		//quaratic equation return reuslt
		auto discriminant = h * h - a * c;

		//At least one real solution
		if (discriminant < 0)
			return false; // no hit

		auto sqtrd = std::sqrt(discriminant);

		// first intercection. The nearest point
		auto root = (h - sqtrd) / a;
		
		//Is the point of intercection behind the camera or past the max distance. if so not vaild.
		if (root <= ray_tmin || ray_tmax <= root) {
			
			//If the first intercection was not vaild try the next intercection point.
			root = (h + sqtrd) / a;
			if (root <= ray_tmin || ray_tmax <= root)	
				return false;
		}

		rec.t = root;
		rec.p = r.at(rec.t);
		rec.normal = (rec.p - center) / radius;

		return true;
	}

private:

	point3 center;
	double radius;
};
#endif // !SPHERE_H
