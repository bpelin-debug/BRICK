#ifndef TOOLS_H
#define TOOLS_H

constexpr double epsil_zero = 0.125;

struct Point {
	double x;
	double y;
};

struct Circle {
	Point center;
	double radius;
};

struct Square {
	Point center;
	double length;
};

double distance( Point a, Point b);

bool intersects_cc(const Circle& a, const Circle& b);
bool intersects_ss(const Square& a, const Square& b);
bool intersects_cs(const Circle& c, const Square& s);

bool include(const Square& square, const Circle& circle);


#endif

