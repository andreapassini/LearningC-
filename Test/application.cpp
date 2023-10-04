#include <iostream>
#include <string>
#include <math.h>

struct Vec3 {
	float x;
	float y;
	float z;
};

float Magnitude(Vec3* vec) {
	float mag = sqrtf( (vec->x * vec->x) + (vec->y * vec->y) + (vec->z * vec->z) );
	return mag;
}

void Normalize(Vec3* v) {
	float m = Magnitude(v);
	v->x /= m;
	v->y /= m;
	v->z /= m;
}

int main() {
	
	int a = 5;

	int* ptr = (int*)0x1678D3F694;

	std::cout << ptr << " " << *ptr << std::endl;

	return -1;
}