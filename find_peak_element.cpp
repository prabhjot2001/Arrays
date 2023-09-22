#include<iostream>
#include<vector>
using namespace std;

/* problem statement 
Given an array , you need to find the peak element. A peak element is the element which is not
smaller than its neighbour */


vector<int> NaiveSolution(vector<int>v)
{
    int n = v.size();
    vector<int> ans;
    if(v[0]>=v[1])
    {
        ans.push_back(v[0]);
    }
    for(int i=1;i<n-1;i++)
    {

        if(v[i]>=v[i-1] and v[i]>=v[i+1])
        {
            ans.push_back(v[i]);
        }
    }

    if(v[n-1] >= v[n-2])
    {
        ans.push_back(v[n-1]);
    }

    return ans;
}


int optimizedSolution(vector<int>v)
{
    int n = v.size();
    auto low = v.begin();
    auto high = v.end();

    while(low <= high)
    {
        auto mid = low + ((high-low)/2);
        if(v[*mid] >= v[*mid-1] and v[*mid] >= v[*mid+1])
           return v[*mid];

        else if(v[*mid]<v[*mid-1]){
           high = mid -1;
        }
        else if(v[*mid]<v[*mid+1]){
           low = mid+1;
        }
    }
}
int main(){
    vector<int> v = {1,2,3,4,5,6,7,8,9,9}; //10,20,15,2,23,90,67
    // vector<int> ans =  NaiveSolution(v);
    // for(auto i : ans)
    // {
    //     cout<<i<<" ";
    // }
    cout<<optimizedSolution(v);
}