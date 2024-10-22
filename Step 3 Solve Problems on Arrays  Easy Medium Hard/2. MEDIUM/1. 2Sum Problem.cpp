#include <bits/stdc++.h>
// this code only work for sorted array

// brute force approach
string read(int n, vector<int> book, int target)
{
    int count = 0;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            int sumTarget = book[i] + book[j];
            if (sumTarget == target)
            {
                count = 1;
                return "YES";
                break;
            }
        }
    }
    if (count == 0)
    {
        return "NO";
    }
}

// better approach

string read1(int n, vector<int> a, int target)
{
    map<int, int> mp;
    int i = 0;
    while (i < n)
    {
        int num = a[i];
        int reminder = target - num;
        if (mp.find(reminder) != mp.end())
        {
            return "YES";
        }
        mp[a[i]] = i;
        i++;
    }
    return "NO";
}

// optimal approach
// 2 pointer approach
// almost comparable to better approach but have less time complexity because we are not using map data structure
string read(int n, vector<int> a, int target)
{
    int left = 0;
    int right = n - 1;
    sort(a.begin(), a.end());
    while (left <= right)
    {
        int sum = a[left] + a[right];
        if (sum == target)
            return "YES";
        else if (sum > target)
            right--;
        else
            left++;
    }
    return "NO";
}

int main()
{
}