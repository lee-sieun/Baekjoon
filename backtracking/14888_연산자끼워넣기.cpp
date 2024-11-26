#include <bits/stdc++.h>

using namespace std;

#define MAX 999999999
#define MIN -999999999

int op[4];
int op_comb[11];
int num[11];
int N;
long mx = MIN, mn = MAX;

void backtracking(int n)
{
    if (N - 1 == n) {
        long res = num[0];
        for (int i = 0; i < N - 1; i++) {
            if (op_comb[i] == 0) { //더하기
                res += num[i + 1];
            } else if (op_comb[i] == 1) { //빼기
                res -= num[i + 1];
            } else if (op_comb[i] == 2) { //곱하기
                res *= num[i + 1];
            } else { //나누기
                res /= num[i + 1];
            }
        }
        mx = max(mx, res);
        mn = min(mn, res);
        return;
    }
    for (int i = 0; i < 4; i++) {
        if (op[i] != 0) {
            op[i]--;
            op_comb[n] = i;
            backtracking(n + 1);
            op[i]++;
        }
    }
}
int main()
{
    cin >> N;

    for (int i = 0; i < N; i++) {
        cin >> num[i];
    }

    for (int i = 0; i < 4; i++) {
        cin >> op[i];
    }

    backtracking(0);
    cout << mx << "\n"
         << mn;

    return 0;
}