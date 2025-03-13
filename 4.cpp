#include<bits/stdc++.h>
using namespace std;
string s;
map<string, int> mp;
int dx[] = {1, 0, -1, 0}, dy[] = {0, 1, 0, -1};
bool dfs(string str)
{
    if (str == "12345678x")
        return true;
    mp[str] = 1;
    int p = 0;
    while (str[p]!='x')
        p++;
    int x = p / 3, y = p % 3;
    for (int i = 0; i < 4; i++)
    {
        int nx = x + dx[i], ny = y + dy[i];
        if (nx < 0 || nx > 2 || ny < 0 || ny > 2)
            continue;
        int npos = nx * 3 + ny;
        swap(str[p], str[npos]);
        if (mp.find(str) == mp.end())
        {
            if (dfs(str))
                return true;
        }
        swap(str[p], str[npos]);
    }
    return false;
}
int main()
{
    for (int i = 0; i < 9; i++)
    {
        char t;
        cin >> t;
        s += t;
    }
    if (dfs(s))
        cout << 1;
    else
        cout << 0;
    return 0;
}
