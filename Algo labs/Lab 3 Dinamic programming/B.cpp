#include <bits/stdc++.h>

using namespace std;
int dp[1001][1001];
int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int n1, n2;
    cin >> n1 >> n2;
    for (int i = 0; i < n1; i++){
        for (int j = 0; j < n2; j++){
            cin >> dp[i][j];
        }
    }
    for (int i = 1; i < n2; i++) {
        dp[0][i] += dp[0][i - 1];
    }
    for (int i = 1; i < n1; i++) {
        dp[i][0] += dp[i - 1][0];
    }
    for (int i = 1; i < n1; i++){
        for (int j = 1; j < n2; j++){
            dp[i][j] += max(dp[i - 1][j], dp[i][j - 1]);
        }
    }
    cout << dp[n1 - 1][n2 - 1] << endl;
    int i = n1 - 1;
    int j = n2 - 1;
    vector <char> answer;
    while (i != 0 && j != 0){
        if (dp[i - 1][j] > dp[i][j - 1 ]) {
            answer.push_back('D');
            i--;
            //cout << 'R' << endl;
        } else {
            answer.push_back('R');
            //cout << 'D' << endl;
            j--;
        }
    }
    if (j == 0 && i != 0) {
        while (i != 0) {
            answer.push_back('D');
            i--;
        }
    }
    if (j != 0 && i == 0) {
        while (j != 0) {
            answer.push_back('R');
            j--;
        }
    }
    for (int k = answer.size() - 1; k >= 0; k--) {
        cout << answer[k];
    }
    return 0;
}
