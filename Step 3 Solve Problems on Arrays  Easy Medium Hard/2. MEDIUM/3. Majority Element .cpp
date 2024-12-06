// brute force approach
//  using two for loop and compare each element and check it occurence

// better approach
// N logN
#include <bits/stdc++.h>
int majorityElement(vector<int> v)
{

	map<int, int> mpp;

	for (int i = 0; i < v.size(); i++)
	{
		mpp[v[i]]++;
	}

	for (auto it : mpp)
	{
		if (it.second > v.size() / 2)
		{
			return it.first;
		}
	}
	return -1;
}

// Moore’s Voting Algorithm

int majorityElement(vector<int> v)
{

	int el;
	int count = 0;
	for (int i = 0; i < v.size(); i++)
	{
		if (count == 0)
		{
			el = v[i];
			count = 1;
		}
		else if (el == v[i])
		{
			count++;
		}
		else
		{
			count--;
		}
	}
	int cnt = 0;
	for (int i = 0; i < v.size(); i++)
	{
		if (v[i] == el)
			cnt++;
	}
	if (cnt > (v.size()) / 2)
	{
		return el;
	}
	else
	{
		return -1;
	}
}

int main()
{
}