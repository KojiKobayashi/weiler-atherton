#include "stdafx.h"
#include "CppUnitTest.h"

#include "../WeilerAtherton/Point.h"
#include "../WeilerAtherton/Polygon.h"
#include "../WeilerAtherton/WeilerAtherton.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace WeilerAthertonAlgorithm;

namespace UnitTests
{

TEST_CLASS(WeilerAthertonTests)
{
public:

    TEST_METHOD(PolygonIntersection1) {
        Polygon p;
        p.addPoint(Point(-3, -3));
        p.addPoint(Point(-3, 3));
        p.addPoint(Point(1, 0));

        Polygon p1;
        p1.addPoint(Point(-1, 0));
        p1.addPoint(Point(3, 3));
        p1.addPoint(Point(3, -3));

        auto res = WeilerAtherton().process(p, p1);
        Assert::IsTrue(!res.empty());
    }

    TEST_METHOD(PolygonIntersection2) {
        Polygon p;
        p.addPoint(Point(-2, 1));
        p.addPoint(Point(2, 1));
        p.addPoint(Point(2, -1));
        p.addPoint(Point(-2, -1));

        Polygon p1;
        p1.addPoint(Point(-1, 2));
        p1.addPoint(Point(1, 2));
        p1.addPoint(Point(1, -2));
        p1.addPoint(Point(-1, -2));
        auto res = WeilerAtherton().process(p, p1);

        Assert::IsTrue(!res.empty());
    }

    TEST_METHOD(PolygonIntersection3) {
        Polygon p1;
        p1.addPoint(Point(0, -1));
        p1.addPoint(Point(0, 0));
        p1.addPoint(Point(1, 1));
        p1.addPoint(Point(2, 0));
        p1.addPoint(Point(3, 1));
        p1.addPoint(Point(4, 0));
        p1.addPoint(Point(5, 1));
        p1.addPoint(Point(6, 0));
        p1.addPoint(Point(6, -1));

        Polygon p2;
        p2.addPoint(Point(0, 0.5));
        p2.addPoint(Point(0, 3));
        p2.addPoint(Point(6, 3));
        p2.addPoint(Point(6, 0.5));
        auto res = WeilerAtherton().process(p1, p2);

        Assert::IsTrue(!res.empty());
    }

    TEST_METHOD(ContainsAnotherPolygonTest) {
        Polygon p1;
        p1.addPoint(Point(2, 2));
        p1.addPoint(Point(2, -2));
        p1.addPoint(Point(-2, -2));
        p1.addPoint(Point(-2, 2));

        Polygon p2;
        p2.addPoint(Point(1, 1));
        p2.addPoint(Point(1, -1));
        p2.addPoint(Point(-1, -1));
        p2.addPoint(Point(-1, 1));

        auto res = WeilerAtherton().process(p1, p2);
        Assert::AreEqual(1U, res.size());

        res = WeilerAtherton().process(p2, p1);
        Assert::AreEqual(1U, res.size());
    }

    TEST_METHOD(ContainsSamePointsTest) {
        Polygon p1;
        p1.addPoint(Point(0, 2));
        p1.addPoint(Point(1, 1));
        p1.addPoint(Point(0, 0));
        p1.addPoint(Point(-1, -1));

        Polygon p2;
        p2.addPoint(Point(1, 1));
        p2.addPoint(Point(1, -1));
        p2.addPoint(Point(-1, -1));
        p2.addPoint(Point(-1, 1));

        auto res = WeilerAtherton().process(p1, p2);
        Assert::AreEqual(1U, res.size());
    }
};
}