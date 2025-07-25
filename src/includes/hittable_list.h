#ifndef HITTABLE_LIST_H
#define HITTABLE_LIST_H

#include "hittable.h"

#include <memory>
#include <vector>

class hittable_list : public hittable {

public:

	std::vector<std::shared_ptr<hittable>> objects;

	hittable_list() {}
	hittable_list(std::shared_ptr<hittable> object) { add(object); }

	void clear() { objects.clear(); }

	void add(std::shared_ptr<hittable> object) { objects.push_back(object); }

	//A override of the hit method from hittable.h. Checking if the ray hit something.
	bool hit(const ray& r, double ray_tmin, double ray_tmax, hit_record& rec) const override {

		hit_record temp_rec;
		bool hit_anything = false;
		auto closest_so_far = ray_tmax;

		for (const auto& object : objects) {
			if (object->hit(r, ray_tmin, closest_so_far, temp_rec)) {
				
				hit_anything = true;

				//T is the intersecting point
				closest_so_far = temp_rec.t;
				rec = temp_rec;
			}
		}
		return hit_anything;
	}
};
#endif // !HITTABLE_LIST_H
