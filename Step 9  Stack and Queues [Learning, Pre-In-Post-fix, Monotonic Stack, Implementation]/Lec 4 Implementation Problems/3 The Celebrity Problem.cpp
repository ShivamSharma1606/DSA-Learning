//brute force approach
//algo: samNotes
/*
1 we created two array knowMe(how many person know me) and Iknow(how many person I know)
2 if their is person whose know me value is equal to n-1 and IKnow value is equal to 0
3 that person is celebrity otherwise return -1

tc: o(n^2) +O(n) and sc: O(2n)
*/

//optimal approach
//tc: 2n and sc: 1

int celebrity(vector<vector<int> >& M, int n) {
        // code here
        int top=0;
        int down=n-1;
        
        while(top<down){
            if(M[top][down]==1)     top++;
            else if(M[down][top]==1)     down--;
            else{
                top++;
                down--;
            }
        }
        
        if(top>down)    return -1;
        
        for(int i=0;i<n;i++){
            if(i==top)  continue;
            if(M[top][i] || !M[i][top]){
                return -1;
            }
            
        }
        return top;
    }