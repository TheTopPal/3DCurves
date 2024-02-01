#define _USE_MATH_DEFINES

#include <cmath>
#include <ctime>
#include <algorithm>
#include "curves.h"

Point3D Curves::Circle::GetPoint3D(const double t) const
{
	return
	{
		radius * cos(t),
		radius * sin(t),
		0.0
	};
}

Point3D Curves::Circle::GetFirstDerivative(const double t) const
{
	return
	{
		radius * sin(t) * -1,
		radius * cos(t),
		0.0
	};
}

Point3D Curves::Ellipse::GetPoint3D(const double t) const
{
	return
	{
		radius_X * cos(t),
		radius_Y * sin(t),
		0.0
	};
}

Point3D Curves::Ellipse::GetFirstDerivative(const double t) const
{
	return
	{
		radius_X * sin(t) * -1,
		radius_Y * cos(t),
		0.0
	};
}

Point3D Curves::Helix::GetPoint3D(const double t) const
{
	return
	{
		radius * cos(t),
		radius * sin(t),
		(t * step) / (2 * M_PI)
	};
}

Point3D Curves::Helix::GetFirstDerivative(const double t) const
{
	return
	{
		radius * sin(t) * -1,
		radius * cos(t),
		step / (2 * M_PI)
	};
}

std::vector<std::shared_ptr<Curves::Curve>> Curves::FillFirstContainer(unsigned int n)
{
	srand(static_cast<unsigned int>(time(nullptr)));

	std::vector<std::shared_ptr<Curves::Curve>> allCurves;

	for (int i = 0; i < n; i++)
	{
		switch (rand() % 3)
		{
		case 0:
			allCurves.emplace_back(std::make_shared<Curves::Circle>(Curves::Circle(rand() % 100 + 1)));
			break;

		case 1:
			allCurves.emplace_back(std::make_shared<Curves::Ellipse>(Curves::Ellipse(rand() % 100 + 1, rand() % 100 + 1)));
			break;

		case 2:
			allCurves.emplace_back(std::make_shared<Curves::Helix>(Curves::Helix(rand() % 100 + 1, rand() % 10 + 1)));
			break;
		}
	}

	return allCurves;

}

std::vector<std::shared_ptr<Curves::Curve>> Curves::FillSecondContainer(std::vector<std::shared_ptr<Curves::Curve>>& allCurves)
{
	std::vector<std::shared_ptr<Curves::Curve>> circles;
	std::copy_if(allCurves.begin(), allCurves.end(), std::back_inserter(circles), [](const auto& el) { return el->GetTypeCurve() == CurveType::Circle; });

	return circles;
}

void Curves::SortContainer(std::vector<std::shared_ptr<Curves::Curve>>& circles)
{
	sort(circles.begin(), circles.end(), [](auto lhs, auto rhs)
		{
			return dynamic_cast<Curves::Circle*>(lhs.get())->GetRadius() < dynamic_cast<Curves::Circle*>(rhs.get())->GetRadius();
		});
}

unsigned int Curves::SumOfRadii(std::vector<std::shared_ptr<Curves::Curve>>& circles)
{
	unsigned int res = 0;

	for (auto el : circles)
	{
		res += dynamic_cast<Curves::Circle*>(el.get())->GetRadius();
	}

	return res;
}