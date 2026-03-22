#ifndef PADDLE_H
#define PADDLE_H

#include "tools.h"

class Paddle
{
private:
    Circle shape;

public:
    Paddle();
    Paddle(Circle shape);
    Paddle(double x, double y, double radius);

    Circle get_shape() const;

    double get_x() const;
    double get_y() const;
    double get_radius() const;

    void set_shape(Circle new_shape);
    void set_x(double x);
    void set_y(double y);
    void set_radius(double radius);
};

#endif
