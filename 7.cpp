#include <bits/stdc++.h>
using namespace std;
int dx[] = {-1, 1, 0, 0}, dy[] = {0, 0, -1, 1};
char dir[] = {'u', 'd', 'l', 'r'};
priority_queue<pair<int, string>, vector<pair<int, string>>, greater<pair<int, string>>> q;
map<string, int> dist;
map<string, pair<string, int>> pre;
int eval(string s)
{
    int sum = 0;
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] != 'x')
        {
            int n = s[i] - '1';
            sum += abs(n / 3 - i / 3) + abs(n % 3 - i % 3);
        }
        else
        {
            int n = 8;
            sum += abs(n / 3 - i / 3) + abs(n % 3 - i % 3);
        }
    }
    return sum;
}
void Astar(string st)
{
    dist[st] = 0;
    q.push(make_pair(eval(st), st));
    while (q.size())
    {
        pair<int, string> t = q.top();
        q.pop();
        string str = t.second;
        int dis = dist[str];
        if (str == "12345678x")
            return;
        if (dis >= 31)
            return;
        int p = str.find('x');
        int x = p / 3, y = p % 3;
        for (int i = 0; i < 4; i++)
        {
            int nx = x + dx[i], ny = y + dy[i];
            int np = nx * 3 + ny;
            if (nx < 0 || nx > 2 || ny < 0 || ny > 2)
                continue;
            string str2 = str;
            swap(str2[p], str2[np]);
            if (dist.find(str2) == dist.end() || dist[str2] > dis + 1)
            {
                dist[str2] = dis + 1;
                pre[str2] = make_pair(str, i);
                q.push(make_pair(dist[str2] + eval(str2), str2));
            }
        }
    }
}
int main()
{
    string s;
    for (int i = 0; i < 9; i++)
    {
        char c;
        cin >> c;
        s += c;
    }
    Astar(s);
    if (!dist.count("12345678x"))
        puts("unsolvable");
    else
    {
        vector<char> ans;
        string tmp = "12345678x";
        while (tmp != s)
        {
            ans.push_back(dir[pre[tmp].second]);
            tmp = pre[tmp].first;
        }
        for (int i = ans.size() - 1; i >= 0; i--)
            cout << ans[i];
    }
    return 0;
}
