#include<bits/stdc++.h>
//we can also use binary search to find the max elemet
int findMaxColumnElement(vector<vector<int>> &mat , int mid,int size){
    int index=-1;
    int maxi=INT_MIN;
    for(int i=0;i<size;i++){
        if(mat[i][mid]>maxi){
            maxi=mat[i][mid];
            index=i;
        }
    }
    return index;
}
vector<int> findPeakGrid(vector<vector<int>> &mat){
    int n=mat.size();
    int m=mat[0].size();
    int low=0;
    int high=m-1;

    while(low<=high){

        int mid=(low+high)/2;
        int maxEC=findMaxColumnElement(mat,mid,n);//max element of that column
        int left=mid-1>=0?mat[maxEC][mid-1]:-1;
        int right=mid+1<m?mat[maxEC][mid+1]:-1;

        if(mat[maxEC][mid]>left && mat[maxEC][mid]>right ){
            return {maxEC,mid};
        }else if(mat[maxEC][mid]<left){
            high=mid-1;
        }else{
            low=mid+1;
        }
    }
    return{-1,-1};
}