#pragma once
#include "Point2D.h"
#include "Console.h"  // Ensure this header defines ConsoleColor and necessary console functions
#include "Shape.h"

class Line : public Shape {
private:
    Point2D endPt;  // Endpoint of the line, startPt is inherited from Shape

public:
    Line(Point2D startPt, Point2D endPt, ConsoleColor color);

    void Draw() const override;  // Override Shape's Draw method
    void PlotLine(int x0, int y0, int x1, int y1) const;
};