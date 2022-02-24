#include <bits/stdc++.h>

using namespace std;
#define MAX 101

vector<bool> vis(MAX, false);
vector<int> nodes[MAX];
int cnt = 0;
void searchConnectedComputers(int node)
{
    vis[node] = true;
    for (int i = 0; i < nodes[node].size(); i++) {
        int nxt = nodes[node][i];
        if (!vis[nxt]) {
            cnt++;
            searchConnectedComputers(nxt);
        }
    }
}
int main()
{
    int N, M;
    cin >> N >> M;

    while (M--) {
        int a, b;
        cin >> a >> b;
        nodes[a].push_back(b);
        nodes[b].push_back(a);
    }

    searchConnectedComputers(1);
    cout << cnt;

    return 0;
}