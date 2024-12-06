    #include <bits/stdc++.h>
    using namespace std;

    int main()
    {
        string bs;
        cin >> bs;

        int size = bs.size();
        vector<int> worth(size);
        for (int i = 0; i < size; ++i)
        {
            cin >> worth[i];
        }

        int remove = 0;
        char last = bs[0];
        int lastIndex = 0;

        for (int i = 1; i < size; ++i)
        {
            if (bs[i] == last)
            {
                if (worth[i] < worth[lastIndex])
                {
                    remove += worth[i];
                }
                else
                {
                    remove += worth[lastIndex];
                    lastIndex = i;
                }
            }
            else
            {
                last = bs[i];
                lastIndex = i;
            }
        }

        cout << remove << endl;

        return 0;
    }
