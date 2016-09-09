//Kevin Namey
//Homework 3


#include <iostream>
#include <iomanip>
using namespace std;

int main() {

	//variable declarations
	float loan_amount;
	float balance;
	float yearly_interest_rate;
	float monthly_interest_rate;
	float principal;
	float monthly_payment;
	float interest_payment;
	int num_month = 0;

	//Prompt user for input
	cout << "Loan Amount: ";
	cin >> loan_amount;
	cout << "Interest Rate (% per year): ";
	cin >> yearly_interest_rate;
	cout << "Monthly Payments: ";
	cin >> monthly_payment;

	//Convert yearly interest rate to monthly rate
	monthly_interest_rate = yearly_interest_rate / 12;
	
	//Initialize balance to loan amount
	balance = loan_amount;

	//Format decimal places
	cout << setprecision(2) << fixed;

	//Print headers for table
	cout << "******************************************************" << endl;
	cout << "      Amortization Table" << endl;
	cout << "******************************************************" << endl;
	cout << right << setw(10) << " ";
	cout << left << setw(10) << "Month" << "Balance" << "Payment" << "Rate" << "Interest" << "Principal" << endl;
	cout << right << setw(10) << " ";
	cout << left << setw(5) << num_month;
	cout << right << setw(6) << "$";
	cout << left << setw(5) << balance;
	cout << right << setw(4) << " ";
	cout << left << setw(10) << "N/A";
	cout <<	left << setw(10) << "N/A";
	cout << left << setw(10) << "N/A";
	cout << left << setw(10) << "N/A" << endl;

	//Loop to calculate each month's payment
	while (balance > 50) {
		interest_payment = balance * (monthly_interest_rate / 100);
		principal = monthly_payment - interest_payment;
		balance = balance - principal;
		num_month++;
		cout << right << setw(10) << " ";
		cout << left << setw(5) << num_month;
		cout << right << setw(6) << "$";
		cout << left << setw(5) << balance;
		cout << right << setw(5) << "$";
		cout << left << setw(5) << monthly_payment;
		cout << right << setw(4) << " ";
		cout << left << setw(5) << monthly_interest_rate;
		cout << right << setw(6) << "$";
		cout << left << setw(5) << interest_payment;
		cout << right << setw(5) << "$";
		cout << left << setw(5) << principal << endl;		
	}

	//Calculate final payment
	num_month++;
	interest_payment = balance * (monthly_interest_rate / 100);
	monthly_payment = balance + interest_payment;
	principal = balance - interest_payment;
	balance = balance - (principal + interest_payment);
	cout << right << setw(10) << " ";
	cout << left << setw(5) << num_month;
	cout << right << setw(6) << "$";
	cout << left << setw(5) << balance;
	cout << right << setw(6) << "$";
	cout << left << setw(5) << monthly_payment;
	cout << right << setw(4) << " ";
	cout << left << setw(5) << monthly_interest_rate;
	cout << right << setw(6) << "$";
	cout << left << setw(5) << interest_payment;
	cout << right << setw(5) << "$";
	cout << left << setw(5) << principal << endl;

	return 0;
}
