#include <iostream>
using namespace std;

//global declaration
int i;
float totalBLUE = 0, totalBOTH = 0, lowr, highr;
char lowc;

//function prototype
void sumBLUE(float BLINK[]);
void sumBOTH(float BLINK[]);
void highlow(float BLINK[]);
void display(float BLINK[], float totalBLUE, float totalBOTH, float lowr, float highr);

int main()
{
	float BLINK[14]; //local variables. both BLUE & PINK will be placed in an array BLINK
	int j = 0, m = 0;

	cout << "\nFor City BLUE : " << endl;

	for (i = 0; i < 14; i++) //get amount of rainfall in BLUE
	{
		if (i == 0 || i % 2 == 0)
		{
			j += 1;
			cout << "Enter the amount of rainfall of BLUE city in day " << j << " (mm) : ";
			cin >> BLINK[i];
		}
	}

	cout << "\nFor City PINK : " << endl;

	for (i = 0; i < 14; i++) //get amount of rainfall in PINK
	{
		if (i % 2 == 1)
		{
			m += 1;
			cout << "Enter the amount of rainfall of PINK city in day " << m << " (mm) : ";
			cin >> BLINK[i];
		}
	}

	for (i = 0; i < 14; i++)
	{
		sumBLUE(BLINK);
		sumBOTH(BLINK);
	}

	highlow(BLINK);
	display(BLINK, totalBLUE, totalBOTH, lowr, highr);
}
void sumBLUE(float BLINK[]) //to get the total of rainfall in BLUE
{
	if (i == 0 || i % 2 == 0)
	{
		totalBLUE += BLINK[i];
	}
}
void sumBOTH(float BLINK[]) //to get thetotal of rainfall in both cities
{
	totalBOTH += BLINK[i];
}
void highlow(float BLINK[]) //identifying the minimum and maximum rainfall from both cities
{
	lowr = BLINK[0];
	highr = BLINK[0];

	for (i = 1; i < 14; i++)
	{
		if (BLINK[i] < lowr)
		{
			if (i == 0 || i % 2 == 0) // to identify which city has the lowest rainfall
				lowc = 'B';
			else
				lowc = 'P';
			lowr = BLINK[i];
		}
		if (BLINK[i] > highr)
			highr = BLINK[i];
	}
}
void display(float BLINK[], float totalBLUE, float totalBOTH, float lowr, float highr) //displaying all of the data
{	
	int j = 0, m = 0;

	cout << "\n\t****Result of the rainfall for both Cities****";
	cout << "\n\nFor City BLUE : " << endl;

	for (i = 0; i < 14; i++)
	{
		if (i == 0 || i % 2 == 0)
		{
			j += 1;
			cout << "\nThe amount of rainfall in day " << j << " is " << BLINK[i] << " mm";
		}
	}

	cout << "\n\nFor City PINK : " << endl;

	for (i = 0; i < 14; i++)
	{
		if (i % 2 == 1)
		{
			m += 1;
			cout << "\nThe amount of rainfall in day " << m << " is " << BLINK[i] << " mm";
		}
	}

	cout << "\n\nThe total amount of rainfall in City BLUE is " << totalBLUE << " mm";
	cout << "\nThe total amount of rainfall in both City is " << totalBOTH << " mm";
	cout << "\nThe highest rainfall is " << highr << " mm";
	cout << "\nThe lowest rainfall is " << lowr << " mm";

	switch (lowc)
	{
	    case 'B': cout << "\nThe city that has the lowest rainfall is City BLUE\n";
		    break;
	    case 'P': cout << "\nThe city that has the lowest rainfall is City PINK\n";
		    break;
	}
}