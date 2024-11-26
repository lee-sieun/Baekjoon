#include <bits/stdc++.h>

using namespace std;

int N;
bool stop = false;

bool isGoodNum(string num)
{
    int len = num.size();
    int end = len - 1;
    for (int i = 1; i <= len / 2; i++) {
        string a = num.substr(end - i, i);
        string b = num.substr(end--, i);
        if (!a.compare(b))
            return false;
    }

    return true;
}
void makeGoodNumber(int n, string num)
{
    if (stop)
        return;
    if (n == N) {
        stop = true;
        cout << num;
    }
    for (int i = 1; i <= 3; i++) {
        if (isGoodNum(num + to_string(i))) {
            makeGoodNumber(n + 1, num + to_string(i));
        }
    }
}
int main()
{
    cin >> N;

    makeGoodNumber(0, "");

    return 0;
}