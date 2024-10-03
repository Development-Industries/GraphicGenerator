#include <iostream>
#include "Console.h"
#include "Input.h"
#include <algorithm>
#include <memory>
#include "Tester.h"
#include "Point2D.h"
#include "Line.h"
#include <random>
#include "Rectangle.h"
#include "Triangle.h"
#include <Circle.h>
#include <ShapeFactory.h>


int main()
{
	Tester graphicsTest;
	srand((unsigned int)time(NULL)); //seed the random # generator

	Console::ResizeWindow(150, 30);

	int menuSelection = 0;
	std::vector<std::string> menuOptions{ "1. Draw Shape", "2. Draw Line", "3. Draw Rectangle", "4. Draw Triangle",  "5. Draw Circle", "6. Draw Random Shapes", "7. Exit" };

	do
	{
		Console::Clear();
		menuSelection = Input::GetMenuSelection(menuOptions);
		Console::Clear();

		switch (menuSelection)
		{
		case 1:
		{// Get the window dimensions
			int width = Console::GetWindowWidth();
			int height = Console::GetWindowHeight();

			// Generate a random point 
			Point2D randomPoint(rand() % width, rand() % height);

			// Create a Shape
			Shape shape(randomPoint, ConsoleColor::Red);

			// Draw the shape
			shape.Draw();

			break; 
		}

		case 2:
		{
			std::random_device rd;
			std::mt19937 eng(rd());
			std::uniform_int_distribution<> distrWidth(0, Console::GetWindowWidth() - 1);
			std::uniform_int_distribution<> distrHeight(0, Console::GetWindowHeight() - 1);

			Point2D startPt(distrWidth(eng), distrHeight(eng));
			Point2D endPt(distrWidth(eng), distrHeight(eng));

			ConsoleColor lineColor = ConsoleColor::Red; 
			Line line(startPt, endPt, lineColor);
			line.Draw();

			break;
		}

		case 3:
		{
			// Setup for random number generation
			std::random_device rd;
			std::mt19937 eng(rd());

			// Get the console window dimensions
			int maxWidth = Console::GetWindowWidth();
			int maxHeight = Console::GetWindowHeight();

			// Define distributions 
			std::uniform_int_distribution<> distrX(0, maxWidth - 10);  
			std::uniform_int_distribution<> distrY(0, maxHeight - 10); 
			std::uniform_int_distribution<> distrWidth(5, maxWidth - distrX(eng) - 1);  // Adjust width based on X
			std::uniform_int_distribution<> distrHeight(5, maxHeight - distrY(eng) - 1); // Adjust height based on Y

			// Generate the top-left point
			Point2D topLeft(distrX(eng), distrY(eng));

			// Generate the width and height ensuring they don't extend beyond console bounds
			int width = distrWidth(eng);
			int height = distrHeight(eng);

			// Create the rectangle instance and draw it
		 MyRectangle rectangle(width, height, topLeft, ConsoleColor::Red);
		 rectangle.Draw();

			break;
		}

		case 4:
		{
			std::random_device rd;
			std::mt19937 eng(rd());
			std::uniform_int_distribution<> distrX(0, Console::GetWindowWidth() - 1);
			std::uniform_int_distribution<> distrY(0, Console::GetWindowHeight() - 1);

			// Generate 3 random points
			Point2D p1(distrX(eng), distrY(eng));
			Point2D p2(distrX(eng), distrY(eng));
			Point2D p3(distrX(eng), distrY(eng));

			// Create a Triangle instance and draw it
			Triangle triangle(p1, p2, p3, ConsoleColor::Green); 
			triangle.Draw();

			break;
		}
		case 5:
		{
			// Generate random coordinates for the center of the circle
			std::random_device rd;
			std::mt19937 eng(rd());
			std::uniform_int_distribution<> distrX(10, Console::GetWindowWidth() - 10);  // Ensure the circle stays within bounds
			std::uniform_int_distribution<> distrY(10, Console::GetWindowHeight() - 10);

			// Generate random coordinates for the center
			int x_coordinate = distrX(eng);
			int y_coordinate = distrY(eng);

			// Create a Point2D object with the random coordinates
			Point2D center(x_coordinate, y_coordinate);

			// Generate a random radius for the circle
			std::uniform_int_distribution<> distrRadius(1, 8);  // Adjust max radius as needed
			int radius = distrRadius(eng);

			// Create the Circle object with the generated parameters
			auto circle = std::make_unique<Circle>(radius, center, ConsoleColor::Green);
			circle->Draw();


			break;
		}


		case 6:
		{
			// Create a vector to hold unique_ptr of Shapes
			std::vector<std::unique_ptr<Shape>> shapes;

			// Get the console window dimensions
			int maxWidth = Console::GetWindowWidth();
			int maxHeight = Console::GetWindowHeight();

			// Create 100 random Shapes and add them to the vector
			for (int i = 0; i < 100; ++i) {
				// Randomly pick which type of Shape to create
				int shapeType = rand() % 5; // Assuming there are 5 types of shapes

				// Create the instance according to its shape type
				std::unique_ptr<Shape> shape;
				switch (shapeType) {
				case 0:
					shape = ShapeFactory::RandomShape();
					break;
				case 1:
					shape = ShapeFactory::RandomLine(maxWidth, maxHeight);
					break;
				case 2:
					shape = ShapeFactory::RandomRectangle(maxWidth, maxHeight);
					break;
				case 3:
					shape = ShapeFactory::RandomTriangle(maxWidth, maxHeight);
					break;
				case 4:
					shape = ShapeFactory::RandomCircle(maxWidth, maxHeight);
					break;
				default:
					// Handle default case (optional)
					break;
				}

				// Add the created shape to the vector
				shapes.push_back(std::move(shape));
			}

			// Loop over the shapes vector and call Draw on each shape
			for (const auto& shape : shapes) {
				shape->Draw();
			}

			break;
		}
		default:
			break;


		}

		Input::PressEnter(true);

	} while (menuSelection != menuOptions.size());
}