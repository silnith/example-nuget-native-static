#include <silnith/tessellation/tessellator.h>

using namespace silnith::tessellation;

std::list<polygon> tessellator::tessellate(polygon _polygon) const
{
	std::list<vertex> vertices{ _polygon.get_vertices() };
	std::list<vertex>::const_iterator iter{ vertices.cbegin() };

	if (iter == vertices.cend())
	{
		throw std::exception{ "Polygon must have at least one vertex." };
	}
	vertex first{ *iter };
	iter++;

	if (iter == vertices.cend())
	{
		throw std::exception{ "Polygon must have more than one vertex." };
	}
	vertex second{ *iter };
	iter++;

	if (iter == vertices.cend())
	{
		throw std::exception{ "Polygon must have more than two vertices." };
	}

	std::list<polygon> tessellated;
	do
	{
		vertex third{ *iter };

		tessellated.push_back(std::list<vertex>{first, second, third});

		second = third;
		iter++;
	} while (iter != vertices.cend());

    return tessellated;
}
