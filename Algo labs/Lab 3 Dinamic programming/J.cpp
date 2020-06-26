#include <bits/stdc++.h>

using namespace std;

bool isTrue(long long a, long long b, int n) {
    int pr1[n], pr2[n];
    for (int i = 0; i < n; i++){
        pr1[i] = a % 2;
        a /= 2;
        pr2[i] = b % 2;
        b /= 2;
    }
    int k = 0;
    int k1 = 0;
    for (int i = 0; i < n; i++){
        if (pr1[i] == 1 && pr2[i] == 1) {
            k++;
        } else {
            k = 0;
        }
        if (pr1[i] == 0 && pr2[i] == 0) {
            k1++;
        } else {
            k1 = 0;
        }
        if (k >= 2 || k1 >= 2) {
            return false;
        }
    }
    return true;
}
int main()
{
    int n, m;
    cin >> n >> m;
    if (n > m)
        swap (n, m);
    long long a[m][(1 << n)] = {0};
    for (long long i = 0; i < (1 << n); i++){
        a[0][i] = 1;
    }
    /*int dp[(1 << n)][(1 << n)];
    for (long long i = 0; i < (1 << n); i++) {
        for (long long j = 0; j < (1 << n); j++) {
            if (isTrue(i, j, n)) {
                dp[i][j] = 1;
            } else {
                dp[i][j] = 0;
            }
        }
    }*/

    for (int k = 1; k < m; k++){
        for (long long i = 0; i < (1 << n); i++){
            for (long long j = 0; j < (1 << n); j++) {
                if (isTrue(i, j, n))
                    a[k][i] += a[k - 1][j];
            }
        }
    }
    long long ans = 0;
    for (long long i = 0; i < (1 << n); i++) {
        ans += a[m - 1][i];
    }
    cout << ans;
    return 0;
}
