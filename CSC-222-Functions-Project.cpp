// This program takes two points provided by the user representing the center of a circle and 
// a point on the circumference of the same circle. This points are used to calculate the radius,
// circumference, and area of the circle.

#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

//Function prototypes
double calcDistance(double x1, double y1, double x2, double y2);
double calcRadius(double x1, double y1, double x2, double y2);
double calcCircumference(double radius);
double calcArea(double radius);


int main()
{
    //Initialize all variables
    double x1, y1, x2, y2, radius, circumference, area;
    bool confirm;
    char correct = 'n';

    //Loop begins assuming all information the user inputs is incorrect unless specified otherwise
    cout << "Welcome! This program returns various properties of a circle.\n";
    while (correct == 'n')
    {
        //User enters coordinates for circle (center point)
        cout << "Please enter the coordinates for the center of the circle.\n";
        cout << "x: ";
        cin >> x1;
        cout << "y: ";
        cin >> y1;

        //User enters coordinates for circle (point on circumference)
        cout << "Please enter the coordinates for a point on the circumference.\n";
        cout << "x: ";
        cin >> x2;
        cout << "y: ";
        cin >> y2;

        //Displays coordinates inputted in (x,y) format
        cout << "Center point coordinates: (" << x1 << ", " << y1 << ")\n";
        cout << "Circumference point coordinates: (" << x2 << ", " << y2 << ")\n";

        //Sets nested while loop expression to false to loop until user inputs appropriate value
        confirm = false;
     
        while (!confirm)
        {
            //Program asks for confirmation of correct information
            cout << "Is this correct? Enter \'y\' for \"yes\" or \'n\' for \"no\": ";
            cin >> correct;

            //Loop exits. "correct" is then compared to expression in parent while loop.
            //If correct == 'y', parent loop ends and program continues
            if (correct == 'y' || correct == 'n')
            {
                confirm = true;
            }

            //Line is displayed as the user inputs an inappropriate value
            else
                cout << "Invalid input!\n";
        }
        
        
    }
    //Executes function and stores return information in radius
    //Preconditions: x- and y-coordinates from both circle points are passed when user confirms information is correct
    radius = calcRadius(x1, y1, x2, y2);
    //Postconditions: calcDistance() is executed, and radius of the circle is return to two decimal places

    //Executes function and stores return information in circumference
    //Preconditions: Radius of the circle is provided
    circumference = calcCircumference(radius);
    //Postconditions: Circumference of circle is returned and stored in circumference

    //Executes function and stores return information in area
    //Preconditions: Radius of the circle is provided
    area = calcArea(radius);
    //Postconditions: Area of circle is returned and stored in area

    //All information for the circle is displayed to two decimal places
    cout << setprecision(2) << fixed << "The radius of the circle is " << radius << " units.\n";
    cout << setprecision(2) << fixed << "The circumference of the circle is " << circumference << " units.\n";
    cout << setprecision(2) << fixed << "The area of the circle is " << area << " square units.\n";

    //Program ends
    return 0;
}

double calcRadius(double x1, double y1, double x2, double y2)
{
    //Calls calcDistance(); calcDistance() remains hidden from main()
    return calcDistance(x1, y1, x2, y2);
}

//Preconditions: Variables representing all coordinates are passed to this function from calcRadius()
//Postconditions: Distance formula is calculated, and results are returned to calcRadius to then be stored in radius variable
double calcDistance(double x1, double y1, double x2, double y2)
{
    //Calculates distance between center point and point on circumference of circle 
    return sqrt(pow((x2 - x1), 2) + pow((y2 - y1), 2));
}

double calcCircumference(double radius)
{
    //Calculates circumference of circle
    return 2 * 3.1416 * radius;
}

double calcArea(double radius)
{
    //Calculates area of circle
    return 3.1416 * pow(radius, 2);
}