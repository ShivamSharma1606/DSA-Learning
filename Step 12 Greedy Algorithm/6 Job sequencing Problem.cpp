// dry run is compulsory
#include<bits/stdc++.h>
using namespace std;
bool const compar(vector<int> a, vector<int> b){
    return a[2]>b[2];
}
/*
0: for job number(basically serial number)
1: deadline of the job
2: profit of the job
*/
vector<int> jobScheduling(vector<vector<int>> &jobs)
{
    int n=jobs.size();  // finding the number of jobs

    sort(jobs.begin(), jobs.end(), compar); // sorting the job based on their profit in descending order[i.e max profit job come first]

    int maxTime=jobs[0][1]; //Temporary declaring maxtime deadline of the first Job

    for(int i=1;i<n;i++){  // finding the maximum deadline
        maxTime=max(maxTime, jobs[i][1]);
    }
    int profit=0, complete=0;

    vector<int> freeDay(maxTime+1,-1);  // create an array of size maxdeadline with all have -1 value initially

    for(int i=0;i<n;i++){
        for(int j=jobs[i][1];j>0;j--){  // finding deadline day 
            if(freeDay[j]==-1){  // first compare with deadline if not find reduce the day
                profit+=jobs[i][2];
                complete++;
                freeDay[j]=jobs[i][0];
                break;  // if find the deadline break the loop
            }
        }
    }
    return {complete, profit};
}