class Solution {
  public:
    bool isBSTTraversal(vector<int>& arr) {
        // your code here
        //as it is bst then inorder is alway in increasing order
        for(int i=1;i<arr.size();i++){
            if(arr[i-1]>=arr[i]){
                return false;
            }
        }
        return true;
    }
};

