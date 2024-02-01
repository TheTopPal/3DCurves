#pragma once

#include <iostream>
#include <vector>
#include <memory>

enum CurveType
{
	Circle,
	Ellipse,
	Helix
};

struct Point3D
{
	double x;
	double y;
	double z;
};

static void PrintPoint(const Point3D& point)
{
	std::cout << "(" << point.x << ", " << point.y << ", " << point.z << ")\n";
}

template<class T>
void PrintPointsAndDerivatives(const std::vector<std::shared_ptr<T>>& v, double t)
{
	for (const auto& curve : v)
	{
		Point3D p = curve->GetPoint3D(t);
		Point3D d = curve->GetFirstDerivative(t);

		std::cout << "Coordinate: ";
		PrintPoint(p);
		std::cout << "Derivative: ";
		PrintPoint(d);
	}
}