//
// Created by sl771 on 02.05.2020.
//

#include <bits/stdc++.h>

using namespace std;

bool used1[100001];
bool terminal1[100001];
int go1[100001][256];
bool terminal2[100001];
int go2[100001][256];

bool equals(int first, int second) {
    return terminal1[first] == terminal2[second];
}

bool dfsEquals(int v, int u) {
    bool result = true;
    used1[v] = true;
    if (!equals(v, u)) return false;
    for (int i = 'a'; i <= 'z'; i++) {
        if (go1[v][i] && !used1[go1[v][i]]) {
            result = result && dfsEquals(go1[v][i], go2[u][i]);
        }
    }
    return result;
}

int main() {
    freopen("isomorphism.in", "r", stdin);
    freopen("isomorphism.out", "w", stdout);
    int n1, m1, k1;
    cin >> n1 >> m1 >> k1;
    for (int i = 0; i < k1; i++) {
        int temp;
        cin >> temp;
        terminal1[temp] = true;
    }
    for(int i = 0; i < m1; i++) {
        int a, b;
        char c;
        cin >> a >> b >> c;
        go1[a][c] = b;
    }

    int n2, m2, k2;
    cin >> n2 >> m2 >> k2;
    for (int i = 0; i < k2; i++) {
        int temp;
        cin >> temp;
        terminal2[temp] = true;
    }
    for(int i = 0; i < m2; i++) {
        int a, b;
        char c;
        cin >> a >> b >> c;
        go2[a][c] = b;
    }

    if (n1 != n2 || m1 != m2 || k1 != k2) {
        cout << "NO";
        return 0;
    }
    /*if (dfsEquals(1, 1)) {
        cout << "YES";
        return 0;
    }*/
    queue <pair<int, int>> q;
    q.push({1, 1});
    while(!q.empty()) {
        int u = q.front().first;
        int v = q.front().second;
        q.pop();
        if (!equals(u, v)) {
            cout << "NO";
            return 0;
        }
        used1[u] = true;
        for (int i = 'a'; i <= 'z'; i++) {
            if (!used1[go1[u][i]]) {
                q.push({go1[u][i], go2[v][i]});
            }
        }
    }
    cout << "YES";
    return 0;
}