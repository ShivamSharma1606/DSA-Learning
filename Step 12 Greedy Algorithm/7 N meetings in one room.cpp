// tc: 2n+ nlogn and sc: 3n

struct meeting{
        int starting;
        int ending;
        int pos;
    };
    
    bool static comp(struct meeting a, struct meeting b){
        return (a.ending<b.ending);
    }
    
    int maxMeetings(vector<int> start, vector<int> end) {
        // Your code here
        int n=start.size();
        vector<meeting> arr(n);
        
        for(int i=0;i<n;i++){
            arr[i].starting=start[i];
            arr[i].ending=end[i];
            arr[i].pos=i+1;
        }
        
        sort(arr.begin(),arr.end(),comp);
        
        int count=1;
        int freetime= arr[0].ending;
        vector<int> position_store;
        position_store.push_back(arr[0].pos);  // in this solution it is not necessary basically it store the positon of that timing which have done the meeting
        
        for(int i=1;i<n;i++){
            if(arr[i].starting>freetime){
                count++;
                freetime=arr[i].ending;
                position_store.push_back(arr[i].pos); // not necessary
            }
        }
        return count;
    }