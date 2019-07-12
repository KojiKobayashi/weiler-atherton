#include "stdafx.h"
#include "CppUnitTest.h"

#include "../Core/Point.h"
#include "../Core/Polygon.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace WeilerAthertonAlgorithm;

namespace UnitTests
{

TEST_CLASS(PlolygonTests)
{
public:

    TEST_METHOD(AddPolygonPoint) {
        Polygon	p;
        p.addPoint(Point(0, 0));
        p.addPoint(Point(0, 0));
        Assert::AreEqual(p.points().size(), static_cast<size_t>(2));
    }

    TEST_METHOD(PolygonSelfintersection) {
        Polygon p;
        p.addPoint(Point(0, 0));
        p.addPoint(Point(0, 1));
        p.addPoint(Point(1, 0));
        Assert::IsFalse(p.isSelfIntersecting());

        p.addPoint(Point(1, 1));
        Assert::IsTrue(p.isSelfIntersecting());
    }

    TEST_METHOD(PolygonClockwiseOrientation) {
        Polygon p;
        p.addPoint(Point(0, 0));
        p.addPoint(Point(0, 1));
        p.addPoint(Point(1, 0));
        Assert::IsTrue(p.isClockwiseOriented());

        Polygon p1;
        p1.addPoint(Point(1, 0));
        p1.addPoint(Point(0, 1));
        p1.addPoint(Point(0, 0));
        Assert::IsFalse(p1.isClockwiseOriented());
    }
};
}
