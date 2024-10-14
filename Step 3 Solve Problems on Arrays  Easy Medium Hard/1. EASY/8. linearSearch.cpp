#include <bits/stdc++.h>
using namespace std;

int linearSearch(int n, int num, vector<int> &arr)
{
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == num)
        {
            return i;   
            break;
        }
    }
    return -1;
}
