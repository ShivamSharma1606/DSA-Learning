// todo: do dry run on copy[must]
//! tc: O(4 aplpha) ~ O(constant)
// https://www.geeksforgeeks.org/problems/disjoint-set-union-find/1

#include <bits/stdc++.h>
using namespace std;


int find(int a[], int x);
void unionSet(int a[], int x, int z);
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int a[n + 1];
        for (int i = 1; i <= n; i++)
            a[i] = i;
        int k;
        cin >> k;
        for (int i = 0; i < k; i++)
        {
            string s;
            cin >> s;
            if (s == "UNION")
            {
                int z, x;
                cin >> x >> z;
                unionSet(a, x, z);
            }
            else
            {
                int x;
                cin >> x;
                int parent = find(a, x);
                cout << parent << " ";
            }
        }
        cout << endl;

        cout << "~" << "\n";
    }
}

int find(int A[], int X)
{
    if (A[X] == X)
    {
        return X;
    }
    return A[X] = find(A, A[X]); // Path compression
}
void unionSet(int A[], int X, int Z)
{
    int parentX = find(A, X);
    int parentZ = find(A, Z);

    if (parentX != parentZ)
    {
        A[parentX] = parentZ; // Union by assigning parent
    }
}