//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
//User function template for C++
class Solution{
public:

	void rearrange(int arr[], int size) {
	    vector<int> positive;
        vector<int> negative;
        

        for(int i=0;i<size;i++){
            if(arr[i]>=0){
                positive.push_back(arr[i]);
            }else{
                negative.push_back(arr[i]);
            }
        }
        
        int posIndex = 0, negIndex = 0;
        int i = 0;

        // Alternate placement of positive and negative numbers
        while (posIndex < positive.size() && negIndex < negative.size()) {
            arr[i++] = positive[posIndex++];
            arr[i++] = negative[negIndex++];
        }
        
        // If there are remaining positive numbers
        while (posIndex < positive.size()) {
            arr[i++] = positive[posIndex++];
        }

        // If there are remaining negative numbers
        while (negIndex < negative.size()) {
            arr[i++] = negative[negIndex++];
        }
        
	}
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        cin >> n;
        int arr[n];
        for (i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        ob.rearrange(arr, n);
        for (i = 0; i < n; i++) {
            cout << arr[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}

// little bit more optimal approach

class Solution{
public:

	void rearrange(int arr[], int size) {
	    vector<int> pos;
        vector<int> neg;
        

        for(int i=0;i<size;i++){
            if(arr[i]>=0){
                pos.push_back(arr[i]);
            }else{
                neg.push_back(arr[i]);
            }
        }
        
    
        
        if(pos.size()>neg.size()){
            for(int i=0;i<neg.size();i++){
                arr[i*2]=pos[i];
                arr[i*2+1]=neg[i];
            }
            int index=neg.size()*2;
            for(int i=neg.size();i<pos.size();i++){
                arr[index]=pos[i];
                index++;
            }
            
        }else{
            for(int i=0;i<pos.size();i++){
                arr[i*2]=pos[i];
                arr[i*2+1]=neg[i];
            }
            int index=pos.size()*2;
            for(int i=pos.size();i<neg.size();i++){
                arr[index]=neg[i];
                index++;
            }
            
        }
        
	}
};