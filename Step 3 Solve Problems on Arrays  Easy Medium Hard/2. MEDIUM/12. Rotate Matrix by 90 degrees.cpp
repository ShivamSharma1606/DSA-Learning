#include <bits/stdc++.h>
#include<vector>

//brute force approach
void rotateMatrix(vector<vector<int>> &mat){

	int n=mat.size();
	vector<vector<int>> ans(n, vector<int>(n));

	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			ans[j][n-i-1]=mat[i][j];
		}
	}

	for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            mat[i][j] = ans[i][j];
        }
    }
}

// SC = N^2 AND TC = N^2

//OPTIMAL APPROACH
//TC= N^2 AND SC=1
