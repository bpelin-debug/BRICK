#ifndef BALL_H
#define BALL_H

#include "tools.h"

class Ball
{
private:
    Circle shape;
    Point speed;

public:
    Ball();
    Ball(Circle shape, Point speed);
    Ball(double x, double y, double radius, double dx, double dy);

    Circle get_shape() const;
    Point get_speed() const;

    double get_x() const;
    double get_y() const;
    double get_radius() const;
    double get_dx() const;
    double get_dy() const;

    void set_shape(Circle new_shape);
    void set_speed(Point new_speed);
    void set_x(double x);
    void set_y(double y);
    void set_radius(double radius);
    void set_dx(double dx);
    void set_dy(double dy);
};

#endif
