//one of the optimal approach
class Solution {
public:
    int longestConsecutive(vector<int>& arr) {
        int n = arr.size();
        if(n==0) return 0;
        int longest =1;
        unordered_set<int> str;

        for(int i=0;i<n;i++){
            str.insert(arr[i]);
        }

        for(auto it: str){
            if(str.find(it-1)==str.end()){
                int count=1;
                int x=it;
                while(str.find(x+1)!=str.end()){
                    x=x+1;
                    count++;
                }
                longest=max(longest,count);
            }
        }

        return longest;

    }
};

//another approach
int findLongestConseqSubseq(int arr[], int N)
    {
        if(N==0)    return 0;
        sort(arr,arr+N);
        int n=N;
        int count=0;
        int longest=1;
        
        int lastSmaller=INT_MIN;
        
        for(int i=0;i<n;i++){
            if(arr[i]-1==lastSmaller){
                count+=1;
                lastSmaller=arr[i];
            }
            else if(lastSmaller!=arr[i]){
                count=1;
                lastSmaller=arr[i];
            }
            longest=max(longest,count);
        }
            
           
        return longest;
            
    }

int main(){
    
}