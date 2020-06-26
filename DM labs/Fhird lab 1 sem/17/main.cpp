#include <bits/stdc++.h>

using namespace std;

long long dp[50][50];

int main() {
    freopen("num2brackets.in", "r", stdin);
    freopen("num2brackets.out", "w", stdout);
    long long n, k;
    cin >> n >> k;

    dp[0][0] = 1;
    for (int i = 1; i <= 2 * n; i++) {
        for (int j = 0; j <= i; j++){
            if (j == 0) {
                dp[i][j] = dp[i - 1][j + 1];
            } else
                dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j + 1];
        }
    }
    int depth = 0;
    string s = "";
    k++;
    for (int i = 0; i < 2 * n; i++) {
        if (dp[2 * n - (i + 1)][depth + 1] >= k) {
            s += '(';
            depth++;
        } else {
            k -= dp[2 * n - (i + 1)][depth + 1];
            s += ')';
            depth--;
        }
    }
    cout << s;
    return 0;
}
