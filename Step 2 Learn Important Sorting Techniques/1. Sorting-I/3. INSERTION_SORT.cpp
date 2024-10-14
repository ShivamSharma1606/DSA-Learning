
#include<bits/stdc++.h>
using namespace std;

void insertionSort(int arr[], int n)
{
    /*
    Algorithm:

    To achieve insertion sort, follow these steps:

    1We have to start with second element of the array as first element in the array is assumed to be sorted.    
    2Compare second element with the first element and check if the second element is smaller than swap them.
    3Move to the third element and compare it with the second element, then the first element and swap as necessary to put it in the correct position among the first three elements.
    4Continue this process, comparing each element with the ones before it and swapping as needed to place it in the correct position among the sorted elements.
    5Repeat until the entire array is sorted.
    */

    for(int i=0;i<=n-1;i++){
        int j=i;
        while(j>0 && arr[j-1]>arr[j]){
            // int temp=arr[j];
            // arr[j]=arr[j-1];
            // arr[j-1]=temp;
            // j--;
            swap(arr[j],arr[j-1]);
            j--;
        }
    }

    /*time complexity
    Best Case: O(n)
    Average Case: O(n^2)
    Worst Case: O(n^2)
    */

   for(int i=0;i<5;i++){
    cout<<arr[i];
   }
}



int main(){

    int arr[]={2,8,7,1,9};

    insertionSort(arr,5);

}