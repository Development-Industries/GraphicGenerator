
#include "Rectangle.h"

MyRectangle::MyRectangle(int width, int height, Point2D startPt, ConsoleColor color)
    : Shape(startPt, color), width(width), height(height) {
    Point2D topRight(startPt.x + width, startPt.y);
    Point2D bottomLeft(startPt.x, startPt.y + height);
    Point2D bottomRight(startPt.x + width, startPt.y + height);

     lines.emplace_back(Line(startPt, topRight, color));      // Top edge
     lines.emplace_back(Line(topRight, bottomRight, color));  // Right edge
     lines.emplace_back(Line(bottomRight, bottomLeft, color)); // Bottom edge
     lines.emplace_back(Line(bottomLeft, startPt, color));    // Left edge
}
void MyRectangle::Draw() const {
    for (const auto& line : lines) {
        line.Draw();

    }
}
