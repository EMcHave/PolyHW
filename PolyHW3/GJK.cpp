#include "GJK.h"
#include <iostream>


bool Simplex::intersects(const Simplex* s1,const Simplex* s2)
{
	vector3 d = vector3(0, 1);
	cout << d << endl;
	vector<vector3> simplex;
	simplex.push_back(support(s1, s2, d));
	d = vector3::origin() - simplex.at(0);
	while (true)
	{
		cout << d << endl;
		vector3 A = support(s1, s2, d);
		cout << A << endl;
		if (vector3::dot(A, d) < 0) return false;
		simplex.push_back(A);
		if (Simplex::handleSimplex(simplex, d)) return true;
	}
}

vector3 Simplex::support(const Simplex* s1, const Simplex* s2, vector3& d)
{
	return s1->furthestPoint(d) - s2->furthestPoint(vector3::origin() - d);
}

bool Simplex::handleSimplex(vector<vector3>& simplex, vector3& d)
{
	if (simplex.size() == 2) return Simplex::lineCase(simplex, d);
	return triangleCase(simplex, d);
}

bool Simplex::lineCase(vector<vector3>& simplex, vector3& d)
{
	vector3 B = simplex.at(0);
	vector3 A = simplex.at(1);
	vector3 AB = B - A;
	vector3 AO = vector3::origin() - A;
	vector3 ABperp = vector3::tripleProd(AB, AO, AB);
	d = ABperp; 
	d.norm();
	return false;

}

bool Simplex::triangleCase(vector<vector3>& simplex, vector3& d)
{
	vector3 C, B, A, AB, AC, AO, ABperp, ACperp;

	C = simplex.at(0); B = simplex.at(1); A = simplex.at(2);
	cout << C << '\n' << B << '\n' << A << endl;
	AB = B - A; AC = C - A; AO = vector3::origin() - A;
	ABperp = vector3::tripleProd(AC, AB, AB);
	ACperp = vector3::tripleProd(AB, AC, AC);
	if (vector3::dot(ABperp, AO) > 0)
	{
		simplex.erase(simplex.begin());
		return false;
	}
	else if (vector3::dot(ACperp, AO) > 0)
	{
		simplex.erase(simplex.begin() + 1);
		return false;
	}
	return true;
}

Simplex::~Simplex() {};

Circle::Circle(float r, float cx, float cy) : r(r), center(cx, cy) {}

vector3 Circle::furthestPoint(const vector3& d) const
{
	float angle = atan2f(d[0], d[1]);

	return vector3(center[0] + r*cosf(angle), center[1] + r*sinf(angle));
}


Circle::~Circle() {}

Polygon::Polygon() {}

Polygon::Polygon(vector<float>& points)
{
	for (size_t i = 0; i < points.size(); i++)
		vertices.at(i) = vector3(points[i++], points[i--]);
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
	float furthestDistance = -numeric_limits<float>::infinity();
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

Polygon::~Polygon() {}

Rect::~Rect() {}
