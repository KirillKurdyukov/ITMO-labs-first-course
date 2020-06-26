#include <bits/stdc++.h>

using namespace std;

bool terminal[100001];
vector <vector <vector<int>>> go(100000, vector <vector <int>> ((int) 'z' + 1, vector<int> (0)));
bool can[10001][101];

int main() {
    freopen("problem2.in", "r", stdin);
    freopen("problem2.out", "w", stdout);
    string s;
    cin >> s;
    int n, m, k;
    cin >> n >> m >> k;
    for (int i = 0; i < k; i++) {
        int temp;
        cin >> temp;
        terminal[temp] = true;
    }
    for(int i = 0; i < m; i++) {
        int a, b;
        char c;
        cin >> a >> b >> c;
        go[a][(int) c].push_back(b);
    }
    can[0][1] = true;
    for(int i = 0; i < s.size(); i++) {
        char c = s[i];
        for(int j = 0; j < n; j++) {
            if (can[i][j + 1]) {
                for(auto v : go[j + 1][c])
                    can[i + 1][v] = true;
            }
        }
    }
    for (int i = 1; i <= n; i++)
        if (can[s.size()][i] && terminal[i]) {
            cout << "Accepts";
            return 0;
        }
    cout << "Rejects";
    return 0;
}
