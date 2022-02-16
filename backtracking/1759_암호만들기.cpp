#include <bits/stdc++.h>

using namespace std;

#define MAX 16

char alpha[MAX];
char passcode[MAX];
int l, c;

void make_passcode(int k, int idx)
{
    if (k == l) {
        int c = 0, v = 0;
        string pc = "";
        for (int i = 0; i < l; i++) {
            pc += passcode[i];
            if (passcode[i] == 'a' || passcode[i] == 'e' || passcode[i] == 'i' || passcode[i] == 'o' || passcode[i] == 'u')
                c++;
            else
                v++;
        }
        if (c >= 1 && v >= 2)
            cout << pc << "\n";
        return;
    }
    for (int i = idx; i < c; i++) {
        passcode[k] = alpha[i];
        make_passcode(k + 1, i + 1);
    }
}
int main()
{

    cin >> l >> c;
    for (int i = 0; i < c; i++) {
        cin >> alpha[i];
    }

    sort(alpha, alpha + c);

    make_passcode(0, 0);

    return 0;
}