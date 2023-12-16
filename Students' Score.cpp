#include <iostream>
#include <fstream>
using namespace std;
#define size 10;

double Function(int score[], int& h, int& l);

int main()
{
	ifstream Name; //Score;
	ofstream Result;

	int i, score[5], h, l;
	char name[5][30];
	double ave;

	Name.open("name.txt");
	//Score.open("score.txt");
	Result.open("result.txt");

	for (i = 0; i < 5; i++)
	{
		Name >> name[i] >> score[i];
	}

	/*for (i = 0; i < 5; i++)
	{
		Score >> score[i];
	}*/

	ave = Function(score, h, l);

	Result << "No\tNames\tScore\n";

	for (int i = 0; i < 5; i++)
	{
		Result << i + 1 << "\t" << name[i] << "\t" << score[i] << endl;
	}

	Result << "\nHighest score : " << h;
	Result << "\nLowest score : " << l;
	Result << "\nAverage : " << ave;

	Name.close();
	//Score.close();
	Result.close();
}
double Function(int score[], int& h, int& l)
{
	int i, sum = 0;
	h = l = score[0];

	for (i = 1; i < 5; i++)
	{
		if (score[i] > h) h = score[i];
		if (score[i] < l) l = score[i];
	}
	for (i = 0; i < 5; i++)
		sum += score[i];

	return (double)sum / 5;
}