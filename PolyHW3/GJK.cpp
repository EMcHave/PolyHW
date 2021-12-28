#include "GJK.h"
#include <iostream>
#include <limits>
using namespace Geometry;

bool Figure::intersects(const Figure* s1,const Figure* s2)
{
	vector3 d = vector3(0, 1);
	vector<vector3> Figure;
	Figure.push_back(support(s1, s2, d));
	d = Figure.at(0).invert().norm();
	while (true)
	{
		vector3 A = support(s1, s2, d);
		if (vector3::dot(A, d) <= 0) 
			return false;
		Figure.push_back(A);
		if (handleSimplex(Figure, d)) 
			return true;
	}
}

vector3 Figure::support(const Figure* s1, const Figure* s2, vector3& d)
{
	return s1->furthestPoint(d) - s2->furthestPoint(d.invert());
}

bool Figure::handleSimplex(vector<vector3>& simplex, vector3& d)
{
	if (simplex.size() == 2) 
		return lineCase(simplex, d);
	return triangleCase(simplex, d);
}

bool Figure::lineCase(vector<vector3>& Figure, vector3& d)
{
	vector3 B = Figure.at(0);
	vector3 A = Figure.at(1);
	vector3 AB = B - A;
	vector3 AO = vector3::origin() - A;
	vector3 ABperp = vector3::tripleProd(AB, AO, AB);
	d = ABperp.norm();
	return false;
}

bool Figure::triangleCase(vector<vector3>& Figure, vector3& d)
{
	vector3 C, B, A, AB, AC, AO, ABperp, ACperp;

	C = Figure.at(0); B = Figure.at(1); A = Figure.at(2);
	AB = B - A; AC = C - A; AO = vector3::origin() - A;
	ABperp = vector3::tripleProd(AC, AB, AB);
	ACperp = vector3::tripleProd(AB, AC, AC);
	if (vector3::dot(ABperp, AO) > 0)
	{
		Figure.erase(Figure.begin());
		d = ABperp.norm();
		return false;
	}
	else if (vector3::dot(ACperp, AO) > 0)
	{
		Figure.erase(Figure.begin() + 1);
		d = ACperp.norm();
		return false;
	}
	return true;
}

Figure::~Figure() {};

Circle::Circle(float r, float cx, float cy) : r(r), center(cx, cy) {}

vector3 Circle::furthestPoint(const vector3& d) const
{
	float angle = atan2f(d[1], d[0]);

	return vector3(center[0] + r*cosf(angle), center[1] + r*sinf(angle));
}


Circle::~Circle() { /*cout << "Circle deleted" << endl; */ }

Polygon::Polygon() {}

Polygon::Polygon(vector<float>& list)
{
	vector<float>::iterator it = list.begin();
	for ( it; it!=list.end(); it++)
		vertices.push_back(vector3(*it++, *(it+1)));
}

Rect::Rect(float ax, float ay, float bx, float by)
{
	vertices.push_back(vector3( ax, ay ));
	vertices.push_back(vector3( bx, ay ));
	vertices.push_back(vector3( bx, by ));
	vertices.push_back(vector3( ax, by ));
}



vector3 Polygon::furthestPoint(const vector3& d) const
{
	float furthestDistance = -FLT_MAX;
	vector3 furthestPoint(0, 0, 0);
	for (vector3 v : vertices)
	{
		float distanceInDirection = vector3::dot(v, d);
		if (distanceInDirection > furthestDistance)
		{
			furthestPoint = v;
			furthestDistance = distanceInDirection;
		}
	}

	return furthestPoint;
}

Polygon::~Polygon() { /*cout << "Polygon delted" << endl;*/ }

Rect::~Rect() { /*cout << "Rect deleted" << endl;*/ }
