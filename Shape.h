#pragma once
#include "Point2D.h"
#include "Console.h"

class Shape {
private:
    Point2D startPt;  // Starting point of the shape


public:
    virtual ~Shape() = default;
    ConsoleColor color;  // Color of the shape 
    // Constructor that takes a Point2D and a color
    Shape(Point2D pt, ConsoleColor col);

    // Constructor that takes x and y coordinates and a color
    Shape(int x, int y, ConsoleColor col);

    // Getter for the starting point
    Point2D getStartPt() const;

    // Setter for the starting point
    void setStartPt(const Point2D& point);

    // Getter for the color
    ConsoleColor getColor() const;

    // Setter for the color - implementation is in Shapes.cpp
    void setColor(ConsoleColor col);

    // Virtual function to draw the shape - implementation is in Shapes.cpp
    virtual void Draw() const;
};