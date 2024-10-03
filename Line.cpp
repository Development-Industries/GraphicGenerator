#include "Line.h"
#include "Console.h"  // Ensure Console class is included for SetCursorPosition
#include <cmath>
#include <iostream>

Line::Line(Point2D startPt, Point2D endPt, ConsoleColor color)
    : Shape(startPt, color), endPt(endPt) {}

void Line::Draw() const {
    Console::SetForegroundColor(Red);  // Set the line color (ensure ConsoleColor is handled in Console)
    PlotLine(getStartPt().x, getStartPt().y, endPt.x, endPt.y);
    std::cout.flush();
}

void Line::PlotLine(int x0, int y0, int x1, int y1) const {
    for (int x = x0; x <= x1; ++x) {
        Console::SetCursorPosition(x, y0);
        std::cout << "X";  // Change " " to "X" for visibility
        std::cout.flush();
    }

    while (true)
        Console::SetCursorPosition(x0, y0);
        std::cout << " ";  // Plot the point
        std::cout.flush();  // Ensure the output is rend
    }
