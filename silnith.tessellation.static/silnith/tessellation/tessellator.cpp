#include <silnith/tessellation/tessellator.h>

using namespace silnith::tessellation;

std::vector<polygon> tessellator::tessellate(polygon const _polygon) const
{
	std::vector<vertex> vertices{ _polygon.get_vertices() };
	std::vector<vertex>::const_iterator iter{ vertices.cbegin() };
	std::vector<vertex>::const_iterator end{ vertices.cend() };

	if (iter == end)
	{
		throw std::exception{ "Polygon must have at least one vertex." };
	}
	vertex first{ *iter };
	iter++;

	if (iter == end)
	{
		throw std::exception{ "Polygon must have more than one vertex." };
	}
	vertex second{ *iter };
	iter++;

	if (iter == end)
	{
		throw std::exception{ "Polygon must have more than two vertices." };
	}

	std::vector<polygon> tessellated;
	do
	{
		vertex third{ *iter };

		tessellated.push_back(polygon{ first, second, third });

		second = third;
		iter++;
	} while (iter != end);

    return tessellated;
}
