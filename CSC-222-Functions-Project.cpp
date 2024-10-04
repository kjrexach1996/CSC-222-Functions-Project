// CSC-222-Functions-Project.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <iomanip>
using namespace std;

void getPrices(double& price1, double& price2, double& price3);
void calcRates(double price1, double price2, double price3, double& rate1, double& rate2);
void displayResults(double price1, double price2, double price3, double rate1, double rate2);

int main()
{
	double price_current_year, price_last_year, price_two_years_ago,
		rate_last_year_to_current, rate_two_years_to_last;

	cout << "Welcome! This program will calculate inflation rates based on an "
		<< "item's price for three consecutive years, respectively.\n";

	getPrices(price_current_year, price_last_year, price_two_years_ago);

	calcRates(price_current_year, price_last_year, price_two_years_ago, rate_last_year_to_current, rate_two_years_to_last);

	displayResults(price_current_year, price_last_year, price_two_years_ago, rate_last_year_to_current, rate_two_years_to_last);

	return 0;
}

void getPrices(double& price1, double& price2, double& price3)
{
	cout << "Please enter the item's price during the current year ($0.00): ";
	cin >> price1;
	cout << "Please enter the item's price from last year ($0.00): ";
	cin >> price2;
	cout << "Please enter the item's price from two years ago ($0.00): ";
	cin >> price3;
}

void calcRates(double price1, double price2, double price3, double& rate1, double& rate2)
{
	rate1 = ((price1 - price2) / price2) * 100;
	rate2 = ((price2 - price3) / price3) * 100;
}

void displayResults(double price1, double price2, double price3, double rate1, double rate2)
{
	cout << "These are your item's prices from the last three consecutive years:\n" << setprecision(2) << fixed
		<< "Current year: " << price1 << endl
		<< "Last year: " << price2 << endl
		<< "Two years ago: " << price3 << endl
		<< "Inflation rate from last year to current year: " << rate1 << "%" << endl
		<< "Inflation rate from two years ago to last year: " << rate2 << "%" << endl;

	double rate_average = (rate1 + rate2) / 2;

	cout << "Average inflation rate: " << rate_average << "%\n";

	if (rate_average > 0)
		cout << "The inflation rate is increasing!";
	else
		cout << "The inflation rate is decreasing!";
}
