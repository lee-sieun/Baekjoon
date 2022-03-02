#include <bits/stdc++.h>

using namespace std;

using pii = pair<int, int>;
#define MAX 1001
#define INF 987654321

vector<int> dist(MAX, INF);
vector<pii> vec[MAX];

void getMinDistToDest(int dept)
{
    dist[dept] = 0; //시작점 초기화 0으로
    priority_queue<pii> pq;
    pq.push({ dist[dept], dept });

    while (!pq.empty()) {
        int cur = pq.top().second;
        int distance = -pq.top().first;
        pq.pop();

        if (dist[cur] < distance)
            continue;

        for (int i = 0; i < vec[cur].size(); i++) {
            int nxt = vec[cur][i].first;
            int nxtDist = vec[cur][i].second + distance; //cur을 지나서 nxt로 가는 distance

            if (nxtDist < dist[nxt]) {
                dist[nxt] = nxtDist;
                pq.push({ -nxtDist, nxt });
            }
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int N, M;
    cin >> N >> M;

    while (M--) {
        int s, e, d;
        cin >> s >> e >> d;
        vec[s].push_back({ e, d });
    }

    int departure, destination;
    cin >> departure >> destination;

    getMinDistToDest(departure);

    cout << dist[destination];

    return 0;
}