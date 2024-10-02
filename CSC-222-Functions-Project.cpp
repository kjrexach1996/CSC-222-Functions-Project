// 
//

#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

double calcDistance(double x1, double y1, double x2, double y2);
double calcRadius(double x1, double y1, double x2, double y2);


int main()
{
    double x1, y1, x2, y2, radius, circumference, area;
    bool correct = false;
    char confirm = 'n', answer;

    cout << "Welcome! This program returns various properties of a circle.\n";
    while (confirm == 'n')
    {
        cout << "Please enter the coordinates for the center of the circle.\n";
        cout << "x: ";
        cin >> x1;
        cout << "y: ";
        cin >> y1;

        cout << "Please enter the coordinates for a point on the circumference.\n";
        cout << "x: ";
        cin >> x2;
        cout << "y: ";
        cin >> y2;

        cout << "Center point coordinates: (" << x1 << ", " << y1 << ")\n";
        cout << "Circumference point coordinates: (" << x2 << ", " << y2 << ")\n";
     
        while (!correct)
        {
            cout << "Is this correct? Enter \'y\' for \"yes\" or \'n\' for \"no\": ";
            cin >> answer;
            if (answer == 'y' || answer == 'n')
            {
                confirm = answer;
                correct == true;
            }
            else
                cout << "Invalid input!\n";
        }
        
        
    }
    radius = calcRadius(x1, y1, x2, y2);

    cout << setprecision(2);
    cout << "The radius of the circle is " << radius << "units.";
    return 0;
}

double calcRadius(double x1, double y1, double x2, double y2)
{
    return calcDistance(x1, y1, x2, y2);
}

double calcDistance(double x1, double y1, double x2, double y2)
{
    return sqrt(pow((x2 - x1), 2) + pow((y2 - y1), 2));
}