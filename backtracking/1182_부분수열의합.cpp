#include <bits/stdc++.h>

using namespace std;
#define MAX 21

int cnt = 0;
int N, S;
int num[MAX];

void dfs(int n, int sum)
{
    if (n == N) {
        //   cout<<sum<<" ";
        if (sum == S)
            cnt++;
        return;
    }
    dfs(n + 1, sum);
    dfs(n + 1, sum + num[n]);
}
int main()
{

    cin >> N >> S;
    for (int i = 0; i < N; i++)
        cin >> num[i];

    if (S == 0)
        cnt--;
    dfs(0, 0);
    cout << cnt;
}