#include<bits/stdc++.h>
using namespace std;
#define pii pair<int,int>
const int N = 510;
int n, m, dist[N], vis[N];
int g[N][N];
void dijkstra()
{
    memset(dist, 0x3f, sizeof dist);
    dist[1] = 0;
    for (int i = 0; i < n - 1; i++)
    {
        int mn = 0x3f3f3f3f, p = 0;
        for (int j = 1; j <= n; j++)
        {
            if (!vis[j] && dist[j] < mn)
            {
                mn = dist[j];
                p = j;
            }
        }
        if (p == 0)
            break;
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
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        g[a][b] = c;
    }
    dijkstra();
    if (dist[n] == 0x3f3f3f3f)
        cout << -1;
    else
        cout << dist[n];
    return 0;
}
