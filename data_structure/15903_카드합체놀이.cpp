#include <bits/stdc++.h>
using namespace std;

int main()
{
    priority_queue<long> cards;

    int n, m;
    cin >> n >> m;

    while (n--) {
        int card;
        cin >> card;
        cards.push(-card);
    }

    while (!cards.empty() && m--) {
        long first = -cards.top();
        cards.pop();
        long second = -cards.top();
        cards.pop();

        cards.push(-(first + second));
        cards.push(-(first + second));
    }

    long answer = 0;
    while (!cards.empty()) {
        answer += -cards.top();
        cards.pop();
    }

    cout << answer;

    return 0;
}