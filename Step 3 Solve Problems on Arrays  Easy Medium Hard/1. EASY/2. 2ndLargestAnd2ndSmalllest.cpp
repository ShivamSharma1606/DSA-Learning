int Slargest(vector<int> &a, int n)
{
    int largest = a[0];
    int slargest = INT_MIN;
    for (int i = 1; i < n; i++)
    {
        if (a[i] > largest)
        {
            slargest = largest;
            largest = a[i];
        }
        else if (a[i] < largest && slargest < a[i])
        {
            slargest = a[i];
        }

        
    }
    return slargest;
}
int Ssmallest(vector<int> &a, int n)
{
    int smallest = a[0];
    int ssmallest = INT_MAX;
    for (int i = 1; i < n; i++)
    {
        if (a[i] < smallest)
        {
            ssmallest = smallest;
            smallest = a[i];
        }
        else if (a[i] != smallest && ssmallest > a[i])
        {
            ssmallest = a[i];
        }
    }
    return ssmallest;
}

vector<int> getSecondOrderElements(int n, vector<int> a)
{
    // Write your code here.
    int secoundLarges = Slargest(a, n);
    int secoundSmallest = Ssmallest(a, n);
    return {secoundLarges, secoundSmallest};
}

int main()
{
}
