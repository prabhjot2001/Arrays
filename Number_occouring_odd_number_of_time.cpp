#include<bits/stdc++.h>
using namespace std;

/* ----------- PROBLEM STATMENT--------------
 Given an array of where each element is occouring even no. of time only one element is occouring odd number of time. find that element */
int main(){
  int arr[] = {1,2,3,1,2,3,3};
  int n = sizeof(arr)/ sizeof(arr[0]);
  map<int,int>mp;
  for(int i=0;i<n;i++){
      mp[arr[i]]++;
  }
  for(auto it=mp.begin(); it!=mp.end();it++)
  {
    if(it->second %2!= 0){
        cout<<it->first;
        break;
    }
  }
  
}
