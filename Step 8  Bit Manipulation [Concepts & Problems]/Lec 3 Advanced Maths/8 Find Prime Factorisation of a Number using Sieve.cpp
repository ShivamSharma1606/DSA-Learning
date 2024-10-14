// brute force approach
int isPrime(int n)
{
    int cnt = 0;

    if (n == 1)
        return 0;
    vector<int> ansLast;
    for (int i = 1; (i * i) <= n; i++)
    {
        if (n % i == 0)
        {
            cnt++;
            if (n / i != i)
            {
                cnt++;
            }
        }

        if (cnt > 2)
            return 0;
    }
    return 1;
}

vector<int> getPrime(int n)
{
    vector<int> ans;
    for (int i = 2; i * i <= n; i++)
    {

        if (n % i == 0)
        {
            if (isPrime(i))
            {

                while (n % i == 0)
                {
                    ans.push_back(i);
                    n = n / i;
                }
            }
        }
    }

    if (n != 1)
        ans.push_back(n);
    return ans;
}

//optimal approach
//nlog(log(n)) + logn

//pen and paper

vector<int> findPrimeFactors(int n) {

        vector <int> spf(n+1);
	    
	    for(int i=2;i<=n;i++){
	        spf[i]=i;
	    }
	    
	    for(int i=2;i*i<=n;i++){
	        
	        if(spf[i]==i){
	            
	            for(int j=i*i;j<=n;j+=i){
	                if(spf[j]==j){
	                    spf[j]=i;
	                }
	            }
	        }
	    }
	    
	    vector<int> ans;
	    
	    while(n!=1){
	        ans.push_back(spf[n]);
	        n=n/spf[n];
	    }
	    return ans;
	
    }

    int main(){
        
    }