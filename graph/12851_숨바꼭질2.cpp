#include <bits/stdc++.h>

using namespace std;
using pii = pair<int, int>;
#define MAX 100001

int N, K;
int answer = MAX;
vector<bool> vis(MAX, false);
vector<int> cnt_answer(MAX, 0);

int main()
{

    cin >> N >> K;

    queue<pii> q; //position, cnt
    q.push({ N, 0 });
    while (!q.empty()) {
        int X = q.front().first;
        int C = q.front().second;
        q.pop();
        vis[X] = true;
        if (X == K) {
            answer = min(answer, C);
            if (answer == C)
                cnt_answer[answer]++;
            continue;
        }
        if (X - 1 >= 0 && !vis[X - 1])
            q.push({ X - 1, C + 1 });
        if (X + 1 < MAX && !vis[X + 1])
            q.push({ X + 1, C + 1 });
        if (2 * X < MAX && !vis[X * 2])
            q.push({ 2 * X, C + 1 });
    }

    //X-1, X+1, 2*x
    cout << answer << "\n"
         << cnt_answer[answer];

    return 0;
}