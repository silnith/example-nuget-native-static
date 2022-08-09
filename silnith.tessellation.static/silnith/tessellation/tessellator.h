#pragma once

#include <vector>
#include <silnith/tessellation/polygon.h>

namespace silnith
{
	namespace tessellation
	{
		/// <summary>
		/// A tessellator capable of converting multi-sided polygons into triangles.
		/// </summary>
		class tessellator
		{
		public:
			/// <summary>
			/// Tessellates an arbitrary polygon into a triangle fan.
			/// </summary>
			/// <remarks>
			/// <para>No attempt is made to correct concave polygons.  Concave polygons may produce triangles that reverse the winding order.</para>
			/// <para>No checking is done to verify all vertices in the polygon are planar.</para>
			/// </remarks>
			/// <param name="polygon">A polygon with any number of vertices.</param>
			/// <returns>A <c>vector</c> of polygons, each with exactly three vertices.</returns>
			/// <exception cref="std::invalid_argument">If <paramref name="polygon"/> has fewer than three vertices.</exception>
			std::vector<polygon> tessellate(polygon const polygon) const;
		};
	}
}
