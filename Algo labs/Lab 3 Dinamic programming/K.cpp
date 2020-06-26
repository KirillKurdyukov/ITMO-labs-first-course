#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4.1,sse4.2,sse4a,popcnt,abm,mmx,avx,avx2,tune=native")
#include <bits/stdc++.h>

using namespace std;


vector < int > cor;

vector < vector < bool > > dp;

vector < vector <int> > down;

bool isCor(){
    int Kirill = 0;
    for (int i = 0; i < cor.size(); i++){
        if (cor[i] == 0)
            Kirill++;
    }
    if (Kirill == cor.size())
        return false;

    return true;
}

void answer(int n, int temp, int k) {
    //cout << "Kirill lox" << endl;
    if (n == 0)
        return;
    if (dp[n - 1][temp])
        answer(n - 1, temp, k);
    else {
        if (dp[n - 1][temp - cor[n]]) {
            down[k].push_back(n);
            answer(n - 1, temp - cor[n], k);
            cor[n] = 0;
        }
    }
}
int main()
{
    freopen("skyscraper.in", "r", stdin);
    freopen("skyscraper.out", "w", stdout);
    long long n, w;
    cin >> n >> w;
    dp.resize(n + 1);
    down.resize(n);
    for (int i = 0; i <= n; i++){
         dp[i].resize(w + 1);
    }
    long long sum = 0;
    cor.push_back(0);
    for (int i = 0; i < n; i++){
        dp[i][0] = true;
        int c;
        cin >> c;
        cor.push_back(c);
        sum += c;
    }
    dp[n][0] = true;
    int k = 0;
    w = min(sum, w);
    /*for (int i = 1; i <= n; i++){
        for (int j = 1; j <= w; j++) {
            if (j - cor[i] < 0) {
                dp[i][j] = dp[i - 1][j];
            } else {
                dp[i][j] = dp[i - 1][j] + dp[i - 1][j - cor[i]];
            }
        }
    }*/
    /*for (int i = 0; i <= n; i++){
        for (int j = 0; j <= w; j++) {
            cout << dp[i][j] << " ";
        }
        cout << endl;
    }
    answer(4,10,0);
    for (int i = 0; i < down[0].size(); i++)
        cout << down[0][i] << " ";*/
    while (isCor()) {
        for (int i = 1; i <= n; i++){
            for (int j = 1; j <= w; j++) {
                if (j - cor[i] < 0) {
                    dp[i][j] = dp[i - 1][j];
                } else {
                    dp[i][j] = dp[i - 1][j] + dp[i - 1][j - cor[i]];
                }
            }
        }
        int temp = w;
        int ans;
        while (temp > 0) {
            if (dp[n][temp]) {
                ans = temp;
                break;
            }
            temp--;
        }
        //cout << ans << endl;
        answer(n, ans, k);
        k++;
        //cout << "Kirill sosi";
        dp.assign(n + 1, vector<bool>(w + 1));
        for (int i = 0; i <= n; i++)
            dp[i][0] = true;
    }
    cout << k;
    cout << endl;
    for (int i = 0; i < k; i++){
        sort(down[i].begin(), down[i].end());
        cout << down[i].size() << " ";
        for (int j = 0; j < down[i].size(); j++){
            cout << down[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}























