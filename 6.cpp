#include<bits/stdc++.h>
using namespace std;
string s;
map<string, int> dist;
int dx[] = {1, 0, -1, 0}, dy[] = {0, 1, 0, -1};
void dijkstra()
{
    priority_queue<pair<int, string>, vector<pair<int, string>>, greater<pair<int, string>>> h;
    dist[s] = 0;
    h.push(make_pair(0, s));
    while (h.size())
    {
        pair<int, string> t = h.top();
        h.pop();
        string str = t.second;
        int dis = t.first;
        if (str == "12345678x")
            return;
        int p = str.find('x');
        int x = p / 3, y = p % 3;
        for (int i = 0; i < 4; i++)
        {
            int nx = x + dx[i], ny = y + dy[i];
            if (nx < 0 || nx > 2 || ny < 0 || ny > 2)
                continue;
            int np = nx * 3 + ny;
            string str2 = str;
            swap(str2[p], str2[np]);
            if (dist.find(str2) == dist.end())
            {
                dist[str2] = dist[str] + 1;
                h.push(make_pair(dist[str2], str2));
            }
        }
    }
}
int main()
{
    for (int i = 0; i < 9; i++)
    {
        char c;
        cin >> c;
        s += c;
    }
    dijkstra();
    if (dist["12345678x"] == 0x3f3f3f3f)
        cout << -1;
    else
        cout << dist["12345678x"];
    return 0;
}