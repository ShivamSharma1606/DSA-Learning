/*
Time Complexity: O(N * queries).
Space Complexity: O(queries).
*/

vector<int> count_NGE(int n, vector<int> &arr, int queries, vector<int> &indices)
{
    // write your code here

    vector<int> ans;
    for (int i = 0; i < queries; i++)
    {
        int check = arr[indices[i]];
        int count = 0;
        for (int j = indices[i]; j < arr.size(); j++)
        {
            if (check < arr[j])
                count++;
        }
        ans.push_back(count);
    }

    return ans;
}

int main(){

}