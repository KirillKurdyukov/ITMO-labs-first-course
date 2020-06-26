#include <bits/stdc++.h>

using namespace std;

int dp[2002];
int from[2002];

int main()
{
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        dp[i] = 1;
    }
    int mx = 1;
    int index = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < i; j++){
            if (a[j] < a[i]) {
                if (dp[j] + 1 > dp[i]){
                    dp[i] = dp[j] + 1;
                    if (dp[i] > mx) {
                        index = i;
                        mx = dp[i];
                    }
                    from[i] = j;
                }
            }
        }
    }
    vector <int> answer;
  /*  cout << index << endl;
    for (int i = 0; i < n; i++) {
        cout << from[i] << endl;
    }*/
    while(from[index] != index){
        answer.push_back(a[index]);
        index = from[index];
    }
    answer.push_back(a[index]);
    sort(answer.begin(), answer.end());
    cout << mx << endl;
    for (auto now : answer)
        cout << now << " ";
    return 0;
}
