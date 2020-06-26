//
// Created by sl771 on 03.05.2020.
//

#include <bits/stdc++.h>

using namespace std;

bool terminal1[10001];
int go1[1001][256];
bool used[1001][1001];
bool terminal2[1001];
int go2[1001][256];

bool equals(int first, int second) {
    return terminal1[first] == terminal2[second];
}

int main() {
    freopen("equivalence.in", "r", stdin);
    freopen("equivalence.out", "w", stdout);
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
        go1[a][(int) c] = b;
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
        go2[a][(int) c] = b;
    }
   // cout << dfsEquals1(1, 1) << " " << dfsEquals2(1, 1) << "\n";
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
       used[u][v] = true;
       for (int i = 'a'; i <= 'z'; i++) {
           if (!used[go1[u][i]][go2[v][i]]) {
               q.push({go1[u][i], go2[v][i]});
           }
       }
   }
   cout << "YES";
}