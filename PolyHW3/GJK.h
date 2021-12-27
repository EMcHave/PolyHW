#pragma once
#include <vector>
#include <cmath>
#include <limits>
#include "vector3.h"

using namespace std;


struct point
{
	float x;
	float y;
	float z;
};

class Simplex {
private:
	static bool handleSimplex(vector<vector3>&, vector3&);
	static bool lineCase(vector<vector3>&, vector3&);
	static bool triangleCase(vector<vector3>&, vector3&);
public:
	static bool intersects(Simplex&,Simplex&);
	static vector3 support(const Simplex&, const Simplex&, const vector3&);
	virtual vector3 furthestPoint(vector3& d) = 0;
	virtual ~Simplex();
};

class Polygon : public Simplex
{
private:
	vector<point> vertices;
public:
	Polygon();
	vector3 furthestPoint(vector3&) override;
	~Polygon();
};

class Circle : public Simplex
{
private:
	float r;
	point center;
public:
	Circle(float r, float cx, float cy);
	vector3 furthestPoint(vector3&) override;
	~Circle();
};

class Rect : public Simplex
{
private:
	vector<point> vertices;
public:
	Rect(float ax, float ay, float bx, float by);
	vector3 furthestPoint(vector3&) override;
	~Rect();
};

