// brute force apprach: using recursion[striver]  oneNote
// tc: 3^n and sc: n

//better approach using dp -> tc:n^2 and sc: n^2

//optimal approach tc: n and sc:1

//finding the range if astrick come

class Solution {
public:
    bool checkValidString(string s) {
        
        int min=0;
        int max=0;
        int n=s.size();

        for(int i=0;i<n;i++){
            if(s[i]=='('){
                min++;
                max++;
            }
            else if(s[i]==')'){
                min--;
                max--;
            }
            //that mean character will be astrick "*"
            else{
                min--;
                max++;
            }
            if(min<0)   min=0;
            if(max<0)   return false;
        }

        return (min==0);
    }
};

