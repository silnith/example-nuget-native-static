#pragma once

#include <vector>
#include <silnith/tessellation/polygon.h>

namespace silnith
{
	namespace tessellation
	{
		class tessellator
		{
		public:
			std::vector<polygon> tessellate(polygon const polygon) const;
		};
	}
}
