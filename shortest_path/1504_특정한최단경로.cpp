#include <bits/stdc++.h>

using namespace std;
using pii = pair<int, int>;
#define MAX 801
#define INF 987654321
vector<pii> vec[MAX];

int getMinDist(int dept, int dest)
{
    vector<int> dist(MAX, INF);
    dist[dept] = 0;
    priority_queue<pii> pq;
    pq.push({ -dist[dept], dept });

    while (!pq.empty()) {
        int cur = pq.top().second;
        int curDist = -pq.top().first;
        pq.pop();

        if (dist[cur] < curDist)
            continue;

        for (int i = 0; i < vec[cur].size(); i++) {
            int nxt = vec[cur][i].first;
            int nxtDist = vec[cur][i].second + curDist;
            if (dist[nxt] > nxtDist) {
                dist[nxt] = nxtDist;
                pq.push({ -nxtDist, nxt });
            }
        }
    }

    // cout<<"From: "<<dept<<"To: "<<dest<<" = "<<dist[dest]<<"\n";

    return dist[dest];
}
int main()
{
    int N, E;
    cin >> N >> E;
    long answer = INF;
    while (E--) {
        int a, b, c;
        cin >> a >> b >> c;
        vec[a].push_back({ b, c });
        vec[b].push_back({ a, c });
    }
    int V1, V2;
    cin >> V1 >> V2;

    int v1v2 = getMinDist(V1, V2);
    int V1toV2 = getMinDist(1, V1) + v1v2 + getMinDist(V2, N);
    int V2toV1 = getMinDist(1, V2) + v1v2 + getMinDist(V1, N);

    answer = min(V2toV1, V1toV2);

    cout << (answer >= INF || v1v2 == INF ? -1 : answer) << "\n";
    return 0;
}