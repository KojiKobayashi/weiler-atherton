#include "WeilerAtherton.h"

using namespace WeilerAthertonAlgorithm;

template <class T>
bool listContains(std::list<T> list, T value) {
	return std::find(list.begin(), list.end(), value) != list.end();
}

std::list<Polygon> WeilerAtherton::process(const Polygon & in_subject, const Polygon & in_clipping) const {
    std::list<Polygon> result;
    Polygon subject(in_subject), clipping(in_clipping);
    if (subject.lines().size() < 3 || clipping.lines().size() < 3) {
        return result;
    }

    if (!subject.isClockwiseOriented()) {
        subject.reverse();
    }
    if (!clipping.isClockwiseOriented()) {
        clipping.reverse();
    }

    std::list<Point> subj_points(subject.points());
    std::list<Point> clip_points(clipping.points());
    std::list<Point> entering_points;
    std::list<Point> exiting_points;

    for (auto&& subj_line : subject.lines()) {
        for (auto&& clip_line : clipping.lines()) {
            IntersectionPoint ip = subj_line.findIntersection(clip_line);
            if (ip.isValid()) {
                if (ip.isEntering()) {
                    entering_points.push_back(ip);
                }
                else {
                    exiting_points.push_back(ip);
                }
                addPointInPlace(subj_line, ip, subj_points);
                addPointInPlace(clip_line, ip, clip_points);
            }
        }
    }

    for (auto iter_entering_points = entering_points.begin(); iter_entering_points != entering_points.end(); ++iter_entering_points) {
        Polygon pol;
        Point start = *iter_entering_points, next = start;

        do {
            next = doWalk(entering_points, exiting_points, subj_points, next, pol);
            next = doWalk(entering_points, exiting_points, clip_points, next, pol);
        } while (next != start);

        result.push_back(pol);
    }

    return result;
}

Point WeilerAtherton::doWalk(const std::list<Point>& enteringPoints, const std::list<Point>& exitingPoints, const std::list<Point>& walking_points, const Point& start, Polygon& pol) {
	auto iter = std::find(walking_points.begin(), walking_points.end(), start);

	while (true) {
		pol.addPoint(*iter++);

		if (iter == walking_points.end()) { // simulate circular list
			iter = walking_points.begin();
		}

		if (listContains<Point>(enteringPoints, *iter)) {
			break;
		}
		
		if (listContains<Point>(exitingPoints, *iter)) {
			break;
		}
	}
	return *iter;
}

double WeilerAtherton::distance(const Point& p, const Point& q) const {
	return std::sqrt((p.x() - q.x())*(p.x() - q.x()) +
		(p.y() - q.y())*(p.y() - q.y()));
}

void WeilerAtherton::addPointInPlace(const Line& line, const IntersectionPoint& ip, std::list<Point>& list) const {
	auto start = std::find(list.begin(), list.end(), line.A());
	auto end_line = std::find(list.begin(), list.end(), line.B());

	auto it = start;
	double dist_from_start = distance(ip, *it);

	while (it != end_line && it != list.end()) {
		if (distance(*it, *start) >= dist_from_start) {
			break;
		}
		++it;
	}
	list.insert(it, ip);
}
