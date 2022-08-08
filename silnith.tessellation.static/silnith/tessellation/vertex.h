#pragma once

namespace silnith
{
	namespace tessellation
	{
		class vertex
		{
		public:
			vertex(void);
			vertex(double x, double y, double z, double w);

			double get_x() const;
			double get_y() const;
			double get_z() const;
			double get_w() const;

			void set_x(double x);
			void set_y(double y);
			void set_z(double z);
			void set_w(double w);

		private:
			double x;
			double y;
			double z;
			double w;
		};
	}
}
