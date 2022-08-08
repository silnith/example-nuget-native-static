#pragma once

#include <list>
#include <silnith/tessellation/vertex.h>

namespace silnith
{
	namespace tessellation
	{
		class polygon
		{
		public:
			polygon(std::list<vertex> vertices);

			std::list<vertex> get_vertices(void) const;

		private:
			std::list<vertex> vertices;
		};
	}
}
