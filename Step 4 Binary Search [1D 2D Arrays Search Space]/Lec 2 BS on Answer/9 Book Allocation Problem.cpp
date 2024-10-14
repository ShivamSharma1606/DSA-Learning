#include<bits/stdc++.h>
int studentCnt(vector<int>&arr, int pages){
    int student=1,count=0;
    for(int i=0;i<=arr.size();i++){
        if(arr[i]+count<=pages){
            count+=arr[i];
        }else{
            count=arr[i];
            student++;
        }
    }
    return student;
}

int findPages(vector<int>& arr, int n, int m) {
    if(n<m) return -1;
    int low=*max_element(arr.begin(),arr.end());
    int high=accumulate(arr.begin(),arr.end(),0);

    while(low<=high){
        int mid=low+(high-low)/2;

        int val =studentCnt(arr,mid);

        if(val==m){
            high=mid-1;//we try to reduce the students//page
        }else if( val<m){
            high=mid-1;//we remove the right part 
        }else{
            low=mid+1;//remove the left page
        }
    }
    return low;
}
int main(){
    
}