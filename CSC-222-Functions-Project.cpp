// This program calculates inflation rates based on three individual item prices provided by the user.
// These item prices each represent a respective year, from current to two years ago. Using the inflation rates,
// the program displays all information and whether the inflation rate is increasing or decreasing.

#include <iostream>
#include <iomanip>
using namespace std;

// Function prototypes
void getPrices(double& price1, double& price2, double& price3);
void calcRates(double price1, double price2, double price3, double& rate1, double& rate2);
void displayResults(double price1, double price2, double price3, double rate1, double rate2);

int main()
{
	//Initialize variables
	double price_current_year, price_last_year, price_two_years_ago,
		rate_last_year_to_current, rate_two_years_to_last;

	//Provide program description
	cout << "Welcome! This program will calculate inflation rates based on an "
		<< "item's price for three consecutive years, respectively.\n";

	//Executes function
	//Preconditions: References to variables representing all item prices are passed to function
	getPrices(price_current_year, price_last_year, price_two_years_ago);
	//Postconditions: Variable values provided by user are stored in reference locations

	//Executes function
	//Preconditions: Value parameters from item price variables and references to variables representing inflation rates are passed
	calcRates(price_current_year, price_last_year, price_two_years_ago, rate_last_year_to_current, rate_two_years_to_last);
	//Postconditions: Values for inflation rates are calculated and stored in reference locations

	//Executes function
	//Preconditions: All value parameters inputted and calculated thus far are passed
	displayResults(price_current_year, price_last_year, price_two_years_ago, rate_last_year_to_current, rate_two_years_to_last);
	//Postconditions: Passed information is neatly displayed for the user as well as status of inflation rates (increasing/decreasing)

	//Program ends
	return 0;
}

void getPrices(double& price1, double& price2, double& price3)
{
	//Program asks user for item prices, and all prices are then stored 
	cout << "Please enter the item's price during the current year (0.00): ";
	cin >> price1;
	cout << "Please enter the item's price from last year (0.00): ";
	cin >> price2;
	cout << "Please enter the item's price from two years ago (0.00): ";
	cin >> price3;
}

void calcRates(double price1, double price2, double price3, double& rate1, double& rate2)
{
	//Inflation rates all calculated and converted into percentages
	rate1 = ((price1 - price2) / price2) * 100;
	rate2 = ((price2 - price3) / price3) * 100;
}

void displayResults(double price1, double price2, double price3, double rate1, double rate2)
{
	//Displays all information including item prices and inflation rates
	cout << "These are your item's prices from the last three consecutive years:\n" << setprecision(2) << fixed
		<< "Current year: " << price1 << endl
		<< "Last year: " << price2 << endl
		<< "Two years ago: " << price3 << endl
		<< "Inflation rate from last year to current year: " << rate1 << "%" << endl
		<< "Inflation rate from two years ago to last year: " << rate2 << "%" << endl;

	//Calculates inflation rate average between three years
	double rate_average = (rate1 + rate2) / 2;

	//Displays inflation rate average
	cout << "Average inflation rate: " << rate_average << "%\n";

	//Displays inflation rate status depending on whether average is positive or negative
	if (rate_average > 0)
		cout << "The inflation rate is increasing!";
	else
		cout << "The inflation rate is decreasing!";
}
