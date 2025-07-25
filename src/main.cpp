#include "Utilitys.h"
#include "hittable_list.h"
#include "hittable.h"
#include "Sphere.h"
#include <vector>




//Returns the color for the given scene ray
color ray_color(const ray& r, const hittable& world) {
	//Does the ray intersect at this point?
	hit_record rec;
	if (world.hit(r, 0, infinity, rec)) {
		return 0.5 * (rec.normal + color(1, 1, 1));
	}

	vec3 unit_direction = UnitVector(r.direction());

	//a Lerp to insure we stay between 0 and 1
	auto lerp = 0.5 * (unit_direction.y() + 1.0);
	
	//White and blue RGB values blended
	auto blended_value = (1.0 - lerp) * color(1.0,1.0,1.0) + lerp * color(0.5, 0.7, 1.0);
	return blended_value;
	

}

int main(){

	//Image size
	auto aspect_ratio = 16 / 9;
	int image_width = 400;
	int image_height = int(image_width / aspect_ratio);
	image_height = (image_height < 1) ? 1 : image_height;
	
	//World
	hittable_list world;
	world.add(std::make_shared<sphere>(point3(0, 0, -1), 0.5));
	world.add(std::make_shared<sphere>(point3(0, -100.5, -1), 100));


	//Camera
	//Distance between the view port and camera
	auto focal_lenght = 1.0;

	//Total height in world space
	auto viewport_Height = 200.0;
	//This is done to get the aspect ratio. Because the true aspect may not be the aspect ratio
	auto viewport_width = viewport_Height * (double(image_width) / image_height);
	auto camera_center = point3(0, 0, 0);

	auto viewport_u = vec3(viewport_width, 0, 0); // x for uv mapping
	auto viewport_v = vec3(0,-viewport_Height,0); // y for uv mapping

	//This is half the pixel distance so the view port is evenly divided into width x height = 0.5(Squared pixels)
	auto pixel_delta_u = viewport_u / image_width;
	auto pixel_delta_v = viewport_v / image_height;

	//Gives the location of the upper left pixel
	auto viewport_upper_left = camera_center - vec3(0, 0, focal_lenght) - viewport_u / 2 - viewport_v / 2;
	auto pixel00_loc = viewport_upper_left + 0.5 * (pixel_delta_u + pixel_delta_v);

	//Render
	std::cout << "P3\n" << image_width << ' ' << image_height << "\n255\n";
	for (int i = 0; i < image_width; i++) {
		std::clog << "\rScanLines remaining: " << (image_width - i) << ' ' << std::flush;
		for (int j = 0; j < image_height; j++) {


			auto pixel_center = pixel00_loc + (i * pixel_delta_u) + (j * pixel_delta_v);
			auto ray_direction = pixel_center - camera_center;

			//Creating a ray that starts at the camera and ends between the pixel center and camera center
			ray r(camera_center, ray_direction);

			color pixel_color = ray_color(r,world);
			WriteColor(std::cout, pixel_color);
		}
		
	}
	std::clog << "\rDone.                          \n"; 


}