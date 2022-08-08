#include <silnith/tessellation/polygon.h>

using namespace silnith::tessellation;

polygon::polygon(std::list<vertex> _vertices) : vertices{ _vertices }
{
}

std::list<vertex> polygon::get_vertices(void) const
{
	return vertices;
}
