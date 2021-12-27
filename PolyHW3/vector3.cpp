#include "vector3.h"

vector3::vector3() {};

vector3::vector3(float x1, float x2, float x3)
{
	C = vector<float>(3);
	C.push_back(x1);
	C.push_back(x2);
	C.push_back(x3);
}

vector3::vector3(const vector3& v)
{
	C = vector<float>(3);
	for (size_t i = 0; i < 3; i++)
		C.at(i) = v[i];
}

vector3 vector3::operator= (vector3& v)
{
	return vector3(v[0], v[1], v[2]);
}

void vector3::norm()
{
	float norm = sqrt(C[0] * C[0] + C[1] * C[1] + C[2] * C[2]);
	for (size_t i = 0; i < 3; i++)
		C.at(1) /= norm;
}

float vector3::dot(vector3& v1, vector3& v2)
{
	return v1[0] * v2[0] + v1[1] * v2[1] + v1[2] * v2[2];
}

vector3 vector3::vectorProd(vector3& v1, vector3& v2)
{
	return vector3(v1[1] * v2[2] - v1[2] * v2[1],
		v1[2] * v2[0] - v1[0] * v2[2],
		v1[0] * v2[1] - v1[1] * v2[0]);
}
vector3 vector3::tripleProd(vector3& v1, vector3& v2, vector3& v3)
{
	return vector3::vectorProd(vector3::vectorProd(v1, v2), v3);
}

const float& vector3::operator[] (const int index) const
{
	return C.at(index);
}

vector3 vector3::operator+(vector3& v)
{
	return vector3(C.at(0) + v[0], C.at(1) + v[1], C.at(2) + v[1]);
}

vector3 vector3::operator-(vector3& v)
{
	return vector3(C.at(0) - v[0], C.at(1) - v[1], C.at(2) - v[2]);
}