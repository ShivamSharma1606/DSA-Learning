#include <bits/stdc++.h>
// my shivam approach
vector<int> findArrayIntersection(vector<int> &arr1, int n, vector<int> &arr2, int m)
{

    vector<int> intersecton;

    int i = 0;
    int j = 0;
    while (i < n && j < m)
    {
        if (arr1[i] == arr2[j])
        {
            intersecton.push_back(arr1[i]);
            i++;
            j++;
        }
        else if (arr1[i] > arr2[j])
        {
            j++;
        }
        else if (arr1[i] < arr2[j])
        {
            i++;
        }
    }

    return intersecton;
}

int main()
{
}