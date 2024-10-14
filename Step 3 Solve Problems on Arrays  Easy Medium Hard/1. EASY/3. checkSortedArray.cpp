#include<bits/stdc++.h>
using namespace std;

bool isSorted(int n, vector<int> a)
{
    for (int i = 1; i < n; i++)
    {
        if (a[i] >= a[i - 1])
        {
            //DO NOTHING
        }
        else
        {
            return false;
        }
    }
    return true;
}

int main()
{
    vector<int> arr={1,2,2,4,6};

    bool check;
    check=isSorted(5,arr);

    if(check)   cout<<"array is sorted";
    else    cout<<"Array is not sorted";
}
