#include <bits/stdc++.h>

using namespace std;

long long dp[10004];
int way[10004];

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int n, k;
    cin >> n >> k;
    for (int i = 2; i < n; i++) {
        cin >> dp[i];
    }
    way[1] = 1;
    for(int i = 2; i <= k + 1; i++){
        int mx = -100000000, to = 0;
        for (int j = 1; j < i; j++){
            if (dp[j] >= mx){
                mx = dp[j];
                to = j;
            }
        }
        dp[i] += mx;
        way[i] = to;
    }
    for (int i = 2 + k; i <= n; i++) {
        int mx = -100000000, to = 0;
        for (int j = i - 1; j >= i - k; j--) {
            if (dp[j] > mx){
                mx = dp[j];
                to = j;
            }
        }
        dp[i] += mx;
        way[i] = to;
    }
    cout << dp[n] << endl;
    int pos = n;
    vector<int> ans;
    ans.push_back(n);
    while (way[pos] != pos) {
        /// cout << way[pos] << " ";
        ans.push_back(way[pos]);
        pos = way[pos];
    }
    cout << ans.size() - 1 << "\n";
    for (int i = ans.size() - 1; i >= 0; i--) {
        cout << ans[i] << " ";
    }
    return 0;
}
