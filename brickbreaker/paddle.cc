#include "paddle.h"

// Default constructor
Paddle::Paddle()
{
    shape.center.x = 0;
    shape.center.y = 0;
    shape.radius = 1;
}

// Constructor (Circle)
Paddle::Paddle(Circle shape)
{
    this->shape = shape;
}

// Constructor (double)
Paddle::Paddle(double x, double y, double radius)
{
    shape.center.x = x;
    shape.center.y = y;
    shape.radius = radius;
}

// Getter
Circle Paddle::get_shape() const
{
    return shape;
}

double Paddle::get_x() const
{
    return shape.center.x;
}

double Paddle::get_y() const
{
    return shape.center.y;
}

double Paddle::get_radius() const
{
    return shape.radius;
}

// Setters
void Paddle::set_shape(Circle new_shape)
{
    shape = new_shape;
}

void Paddle::set_x(double x)
{
    shape.center.x = x;
}

void Paddle::set_y(double y)
{
    shape.center.y = y;
}

void Paddle::set_radius(double radius)
{
    shape.radius = radius;
}
