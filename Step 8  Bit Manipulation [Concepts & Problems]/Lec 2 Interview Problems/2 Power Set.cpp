//tc and sc(approx): n * 2^n 
//tough question

#include <bits/stdc++.h> 
vector<vector<int>> pwset(vector<int>v)
{
    //Write your code here
    int len=v.size();
    int subset=1<<len;
    vector<vector<int>> ans;

    for(int i=0;i<subset;i++){

        vector<int> list;
        for(int j=0;j<len;j++){
            if(i&(1<<j)){

                list.push_back(v[j]);
                
            }
        }
        ans.push_back(list);
    }
    return ans;
}