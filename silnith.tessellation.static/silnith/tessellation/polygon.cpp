#include <silnith/tessellation/polygon.h>

using namespace silnith::tessellation;

polygon::polygon(std::initializer_list<vertex> _vertices) : vertices{ _vertices }
{
}

std::list<vertex> polygon::get_vertices(void) const
{
	return vertices;
}
