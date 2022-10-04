#include <iostream>
#include <conio.h>
using namespace std;

int main()
{
    int i, j, k, choice;

    cout << "1.Print Half Pyramid using * " << endl;
    cout << "2.Print Half Pyramid using Numbers" << endl;
    cout << "3.Print Half Pyramid using Alphabets" << endl;
    cout << "4.Print Inverted Half Pyramid using *" << endl;
    cout << "5.Print Inverted Half Pyramid using Numbers" << endl;
    cout << "6.Print Full Pyramid using *" << endl;
    cout << "7.Print Pyramid using Numbers" << endl;
    cout << "8.Print Inverted Full Pyramid using *" << endl;
    cout << "9.Print Pascal's Triangle" << endl;
    cout << "10.Print Floyds's Triangle" << endl;
    cout << "Enter your choice: ";
    cin >> choice;

    switch (choice)
    {
        case 1:{
            for (i = 1; i <= 5; i++)
            {
                for (j = 1; j <= i; j++)
                {
                    cout << "*";
                }
                cout << endl;
            }
            break;
        }

        case 2:{
            for (i = 1; i <= 5; i++)
            {
                for (j = 1; j <= i; j++)
                {
                    cout << j;
                }
                cout << endl;
            }
            break;
        }

        case 3:{
            for (i = 1; i <= 5; i++)
            {
                for (j = 1; j <= i; j++)
                {
                    cout << ((char)(i + 64));
                }
                cout << endl;
            }
            break;
        }

        case 4:{
            for (i = 5; i >= 1; i--)
            {
                for (j = 1; j <= i; j++)
                {
                    cout << "*";
                }
                cout << endl;
            }
            break;
        }

        case 5:{
            for (i = 5; i >= 1; i--)
            {
                for (j = 1; j <= i; j++)
                {
                    cout << j;
                }
                cout << endl;
            }
            break;
        }

        case 6:{
            for (i = 1; i <= 5; i++)
            {
                for (j = i; j < 5; j++)
                {
                    cout << " ";
                }
                for (k = 1; k < (i * 2); k++)
                {
                    cout << "*";
                }
                cout << endl;
            }
            break;
        }

        case 7:{
            for (i = 1; i <= 5; i++)
            {
                for (j = i; j < 5; j++)
                {
                    cout << " ";
                }
                for (k = 1; k < (i * 2); k++)
                {
                    cout << k;
                }
                cout << endl;
            }
            break;
        }

        case 8:{
            for (i = 5; i >= 1; i--)
            {
                for (j = 5; j > i; j--)
                {
                    cout << " ";
                }
                for (k = 1; k < (i * 2); k++)
                {
                    cout << "*";
                }
                cout << endl;
            }
            break;
        }

        case 9:{
            int c = 1;

            for (i = 0; i < 6; i++)
            {
                for (j = 1; j <= 6 - 1; j++)
                {
                    cout << " ";
                }
                for (k = 0; k <= i; k++)
                {
                    if (k == 0 || i == 0)
                    {
                        c = 1;
                    }
                    else
                    {
                        c = c * (i - k + 1) / k;
                    }
                    cout << c << " ";
                }
                cout << endl;
            }
            break;
        }

        case 10:{
            int num = 1;

            for (i = 1; i <= 5; i++)
            {
                for (j = 1; j <= i; ++j)
                {
                    cout << num++ << " ";
                }
                cout << endl;
            }
            break;
        }

        default:{
            cout << "INVALID CHOICE";
            break;
        }
    }

    getch();
}