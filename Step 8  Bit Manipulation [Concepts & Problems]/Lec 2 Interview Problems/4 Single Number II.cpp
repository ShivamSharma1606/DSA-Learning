#include<bits/stdc++.h>
#include <vector>
//brute force approach using the map and counting its frequency
// ss in samNotes

//better approach
//tc: n*32
class Solution {
public:
    int singleNumber(vector<int>& nums) {

        int ans=0;
        for(int i=0;i<32;i++){

            int cnt=0;
            for(int j=0;j<nums.size();j++){
                if(nums[j]&(1<<i)){ // to finding the numbers of 1 of each element
                    cnt++;
                }
            }
            
            if(cnt%3!=0){ //it mean their is one 1 of single bit
                ans=ans|(1<<i);
            }
        }
        return ans;
        
    }
};

//more better approach
//tc: nlogn + n/3
//sc: 1
//disadvantage: orignal data is disorted

#include<bits/stdc++.h>
using namespace std;
int elementThatAppearsOnce(vector<int> arr) {

	int n=arr.size();
	sort(arr.begin(),arr.end());

	for(int i=1;i<arr.size();i=i+3){
          if (arr[i] != arr[i - 1]) {
            return arr[i - 1];
          }
        }
	return arr[n-1];
}

//optimal approach based on bucket
//tc: o(n) and sc: 1
//not to much important

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        // do it on pen and paper (imp)        
        int one=0;
        int two=0;

        for(int i=0;i<nums.size();i++){
            one=(one^nums[i])&(~two);
            two=(two^nums[i])&(~one);
        }
        return one;
    }
};


