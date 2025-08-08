/*
    1                 1
    1 2             2 1
    1 2 3         3 2 1
    1 2 3 4     4 3 2 1
    1 2 3 4 5 5 4 3 2 1
*/

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cout << "Enter the number of rows: ";
    cin >> n;
    int space = 2 * (n - 1);
    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            cout << j + 1 << " ";
        }

        for (int j = 1; j <= space; j++)
        {
            cout << "  ";
        }

        for (int j = 0; j < i; j++)
        {
            cout << i - j << " ";
        }
        cout << endl;
        space -= 2;
    }
    return 0;
}