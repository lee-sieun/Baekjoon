#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    priority_queue<int> maxHeap;
    priority_queue<int, vector<int>, greater<int>> minHeap;

    int N;
    cin >> N;

    while (N--) {
        int x;
        cin >> x;

        if (maxHeap.size() == minHeap.size()) {
            maxHeap.push(x);
        } else {
            minHeap.push(x);
        }

        if (!maxHeap.empty() && !minHeap.empty() && maxHeap.top() > minHeap.top()) {
            int mx = maxHeap.top();
            int mn = minHeap.top();

            maxHeap.pop();
            minHeap.pop();

            maxHeap.push(mn);
            minHeap.push(mx);
        }
        cout << maxHeap.top() << '\n';
    }

    return 0;
}