#pragma once
#include "Shape.h"
#include "Line.h"
#include "Point2D.h"
#include <vector>

class Triangle : public Shape {
private:
    Point2D p2;
    Point2D p3;
    std::vector<Line> lines;

public:
    Triangle(const Point2D& startPt, const Point2D& p2, const Point2D& p3, ConsoleColor color);

    void Draw() const override;
};
