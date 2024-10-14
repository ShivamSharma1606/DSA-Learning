//brute force approach : O(n^2)
//samNotes

//better approach

int longestRepeatingSubstring(string &str, int k) {
    // Write your code here.
    int l=0;
    int r=0;
    int hash[26]={0};   //it is an array of 26 length
    int len=0;
    int maxfreq=0;

    while(r<str.size()){

        hash[str[r]-'A']++;
        maxfreq=max(maxfreq,hash[str[r]-'A']);

        while((r-l+1)-maxfreq>k){
            hash[str[l]-'A']--;
            l++;
        }
        if((r-l+1)-maxfreq<=k){
            len=max(len,r-l+1);
        }
        r++;
    }

    return len;
}

//optimal solution


int longestRepeatingSubstring(string &str, int k) {
    // Write your code here.
    int l=0;
    int r=0;
    int hash[26]={0};   //it is an array of 26 length
    int len=0;
    int maxfreq=0;

    while(r<str.size()){

        hash[str[r]-'A']++;
        maxfreq=max(maxfreq,hash[str[r]-'A']);

        if((r-l+1)-maxfreq>k){
            hash[str[l]-'A']--;
            l++;
        }
        if((r-l+1)-maxfreq<=k){
            len=max(len,r-l+1);
        }
        r++;
    }

    return len;
}