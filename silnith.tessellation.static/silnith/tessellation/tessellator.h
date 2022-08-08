#pragma once

#include <list>
#include <silnith/tessellation/polygon.h>

namespace silnith
{
	namespace tessellation
	{
		class tessellator
		{
		public:
			std::list<polygon> tessellate(polygon polygon) const;
		};
	}
}
