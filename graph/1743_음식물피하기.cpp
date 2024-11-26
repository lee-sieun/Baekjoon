#include <bits/stdc++.h>
#define MAX 101
using namespace std;

int N, M, K;
int path[MAX][MAX];
bool vis[MAX][MAX];
int cnt = 0;

int dx[] = { -1, 1, 0, 0 };
int dy[] = { 0, 0, -1, 1 };
void getScaleOfFoodWaste(int x, int y)
{
    cnt++;
    vis[x][y] = true;
    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (nx <= 0 || ny <= 0 || nx >= N + 1 || ny >= M + 1 || path[nx][ny] != 1 || vis[nx][ny])
            continue;
        getScaleOfFoodWaste(nx, ny);
    }
}
int main()
{

    cin >> N >> M >> K;

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            path[i][j] = 0;
            vis[i][j] = false;
        }
    }
    while (K--) {
        int x, y;
        cin >> x >> y;
        path[x][y] = 1;
    }
    int ans = 0;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            if (!vis[i][j] && path[i][j] == 1) {
                cnt = 0;
                getScaleOfFoodWaste(i, j);
                ans = max(ans, cnt);
            }
        }
    }
    cout << ans;
    return 0;
}