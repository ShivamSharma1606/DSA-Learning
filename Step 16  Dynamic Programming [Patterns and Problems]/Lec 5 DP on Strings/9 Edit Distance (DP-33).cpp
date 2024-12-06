// WE HAVE THREE STEP WHEN CHARACTER ARE NOT MATCHING
/*
1. insertion of the element
2. replacement of the element
3. deletion of the element
*/

// brute force approah[important for understanding the problem] 

class bruteRecursion
{
#include <bits/stdc++.h>
    // in the insertion step we don't reduce the value of i because first we insert the character hence i=i+1 and now we reduce the size for comparing other part of the string --(i+1) =i

    int f(int i, int j, string a, string b)
    {

        if (i < 0)
        {
            // string 1 is exhausted, hence we required j+1 insert operation in string a so that it can become b
            return j + 1;
        }
        if (j < 0)
        {
            // string b is exhausted, hence we required i+1 deletion operation on string a so that it can become string b
            return i + 1;
        }

        if (a[i] == b[j])
        {
            // simply reduce the size and comparing left parts of the string
            return 0 + f(i - 1, j - 1, a, b); // no operation are required
        }

        // else char are not matching

        // insertion operation (both string are shrinking but i value don't change [explaination at top of code])
        int insert = 1 + f(i, j - 1, a, b);
        // deletion operation[shrinking of string a only]
        int deletion = 1 + f(i - 1, j, a, b);
        // replacing operation[both the string are shrink by 1 size after replacing]
        int replace = 1 + f(i - 1, j - 1, a, b);

        return min(insert, min(deletion, replace));
    }
    int editDistance(string a, string b)
    {
        int l = a.size();
        int r = b.size();

        return f(l - 1, r - 1, a, b);
    }
};

class memorization{
    #include <bits/stdc++.h> 
//in the insertion step we don't reduce the value of i because first we insert the character hence i=i+1 and now we reduce the size for comparing other part of the string --(i+1) =i

int f(int i, int j, string a, string b,  vector<vector<int>> &dp){

	if(i==0){
		//string 1 is exhausted, hence we required j+1 insert operation in string a so that it can become b
		return dp[i][j]= j;
	}
	if(j==0){
		//string b is exhausted, hence we required i+1 deletion operation on string a so that it can become string b
		return dp[i][j] = i;
	}

    if(dp[i][j]!= -1)   return dp[i][j];

	if(a[i-1]==b[j-1]){
		//simply reduce the size and comparing left parts of the string
		dp[i][j]= 0 + f(i-1,j-1,a,b,dp);  //no operation are required
	}

	//else char are not matching

	else{
		//insertion operation (both string are shrinking but i value don't change [explaination at top of code])
		int insert=1+f(i,j-1,a,b,dp);
		//deletion operation[shrinking of string a only]
		int deletion=1+f(i-1,j,a,b,dp);
		//replacing operation[both the string are shrink by 1 size after replacing]
		int replace =1+f(i-1,j-1,a,b,dp);

		dp[i][j]= min(insert, min(deletion,replace));
    }

    return dp[i][j];
	

}
int editDistance(string a, string b)
{
	int n=a.size();
	int m=b.size();
    vector<vector<int>> dp(n+1,vector<int>(m+1,-1));

	return f(n,m,a, b,dp);
}
};

class tabulation{
    
    int f(int i, int j, string a, string b, vector<vector<int>>& dp) {

        if (i == 0) {
            // string 1 is exhausted, hence we required j+1 insert operation in
            // string a so that it can become b
            return dp[i][j] = j;
        }
        if (j == 0) {
            // string b is exhausted, hence we required i+1 deletion operation
            // on string a so that it can become string b
            return dp[i][j] = i;
        }

        if (dp[i][j] != -1)
            return dp[i][j];

        if (a[i - 1] == b[j - 1]) {
            // simply reduce the size and comparing left parts of the string
            dp[i][j] =
                0 + f(i - 1, j - 1, a, b, dp); // no operation are required
        }

        // else char are not matching

        else {
            // insertion operation (both string are shrinking but i value don't
            // change [explaination at top of code])
            int insert = 1 + f(i, j - 1, a, b, dp);
            // deletion operation[shrinking of string a only]
            int deletion = 1 + f(i - 1, j, a, b, dp);
            // replacing operation[both the string are shrink by 1 size after
            // replacing]
            int replace = 1 + f(i - 1, j - 1, a, b, dp);

            dp[i][j] = min(insert, min(deletion, replace));
        }

        return dp[i][j];
    }

public:
    int minDistance(string a, string b) {
        int n = a.size();
        int m = b.size();
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));

        // return f(n, m, a, b, dp);

        // base case if string 1 is empty
        for (int i = 0; i <= m; i++) {
            dp[0][i] = i;
        }
        // base case if string 2 is empty
        for (int i = 0; i <= n; i++) {
            dp[i][0] = i;
        }

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (a[i - 1] == b[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1];
                } else {
                    int insert = 1 + dp[i][j - 1];
                    int deletion = 1 + dp[i - 1][j];
                    int replace = 1 + dp[i - 1][j - 1];

                    dp[i][j] = min(insert, min(deletion, replace));
                }
            }
        }

        return dp[n][m];
    }

};

//optimal with space optimization[little bit change in for loop]

