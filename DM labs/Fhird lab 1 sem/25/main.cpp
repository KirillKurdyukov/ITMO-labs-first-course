#include <bits/stdc++.h>

using namespace std;

int n, k;

int main() {
    freopen("nextchoose.in", "r", stdin);
    freopen("nextchoose.out", "w", stdout);
    cin >> n >> k;
    int a[k];
    int b[k + 1];
    for (int i = 0; i < k; i++){
        cin >> a[i];
        b[i] = a[i];
    }
    b[k] = n + 1;
    int i = k - 1;
    while (i >= 0 && b[i + 1] - b[i] < 2)
        i--;
    if (i < 0) {
        cout << -1;
        return 0;
    }
    b[i]++;
    for (int j = i + 1; j < k; j++){
        b[j] = b[j - 1] + 1;
    }
    for (int i = 0; i < k; i++){
        cout << b[i] << " ";
    }
    return 0;
}
