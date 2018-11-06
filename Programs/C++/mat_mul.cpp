#include <iostream>
using namespace std;
int main()
{
    long long a[10][10], b[10][10], mult[10][10], row1, column1, row2, column2, i, j, k;

    cout << "Enter rows and columns for mat1: ";
    cin >> row1 >> column1;
    cout << "Enter rows and columns for mat2: ";
    cin >> row2 >> column2;

    cout << "\n"
         << "Enter numbers in mat1:"
         << "\n";
    for (i = 0; i < row1; i++)
        for (j = 0; j < column1; j++)
        {
            cout << "Enter element " << i + 1 << " " << j + 1 << " : ";
            cin >> a[i][j];
        }

    cout << "\n"
         << "Enter numbers in mat2:"
         << "\n";
    for (i = 0; i < row2; i++)
        for (j = 0; j < column2; j++)
        {
            cout << "Enter element " << i + 1 << j + 1 << " : ";
            cin >> b[i][j];
        }

    for (i = 0; i < row1; i++)
        for (j = 0; j < column2; j++)
        {
            mult[i][j] = 0;
        }
    for (i = 0; i < row1; i++)
        for (j = 0; j < column2; j++)
            for (k = 0; k < column1; ++k)
            {
                mult[i][j] += a[i][k] * b[k][j];
            }

    cout << "Output Matrix:\n";
    for (i = 0; i < row1; i++)
        for (j = 0; j < column2; j++)
        {
            cout << " " << mult[i][j];
            if (j == column2 - 1)
                cout << "\n";
        }

    return 0;
}