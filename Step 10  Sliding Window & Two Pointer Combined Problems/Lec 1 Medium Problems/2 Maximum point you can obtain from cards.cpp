int maxScore(vector<int> &cardPoints, int k)
{

    int leftsum = 0;
    int rightsum = 0;
    int maxi = 0;

    for (int i = 0; i < k; i++)
    {
        leftsum += cardPoints[i];
    }
    maxi = leftsum;

    int rIndex = cardPoints.size() - 1;

    for (int j = k - 1; j >= 0; j--)
    {
        leftsum -= cardPoints[j];
        rightsum += cardPoints[rIndex];
        maxi = max(maxi, (leftsum + rightsum));
        rIndex--;
    }
    return maxi;
}