#include <bits/stdc++.h>

void bubbleSort(vector<int> &arr, int n)
{
    /*take bubble of first two element(arr[0],arr[1]) and compare if they are in acending order then do nothing ,ohterwise
    swap it, then take next two element(arr[1],arr[2]) as bubble then comparing .. going on , after the one loop largest element
    is at its position i.e is last in the array and so on loop will continue and fix the 2nd largest the elment on 2nd
    largest position and so on...*/

    for (int i = n - 1; i >= 1; i--)
    {
        int doswap = 0; // doswap help bubble sort time complexity 0(n) in best time case
        for (int j = 0; j <= i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                swap(arr[j], arr[j + 1]);
                doswap = 1;
            }
        }
        if (doswap == 0)
        {
            break;
        }
    }
    /*time complexity
    Best Case: O(n)
    Average Case: O(n^2)
    Worst Case: O(n^2)
    */
}

int main()
{
}