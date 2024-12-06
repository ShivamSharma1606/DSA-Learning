vector<int> MinimumCoins(int amt)
{
    // Write your code here
    vector<int> currency ={1, 2, 5, 10, 20, 50, 100, 500, 1000};

    int size=currency.size();
    int cnt=0;
    vector<int> result;

    for(int i=size-1;i>=0;i-- ){
        while(amt>=currency[i]){
            result.push_back(currency[i]);
            amt-=currency[i];
            cnt++;
        }
    }
    return result;
}