#include <silnith/tessellation/polygon.h>

using namespace silnith::tessellation;

polygon::polygon(void) : vertices{ static_cast<std::vector<vertex>::size_type>(3) }
{
}

polygon::polygon(std::initializer_list<vertex> _vertices) : vertices{ _vertices }
{
}

std::vector<vertex> polygon::get_vertices(void) const
{
	return vertices;
}

void polygon::set_vertices(std::vector<vertex> _vertices)
{
	vertices = _vertices;
}

void polygon::add_vertex(vertex _vertex)
{
	vertices.push_back(_vertex);
}
