#include "GJK.h"


bool Simplex::intersects(Simplex& s1,Simplex& s2)
{
	vector3 d = vector3(0, 1);
	vector<vector3> simplex;
	simplex.push_back(support(s1, s2, d));
	d = vector3::origin() - simplex.at(0);
	while (true)
	{
		vector3 A = support(s1, s2, d);
		if (vector3::dot(A, d) < 0) return false;
		simplex.push_back(A);
		if (Simplex::handleSimplex(simplex, d)) return true;
	}
}

vector3 Simplex::support(const Simplex&, const Simplex&, const vector3&)
{
	return vector3();
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

Circle::Circle(float r, float cx, float cy) : r(r), center{ cx, cy } {}

vector3 Circle::furthestPoint(vector3&)
{
	return vector3();
}


Circle::~Circle()
{
}

Rect::Rect(float ax, float ay, float bx, float by)
{
	vertices.push_back(point{ ax, ay, 0 });
	vertices.push_back(point{ ax, by, 0 });
	vertices.push_back(point{ bx, by, 0 });
	vertices.push_back(point{ bx, ay, 0 });	
}

vector3 Rect::furthestPoint(vector3&)
{
	float max = -numeric_limits<float>::infinity();
	vector3 furthestPoint(0, 0, 0);

	return vector3();
}

Rect::~Rect()
{
}
