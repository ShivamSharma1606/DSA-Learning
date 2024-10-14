// optimal solution
// https://www.geeksforgeeks.org/problems/count-primes-in-range1604/1
//  TC: 10^6 + 10^6*log(log(n))

vector<int> sieve(int n)
{

    if (n < 2)
        return vector<int>(0);

    // we can also used for loop for this
    vector<int> dat(n, 1);

    dat[0] = dat[1] = 0;

    for (int i = 2; i * i <= n; i++)
    { // it is optimize version of i<=n

        if (dat[i] == 1)
        {
            for (int j = i * i; j < n; j += i)
            { 
                dat[j] = 0;
            }
        }
    }

    return dat;
}
int countPrimes(int L, int R)
{
    // code here
    vector<int> prime = sieve(R + 1);

    int cnt = 0;
    for (int i = 2; i <= R; i++)
    {
        cnt = cnt + prime[i];
        prime[i] = cnt;
    }

    return (prime[R] - prime[L - 1]);
}