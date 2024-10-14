//brute force approach
//tc: O(no of days)*n and sc:O(total no of next calls)

vector<int> findStockSpans(vector<int>& prices) {
    // Write your code here.

    vector<int> ans;
    vector<int> count;

    for(int i=0;i<prices.size();i++){
        ans.push_back(prices[i]);
        int value=ans.back();

        int cnt=1;
        for(int j=ans.size()-2;j>=0;j--){
            if(ans[j]<value)   cnt++;
            else    break;
        }
        count.push_back(cnt);
    }

    return count;
    
}

//optimal approach
//tc: 2n ans sc:n
//leetcode
    
class StockSpanner {
public:
    
    int index;
    stack <pair<int,int>> st;
    StockSpanner() {
        index=-1;
        st;        
    }
    
    int next(int val) a{
        index++;
        while(!st.empty() && st.top().first<=val){
            st.pop();
        }
        
        int ans=index-(st.empty()?-1:st.top().second);

        st.push({val,index});

        return ans;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */



