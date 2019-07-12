#pragma once

#include "Polygon.h"

namespace  WeilerAthertonAlgorithm {
	class WeilerAtherton {
	public:
        std::list<Polygon> process(const Polygon& subject, const Polygon& clipping) const;
	private:
		static Point doWalk(const std::list<Point>& enteringPoints, const std::list<Point>& exitingPoints, const std::list<Point>& walking_points, const Point& start, Polygon& pol);
		double distance(const Point& p, const Point& q) const;
		void addPointInPlace(const Line& line, const IntersectionPoint& ip, std::list<Point>& list) const;
	};
}
