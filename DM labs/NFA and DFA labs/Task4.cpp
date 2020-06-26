//
// Created by sl771 on 01.05.2020.
//

#include <bits/stdc++.h>

using namespace std;

int n, m, k, l;
bool terminal[100001];
int go[101][256];
long long can[1001][101];

int main() {
    freopen("problem4.in", "r", stdin);
    freopen("problem4.out", "w", stdout);
    cin >> n >> m >> k >> l;
    for (int i = 0; i < k; i++) {
        int temp;
        cin >> temp;
        terminal[temp] = true;
    }
    for(int i = 0; i < m; i++) {
        int a, b;
        char c;
        cin >> a >> b >> c;
        go[a][c] = b;
    }
    can[0][1] = 1;
    for (int i = 0; i < l; i++) {
        for (int j = 1; j <= n; j++) {
            if (can[i][j]) {
                for(int v : go[j])
                    if (v) {
                        can[i + 1][v] += (can[i][j] % (1000000000 + 7));
                        can[i + 1][v] %= (1000000000 + 7);
                    }
            }
        }
    }
    long long answer = 0;
    for (int i = 1; i <= n; i++) {
        if (terminal[i]) {
            answer += (can[l][i] % (1000000000 + 7));
            answer %= (1000000000 + 7);
        }
    }
    cout << answer;
    return 0;
}
