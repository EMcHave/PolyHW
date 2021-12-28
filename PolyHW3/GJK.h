#pragma once
#include <vector>
#include <cmath>
#include <limits>
#include <initializer_list>
#include "vector3.h"

namespace Geometry 
{
	class Figure {
	private:
		static bool handleSimplex(vector<vector3>&, vector3&);
		static bool lineCase(vector<vector3>&, vector3&);
		static bool triangleCase(vector<vector3>&, vector3&);
	public:
		static bool intersects(const Figure*, const Figure*);
		static vector3 support(const Figure*, const Figure*, vector3&);
		virtual vector3 furthestPoint(const vector3& d) const = 0;
		virtual ~Figure();
	};

	class Polygon : public Figure
	{
	protected:
		vector<vector3> vertices;
	public:
		Polygon();
		Polygon(vector<float>&);
		virtual vector3 furthestPoint(const vector3&) const override;
		~Polygon();
	};

	class Circle : public Figure
	{
	private:
		float r;
		vector3 center;
	public:
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
}


