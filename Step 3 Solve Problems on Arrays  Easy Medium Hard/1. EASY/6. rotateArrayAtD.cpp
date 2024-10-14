#include <bits/stdc++.h>
// my shivam approach
// brute force approach

vector<int> rotateArray(vector<int> arr, int k)
{
    int n = arr.size();

    vector<int> temp;
    for (int i = 0; i < k; i++)
    {
        temp.push_back(arr[i]);
    }

    for (int i = 0; i < n - k; i++)
    {
        arr[i] = arr[k + i];
    }

    for (int i = 0; i < k; i++)
    {
        arr[n - k + i] = temp[i];
    }

    return arr;
}

// optimal approach
void rotateArr(int arr[], int d, int n)
{
    d = d % n;
    // reverse is an inbuilt function of c++
    reverse(arr, arr + d);
    reverse(arr + d, arr + n);
    reverse(arr, arr + n);
}

int main()
{
}
