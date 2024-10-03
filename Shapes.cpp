#include "Shape.h"
#include <iostream>
Shape::Shape(Point2D pt, ConsoleColor col) : startPt(pt), color(col) {}
Shape::Shape(int x, int y, ConsoleColor col) : startPt(x, y), color(col) {}

Point2D Shape::getStartPt() const {
    return startPt;
}

void Shape::setStartPt(const Point2D& point) {
    startPt = point;
}

ConsoleColor Shape::getColor() const {
    return color;
}

void Shape::setColor(ConsoleColor col) {
    color = col;
}

void Shape::Draw() const {
    Console::SetBackgroundColor(color);
    Console::SetCursorPosition(startPt.x, startPt.y);
    std::cout << " "; // Print a space
    Console::ResetColor();
}