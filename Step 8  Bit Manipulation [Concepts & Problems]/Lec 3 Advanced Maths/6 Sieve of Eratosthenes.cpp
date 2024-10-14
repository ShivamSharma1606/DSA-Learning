// sieve of erothosthenes
// pen and paper: for 30 ,50
// TC: n + nlog(log(n)) n

int countPrimes(int n)
{

    if (n < 2)
        return 0;

    // we can also used for loop for this
    vector<int> dat(n, 1);

    dat[0] = dat[1] = 0;

    for (int i = 2; i * i <= n; i++)
    { // it is optimize version of i<=n

        if (dat[i] == 1)
        {
            for (int j = i * i; j < n; j += i)
            { // it is optimize version of j=i*2
                dat[j] = 0;
            }
        }
    }

    // we can also used for loop for this
    return count(dat.begin(), dat.end(), 1);
}

int main()
{
}