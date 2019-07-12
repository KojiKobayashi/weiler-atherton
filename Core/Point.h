#pragma once

namespace WeilerAthertonAlgorithm {
	class Point	{
		double _x;
		double _y;
		//double max_double = std::numeric_limits<double>::max();
	public:
        Point();
        Point(double x, double y);
		double x() const;
		double y() const;
		bool operator==(const Point& p) const;
		bool operator!=(const Point& p) const;
	};

	class IntersectionPoint : public Point {
		bool _entering;
		bool _isIntersectionPoint;
	public:
		IntersectionPoint();
		IntersectionPoint(double x, double y);
		IntersectionPoint(double x, double y, bool isEntering);
		bool isEntering() const;
		bool isValid() const;
	};
}