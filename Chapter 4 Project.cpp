// Chapter 4 Project.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <iomanip>
using namespace std;

int main()
{

    // Program 1 : Days in a Month Program
    int month, year;
    std::cout << "Please enter the month usng integers 1-12: " << "\n";
    std::cin >> month;
    std::cout << "Please enter the year: " << "\n";
    std::cin >> year;
    //determines how many days are in each month
    if (month <= 12 && month > 0)
    {
        if (month == 1)
        {
            std::cout << "31 days" << "\n\n";
        }
        else if ((month >= 3 && month <= 7) || (month >= 9 && month <= 12)) //months in the year that go in a pattern alternating 31 & 30 days
        {
            if (month % 2 == 0)
            {
                std::cout << "30 days" << "\n\n";
            }
            else
            {
                std::cout << "31 days" << "\n\n";
            }
        }
        else if (month == 8) //month that breaks pattern
        {
            std::cout << "31 days" << "\n\n";
        }
        //leap year special cases
        else if (month == 2) //month that us affected by leap years
        {
            if (year % 100 == 0 && year % 400 == 0)
            {
                std::cout << "29 days" << "\n\n"; // Leap year
            }
            else if (year % 100 != 0 && year % 4 == 0)
            {
                std::cout << "29 days" << "\n\n"; // Leap year
            }
            else
            {
                std::cout << "28 days" << "\n\n"; // Non-leap year
            }
        }
    }
    //checks for month inputs outside of the range (1-12)
    if (month < 1 || month > 12)
    {
        std::cout << "Invalid month. Please enter a number between 1 and 12." << "\n" << endl;

    }



    // Program 2: Shipping Charges Program
    double rate = 0, miles = 0, weight = 0, charges = 0;//initializes variables

	std::cout << fixed << showpoint << setprecision(2); // Set the output format for floating-point numbers
    //prompt user to input needed information
	std::cout << "Please enter the weight of the package in kg (0-20): " << "\n";
	std::cin >> weight;
	std::cout << "Please enter the distance in miles (10-3000): " << "\n";
	std::cin >> miles;

    if ((!(weight <= 0)) && (!(weight >= 20)) && (!(miles <= 10)) && (!(miles >= 3000))) //conditions that weight & miles need to adhere to
    {
        //determines specific rate for different weight ranges
        if (weight > 0 && weight <= 2)
        {
            rate = 1.10;
        }
        if (weight > 2 && weight <= 6)
        {
            rate = 2.20;
        }
        if (weight > 6 && weight <= 10)
        {
            rate = 3.70;
        }
        if (weight > 10 && weight <= 20)
        {
            rate = 4.80;
        }
    }
    else
    {
        //Checks for invalid rates
        std::cout << "Invalid weight or miles. Please enter a number between 0 and 20 (kg) for weight and a number between 10 and 3,000 for miles." << "\n";
    }
    //Calculates charge
    miles /= 500;
    charges = weight * rate * miles;
    std::cout << "The charges are going to be: $" << charges << "\n\n" << endl;




    // Program 3: Geometry Calculator Program
    //define variables
	int choice;
    double radius, area, length, width;
	const double PI = 3.14159;
    //keep numbers associated with these variables constant
    const int circle_choice = 1,
	          rectangle_choice = 2,
			  triangle_choice = 3,
			  quit_choice = 4;
    //format & print options for user
    std::cout << "Geometry Calculator\n\n"
         << "\t\t1. Calculate the area of a circle\n"
         << "\t\t2. Calculate the area of a rectangle\n"
         << "\t\t3. Calculate the area of a triangle\n"
		 << "\t\t4. Quit\n\n"
	     << "Please enter your choice (1-4): \n";
	std::cin >> choice;

    std::cout << fixed << showpoint << setprecision(2);
    //calculates options & what to do once each option is picked
    if (choice == circle_choice)
         {
        std::cout << "Please enter the area of the circle: ";
		std::cin >> radius; // Get the radius of the circle from the user
		area = PI * pow(radius, 2); // Calculate the area of the circle
		std::cout << "The area of the circle is : " << area << "\n";
         }
    else if (choice == rectangle_choice)
    {
        std::cout << "Please enter the length of the rectangle: ";
        std::cin >> length;
        std::cout << "Please enter the width of the rectangle: ";
        std::cin >> width;
        area = length * width; // Calculate the area of the rectangle
        std::cout << "The area of the rectangle is : " << area << "\n";
       
		
    }
    else if (choice == triangle_choice)
	{
        std::cout << "Please enter the base of the triangle: ";
        std::cin >> length; // Get the base of the triangle from the user
        std::cout << "Please enter the height of the triangle: ";
        std::cin >> width; // Get the height of the triangle from the user
		area = 0.5 * length * width; // Calculate the area of the triangle
		std::cout << "The area of the triangle is : " << area << "\n";
    }
	else if (choice == quit_choice)
    {
        std::cout << "Exiting the program. Goodbye!" << endl; // Message when quitting
    }
    else if (choice > 4)
    {
        std::cout << "Invalid choice. Please enter a number between 1 and 4." << "\n";
    }

return 0; // Exit the program successfully
}
