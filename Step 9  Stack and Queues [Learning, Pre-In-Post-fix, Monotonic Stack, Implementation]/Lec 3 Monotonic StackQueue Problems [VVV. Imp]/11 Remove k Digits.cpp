//tc: 3n+k  and sc: 2n

string removeKDigits(string num, int k) 
{
    // Write your code here.
    string res;

    stack<char> st;

    for(int i=0;i<num.size();i++){
        while(!st.empty() && k>0 && ((num[i])<(st.top()))){
            st.pop();
            k--;
        }
        st.push(num[i]);
    }

    if(st.top()=='0')   return "0";

    while(k>0  && !st.empty()) {
        st.pop();
        k--;
    }

    
    if(st.empty())  return "0";

    while(!st.empty()){
        res.push_back(st.top());
        st.pop();
    }
    
    if(res=="0")    return "0";

    while(res.size()!=0 && res.back()=='0'){
        res.pop_back();
    }
  

    if(res.size()==0)   return "0";

    reverse(res.begin(),res.end());
    return res;

}

int main(){
        
}