
int findContentChildren(vector<int> &g, vector<int> &s)
{
    int n = g.size();  // greed size
    int m = s.size();   // cookies size

    sort(g.begin(), g.end());
    sort(s.begin(), s.end());

    int l = 0, r = 0;

    while (r < n && l < m)
    {
        if (g[r] <= s[l])
        {
            r++;
        }
        l++;
    }
    return r;
}
