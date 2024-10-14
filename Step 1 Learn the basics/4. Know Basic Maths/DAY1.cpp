#include <bits/stdc++.h>
using namespace std;

void countDigit(int n);

class Solution
{
public:
	int reverse(int x)
	{
		long z = 0;
		long result = 0;

		while (x)
		{
			z = x % 10;
			result = (result * 10 + z);
			x = x / 10;
		}
		if (result > INT_MAX || result < INT_MIN)
		{
			return 0;
		}
		else
			return result;
	}
};

// NEW WAY BUT MORE TIME COMPLEXITY
class Solution
{
public:
	bool isPalindrome(int x)
	{
		vector<int> check;
		for (int i = x; i > 0; i = i / 10)
		{
			int z = i % 10;

			check.push_back(z);
		}

		if (x < 0)
		{
			return false;
		}
		else
		{
			for (int j = 0; j < check.size(); j++)
			{
				if (check[j] != check[check.size() - 1 - j])
				{
					return false;
				}
			}
			return true;
		}
	}
};

bool checkArmstrong(int n)
{
	// Write your code here

	int z = 0;
	int k = n;
	int result = 0;
	int length = to_string(n).length();
	while (n)
	{
		z = n % 10;

		result = result + (int)pow(z, length);

		n = n / 10;
	}
	if (result == k)
		return true;
	return false;
}

bool isPrime(int n)
{
	// Write your code here.
	int cout = 1;

	for (int i = 2; i <= sqrt(n); i++)
	{
		if (n % i == 0)
		{
			cout = 1;
			break;
		}
		else
		{
			cout = 0;
		}
	}
	if (cout == 1)
		return false;
	return true;
}

int sumOfAllDivisors(int n)
{
	// Write your code here.

	int fresult = 0;
	int j = 1;
	for (j; j <= n; j++)
	{

		int result = 0;
		for (int m = 1; m <= sqrt(j); m++)
		{
			if (j % m == 0)
			{

				result = result + m;
				if (m != j / m)
				{
					result = result + j / m;
				}
			}
		}
		fresult = fresult + result;
	}

	return fresult;
}

int main()
{
	int n;
	cin >> n;
	if (true)
	{
		countDigit(n);
	}
}

void countDigit(int n)
{
	// shortcut method
	int c = (int)(log10(n) + 1);
	cout << c;
}
