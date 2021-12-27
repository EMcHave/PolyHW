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
	static bool intersects(const Simplex*, const Simplex*);
	static vector3 support(const Simplex*, const Simplex*, vector3&);
	virtual vector3 furthestPoint(const vector3& d) const = 0;
	virtual ~Simplex();
};

class Polygon : public Simplex
{
protected:
	vector<vector3> vertices;
public:
	Polygon();
	Polygon(vector<float>& points);
	virtual vector3 furthestPoint(const vector3&) const override;
	~Polygon();
};

class Circle : public Simplex
{
private:

public:
	float r;
	vector3 center;
	Circle(float r, float cx, float cy);
	virtual vector3 furthestPoint(const vector3&) const override;
	~Circle();
};

class Rect : public Polygon
{
public:
	Rect(float ax, float ay, float bx, float by);
	~Rect();
};

