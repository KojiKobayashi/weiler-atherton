#pragma once

#include "Point.h"

namespace WeilerAthertonAlgorithm {
	class Line {
		Point _A;
		Point _B;

		double _a1 = 0;
		double _b1 = 0;
		double _c1 = 0;

		void computeEquation();
	public:
		Line(const Point& A, const Point& B);
		const Point& A() const;
		const Point& B() const;
		void A(const Point& p) { _A = p; }
		void B(const Point& p) { _B = p; }
		Line(double x1, double y1, double x2, double y2);
		bool operator ==(const Line& l2) const;

		bool operator !=(const Line& l2) const;
		IntersectionPoint findIntersection(const Line& l) const;
		bool isIntersecting(const Line& b) const;
	};
}
