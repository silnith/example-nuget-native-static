#pragma once

namespace silnith
{
	namespace tessellation
	{
		/// <summary>
		/// A vertex in 3-space.
		/// </summary>
		/// <remarks>
		/// <para>Technically this is a point in 4-space that will be projected onto a 3-dimensional surface.</para>
		/// </remarks>
		class vertex
		{
		public:
			/// <summary>
			/// Creates a new vertex at the origin.
			/// </summary>
			vertex(void);

			/// <summary>
			/// Creates a new vertex.
			/// </summary>
			/// <param name="x">The X coordinate.</param>
			/// <param name="y">The Y coordinate.</param>
			/// <param name="z">The Z coordinate.</param>
			/// <param name="w">The W coordinate.  Normally should be <c>1</c>.</param>
			/// <example>
			/// <code>
			/// vertex origin{ 0, 0, 0 };
			/// </code>
			/// </example>
			vertex(double x, double y, double z, double w = 1);

			/// <summary>
			/// Returns the X coordinate.
			/// </summary>
			/// <returns>The X coordinate.</returns>
			double get_x() const;

			/// <summary>
			/// Returns the Y coordinate.
			/// </summary>
			/// <returns>The Y coordinate.</returns>
			double get_y() const;

			/// <summary>
			/// Returns the Z coordinate.
			/// </summary>
			/// <returns>The Z coordinate.</returns>
			double get_z() const;

			/// <summary>
			/// Returns the W coordinate.
			/// </summary>
			/// <remarks>
			/// <para>This is used for performing projections and perspective correction.  In normal situations, this will always be <c>1</c>.</para>
			/// </remarks>
			/// <returns>The W coordinate.</returns>
			double get_w() const;

			/// <summary>
			/// Sets the X coordinate.
			/// </summary>
			/// <param name="x">The new X coordinate.</param>
			void set_x(double x);

			/// <summary>
			/// Sets the Y coordinate.
			/// </summary>
			/// <param name="y">The new Y coordinate.</param>
			void set_y(double y);

			/// <summary>
			/// Sets the Z coordinate.
			/// </summary>
			/// <param name="z">The new Z coordinate.</param>
			void set_z(double z);

			/// <summary>
			/// Sets the W coordinate.
			/// </summary>
			/// <param name="w">The new W coordinate.</param>
			void set_w(double w);

		private:
			double x;
			double y;
			double z;
			double w;
		};
	}
}
