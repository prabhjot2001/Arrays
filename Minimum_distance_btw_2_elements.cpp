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



int solution2(vector<int>&v, int x, int y)
{
    int minDist = INT_MAX;
    int _1stFound;
    int idx =0 ;

   
   for(;idx<v.size();idx++)
   {
     if(v[idx] == x or v[idx] == y){
         _1stFound = idx;
         break;
     }
   }

   for(; idx<v.size();idx++ )
   {
      if(v[idx]==x or v[idx]==y){
        if(v[idx] != v[_1stFound])
        {
            minDist = min(minDist, abs(idx-_1stFound));
            _1stFound = idx;
        }
        else{
            _1stFound = idx;
        }
      }
   }
  

   return minDist;
}


int main(){

    vector<int>v = {3,5,4,2,6,5,6,6,5,4,8,3};
    int x,y;
    cin>>x>>y;
    cout<<solution2(v,x,y);
}