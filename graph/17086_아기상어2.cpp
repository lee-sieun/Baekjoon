#include <bits/stdc++.h>

using namespace std;
using pii = pair<int, int>;
#define MAX 51

int field[MAX][MAX];
int N, M;

int dx[] = {
    -1,
    1,
    -1,
    1,
    0,
    0,
    1,
    -1,
};
int dy[] = {
    1,
    -1,
    0,
    0,
    -1,
    1,
    1,
    -1,
};

int getSafetyDis(int x, int y)
{
    bool vis[N][M];
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            vis[i][j] = false;
        }
    }

    queue<pair<int, pii>> q;
    q.push({ 0, { x, y } });
    vis[x][y] = true;
    while (!q.empty()) {
        int dis = q.front().first;
        int xx = q.front().second.first;
        int yy = q.front().second.second;
        q.pop();

        if (field[xx][yy] == 1) {
            return dis;
        }
        for (int k = 0; k < 8; k++) {
            int nx = xx + dx[k];
            int ny = yy + dy[k];
            if (nx < 0 || ny < 0 || nx >= N || ny >= M || vis[nx][ny])
                continue;
            q.push({ dis + 1, { nx, ny } });
            vis[nx][ny] = true;
        }
    }
}
int main()
{

    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> field[i][j];
        }
    }

    int ans = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (field[i][j] == 0)
                ans = max(ans, getSafetyDis(i, j));
        }
    }

    cout << ans;

    return 0;
}