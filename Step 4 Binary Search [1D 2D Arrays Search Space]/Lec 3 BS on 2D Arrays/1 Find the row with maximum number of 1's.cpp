// tc: nlogm

#include<bits/stdc++.h>
int lowerBound(vector<int> arr, int n, int x) {
	int ans=n;
	int low=0;
	int high=n-1;
	while(low<=high){
		int mid=low+(high-low)/2;
		if(arr[mid]>=x){
			ans=mid;
			high=mid-1;
		}else{
			low=mid+1;
		}
	}
	return ans;
}
int rowWithMax1s(vector<vector<int>> &matrix, int n, int m) {
    int cnt_max=0;
    int index=-1;

    for(int i=0;i<n;i++){
        int cnt_ones=m-lowerBound(matrix[i], m, 1);
        if(cnt_ones>cnt_max){
            index=i;
            cnt_max=cnt_ones;
        }
    }
    return index;
}

int main(){
    
}