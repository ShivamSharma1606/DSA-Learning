#include <bits/stdc++.h>

void selectionSort(vector<int> &arr){
    // in this sort we take the minimum element from the array and swap with the given position one by one , at first we swap element at first position
    // with the minimum element , then swap 2nd element from the right array minimum element
    int n = arr.size();

    // we take n-2 beacuse last element was already sorted
    for (int i = 0; i <= n - 2; i++)
    {
        int min = i;    
        for (int j = i; j <= n - 1; j++)
        {
            if (arr[min] > arr[j])
                min = j;
        }
        swap(arr[min], arr[i]);
    }
    /*time complexity
    Best Case: O(n^2)
    Average Case: O(n^2)
    Worst Case: O(n^2)
    */
}

int main()
{
    vector<int> numbers = {5, 3, 8, 1, 9, 4};

    cout << "Before sorting:" << endl;
    for (int num : numbers)
    {
        cout << num << " ";
    }
    cout << endl;

    selectionSort(numbers);

    cout << "After sorting:" << endl;
    for (int num : numbers)
    {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}