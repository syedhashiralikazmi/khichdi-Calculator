/* 
The Khichdi Calculator is a console-based utility tool that combines financial, conversion, and classification features in one place. 
Operating within defined calculation criteria and limits, it provides a fast, all-in-one menu for handling standard daily tasks right from your terminal.  
@Programmer: Syed Hashir Ali Kazmi
*/
#include<iostream>
using namespace std;
int main()
{
	//	Tool 1 - variables
	double originalBill = 0.0;
	double discountAmount = 0.0;
	double finalBill = 0.0;

	// Tool 2 - variables
	double costPrice = 0.0;
	double sellingPrice =0.0;

	// Tool 3 - variable
	double monthlyIncome = 0.0;

	// Tool 4 - variables
	double orderAmount = 0.0;
	char isMemberPremium = 'n';

	// Tool 5 - variables
	float serviceYear = 0.0; // I use double because may be someone service year would be 5.5 year or 1.5 etc.
	int employeePerfomanceRating = 0;

	// Tool 6 - variables
	double valueToConvert =0.0;
	double convertedValue = 0.0;
	int choice = 0;

	int selectQuestion = 0;
	cout << "\n========================================\n";
	cout << "             Khichdi Caculator            \n";
	cout << "========================================\n";
	cout << "  [1] Electricity Bill Calculator\n";
	cout << "  [2] Profit & Loss Finder \n";
	cout << "  [3] Income Classifier\n";
	cout << "  [4] Free Delivery checker \n";
	cout << "  [5] Employee Bonus Calculator \n";
	cout << "  [6] Unit Convertor\n";
	cout << "----------------------------------------\n";
	cout << " Enter your selection (1-6): ";
	cin >> selectQuestion;
	cout << "========================================\n\n";
	

	if (selectQuestion <= 0 || selectQuestion > 6)
	{
		cout << "Invalid! Enter the value from 1 to 6";
		return 0;
	}
	else {
		switch (selectQuestion) {
		case 1:
			cout << "\n========================================\n"
				 << "        ELECTRICITY BILL CALCULATOR     \n"
				 << "========================================\n";

			cout << "Enter your electrcity bill amount: ";
			cin >> originalBill;

			// I dont check for =0  becuase I think may he insatlled solar panel or something else (But if he have 0 bill so why he is calculating it?) 
			// Thats why I am applying this logic
			if (originalBill <= 0)
			{
				cout << "You entered invalid value: " << originalBill<<endl;
				return 0;
			}

			if (originalBill > 10000.0) {
				discountAmount = originalBill * 0.10;
			}
			finalBill = originalBill - discountAmount;

			cout << "\n\t--- Electricity Bill ---"
				<< "\nOriginal bill: " << originalBill
				<< "\nDiscounted amount (10%):" << discountAmount
				<< "\nFinal bill: " << finalBill<<endl;
			break;
		case 2:
			cout << "\n========================================\n"
				 << "        PROFIT & LOSS CALCULATOR        \n"
				 << "========================================\n";

			cout << "Enter the cost price: ";
			cin >> costPrice;

			cout << "Enter the selling price: ";
			cin >> sellingPrice;

			// I am assuming selling price would be zero 
			// because some vendor may sell there product free to their relatives or known person
			// thats why I check costPrice only.
			if (costPrice > 0)
			{
				if (sellingPrice == costPrice) {
					cout << "\nNo Profit, No Loss"<<endl;
				}
				else if (costPrice > sellingPrice) {
					cout << "Loss: Rs " << costPrice - sellingPrice<<endl;
				}
				else {
					cout << "Profit: Rs " << sellingPrice - costPrice<<endl;
				}
			}
			else {
				cout << "\tCost price could not be ZERO or NEGATIVE"<<endl;
			}
			break;
		case 3:
			cout << "\n================================"
				 << "\n       Income Classifier        "
				 << "\n================================";

			cout <<"\nEnter your montly income: ";
			cin >> monthlyIncome;

			if (monthlyIncome <= 0)
			{
				cout << "\nInvalid! Income not be zero.";
				return 0;
			}
			if (monthlyIncome < 30000) {
				cout << "Low Income\n";
			}
			else if (monthlyIncome <= 59000) {
				cout << "Middle Income\n";
			}
			else if (monthlyIncome <= 99999) {
				cout << "Upper-Middle Income\n";
			}
			else {
				cout << "High Income\n";
			}
			break;
		case 4:
			cout << "\n================================";
			cout << "\n    Free Delivey Calculator     ";
			cout << "\n================================";
			cout << "\n\nEnter the order amount: ";
			cin >> orderAmount;

			cout << "Are you premium member? (enter Y for yes N for no): ";
			cin >> isMemberPremium;

			isMemberPremium = toupper(isMemberPremium);

			if (isMemberPremium != 'Y' && isMemberPremium != 'N') {
				cout << "Inavlid choice! Choose Y or N";
				return 0;
			}
			if (orderAmount > 0) {
				if (orderAmount >= 3000 || isMemberPremium == 'Y') {
					cout << "\nCongratulation! Your delivery is FREE.\n";
				}
				else {
					cout << "\nDelivery is NOT FREE\n";
				}
			}
			else {
				cout << "\nOrder amount must be greater than 0\n";
			}
			break;
		case 5:
			cout << "\n========================================\n";
			cout << "          EMPLOYEE BONUS CALCULATOR      \n";
			cout << "========================================\n";

			cout << "\nEnter your service year: ";
			cin >> serviceYear;
			
			cout << "\nEnter your perfomance rating out of 10: ";
			cin >> employeePerfomanceRating;

			//I am not putting threshold for service year beacusse 
			// I think user can give service to many years also 1year or 0 year beacuse may be he is new to job thats why he just provide service for a month not a years .
			if (employeePerfomanceRating > 0 && employeePerfomanceRating <= 10) {
				if (serviceYear > 5 && employeePerfomanceRating == 8)
				{
					cout << "\nCongratulation! Your Eligible for BONUS"<<endl;
				}
				else if (employeePerfomanceRating == 10)
				{
					cout << "\nCongratulation! Your Eligible for SPECIAL BONUS"<<endl;
				}
				else
				{
					cout << "\nNOT Eligible for bonus"<<endl;
				}
			}
			else {
				cout << "Perfomance rating must be 1 to 10 ";
			}
			break;
		case 6:
			cout<< "\n================================"
				<< "\n     Unit Conversion Tool       "
				<< "\n================================"
				<< "\n1 : Kilometers to meters"
				<< "\n2 : Meters to centimeters"
				<< "\n3 : Kilograms to grams"
				<< "\n4 : Hours to minutes"
				<< "\n\nEnter value for conversion: ";
			cin >> valueToConvert;

			cout << "Select option (1-4): ";
			cin >> choice;

			switch (choice) {
			case 1:
				convertedValue = valueToConvert * 1000;
				cout << " Result: " << valueToConvert << " km  =  " << convertedValue << " meters\n";
				break;
			case 2:
				convertedValue = valueToConvert * 100;
				cout << " Result: " << valueToConvert << " m   =  " << convertedValue << " centimeters\n";
				break;
			case 3:
				convertedValue = valueToConvert * 1000;
				cout << " Result: " << valueToConvert << " kg  =  " << convertedValue << " grams\n";
				break;
			case 4:
				convertedValue = valueToConvert * 60;
				cout << " Result: " << valueToConvert << " hrs =  " << convertedValue << " minutes\n";
				break;
			default:
				cout << "Invalid choice! Please select between 1 and 4.";
				break;
			}
		}
	}
	return 0;
}
