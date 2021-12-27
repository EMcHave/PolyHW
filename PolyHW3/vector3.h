#pragma once
#include <vector>
#include <cmath>
#include <ostream>

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
	vector3 invert() { return vector3::origin() - *this; }
	static float dot(const vector3&, const vector3&);
	static vector3 vectorProd(vector3&, vector3&);
	static vector3 tripleProd(vector3&, vector3&, vector3&);

	static vector3 origin() { return vector3(0, 0, 0); }
	const float& operator[] (const int) const;
	vector3 operator+ (vector3&);
	vector3 operator- (vector3&);
	friend ostream& operator << (ostream&, const vector3);
};