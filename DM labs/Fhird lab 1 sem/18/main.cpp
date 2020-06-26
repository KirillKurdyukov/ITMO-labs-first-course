#include <bits/stdc++.h>

using namespace std;

long long dp[50][50];

int main() {
    freopen("brackets2num.in", "r", stdin);freopen("brackets2num.out", "w", stdout);
    string s;
    cin >> s;

    dp[0][0] = 1;
    for (int i = 1; i <= s.size(); i++) {
        for (int j = 0; j <= i; j++){
            if (j == 0) {
                dp[i][j] = dp[i - 1][j + 1];
            } else
                dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j + 1];
        }
    }
    long long num = 0;
    int depth = 0;

    for (int i = 0; i < s.size(); i++) {
        if (s[i] == '(')
            depth++;
        else {
            num += dp[s.size() - 1 - i][depth + 1];
            depth -- ;
        }
    }
    cout << num;
    return 0;
}
