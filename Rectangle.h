#pragma once
#include "Shape.h"
#include "Line.h"
#include <vector>

class MyRectangle : public Shape {
private:
    int width;
    int height;
    std::vector<Line> lines;

public:
    MyRectangle(int width, int height, Point2D startPt, ConsoleColor color);

    void Draw() const override;
};
