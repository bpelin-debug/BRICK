// Default constructor
//tolga bozok
Ball::Ball()
{
    shape.center.x = 0;
    shape.center.y = 0;
    shape.radius = 1;

    speed.x = 0;
    speed.y = 0;
}

// Constructor (Circle + Point)
Ball::Ball(Circle shape, Point speed)
{
    this->shape = shape;
    this->speed = speed;
}

// Constructor (double ile)
Ball::Ball(double x, double y, double radius, double dx, double dy)
{
    shape.center.x = x;
    shape.center.y = y;
    shape.radius = radius;

    speed.x = dx;
    speed.y = dy;
}

// Getters
Circle Ball::get_shape() const
{
    return shape;
}

Point Ball::get_speed() const
{
    return speed;
}

double Ball::get_x() const
{
    return shape.center.x;
}

double Ball::get_y() const
{
    return shape.center.y;
}

double Ball::get_radius() const
{
    return shape.radius;
}

double Ball::get_dx() const
{
    return speed.x;
}

double Ball::get_dy() const
{
    return speed.y;
}

// Setters
void Ball::set_shape(Circle new_shape)
{
    shape = new_shape;
}

void Ball::set_speed(Point new_speed)
{
    speed = new_speed;
}

void Ball::set_x(double x)
{
    shape.center.x = x;
}

void Ball::set_y(double y)
{
    shape.center.y = y;
}

void Ball::set_radius(double radius)
{
    shape.radius = radius;
}

void Ball::set_dx(double dx)
{
    speed.x = dx;
}

void Ball::set_dy(double dy)
{
    speed.y = dy
