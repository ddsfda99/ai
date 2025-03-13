#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
int n, m, dist[N], vis[N];
vector<int> g[N];
int bfs()
{
    memset(dist, 0x3f, sizeof dist);
    queue<int> q;
    q.push(1);
    dist[1] = 0;
    while (q.size())
    {
        int t = q.front();
        q.pop();
        if (vis[t])
            continue;
        vis[t] = 1;
        for (int i = 0; i < g[t].size(); i++)
        {
            int j = g[t][i];
            if (!vis[j])
            {
                dist[j] = dist[t] + 1;
                vis[j] = 1;
                q.push(j);
            }
        }
    }
    if (dist[n] == 0x3f3f3f3f)
        return -1;
    return dist[n];
}
int main()
{
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        g[a].push_back(b);
    }
    cout << bfs();
    return 0;
}