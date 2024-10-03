#pragma once
#include "Point2D.h"
#include "Shape.h"
#include "Line.h"
#include "Rectangle.h"  // Adjust the include if your rectangle class has a different name
#include "Triangle.h"
#include "Circle.h"
#include <memory>
#include <random>

class ShapeFactory {
public:
    static Point2D RandomPoint(int maxWidth, int maxHeight);
    static ConsoleColor RandomColor();
    static std::unique_ptr<Shape> RandomShape();
    static std::unique_ptr<Line> RandomLine(int maxWidth, int maxHeight);
    static std::unique_ptr<MyRectangle> RandomRectangle(int maxWidth, int maxHeight); // Use MyRectangle or your Rectangle class name
    static std::unique_ptr<Triangle> RandomTriangle(int maxWidth, int maxHeight);
    static std::unique_ptr<Circle> RandomCircle(int maxWidth, int maxHeight);
};

