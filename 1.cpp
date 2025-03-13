#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
int n, m, dist[N], vis[N];
set<int> g[N];
void bfs()
{
    queue<int> q;
    q.push(1);
    dist[1] = 0;
    vis[1] = 1;
    while (q.size())
    {
        int t = q.front();
        q.pop();
        for (const auto &j : g[t])
        {
            if (!vis[j])
            {
                dist[j] = dist[t] + 1;
                vis[j] = 1;
                q.push(j);
            }
        }
    }
}
int main()
{
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        g[a].insert(b);
    }
    bfs();
    if (vis[n] == 0)
        cout << -1;
    else
        cout << dist[n];
    return 0;
}
