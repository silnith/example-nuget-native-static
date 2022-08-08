#pragma once

namespace silnith
{
	namespace tessellation
	{
		class vertex
		{
		public:
			vertex(double x, double y, double z, double w);

			double get_x() const;
			double get_y() const;
			double get_z() const;
			double get_w() const;

		private:
			double x;
			double y;
			double z;
			double w;
		};
	}
}
