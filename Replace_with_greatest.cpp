#include <iostream>
#include <bits/stdc++.h>
using namespace std;

/*  ------------ PROBLEM STATEMENT ---------------
    Given an array of n elements, your need replace all elements with the greatest element to its right
*/


void printArr(int arr[], int n)
{
      for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
}


void solution1(int arr[], int n) // O(n^2)  complexity
{
    for (int i = 0; i < n; i++)
    {
        int mx = arr[i + 1];
        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] > mx)
            {
                mx = arr[j];
            }
            arr[i] = mx;
        }
    }
    arr[n - 1] = -1;
    printArr(arr,n);
}

void solution2(int arr[], int n) // O(n^2)  time complexity
{
    for (int i = 0; i < n; i++)
    {
        int mx = *max_element(arr + i + 1, arr + n);
        arr[i] = mx;
    }
    arr[n - 1] = -1;
   printArr(arr,n);
}

void solution3(int arr[], int n) // O(n) time complexity best solution
{
    int mx = arr[n - 1];
    arr[n - 1] = -1;
    for (int i = n - 2; i >= 0; i--)
    {
        if (arr[i] > mx)
        {
            int temp = arr[i];
            arr[i] = mx;
            mx = temp;
        }
        else
        {
            arr[i] = mx;
        }
    }

    printArr(arr,n);
}
int main()
{
    int arr[] = {16,17,4,3,5,2};
    int n = sizeof(arr) / sizeof(arr[0]);
    // solution(arr, n);
    solution3(arr, n);
}