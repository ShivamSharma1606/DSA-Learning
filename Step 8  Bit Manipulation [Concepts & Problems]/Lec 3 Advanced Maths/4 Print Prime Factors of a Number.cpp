//brute force approach
/*
1 traverse the whole element(n)
2 check each element is prime or not(sqrt(n))
3 if prime add into list otherwise left it

tc: n*sqrt(n) and sc: not need any extra space
*/

//better approach
//same as brute but first traversal can be done for sqrt(n)
//tc: O(sqrt(n)*2*sqrt(n))

//optimal approach
//same as more better approach with some minor updataion

//tc: sqrt(n)*(logn)  
//pen and paper: for eg 35, 16, 720

int isPrime(int n){   
    int cnt=0;
    
    if(n==1)    return 0;
    vector<int> ansLast;
    for(int i=1;(i*i)<=n;i++){
        if(n%i==0){      
            cnt++;
            if(n/i!=i){
                cnt++;
            }
        }
            
        if(cnt>2)   return 0;
    }
    return 1;
        
}

vector<int> countPrimes(int n)
{
    vector<int> ans;
    for(int i=2;i*i<=n;i++){

        if(n%i==0){
            if(isPrime(i))  ans.push_back(i)  ;

            while(n%i==0){
                n=n/i;
            }
        }
    }

    if(n!=1)    ans.push_back(n);
    return ans;
}