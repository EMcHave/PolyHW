#pragma once
#include <vector>
#include <cmath>

using namespace std;

class vector3
{
private:
	vector<float> C;
public:
	vector3();
	vector3(float x1, float x2, float x3 = 0);
	vector3(const vector3&);
	vector3 operator= (vector3&);
	void norm();
	static float dot(vector3&, vector3&);
	static vector3 vectorProd(vector3&, vector3&);
	static vector3 tripleProd(vector3&, vector3&, vector3&);

	static vector3 origin() { return vector3(0, 0, 0); }
	const float& operator[] (const int) const;
	vector3 operator+ (vector3&);
	vector3 operator- (vector3&);
};