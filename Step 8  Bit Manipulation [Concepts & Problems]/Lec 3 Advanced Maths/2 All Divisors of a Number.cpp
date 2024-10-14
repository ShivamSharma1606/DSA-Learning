//brute force approach
//traverse all the element from 1 to n  
//tc: o(n)



//optimal approach
//tc: O(sqrt(n))

#include<bits/stdc++.h>
int* printDivisors(int n, int &size){

    int *ans= new int[10000];
    int j=0;

    for(int i=1;(i*i)<=n;i++){
        if(n%i==0){
            ans[j++]=i;
            size++;
            if(n/i!=i){
                ans[j++]=n/i;
                size++;
            }
        }
    }
        
    sort(ans,ans+size);

    return ans;
}

//same approach but less time to print
void print_divisors(int n) {
        // Code here
        
        vector<int> ansLast;
        for(int i=1;(i*i)<=n;i++){
            if(n%i==0){
                cout << i <<" ";
                if(n/i!=i){
                    ansLast.push_back(n/i);
                }
            }
        }
        
        
        for(int i=ansLast.size()-1;i>=0;i--){
            cout<<ansLast[i]<<" ";
        }
    }

    
int main(){

}