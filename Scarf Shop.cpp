#include <iostream>
#include <iomanip>
using namespace std;

//global variables
char fname[20], lname[20];
int phone, qtyi;
float finaltotal;

//function prototype
void menu(float price[]);
void personal_info();
float total(float price);
void discount(float totalA);
void display(int qty[], float totalp[], float totalA, float finaltotal);

int main()
{
	//local variables
	char code, yn;
	int qty[5] = {};
	float price[5] = { 12, 13, 13.5, 14, 15 }, totalp[5] = { 0 }, totalA = 0; //variable price is initialized with each scarf's price

	menu(price);
	personal_info();

	cout << "\nYour Order :\n";

	do
	{
		do
		{
			cout << "\nEnter the product code : "; //user has to enter the code based on their choosen scarf's color. for next loop, user can enter the same code if wanted
			cin >> code;

			if (code == 'A' || code == 'a')
			{
				totalp[0] += total(price[0]); //update the product's total via function call total(price)
				qty[0] += qtyi; //update the product's quantity from the function total(price)
			}
			else if (code == 'B' || code == 'b')
			{
				totalp[1] += total(price[1]);
				qty[1] += qtyi;
			}
			else if (code == 'C' || code == 'c')
			{
				totalp[2] += total(price[2]);
				qty[2] += qtyi;
			}
			else if (code == 'D' || code == 'd')
			{
				totalp[3] += total(price[3]);
				qty[3] += qtyi;
			}
			else if (code == 'E' || code == 'e')
			{
				totalp[4] += total(price[4]);
				qty[4] += qtyi;
			}
			else
				cout << "\nInvalid Code. Try again.\n"; //display if user choose neither a,b,c,d,e

		} while (code != 'A' && code != 'a' && code != 'B' && code != 'b' && code != 'C' && code != 'c' && code != 'D' && code != 'd' && code != 'E' && code != 'e');

		cout << "\nDo you want to make another order ? [Y/N] : "; //if user choose other than y, the program will stop asking for code
		cin >> yn;

	} while (yn == 'Y' || yn == 'y');

	for (int i = 0; i < 5; ++i)
	{
		totalA += totalp[i]; //total price for each code will be sum up here
	}

	discount(totalA);
	display(qty, totalp, totalA, finaltotal);
}
void menu(float price[]) //function to display the menu
{
	cout << "\n\t    ***WELCOME TO OUR SCARF SHOP***\n";
	cout << "\n\t----------------------------------------";
	cout << "\n\tCode\tScarf's Color\t\tPrice";
	cout << "\n\t----------------------------------------";
	cout << "\n\tA" << "\tBlack\t\t\t" << "RM " << fixed << setprecision(2) << price[0]; //black - array index [0]
	cout << "\n\tB" << "\tOff White\t\t" << "RM " << price[1]; //off white - array index [1]
	cout << "\n\tC" << "\tLilac\t\t\t" << "RM " << price[2]; //lilac - array index [2]
	cout << "\n\tD" << "\tScarlet Red\t\t" << "RM " << price[3]; //scarlet red - array index [3]
	cout << "\n\tE" << "\tEmerald Blue\t\t" << "RM " << price[4]; //emerald blue - array index [4]
	cout << "\n\t----------------------------------------";
	cout << "\n\n\tTotal fees worth over RM 50.00 will be \n\tgiven a RM 5.00 discount.\n";
}
void personal_info() //function for user to enter their personal info
{
	cout << "\nEnter your first name : "; //e.g. amber
	cin >> fname;
	cout << "Enter your last name : "; //e.g. heard
	cin >> lname;
	cout << "Enter your phone number : +60-"; //e.g. 199545506
	cin >> phone;
}
float total(float price) //function for user to enter the code's quantity needed & it will calculate the total
{
	float totali;

	cout << "Enter the quantity you want to purchase : "; //user has to enter the quantity they needed 
	cin >> qtyi;
	totali = qtyi * price; //the quantity will be multiplied with product's price 

	return totali;
}
void discount(float totalA) //function to find out if user will get discount & calculate the final total
{
	if (totalA > 50) //if total is above RM 50, RM 5 will be deducted
		finaltotal = totalA - 5;
	else
		finaltotal = totalA;
}
void display(int qty[], float totalp[], float totalA, float finaltotal) //function to display the receipt
{
	cout << "\n\n\t\t\t*****INVOICE*****\n";
	cout << "\n\tCode\tScarf's Color\t\tQuantity\tPrice";
	cout << "\n\t---------------------------------------------------------";
	cout << "\n\tA" << "\tBlack\t\t\t" << qty[0] << "\t\tRM " << fixed << setprecision(2) << totalp[0];
	cout << "\n\tB" << "\tOff White\t\t" << qty[1] << "\t\tRM " << totalp[1];
	cout << "\n\tC" << "\tLilac\t\t\t" << qty[2] << "\t\tRM " << totalp[2];
	cout << "\n\tD" << "\tScarlet Red\t\t" << qty[3] << "\t\tRM " << totalp[3];
	cout << "\n\tE" << "\tEmerald Blue\t\t" << qty[4] << "\t\tRM " << totalp[4];
	cout << "\n\t\t\t\t\t-------------------------";
	cout << "\n\t\t\t\t\tTotal Price\tRM " << totalA;
	if (totalA > 50)
		cout << "\n\t\t\t\t\tDiscount\tRM " << totalA << " - RM 5.00";
	else
		cout << "\n\t\t\t\t\tDiscount\tRM " << totalA << " - RM 0.00";
	cout << "\n\t\t\t\t\tFinal Total\tRM " << finaltotal;
	cout << "\n\n\tThank you for your purchase, " << fname << " " << lname;
	cout << "\n\tIn case of any problem, we will contact you via +60-" << phone << endl;
}