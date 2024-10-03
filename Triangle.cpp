#include "Triangle.h"

Triangle::Triangle(const Point2D& startPt, const Point2D& p2, const Point2D& p3, ConsoleColor color)
    : Shape(startPt, color), p2(p2), p3(p3) {
    lines.emplace_back(Line(startPt, p2, color)); // Line from p1 to p2
    lines.emplace_back(Line(p2, p3, color));     // Line from p2 to p3
    lines.emplace_back(Line(p3, startPt, color)); // Line from p3 to p1
}


void Triangle::Draw() const {
    for (const auto& line : lines) {
        line.Draw();
    }
}
