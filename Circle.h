#pragma once

#include "Point2D.h"
#include "Shape.h"
#include "Console.h"

class Circle : public Shape {
private:
    int radius;

public:
        Circle(int radius, const Point2D& center, ConsoleColor color);


    int getRadius() const;
    void setRadius(int r);

    void Draw() const override;

private:
    void DrawCirclePoints(int xc, int yc, int x, int y) const;
    void DrawCircle(int xc, int yc, int r) const;

        Point2D center;
        ConsoleColor color;
};
 