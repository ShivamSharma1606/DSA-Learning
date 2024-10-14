#include <bits/stdc++.h>
using namespace std;

int removeDuplicates(vector<int> &arr, int n)
{

	sort(arr.begin(), arr.end());
	// for the sorted array

	int i = 0;
	for (int j = 1; j < n; j++)
	{
		if (arr[j] != arr[i])
		{
			arr[i + 1] = arr[j];
			i++;
		}
	}
	return i + 1;
}

int main()
{
}