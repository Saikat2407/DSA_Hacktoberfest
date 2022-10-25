// Leetcode: https://leetcode.com/problems/number-of-provinces/
#include <bits/stdc++.h>

#define ll long long
#define vl vector<ll>
#define PB push_back
#define MP make_pair

using namespace std;

int findCircleNum(vector<vector<int>> &isConnected)
{
    long long int i, j, n = isConnected[0].size();
    long long int cont = 0;
    vector<long long int> node[n + 1];
    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= n; j++)
        {
            if ((i != j) && (isConnected[i - 1][j - 1] == 1))
            {
                node[i].push_back(j);
                node[j].push_back(i);
            }
        }
    }

    bool vis[n + 1];
    memset(vis, 0, sizeof(vis));
    queue<long long int> q;

    for (i = 1; i <= n; i++)
    {
        if (vis[i] == false)
        {
            cont++;
            vis[i] = true;
            q.push(i);
            while (!q.empty())
            {
                int par = q.front();
                q.pop();

                for (auto x : node[par])
                {
                    if (vis[x] == false)
                    {
                        q.push(x);
                        vis[x] = true;
                    }
                }
            }
        }
    }

    return cont;
}

void solve()
{
    int i, j, n;
    cin >> n; // Enter total number of cities

    vector<vector<int>> isConnected(n);
    for (i = 0; i < n; i++)
    {
        isConnected[i].resize(n);
        for (j = 0; j < n; j++)
        {
            cin >> isConnected[i][j]; // Input only 1 or 0
        }
    }

    int result = findCircleNum(isConnected);
    cout << result << endl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int test_cases = 1;
    while (test_cases--)
    {
        solve();
    }
    return 0;
}