#include <bits/stdc++.h>

using namespace std;

int main()
{
    priority_queue<int, vector<int>, greater<int>> pq;
    int N;
    cin >> N;

    while (N--) {
        int x;
        cin >> x;
        pq.push(x);
    }

    int answer = 0;
    while (!pq.empty() && pq.size() > 1) {
        int a = pq.top();
        pq.pop();
        int b = pq.top();
        pq.pop();
        answer += a + b;
        pq.push(a + b);
    }

    cout << answer;
    return 0;
}