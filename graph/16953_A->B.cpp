#include <bits/stdc++.h>

using namespace std;

#define MAX 987654321

long A, B;
long answer = MAX;
void AtoB(long x, long cnt)
{
    if (x == B) {
        answer = min(answer, cnt);
        return;
    }
    if (x * 2 <= B)
        AtoB(x * 2, cnt + 1);
    if (x * 10 + 1 <= B)
        AtoB(x * 10 + 1, cnt + 1);
}
int main()
{
    cin >> A >> B;

    AtoB(A, 1);

    cout << (answer == MAX ? -1 : answer);

    return 0;
}