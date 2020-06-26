#include <bits/stdc++.h>

using namespace std;

int main() {
    ///freopen("choose2num.in", "r", stdin);
    ///freopen("choose2num.out", "w", stdout);
    int n, k, m;
    cin >> n >> k;
    int choose[k + 1];
    choose[0] = 0;
    for (int i = 1; i <= k; i++){
        cin >> choose[i];
    }
    long long c[n + 1][n + 1];
    for (int i = 0; i <= n; i++) {
        c[i][0] = 1;
    }
    for (int i = 0; i <= n; i++) {
        c[i][i] = 1;
    }
    for (int i = 2; i <= n; i++) {
        for (int j = 1 ; j < i; j++){
            c[i][j] = c[i - 1][j - 1] + c[i - 1][j];
        }
    }
    int numOfChoose = 0;
    for (int i = 1; i < k + 1; i++){
        for (int j = choose[i - 1] + 1; j <= choose[i] - 1; j++){
            numOfChoose += c[n - j][k - i];
        }
    }
    cout << numOfChoose;
    return 0;
}
