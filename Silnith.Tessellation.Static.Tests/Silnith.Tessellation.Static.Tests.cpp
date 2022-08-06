#include "CppUnitTest.h"

#include <silnith/tessellation/tessellator.h>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace silnith::tessellation::tests
{
	TEST_CLASS(SilnithTessellationStaticTests)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			tessellator tessellator{};

			vertex bottom_left{ 0, 0, 0, 1 };
			vertex top_left{ 0, 1, 0, 1 };
			vertex top_right{ 1, 1, 0, 1 };
			vertex bottom_right{ 1, 0, 0, 1 };

			std::list<polygon> result{ tessellator.tessellate(polygon{ std::list<vertex>{bottom_left, top_left, top_right, bottom_right} }) };

			Assert::AreEqual(static_cast<size_t>(2), result.size());
		}
	};
}
