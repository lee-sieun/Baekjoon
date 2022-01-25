#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    priority_queue<long> pq;
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
            cout << pq.top() << "\n";
            pq.pop();
        } else {
            pq.push(x);
        }
    }
    return 0;
}