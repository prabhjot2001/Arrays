#include <bits/stdc++.h>
using namespace std;

/*Problem - find intersection and union of two sorted array*/

vector<int> Union_solution(vector<int> &v1, vector<int> &v2)
{
    vector<int> ans;
    auto i = v1.begin(), j = v2.begin();
    while (i != v1.end() and j != v2.end())
    {
        if (*i > *j)
        {
            ans.push_back(*j);
            j++;
        }
        else if (*i < *j)
        {
            ans.push_back(*i);
            i++;
        }
        else
        {
            ans.push_back(*i);
            i++;
            j++;
        }
    }

    if (i != v1.end())
    {
        while (i != v1.end())
        {
            ans.push_back(*i);
            i++;
        }
    }
    if (j != v2.end())
    {
        while (j != v2.end())
        {
            ans.push_back(*j);
            j++;
        }
    }

    return ans;
}


vector<int> Intersection_solution(vector<int> &v1, vector<int> &v2)
{
    vector<int> ans;
    auto i = v1.begin(), j = v2.begin();

    while (i != v1.end() and j != v2.end())
    {
        if (*i == *j)
        {
            ans.push_back(*i);
            i++;
            j++;
        }
        else if (*i < *j)
        {
            i++;
        }
        else
        {
            j++;
        }
    }
    return ans;
}

void printAnswer(vector<int> ans)
{
    cout<<endl;
    for (auto i : ans)
    {
        cout << i << " ";
    }
}

int main()
{

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    vector<int> v1 = {1, 3, 4, 5, 7, 9, 11, 12};
    vector<int> v2 = {2, 3, 5, 6};

    printAnswer(Union_solution(v1, v2));
    printAnswer(Intersection_solution(v1,v2));

    return 0;
}