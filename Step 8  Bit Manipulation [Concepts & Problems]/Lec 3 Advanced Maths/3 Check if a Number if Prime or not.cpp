class Solution{
public:
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
    
};


int main(){
    
}