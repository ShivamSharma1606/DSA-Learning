//please see the code of majority element 2 for better understanding.
//optimial approach
#include<bits/stdc++.h>

vector<int> majorityElement(vector<int> v) {
	int n=v.size();
	int el1=INT_MIN;
	int el2=INT_MIN;
	int cnt1=0,cnt2=0;

	for(int i=0;i<n;i++){
		if(cnt1==0&&el2!=v[i]){
			cnt1=1;
			el1=v[i];
		}
		else if(cnt2==0&&el1!=v[i]){
			cnt2=1;
			el2=v[i];
		}
		else if(el1==v[i]) cnt1++;
		else if(el2==v[i]) cnt2++;
        else {
            cnt2--, cnt1--;
        }
    }
	cnt1=0,cnt2=0;
	vector<int>ls;

	for(int i=0;i<n;i++){
		if(v[i]==el1) cnt1++;
		if(v[i]==el2) cnt2++;
	}
	int mini=int(n/3)+1;
	if(cnt1>=mini)	ls.push_back(el1);
	if(cnt2>=mini)	ls.push_back(el2);

	return ls;
}
int main(){

}