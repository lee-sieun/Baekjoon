#include <bits/stdc++.h>

using namespace std;
using pll = pair<long, long>;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    priority_queue<pll> pq;
    int N;
    cin >> N;

    while (N--) {
        long x;
        cin >> x;
        if (x == 0) {
            if (pq.empty()) {
                cout << 0 << "\n";
                continue;
            }
            cout << -pq.top().second << "\n";
            pq.pop();
        } else {
            pq.push({ -abs(x), -x });
        }
    }
    return 0;
}