#include <silnith/tessellation/vertex.h>

using namespace silnith::tessellation;

vertex::vertex(void) : x{ 0 }, y{ 0 }, z{ 0 }, w{ 1 }
{
}

vertex::vertex(double _x, double _y, double _z, double _w) : x{ _x }, y{ _y }, z{ _z }, w{ _w }
{
}

double vertex::get_x() const
{
	return x;
}

double vertex::get_y() const
{
	return y;
}

double vertex::get_z() const
{
	return z;
}

double vertex::get_w() const
{
	return w;
}

void vertex::set_x(double _x)
{
	x = _x;
}

void vertex::set_y(double _y)
{
	y = _y;
}

void vertex::set_z(double _z)
{
	z = _z;
}

void vertex::set_w(double _w)
{
	w = _w;
}
