#include <bits/stdc++.h>

using namespace std;

string s;

vector < vector < int > > dp;

vector < vector < int > > ep;

void rec(int l, int r) {
    if (dp[l][r] == r - l + 1)
        return;
    if (dp[l][r] == 0) {
        cout << s.substr(l, r - l + 1);
        return;
    }
    if (ep[l][r] == -1){
        cout << s[l];
        rec(l + 1, r - 1);
        cout << s[r];
        return;
    }
    rec(l, ep[l][r]);
    rec(ep[l][r] + 1, r);
}
int main()
{
    cin >> s;
    dp.resize(s.size() + 1);
    for (int i = 0; i < s.size(); i++)
        dp[i].resize(s.size() + 1);
    for (int i = 0; i < s.size(); i++) {
        dp[i][i] = 1;
    }
    ep.resize(s.size() + 1);
    for (int i = 0; i < s.size(); i++)
        ep[i].resize(s.size() + 1);
    for (int i = 0; i < s.size(); i++) {
        ep[i][i] = -1;
    }
    for (int r = 0; r < s.size(); r++) {
        for (int l = r - 1; l >= 0; l--) {
            if (l != r) {
                int mk = -1;
                int mn = 1000;
                if (s[l] == '(' && s[r] == ')' || s[l] == '{' && s[r] == '}' || s[l] == '[' && s[r] == ']')
                    mn = dp[l + 1][r - 1];
                for (int k = l; k < r; k++) {
                    if (mn > dp[l][k] + dp[k + 1][r]) {
                        mn = dp[l][k] + dp[k + 1][r];
                        mk = k;
                    }
                }
                dp[l][r] = mn;
                ep[l][r] = mk;
            }
        }
    }
    for (int i = 0 ; i < s.size(); i++ ){
        for (int j = 0; j < s.size(); j++){
            cout << dp[i][j] << " ";
        }
        cout << endl;
    }
    rec(0, s.size() - 1);
    return 0;
}
