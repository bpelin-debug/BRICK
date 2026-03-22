#include "tools.h"
#include <cmath>


double distance(Point a, Point b){
	double dist_x;
	double dist_y;
	dist_x = a.x - b.x;
	dist_y = a.y - b.y;
	return std::sqrt(dist_x*dist_x + dist_y*dist_y);
}

bool intersects_cc(const Circle& a, const Circle& b){
	double d( distance(a.center,b.center));
	return ( d < (a.radius + b.radius + epsil_zero));

}

bool intersects_ss(const Square& a, const Square& b){
	double s1(a.length / 2);
	double s2(b.length / 2);
	bool separated =
	(a.center.x + s1 < b.center.x - s2 - epsil_zero) or
    (a.center.x - s1 > b.center.x + s2 + epsil_zero) or
    (a.center.y + s1 < b.center.y - s2 - epsil_zero) or
    (a.center.y - s1 > b.center.y + s2 + epsil_zero);
    return !separated; 
} // inspired by chapgpt burayi chatten aldim degistirebilirsen degisir.

bool intersects_cs(const Circle& c, const Square& s){
	double s1(s.length/2);
	double x_min(c.center.x);
	double y_min(c.center.y);
	
	double l(s.center.x - s1);
	double r(s.center.x + s1);
	double t(s.center.y + s1);
	double b(s.center.y - s1); // karenin sol sag alt ustteki x y degerleri
	
	if (c.center.x < l){ // dairenin otrasinin x i karenin sol tarafinin konumundan kucukse yani karenin solundaysa daireye en yakin x kareni solu
		x_min = l;
	} else if (c.center.x > r){
		 x_min= r;
	}
	
	if (c.center.y < b){
		y_min = b;
	} else if (c.center.y > t){
		y_min = t;
	}
	
	Point closest_point = {x_min, y_min};
	
	
	return distance(c.center,closest_point) < (c.radius + epsil_zero); // bu kodu daha iyilestirebiliyosan iyillestir
}
	

bool include(const Square& s, const Circle& c){
	double s1 (s.length / 2.);
	
	double l(s.center.x - s1);
	double r(s.center.x + s1);
	double t(s.center.y + s1);
	double b(s.center.y - s1); 
	
	if (c.center.x - c.radius <= l + epsil_zero){ return false;}
	if (c.center.x + c.radius >= r - epsil_zero){ return false;}
	if (c.center.y + c.radius >= t - epsil_zero){ return false;}
	if (c.center.y - c.radius <= b + epsil_zero){ return false;}
	
	return true;
}

	
	
	
	

	
	
	
	
	
	
