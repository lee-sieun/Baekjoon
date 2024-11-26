#include <bits/stdc++.h>

using namespace std;
using pii = pair<int, int>;
#define MAX 50001
#define INF 987654321
int N, M;
vector<pii> path[MAX];
vector<int> dist(MAX, INF);

int getMinDist(int departure, int destination)
{

    dist[departure] = 0;
    std::priority_queue<pii> pq;
    pq.push({ -dist[departure], departure });
    while (!pq.empty()) {
        int cur = pq.top().second;
        int curDist = -pq.top().first;
        pq.pop();

        if (dist[cur] < curDist)
            continue;
        for (int k = 0; k < path[cur].size(); k++) {
            int nxt = path[cur][k].first;
            int nxtDist = path[cur][k].second + curDist;

            if (dist[nxt] > nxtDist) {
                dist[nxt] = nxtDist;
                pq.push({ -nxtDist, nxt });
            }
        }
    }

    return dist[destination];
}
int main()
{

    cin >> N >> M;
    while (M--) {
        int a, b, c;
        cin >> a >> b >> c;
        path[a].push_back({ b, c });
        path[b].push_back({ a, c });
    }

    cout << getMinDist(1, N);

    return 0;
}