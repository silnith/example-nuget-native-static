#include <silnith/tessellation/vertex.h>

using namespace silnith::tessellation;

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
