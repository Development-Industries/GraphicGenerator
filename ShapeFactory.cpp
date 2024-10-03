#include "ShapeFactory.h"

Point2D ShapeFactory::RandomPoint(int maxWidth, int maxHeight) {
    std::random_device rd;
    std::mt19937 eng(rd());
    std::uniform_int_distribution<> distrX(0, maxWidth);
    std::uniform_int_distribution<> distrY(0, maxHeight);
    return Point2D(distrX(eng), distrY(eng));
}

ConsoleColor ShapeFactory::RandomColor() {
    std::random_device rd;
    std::mt19937 eng(rd());
    std::uniform_int_distribution<> distr(0, static_cast<int>(ConsoleColor::Cyan) - 1);
    return static_cast<ConsoleColor>(distr(eng));
}

std::unique_ptr<Shape> ShapeFactory::RandomShape() {
    // Example: Returns a random point as a Shape
    return std::make_unique<Shape>(RandomPoint(100, 100), RandomColor());
}

std::unique_ptr<Line> ShapeFactory::RandomLine(int maxWidth, int maxHeight) {
    return std::make_unique<Line>(RandomPoint(maxWidth, maxHeight), RandomPoint(maxWidth, maxHeight), RandomColor());
}

std::unique_ptr<MyRectangle> ShapeFactory::RandomRectangle(int maxWidth, int maxHeight) {
    auto topLeft = RandomPoint(maxWidth - 10, maxHeight - 10); // Ensure there's space for the rectangle
    return std::make_unique<MyRectangle>(5, 5, topLeft, RandomColor()); // Fixed size for simplicity
}

std::unique_ptr<Triangle> ShapeFactory::RandomTriangle(int maxWidth, int maxHeight) {
    return std::make_unique<Triangle>(RandomPoint(maxWidth, maxHeight), RandomPoint(maxWidth, maxHeight), RandomPoint(maxWidth, maxHeight), RandomColor());
}

std::unique_ptr<Circle> ShapeFactory::RandomCircle(int maxWidth, int maxHeight) {
    auto center = RandomPoint(maxWidth, maxHeight);
    std::random_device rd;
    std::mt19937 eng(rd());
    std::uniform_int_distribution<> distrRadius(1, 10); // Example radius range
    return std::make_unique<Circle>(center, RandomColor(), distrRadius(eng));
}
