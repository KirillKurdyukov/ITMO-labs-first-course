//
// Created by sl771 on 09.05.2020.
//

//
// Created by sl771 on 09.05.2020.
//

#include <bits/stdc++.h>

using namespace std;
int n;
int jmp[200002][18];
int up[200002][18];
int d[200002];
bool used[200002];
vector<vector <int>> tree(200002, vector <int> (0));
void bypassTree () {
    queue<int> q;
    q.push(1);
    while(!q.empty()) {
        int u = q.front();
        q.pop();
        for (int v : tree[u]) {
            d[v] = (d[u] + 1);
            q.push(v);
        }
    }
}
int LCA_min(int u, int v) {
    int answer = 1000000;
    if (d[u] < d[v])
        swap(u, v);
    int D = d[u] - d[v];
    for (int k = 17; k >= 0; k--) {
        if (D >= (1 << k)) {
            answer = min(answer, up[u][k]);
            u = jmp[u][k];
            D -=  (1 << k);
        }
    }
    if (u == v)
        return answer;
    for (int k = 17; k >= 0; k--) {
        int uu = jmp[u][k];
        int vv = jmp[v][k];
        if (uu != vv) {
            answer = min(answer, up[u][k]);
            answer = min(answer, up[v][k]);
            u = uu;
            v = vv;
        }
    }
    answer = min(answer, up[u][0]);
    answer = min(answer, up[v][0]);
    return answer;
}
int main() {
    freopen("minonpath.in", "r", stdin);
    freopen("minonpath.out", "w", stdout);
    cin >> n;
    for (int i = 0; i < n - 1; i++) {
        int x, y;
        cin >> x >> y;
        jmp[i + 2][0] = x;
        tree[x].push_back(i + 2);
        up[i + 2][0] = y;
    }
    for (int k = 1; k < 18; k++) {
        for (int i = 1; i <= n; i++) {
            jmp[i][k] = jmp[jmp[i][k - 1]][k - 1];
            up[i][k] = min(up[i][k - 1], up[jmp[i][k - 1]][k - 1]);
        }
    }
    bypassTree();
    int m;
    cin >> m;
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        cout << LCA_min(u, v) << endl;
    }
}
