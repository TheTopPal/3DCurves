#define _USE_MATH_DEFINES

#include <iostream>
#include <cmath>
#include <vector>
#include "curves.h"


int main(void)
{
	const int N = 10;

	auto all_curves = Curves::FillFirstContainer(N);

	std::cout << "Coordinates of points and derivatives of all curves at t= M_PI/4:\n";
	PrintPointsAndDerivatives(all_curves, M_PI / 4);
	std::cout << std::endl;

	auto circles = Curves::FillSecondContainer(all_curves);

	std::cout << "Sorting the circles in second container:\n";
	Curves::SortContainer(circles);
	PrintPointsAndDerivatives(circles, M_PI / 4);
	std::cout << std::endl;

	std::cout << "Sum of radii: " << Curves::SumOfRadii(circles) << std::endl;

	std::cin.get();

	return 0;
}