#include <bits/stdc++.h>

using namespace std;
string s;

int N;
vector <int> raz;

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
    freopen("num2part.in", "r", stdin);freopen("num2part.out", "w", stdout);
    cin >> s;
    int n = s.size();
    razb();
    int dp[n + 2][n + 2];

    for (int i = 0; i <= n; i++){
        for (int j = n; j >= 0; j--){
            if (i < j) {
                dp[i][j] = 1;
            }
            if (i == j)
                dp[i][j] = 0;
            if (i > j) {
                dp[i][j] = dp[i][j + 1] + dp[i - j][j];
            }
        }
    }
    /*for (auto i: raz) {
        cout << i << " ";
    }
    cout << endl;*/
    int num = 0, last = 0, sum = 0;
    for (int i = 0; i < raz.size(); i++) {
        for (int j = last; j <= raz[i] - 1; j++) {
            num +=  dp[N - sum - j][j];
        }
        sum += raz[i];
        last = raz[i];
    }
    cout << num;
    return 0;
}
