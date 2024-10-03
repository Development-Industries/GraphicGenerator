#include "Circle.h"
#include "Console.h"
#include <iostream>  // For std::cout

Circle::Circle(int radius, const Point2D& center, ConsoleColor color)
    : Shape(center, color), radius(radius) {}

    int Circle::getRadius() const { return radius; }
void Circle::setRadius(int r) { radius = r; }

void Circle::Draw() const {
    Console::SetBackgroundColor(getColor());
    DrawCircle(getStartPt().x, getStartPt().y, radius);
    Console::ResetColor();
}

void Circle::DrawCirclePoints(int xc, int yc, int x, int y) const {
    // Replace Plot calls with actual console plotting
    Console::SetCursorPosition(xc + x, yc + y); std::cout << " ";
    Console::SetCursorPosition(xc - x, yc + y); std::cout << " ";
    Console::SetCursorPosition(xc + x, yc - y); std::cout << " ";
    Console::SetCursorPosition(xc - x, yc - y); std::cout << " ";
    Console::SetCursorPosition(xc + y, yc + x); std::cout << " ";
    Console::SetCursorPosition(xc - y, yc + x); std::cout << " ";
    Console::SetCursorPosition(xc + y, yc - x); std::cout << " ";
    Console::SetCursorPosition(xc - y, yc - x); std::cout << " ";
}

void Circle::DrawCircle(int xc, int yc, int r) const {
    int x = 0, y = r, d = 3 - 2 * r;
    DrawCirclePoints(xc, yc, x, y);
    while (y >= x) {
        x++;
        if (d > 0) {
            y--;
            d = d + 4 * (x - y) + 10;
        } else {
            d = d + 4 * x + 6;
        }
        DrawCirclePoints(xc, yc, x, y);
    }
}
