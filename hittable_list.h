#ifndef HITTABLE_LIST_H
#define HITTABLE_LIST_H

#include "hittable.h"

#include <memory>
#include <vector>

using std::make_shared;
using std::shared_ptr;

class hittable_list : hittable {

public:

	std::vector<shared_ptr<hittable>> objects;

	hittable_list(){}
	hittable_list(shared_ptr<hittable> object) { add(object); }

	void clear() { objects.clear(); }

	void add(shared_ptr<hittable> object) { objects.push_back(object); }


}
#endif // !HITTABLE_LIST_H
