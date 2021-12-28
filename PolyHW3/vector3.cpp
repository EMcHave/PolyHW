#include "vector3.h"

vector3::vector3() {};

vector3::vector3(float x1, float x2, float x3)
{
	C.at(0) = x1; C.at(1) = x2; C.at(2) = x3;
}

vector3::vector3(const vector3& v)
{
	for (size_t i = 0; i < 3; i++)
		C.at(i) = v[i];
}

vector3& vector3::operator= (const vector3& v)
{
	for (size_t i = 0; i < 3; i++)
		C.at(i) = v[i];
	return *this;
}

vector3 vector3::norm()
{
	float norm = sqrt(C[0] * C[0] + C[1] * C[1] + C[2] * C[2]);
	return vector3(C.at(0) / norm, C.at(1) / norm, C.at(2) / norm);
}

float vector3::dot(const vector3& v1, const vector3& v2)
{
	return v1[0] * v2[0] + v1[1] * v2[1] + v1[2] * v2[2];
}

vector3 vector3::vectorProd(const vector3& v1,const vector3& v2)
{
	return vector3(v1[1] * v2[2] - v1[2] * v2[1],
		v1[2] * v2[0] - v1[0] * v2[2],
		v1[0] * v2[1] - v1[1] * v2[0]);
}
vector3 vector3::tripleProd(const vector3& v1, const vector3& v2, const vector3& v3)
{
	return vectorProd(vectorProd(v1, v2), v3);
}

const float& vector3::operator[] (const int index) const
{
	return C.at(index);
}

vector3 vector3::operator+(vector3& v)
{
	return vector3(C.at(0) + v[0], C.at(1) + v[1], C.at(2) + v[2]);
}

vector3 vector3::operator-(vector3& v)
{
	return vector3(C.at(0) - v[0], C.at(1) - v[1], C.at(2) - v[2]);
}

ostream& operator<<(ostream& out, const vector3 v)
{
	out << v[0] << ' ' << v[1] << ' ' << v[2] << endl;
	return out;
}
