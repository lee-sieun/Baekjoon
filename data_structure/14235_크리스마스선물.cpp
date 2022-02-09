#include <bits/stdc++.h>

using namespace std;

int main()
{
    priority_queue<int> gifts;

    int n;
    cin >> n;

    while (n--) {
        int a;
        cin >> a;
        if (a == 0) {
            if (gifts.empty()) {
                cout << -1 << "\n";
                continue;
            }
            cout << gifts.top() << "\n";
            gifts.pop();
        } else {
            while (a--) {
                int gift;
                cin >> gift;
                gifts.push(gift);
            }
        }
    }
    return 0;
}