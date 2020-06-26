#include <bits/stdc++.h>

using namespace std;

int close, open;

int main()
{
    freopen("nextbrackets.in", "r", stdin);
    freopen("nextbrackets.out", "w", stdout);
    string s;
    cin >> s;
    int j = -1;
    for (int i = s.size() - 1; i >= 0; i--) {
        if (s[i] == '('){
            open++;
            if (close > open) {
                j = i;
                break;
            }
        } else
            close++;
    }
    if (j != -1) {
        string ans = "";
        for (int i = 0; i < j; i++) {
            ans += s[i];
        }
        ans += ')';
        for (int i = 0; i < open; i++) {
            ans += '(';
        }
        for (int i = 0; i < close - 1; i++) {
            ans += ')';
        }
        cout << ans << "\n";
    } else {
        cout << "-";
    }
    return 0;
}
