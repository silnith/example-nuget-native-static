#include "CppUnitTest.h"

#include <vector>
#include <silnith/tessellation/tessellator.h>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace silnith::tessellation::tests
{
	TEST_CLASS(tessellator_tests)
	{
	public:
		
		TEST_METHOD(test_tessellate)
		{
			// arrange
			tessellator tessellator{};

			vertex bottom_left{ 10, 10, 0, 1 };
			vertex top_left{ 20, 21, 0, 1 };
			vertex top_right{ 31, 31, 0, 1 };
			vertex bottom_right{ 41, 40, 0, 1 };

			polygon square{ bottom_left, top_left, top_right, bottom_right };

			// act
			std::vector<polygon> result{ tessellator.tessellate(square) };

			// assert
			Assert::AreEqual(static_cast<std::vector<polygon>::size_type>(2), result.size());

			std::vector<vertex> first_vertices{ result[0].get_vertices() };

			Assert::AreEqual(static_cast<std::vector<vertex>::size_type>(3), first_vertices.size());

			vertex one{ first_vertices[0] };
			vertex two{ first_vertices[1] };
			vertex three{ first_vertices[2] };

			Assert::AreEqual(bottom_left.get_x(), one.get_x(), epsilon);
			Assert::AreEqual(bottom_left.get_y(), one.get_y(), epsilon);
			Assert::AreEqual(bottom_left.get_z(), one.get_z(), epsilon);

			Assert::AreEqual(top_left.get_x(), two.get_x(), epsilon);
			Assert::AreEqual(top_left.get_y(), two.get_y(), epsilon);
			Assert::AreEqual(top_left.get_z(), two.get_z(), epsilon);

			Assert::AreEqual(top_right.get_x(), three.get_x(), epsilon);
			Assert::AreEqual(top_right.get_y(), three.get_y(), epsilon);
			Assert::AreEqual(top_right.get_z(), three.get_z(), epsilon);

			std::vector<vertex> second_vertices{ result[1].get_vertices() };

			Assert::AreEqual(static_cast<std::vector<vertex>::size_type>(3), second_vertices.size());

			vertex four{ second_vertices[0] };
			vertex five{ second_vertices[1] };
			vertex six{ second_vertices[2] };

			Assert::AreEqual(bottom_left.get_x(), four.get_x(), epsilon);
			Assert::AreEqual(bottom_left.get_y(), four.get_y(), epsilon);
			Assert::AreEqual(bottom_left.get_z(), four.get_z(), epsilon);

			Assert::AreEqual(top_right.get_x(), five.get_x(), epsilon);
			Assert::AreEqual(top_right.get_y(), five.get_y(), epsilon);
			Assert::AreEqual(top_right.get_z(), five.get_z(), epsilon);

			Assert::AreEqual(bottom_right.get_x(), six.get_x(), epsilon);
			Assert::AreEqual(bottom_right.get_y(), six.get_y(), epsilon);
			Assert::AreEqual(bottom_right.get_z(), six.get_z(), epsilon);
		}

	private:
		const double epsilon = 0.001;
	};
}
