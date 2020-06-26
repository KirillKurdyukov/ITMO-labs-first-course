#include <bits/stdc++.h>

using namespace std;
string s;

int N;
vector <int> raz;
int dp[100 + 5][100 + 5];

void razb() {
    int temp = 0;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] >= '0' && s[i] <= '9') {
            temp = ((int) s[i] - 48) + temp * 10;
        } else {
            raz.push_back(temp);
            N += temp;
            temp = 0;
        }
    }
    raz.push_back(temp); N += temp;
}
int main() {
    freopen("part2num.in", "r", stdin);freopen("part2num.out", "w", stdout);
    cin >> s;
    int n = s.size();
    razb();

    for (int i = 1; i <= 102; i++){
        for (int j = 100; j >= 1; j--){
            if (i < j) {
                dp[i][j] = 0;
            }
            else if (i == j)
                dp[i][j] = 1;
            else {
                dp[i][j] = dp[i][j + 1] + dp[i - j][j];
            }
        }
    }
    int num = 0, last = 0, sum = 0;
    for (int i = 0; i < raz.size(); i++) {
        for (int j = last; j <= raz[i] - 1; j++) {
            num += dp[N - sum - j][j];
           /// cout << N - sum - j << " " << dp[N - sum - j][j] << "\n";
        }
        sum += raz[i];
        last = raz[i];
    }
    cout << num;
    return 0;
}
