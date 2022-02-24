#include <bits/stdc++.h>

using namespace std;
using pii = pair<int, int>;
#define MAX 100001

int N, K;
int answer = MAX;
vector<bool> vis(MAX, false);

int main()
{
    cin >> N >> K;

    queue<pii> q;
    q.push({ N, 0 });
    while (!q.empty()) {
        int X = q.front().first;
        int C = q.front().second;
        q.pop();
        vis[X] = true;
        if (X == K) {
            answer = min(answer, C);
            continue;
        }
        if (X - 1 >= 0 && !vis[X - 1])
            q.push({ X - 1, C + 1 });
        if (X + 1 < MAX && !vis[X + 1])
            q.push({ X + 1, C + 1 });
        if (X * 2 < MAX && !vis[2 * X])
            q.push({ X * 2, C });
    }

    cout << answer << "\n";
    return 0;
}