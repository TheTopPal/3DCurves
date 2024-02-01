#pragma once

#include <memory>
#include <vector>
#include "common.h"

namespace Curves
{
	class Curve
	{
	public:
		virtual ~Curve()
		{

		}

		virtual Point3D GetPoint3D(const double t) const = 0;
		virtual Point3D GetFirstDerivative(const double t) const = 0;
		virtual CurveType GetTypeCurve() const = 0;
	};

	class Circle : public Curve
	{
	private:
		unsigned int radius;
		CurveType type;
	public:
		Circle(const unsigned int radius) : radius(radius), type(CurveType::Circle)
		{

		};

		Point3D GetPoint3D(const double t) const override;

		Point3D GetFirstDerivative(const double t) const override;

		CurveType GetTypeCurve() const override
		{
			return type;
		}

		unsigned int GetRadius() const
		{
			return radius;
		}

	};

	class Ellipse : public Curve
	{
	private:
		unsigned int radius_X;
		unsigned int radius_Y;
		CurveType type;
	public:
		Ellipse(const unsigned int radius_X, const unsigned int radius_Y) : radius_X(radius_X), radius_Y(radius_Y), type(CurveType::Ellipse)
		{

		};

		Point3D GetPoint3D(const double t) const override;

		Point3D GetFirstDerivative(const double t) const override;

		CurveType GetTypeCurve() const override
		{
			return type;
		}
	};

	class Helix : public Curve
	{
	private:
		unsigned int radius;
		unsigned int step;
		CurveType type;
	public:
		Helix(const unsigned int radius, const unsigned int step) : radius(radius), step(step), type(CurveType::Helix)
		{

		};

		Point3D GetPoint3D(const double t) const override;

		Point3D GetFirstDerivative(const double t) const override;

		CurveType GetTypeCurve() const override
		{
			return type;
		}
	};


	std::vector<std::shared_ptr<Curve>>  FillFirstContainer(unsigned int n);

	std::vector<std::shared_ptr<Curve>> FillSecondContainer(std::vector<std::shared_ptr<Curve>>& allCurves);

	void SortContainer(std::vector<std::shared_ptr<Curve>>& circles);

	unsigned int SumOfRadii(std::vector<std::shared_ptr<Curve>>& circles);
}