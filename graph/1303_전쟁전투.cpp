#include <bits/stdc++.h>

using namespace std;
#define MAX 101

int N, M;
char field[MAX][MAX];
bool vis[MAX][MAX];
int dx[] = { -1, 1, 0, 0 };
int dy[] = { 0, 0, -1, 1 };
int cnt = 0;

void count_soldiers(int x, int y, char color)
{
    cnt++;
    vis[x][y] = true;
    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (nx < 0 || ny < 0 || nx >= N || ny >= M || vis[nx][ny] || field[nx][ny] != color)
            continue;
        vis[nx][ny] = true;
        count_soldiers(nx, ny, color);
    }
}
int main()
{
    cin >> M >> N;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> field[i][j];
            vis[i][j] = false;
        }
    }

    int white = 0, black = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (!vis[i][j]) {
                cnt = 0;
                if (field[i][j] == 'W') {
                    count_soldiers(i, j, 'W');
                    white += cnt * cnt;
                } else if (field[i][j] == 'B') {
                    count_soldiers(i, j, 'B');
                    black += cnt * cnt;
                }
            }
        }
    }

    cout << white << " " << black;
    return 0;
}