#pragma once

#include <vector>
#include <silnith/tessellation/vertex.h>

namespace silnith
{
	namespace tessellation
	{
		/// <summary>
		/// A polygon.
		/// </summary>
		/// <remarks>
		/// <para>A polygon may have an arbitrary number of sides.</para>
		/// </remarks>
		class polygon
		{
		public:
			/// <summary>
			/// Creates a polygon with no vertices.
			/// </summary>
			polygon(void);

			/// <summary>
			/// Creates a polygon from the provided list of vertices.
			/// </summary>
			/// <param name="vertices">The polygon vertices.</param>
			polygon(std::initializer_list<vertex> vertices);

			/// <summary>
			/// Returns the vertices of the polygon.
			/// </summary>
			/// <remarks>
			/// <para>The returned vertices are a copy.  Modifying them will not affect the polygon.</para>
			/// </remarks>
			/// <returns>A copy of the vertices of the polygon.</returns>
			std::vector<vertex> get_vertices(void) const;

			/// <summary>
			/// Sets the vertices for the polygon.
			/// </summary>
			/// <remarks>
			/// <para>The vertices are latched during execution of the method.  Subsequent modifications to the parameter will not affect the polygon.</para>
			/// </remarks>
			/// <param name="vertices">The new vertices for the polygon.</param>
			void set_vertices(std::vector<vertex> vertices);

			/// <summary>
			/// Adds a vertex to the polygon.
			/// </summary>
			/// <remarks>
			/// <para>The new vertex is appended to the existing list of vertices.</para>
			/// </remarks>
			/// <param name="vertex">The new vertex for the polygon.</param>
			void add_vertex(vertex vertex);

		private:
			std::vector<vertex> vertices;
		};
	}
}
