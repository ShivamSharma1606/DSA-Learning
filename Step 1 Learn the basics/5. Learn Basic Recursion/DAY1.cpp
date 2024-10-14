#include<bits/stdc++.h>
using namespace std;

vector<string> printNTimes(int n) {
	vector<string> ans;

	if(n==0){
		ans.push_back("Coding Ninjas") ;
	}else{
		ans=printNTimes(n-1);
		ans.push_back("Coding Ninjas");
	}
	return ans;

}

vector<long long> factorialNumbers(long long n) {
    vector<long long> k;

    long long i = 1;
    long long factorial = 1;

    while(factorial<=n){
            k.push_back(factorial);

        i++;
        factorial*=i;
    }

    return k;

}

int i=-1;
vector<int> reverseArray(int n, vector<int> &nums)
{
    int k=nums.size();

    if(i>=k/2){
        swap(nums[i],nums[k-i-1]);
        return nums;  
    }
    i++;
    swap(nums[i],nums[k-i-1]);
    reverseArray(i, nums);
    return nums;   
}

int i=-1;
bool isPalindrome(string& str) {
    int k=str.size();

    if(i>=k/2){
        return true;  
    }
    i++;
    if(str[i]!=str[k-i-1])  return false;
    return  isPalindrome(str);
     
}

vector<int> generateFibonacciNumbers(int n) {
    vector<int> sol; 
    if(n==1)   {
        sol.push_back(0);
        return sol;
    }

    if (n == 2) {
        sol.push_back(0);
        sol.push_back(1);
        return sol;
    }

    vector<int> prev = generateFibonacciNumbers(n - 1);
    int fib = prev[prev.size() - 1] + prev[prev.size() - 2];
    prev.push_back(fib);
    return prev;
}

int main(){
    
}