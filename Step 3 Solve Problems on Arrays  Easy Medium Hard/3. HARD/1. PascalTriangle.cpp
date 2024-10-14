#include<bits/stdc++.h>

//brute force approach
int factorialRecursive(int n) {
    
    if (n == 0 || n == 1) {
        return 1;
    }
    return n * factorialRecursive(n - 1);
}

vector<vector<int>> pascalTriangle(int n) {
    
    vector<vector<int>> ans(n);
    for(int i=0;i<n;i++){
        ans[i].resize(i+1);
        for(int j=0;j<=i;j++){

            ans[i][j]=factorialRecursive(i)/(factorialRecursive(j)*factorialRecursive(i-j));
        }
    }

    return ans;
}

//optimal approach

#include <bits/stdc++.h>
vector<int> generateRow(int row){
    long long ans=1;
    vector<int > ansRow;
    ansRow.push_back(1);

    for(int col=1;col<row;col++){
        ans=ans*(row-col)   ;
        ans=ans/(col);
        ansRow.push_back(ans);
    }
    return ansRow;
}

vector<vector<int>> pascalTriangle(int n) {
            
    vector<vector<int>> ans;
    for(int i=1;i<=n;i++){
        ans.push_back(generateRow(i));
    }

    return ans;
}


int main(){

}