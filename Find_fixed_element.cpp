#include<bits/stdc++.h>
using namespace std;


/*             PROBLEM STATEMENT           
   Given an array of n integers with all distinct elements and are sorted in ascending order.
   your task is to find the fixed element. A fixed element is defined as arr[i] is equal to i
   If not such element is present in the array then return -1  */


int solution1(int arr[] , int n)
{
     for(int i=0;i<n;i++)
     {
        if(arr[i] == i){
            return i ;
        }
     }
     return - 1;
}

int solution2(int arr[], int n)
{
    int low = 0, high = n-1;
    while(low<=high)
    {
        int mid = (low+high)/2;
        if(arr[mid] == mid)
        {
            return mid;
        }
        else if(arr[mid]< mid){
            low = mid+1;
        }
        else{
            high = mid-1;
        }
    }
    return -1;
}

int main(){
    int arr[] = {-10,-5,0,9,7};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout<<solution2(arr,n);
}