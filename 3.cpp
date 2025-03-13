#include<bits/stdc++.h>
using namespace std;
#define pii pair<int,int>
const int N = 2e5;
int n, m, dist[N], vis[N];
vector<pii> g[N];
void dijkstra()
{
    memset(dist, 0x3f, sizeof dist);
    dist[1] = 0;
    priority_queue<pii, vector<pii>, greater<pii>> h;
    h.push(make_pair(0, 1));
    while (h.size())
    {
        pii t = h.top();
        h.pop();
        int dis = t.first, v = t.second;
        if (vis[v])
            continue;
        vis[v] = 1;
        for (int j = 0; j < g[v].size(); j++)
        {
            int k = g[v][j].first, d = g[v][j].second;
            if (!vis[k] && dis + d < dist[k])
            {
                dist[k] = dis + d;
                h.push(make_pair(dist[k], k));
            }
        }
    }
}
int main()
{
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        g[a].push_back(make_pair(b, c));
    }
    dijkstra();
    if (dist[n] == 0x3f3f3f3f)
        cout << -1;
    else
        cout << dist[n];
    return 0;
}