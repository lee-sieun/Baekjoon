#include <bits/stdc++.h>

using namespace std;

using pii = pair<int, int>;

int main()
{

    priority_queue<int> pq;
    int dasom = 0;
    int cnt = 0;
    int N;
    cin >> N;

    for (int i = 1; i <= N; i++) {
        int x;
        cin >> x;
        if (i == 1) {
            dasom = x;
            continue;
        }
        pq.push(x);
    }

    while (!pq.empty() && pq.top() >= dasom) {
        cnt++;
        int first = pq.top();
        pq.pop();
        pq.push(--first);
        dasom++;
    }

    cout << cnt;
    return 0;
}