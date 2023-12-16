#include <iostream>
using namespace std;

void readData(float studWeight[2][5], float studHeight[2][5]);
void calBMI(float studWeight[2][5], float studHeight[2][5]);
void catBMI(float studBMI[2][5]);

int main()
{
    float studWeight[2][5];
    float studHeight[2][5];

    readData(studWeight, studHeight);
}

void readData(float studWeight[2][5], float studHeight[2][5])
{
    for (int i = 0; i < 2; i++)
    {
        cout << "Please enter the weight and height for each student in Class " << i + 1 << endl;

        for (int j = 0; j < 5; j++)
        {
            cout << "Student " << j + 1 << ":" << endl;
            cout << "Weight: ";
            cin >> studWeight[i][j];
            cout << "Height: ";
            cin >> studHeight[i][j];

            cout << endl;
        }
    }
    calBMI(studWeight, studHeight);
}

void calBMI(float studWeight[2][5], float studHeight[2][5])
{
    float studBMI[2][5];

    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            studBMI[i][j] = studWeight[i][j] / (studHeight[i][j] * studHeight[i][j]);
        }
    }

    catBMI(studBMI);
}

void catBMI(float studBMI[2][5])
{
    string category;
    for (int i = 0; i < 2; i++)
    {
        cout << "Class " << i + 1 << endl;
        for (int j = 0; j < 5; j++)
        {
            if (studBMI[i][j] < 18.5)
            {
                category = "Underweight";
            }
            else if (studBMI[i][j] >= 18.5 && studBMI[i][j] <= 24.9)
            {
                category = "Normal Weight";
            }
            else if (studBMI[i][j] >= 25 && studBMI[i][j] <= 29.9)
            {
                category = "Overweight";
            }
            else
            {
                category = "Obesity";
            }
            cout << "Student " << j + 1 << " BMI category : " << category << endl;
        }
        cout << endl;
    }
}