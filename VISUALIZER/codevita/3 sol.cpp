#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    unordered_map<string, vector<string>> adjList;
    unordered_set<string> allNodes, childNodes;
    for (int i = 0; i < n; ++i)
    {
        string parent, child;
        cin >> parent >> child;
        adjList[parent].push_back(child);
        allNodes.insert(parent);
        allNodes.insert(child);
        childNodes.insert(child);
    }
    string inputString;
    cin.ignore();
    getline(cin, inputString);
    string root;
    for (const auto &node : allNodes)
    {
        if (childNodes.find(node) == childNodes.end())
        {
            root = node;
            break;
        }
    }
    unordered_map<string, int> levels;
    if (!root.empty())
    {
        queue<pair<string, int>> q;
        q.push({root, 1});

        while (!q.empty())
        {
            auto [current, level] = q.front();
            q.pop();

            if (levels.find(current) != levels.end())
                continue;
            levels[current] = level;

            for (const auto &neighbor : adjList[current])
            {
                if (levels.find(neighbor) == levels.end())
                {
                    q.push({neighbor, level + 1});
                }
            }
        }
    }
    int totalValue = 0;
    stringstream ss(inputString);
    string word;
    while (ss >> word)
    {
        totalValue += levels.count(word) ? levels[word] : -1;
    }
    cout << totalValue << endl;
    return 0;
}
