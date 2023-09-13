#include <bits/stdc++.h>
using namespace std;

int solution1(vector<int> &v)
{
    int n = *max_element(v.begin(), v.end());

    vector<int> aux(n + 1, -1);

    for (int i = 0; i < v.size(); i++)
    {
        int count = 0;
        for (int j = 0; j < v.size(); j++)
        {
            if (aux[v[i]] == -1)
            {
                if (v[j] == v[i])
                {
                    count++;
                }
            }
        }

        if (aux[v[i]] == -1)
        {
            aux[v[i]] = count;
        }
    }
    int mostFrequent = *max_element(aux.begin(), aux.end());

    if (mostFrequent > (v.size() / 2))
    {
        int idx;
        auto it = find(aux.begin(), aux.end(), mostFrequent);
        if (it != aux.end())
        {
         idx = it - aux.begin();
        }
        return idx;
    }
    else
    {
        return -1;
    }
}



int solution2 (vector<int>&v)  // using moore's voting algorithm
{
    int maj_idx = 0;
    int count= 1;

    for(int i=1;i<v.size();i++)
    {
        if(v[maj_idx] == v[i])
        {
            count++;
        }
        else{
            count--;
        }
        if(count == 0)
        {
            maj_idx = i;
            count=1;
        }
    }
    //  cout<<v[maj_idx];
    int freq = 0;
    for(int i=0;i<v.size();i++)
    {
        if(v[i] == v[maj_idx])
            freq++;
    }

    if(freq>(v.size())/2){
        return v[maj_idx];
    }else{
        return -1;
    }

}
int main()
{
    vector<int> v = {3, 2,1,1,1,1,1,1,1,1,11,1,1,1,1, 3, 2,4, 3, 3};
   cout<< solution2(v);
}