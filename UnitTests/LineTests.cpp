#include "stdafx.h"
#include "CppUnitTest.h"

#include "../WeilerAtherton/Line.h"
#include "../WeilerAtherton/Point.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace WeilerAthertonAlgorithm;

namespace UnitTests
{

TEST_CLASS(LineTests)
{
public:

    TEST_METHOD(LineIntersection) {
        Line line1(0, 0, 4, 4);
        Line line2(0, 4, 4, 0);

        IntersectionPoint p = line1.findIntersection(line2);

        Assert::IsTrue(line2.isIntersecting(line1));
        Assert::AreEqual(Point(2, 2).x(), p.x());
        Assert::AreEqual(Point(2, 2).y(), p.y());
        Assert::IsFalse(p.isEntering());
    }
};
}
