#include<bits/stdc++.h>
using namespace std;

/*problem - Leaders in the array*/
/*A leader in the array is the element which is greater than all the elements to its right side*/

vector<int> solution(vector<int>&v)
{
   vector<int> ans;

     for(int i=0;i<v.size();i++)
     {
        bool flag = false;
        for(int j=i+1;j<v.size();j++)
        {
            if(v[i] < v[j])
            {
                flag = false;
                break;
            }
            if(v[i]>v[j]){
                flag = true;
            }
        }
       if(flag == true or i==v.size()-1)
       {
          ans.push_back(v[i]);
       }
     }
   return ans;
}



vector<int> solution1(vector<int>&v)    // optimized solution 
{
       vector<int> ans;
       int max = v[v.size()-1];
       ans.push_back(max);
       for(int i=v.size()-1; i>=0;i--)
       {
           if(v[i]>max)
           {
            ans.push_back(v[i]);
            max = v[i];
           }
       }

       return ans;
}


int main(){
    vector<int> v  = {16,17,4,3,5,2,15};
    for(auto ele : solution1(v)){
        cout<<ele<<" ";
    }
}