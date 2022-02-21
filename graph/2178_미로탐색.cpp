#include <bits/stdc++.h>

using namespace std;
using pii = pair<int, int>;

int N, M;
int maze[101][101];
int dx[] = { -1, 1, 0, 0 };
int dy[] = { 0, 0, -1, 1 };

int getMinPath()
{
    queue<pii> q;
    q.push({ 0, 0 });

    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx < 0 || ny < 0 || nx >= N || ny >= M || maze[nx][ny] != 1)
                continue;
            maze[nx][ny] = maze[x][y] + 1;
            q.push({ nx, ny });
        }
    }

    return maze[N - 1][M - 1];
}
int main()
{
    cin >> N >> M;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            scanf("%1d", &maze[i][j]);
        }
    }

    cout << getMinPath();
    return 0;
}