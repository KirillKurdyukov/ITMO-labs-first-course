//
// Created by sl771 on 09.05.2020.
//

#include <bits/stdc++.h>

using namespace std;
int n;
int jmp[200002][18];
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
int LCA(int u, int v) {
    if (d[u] < d[v])
        swap(u, v);
    int D = d[u] - d[v];
    for (int k = 17; k >= 0; k--) {
        if (D >= (1 << k)) {
            u = jmp[u][k];
            D -=  (1 << k);
        }
    }
    if (u == v)
        return u;
    for (int k = 17; k >= 0; k--) {
        int uu = jmp[u][k];
        int vv = jmp[v][k];
        if (uu != vv) {
            u = uu;
            v = vv;
        }
    }
    return jmp[u][0];
}
int main() {
    cin >> n;
    for (int i = 0; i < n - 1; i++) {
        int temp;
        cin >> temp;
        jmp[i + 2][0] = temp;
        tree[temp].push_back(i + 2);
    }
    for (int k = 1; k < 18; k++) {
        for (int i = 1; i <= n; i++) {
            jmp[i][k] = jmp[jmp[i][k - 1]][k - 1];
        }
    }
    bypassTree();
    int m;
    cin >> m;
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        cout << LCA(u, v) << endl;
    }
}