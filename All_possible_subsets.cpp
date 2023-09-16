#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> solution(vector<int>&v)
{
    vector<vector<int>> ans;
     int n = v.size();
    for(int i=0;i<(1<<n);i++)  // no. of all possible subset 2^n, n = no. of elements in set
    /* pow(2,n) is same as (1<<n);   
       128 64  32 16 8  4  2  1
       0   0   0  0  0  0  0  0
    */
    {
        vector<int>temp;
        for(int j = 0;j<n;j++)// for every subset choice 'n' combinations
        {
            if((1<<j)&i)
            {
                temp.push_back(v[j]);
            }
        }
        ans.push_back(temp);
    }
    return ans;
}
int main(){
    vector<int>v = {1,2,3}; 
    for(auto i: solution(v))
    {
        cout<<"{ ";
        for(auto j : i)
        {
            cout<<j<<" ";
        }
        cout<<"}\n";
    }
}