#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    priority_queue<int, vector<int>, greater<int>> pq;

    int N;
    cin >> N;
    int n = N * N;

    while (n--) {
        int x;
        cin >> x;
        pq.push(x);
        if (pq.size() > N)
            pq.pop();
    }

    cout << pq.top();
    return 0;
}