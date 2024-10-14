#include <bits/stdc++.h> 

//brute force approach
// by simple sort the array using any sorting techniques

//better approach
void sortArray(vector<int>& arr, int n)
{
    int count1=0;
    int count2=0;
    int count0=0;
    for(int i=0;i<n;i++){
        if(arr[i]==1){
            count1++;
        }
        else if(arr[i]==2){
            count2++;
        }else if(arr[i]==0){
            count0++;
        }
    }
    

    for(int i=0;i<count0;i++){
        arr[i]=0;
    }
    for(int i=count0;i<count1+count0;i++){
        arr[i]=1;
    }
    for(int i=count1+count0;i<n;i++){
        arr[i]=2;
    }
}

//optimal solution
//Dutch National flag algorithm 
class Solution {
public:
    void sortColors(vector<int>& nums) {
        int low=0,mid=0;
        int high=nums.size()-1;

        while(mid<=high){
            if(nums[mid]==0){
                swap(nums[low],nums[mid]);
                low++;
                mid++;
            }
            else if(nums[mid]==1 ){
                mid++;

            }else{ 
                swap(nums[mid],nums[high]);
                high--;
            }
        }
        
    }
};

int main(){

}
