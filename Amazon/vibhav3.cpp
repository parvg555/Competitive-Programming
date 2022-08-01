#include <bits/stdc++.h>
#define ll long long int
using namespace std;

vector<vector<int>> adj; // adjacency list of graph
vector<pair<int, int>> ed;

vector<bool> visited;
vector<int> tin, low;
int timer;
int n, m;

vector<bool> visited2;
vector<int> dp2;

int dfs2(int s)
{
    visited2[s] = 1;
    dp2[s]++;
    for (auto x : adj[s])
    {
        if (!visited2[x])
        {
            dp2[s] += dfs2(x);
        }
    }
    return dp2[s] ;
}

ll ans = 0;

void IS_BRIDGE(int v, int to)
{
    ans += (dp2[v] - dp2[to]) * (dp2[to]);
}

void dfs(int v, int p = -1)
{
    visited[v] = true;
    tin[v] = low[v] = timer++;
    for (int to : adj[v])
    {
        if (to == p)
            continue;
        if (visited[to])
        {
            low[v] = min(low[v], tin[to]);
        }
        else
        {
            dfs(to, v);
            low[v] = min(low[v], low[to]);
            if (low[to] > tin[v])
            {
                IS_BRIDGE(v, to);
            }
        }
    }
}

void find_bridges()
{
    timer = 0;
    visited.assign(n + 1, false);
    tin.assign(n + 1, -1);
    low.assign(n + 1, -1);
    for (int i = 1; i <= n; ++i)
    {
        if (!visited[i])
            dfs(i);
    }
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        cin >> n >> m;
        ll x, y;
        for (int i = 0; i < m; ++i)
        {
            cin >> x >> y;
            ed.push_back(make_pair(x, y));
        }
        adj.resize(n + 1);
        for (auto p0 : ed)
        {
            adj[p0.first].push_back(p0.second);
            adj[p0.second].push_back(p0.first);
        }
        dp2.assign(n + 1, 0);
        visited2.assign(n + 1, false);

        ll z = dfs2(1);

        find_bridges();
        cout
            << ans << "\n";
    }
    return 0;
}