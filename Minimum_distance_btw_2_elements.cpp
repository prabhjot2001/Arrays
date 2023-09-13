#include<bits/stdc++.h>
using namespace std;



// int solution(vector<int>&v, int x, int y)
// {
//     int xidx, yidx;
//     for(auto i=0;i<v.size();i++)
//     {
//         if(v[i]==x)
//         {
//             xidx = i;
//         }
//         if(v[i]==y)
//         {
//             yidx = i;
//         }
//     }
//     return abs(xidx - yidx);
// }

int solution(vector<int>&v, int x, int y)
{
    int minDist = INT_MAX;
    for(int i=0;i<v.size();i++)
    {
        for(int j=0;j<v.size();j++)
        {
            if((x == v[i] and y == v[j]
                          or
               x == v[j] and y == v[i])
                          and 
               abs(i-j) < minDist)
              {
                minDist = abs(i-j);
              }
        }
    }
    return minDist;
}

int main(){

    vector<int>v = {3,5,4,2,6,5,6,6,5,4,8,3};
    int x,y;
    cin>>x>>y;
    cout<<solution(v,x,y);
}