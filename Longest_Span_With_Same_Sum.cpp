#include <bits/stdc++.h>
using namespace std;

int Solution_1(vector<int> &A1, vector<int> &A2)
{
    /*  Calculating all posible subarrays  */

    int n = A1.size();
    int maxLength = 0;

    for (int i = 0; i < n; i++)
    {
        int sum1 = 0, sum2 = 0;

        for (int j = i; j < n; j++)
        {
            sum1 += A1[j];
            sum2 += A2[j];

            if (sum1 == sum2)
            {
                int len = j - i + 1;
                maxLength = max(len, maxLength);
            }
        }
    }
    return maxLength;
}

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    vector<int> A1;
    vector<int> A2;
    int n;
    cin >> n;
    int x;
    for (int i = 0; i < n; i++)
    {
        cin >> x;
        A1.push_back(x);
    }
    for (int i = 0; i < n; i++)
    {
        cin >> x;
        A2.push_back(x);
    }

    cout << Solution_1(A1, A2);
}