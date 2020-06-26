#include <bits/stdc++.h>

using namespace std;

int main() {
    freopen("num2choose.in", "r", stdin);
    freopen("num2choose.out", "w", stdout);
    int n, k, m;
    cin >> n >> k >> m;
    long long c[n + 1][n + 1];
    for (int i = 0; i <= n; i++) {
        c[i][0] = 1;
    }
    for (int i = 0; i <= n; i++) {
        c[i][i] = 1;
    }
    for (int i = 2; i <= n; i++) {
        for (int j = 1 ; j < i; j++){
            c[i][j] = c[i - 1][j - 1] + c[i - 1][j];
        }
    }
    deque < long long > v;
    int next = 1;
    while (k > 0) {
        if (m < c[n - 1][k - 1]) {
            v.push_back(next);
            k--;
        } else
            m-=c[n - 1][k - 1];
        n--;
        next++;
    }
    while (!v.empty()) {
        cout << v.front() << " ";
        v.pop_front();
    }
    return 0;
}
