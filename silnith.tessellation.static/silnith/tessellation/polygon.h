#pragma once

#include <vector>
#include <silnith/tessellation/vertex.h>

namespace silnith
{
	namespace tessellation
	{
		class polygon
		{
		public:
			polygon(void);
			polygon(std::initializer_list<vertex> vertices);

			std::vector<vertex> get_vertices(void) const;

			void set_vertices(std::vector<vertex> vertices);

			void add_vertex(vertex vertex);

		private:
			std::vector<vertex> vertices;
		};
	}
}
