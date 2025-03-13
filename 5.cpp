#include <bits/stdc++.h>
using namespace std;
int dx[] = {1, 0, -1, 0}, dy[] = {0, 1, 0, -1};
unordered_map<string, int> dist;
string s;
int bfs(string st)
{
    queue<string> q;
    q.push(st);
    while (!q.empty())
    {
        string t = q.front();
        q.pop();
        if (t == "12345678x")
            return dist[t];
        int p = t.find('x'); 
        int x = p / 3, y = p % 3;  
        for (int i = 0; i < 4; i++)
        {
            int nx = x + dx[i], ny = y + dy[i];
            if (nx < 0 || nx > 2 || ny < 0 || ny > 2)
                continue;                    
            int npos = nx * 3 + ny;
            string tmp = t;
            swap(t[p], t[npos]);
            if (dist.find(t) == dist.end())
            {
                dist[t] = dist[tmp] + 1;
                q.push(t);
            }
            swap(t[p], t[npos]);
        }
    }
    return -1;
}
int main()
{
    for (int i = 0; i < 9; i++)
    {
        char t;
        cin >> t;
        s += t;
    }
    cout << bfs(s);
    return 0;
}
