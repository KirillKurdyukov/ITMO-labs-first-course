#include <bits/stdc++.h>

using namespace std;

int dp[105][105];

int a[200];

vector <int > answer;

void ans (int n, int j) {
    if (n == 0)
        return;
    if (a[n] <= 100) {
        if (dp[n - 1][j] + a[n] <= dp[n - 1][j + 1]) {
            ans(n - 1, j);
        } else {
            answer.push_back(n);
            ans(n - 1, j + 1);
        }
    } else {
        if (j == 0) {
            ans(n - 1, j + 1);
            answer.push_back(n);
        } else {
            if (dp[n - 1][j - 1] + a[n] <= dp[n - 1][j + 1]) {
                ans(n - 1, j - 1);
            } else {
                answer.push_back(n);
                ans(n - 1, j + 1);
            }
        }
    }
}
int main()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = 0; i <= n + 2; i++) {
        for (int j = 0; j <= n + 2; j++) {
            dp[i][j] = 100100;
        }
    }
    dp[0][0] = 0;
    for (int i = 1; i <= n; i++){
        for (int j = 0; j <= i; j++){
            if (a[i] <= 100) {
                dp[i][j] = min(dp[i - 1][j] + a[i], dp[i - 1][j + 1]);
            } else {
                if (j == 0)
                    dp[i][j] = dp[i - 1][j + 1];
              else
                    dp[i][j] = min(dp[i - 1][j - 1] + a[i], dp[i - 1][j + 1]);
            }
        }
    }
    /*for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= n; j++) {
            cout << dp[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;*/
    int res = 100100;
    int kup = 0;
    for (int j = 0; j <= n; j++) {
        if (res >= dp[n][j]) {
            res = dp[n][j];
            kup = j;
        }
    }
    cout << res << "\n";
    ans(n, kup);
    cout << kup << " " << answer.size() << "\n";
    sort(answer.begin(), answer.end());
    for (auto now : answer)
        cout << now << "\n";
    return 0;
}
