#include "Point.h"

using namespace WeilerAthertonAlgorithm;

Point::Point() : _x(0), _y(0) {}

Point::Point(double x, double y) : _x(x), _y(y) {}

double Point::x() const {
	return _x;
}

double Point::y() const {
	return _y;
}

bool Point::operator==(const Point& p) const {
	return _x == p.x() && _y == p.y();
}

bool Point::operator!=(const Point& p) const {
	return !(*this == p);
}

IntersectionPoint::IntersectionPoint(): _entering(false), _isIntersectionPoint(false) {
}

IntersectionPoint::IntersectionPoint(double x, double y): Point(x, y), _entering(false), _isIntersectionPoint(false) {
}

IntersectionPoint::IntersectionPoint(double x, double y, bool isEntering): Point(x, y), _entering(isEntering), _isIntersectionPoint(true) {
}

bool IntersectionPoint::isEntering() const {
	return _entering;
}

bool IntersectionPoint::isValid() const {
	return _isIntersectionPoint;
}
