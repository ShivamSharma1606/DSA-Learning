//brute force approach ; striver and notes
//better approach

#include<bits/stdc++.h>
double minimiseMaxDistance(vector<int> &arr, int k){

	int n=arr.size();
	vector<int> howMany(n-1,0)	;
	priority_queue<pair<long double, int>> pq;

	for(int i=0;i<n-1;i++){
		pq.push({arr[i+1]-arr[i],i});
	}
	for(int i=1;i<=k;i++){
		auto tp=pq.top();
		pq.pop();
		int secInd=tp.second;
		howMany[secInd]++;
		long double initDiff=arr[secInd+1]-arr[secInd];
		long double newSecLen=initDiff/(long double)(howMany[secInd]+1);
		pq.push({newSecLen,secInd});
	}
	return pq.top().first;
}

//optimal approach
#include<bits/stdc++.h>
int countStation(vector<int> &arr,long double dist){
	int count=0;
	int n=arr.size();
	for(int i=1;i<n;i++){
		int inBetween=(arr[i]-arr[i-1])/dist;
		if(arr[i]-arr[i-1]==dist*inBetween){
			inBetween--; //if the number is exactly divisible by the difference then we have to reduce the section length by 1
		}
		count+=inBetween;
	}
	return count;
}

double minimiseMaxDistance(vector<int> &arr, int k){

	int n=arr.size();
	long double low=0;
	long double high=0;
	for(int i=0;i<n;i++){
		high=max(high,(long double)(arr[i+1]-arr[i]));
	}

	long double diff=1e-6;
	while(high-low>diff){

		long double mid=(high+low)/(2.0);

		int cnt=countStation(arr, mid);
		if(cnt>k){
			low=mid; //number of station are required more than number of given
		}else{
			high=mid;
		}
	}
	return high;
}

int main(){
    
}
