#include <stdexcept>
#include <silnith/tessellation/tessellator.h>

using namespace silnith::tessellation;

std::vector<polygon> tessellator::tessellate(polygon const _polygon) const
{
	std::vector<vertex> const vertices{ _polygon.get_vertices() };
	std::vector<vertex>::const_iterator iter{ vertices.cbegin() };
	std::vector<vertex>::const_iterator end{ vertices.cend() };

	if (iter == end)
	{
		throw std::invalid_argument{ "Polygon must have at least one vertex." };
	}
	vertex const first{ *iter };
	iter++;

	if (iter == end)
	{
		throw std::invalid_argument{ "Polygon must have more than one vertex." };
	}
	vertex second{ *iter };
	iter++;

	if (iter == end)
	{
		throw std::invalid_argument{ "Polygon must have more than two vertices." };
	}

	std::vector<polygon> tessellated{};
	tessellated.reserve(vertices.size() - 2);
	do
	{
		vertex const third{ *iter };

		tessellated.push_back(polygon{ first, second, third });

		second = third;
		iter++;
	} while (iter != end);

    return tessellated;
}
