#include <bits/stdc++.h>
using namespace std;
const int N = 510;
int n, m;
int dist[N], vis[N];
int g[N][N];
void dijkstra()
{
    memset(dist, 0x3f, sizeof dist);
    dist[1] = 0;
    for (int i = 0; i < n; i++)
    {
        int p = 0;
        for (int j = 1; j <= n; j++)
        {
            if (!vis[j] && (p == 0 || dist[p] > dist[j]))
                p = j;
        }
        vis[p] = 1;
        for (int j = 1; j <= n; j++)
        {
            if (!vis[j] && g[p][j] && dist[p] + g[p][j] < dist[j])
                dist[j] = dist[p] + g[p][j];
        }
    }
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    scanf("%d%d", &n, &m);
    memset(g, 0x3f, sizeof g);
    for (int i = 0; i < m; i++)
    {
        int u, v, w;
        scanf("%d%d%d", &u, &v, &w);
        g[u][v] = min(g[u][v], w);
    }
    dijkstra();
    if (dist[n] == 0x3f3f3f3f)
        cout << -1;
    else
        cout << dist[n];
    return 0;
}
