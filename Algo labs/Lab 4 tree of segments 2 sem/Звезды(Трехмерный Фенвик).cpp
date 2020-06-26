#include <bits/stdc++.h>

using namespace std;
int n;

int t[250][250][250];

void inc(int x, int y, int z, int delta) {
    for (int i = x; i < n; i = (i | (i + 1))) {
        for (int j = y; j < n; j = (j | (j + 1))) {
            for (int k = z; k < n; k = (k | (k + 1))) {
                t[i][j][k] += delta;
            }
        }
    }
}
int sum(int x, int y, int z) {
    int result = 0;
    for (int i = x; i >= 0; i = ((i & (i + 1))) - 1) {
        for (int j = y; j >= 0; j = ((j & (j + 1))) - 1) {
            for (int k = z; k >= 0; k = ((k & (k + 1))) - 1) {
                result += t[i][j][k];
            }
        }
    }
    return result;
}
int main() {
    cin >> n;
    for (int i = 0; i < 100002; i++) {
        int temp;
        cin >> temp;
        if (temp == 1) {
            int x, y, z, delta;
            cin >> x >> y >> z >> delta;
            inc(x, y, z, delta);
        }
        if (temp == 2) {
            int x1, y1, z1, x2, y2, z2;
            cin >> x1 >> y1 >> z1 >> x2 >> y2 >> z2;
            cout << sum(x2, y2, z2) - sum(x2, y1 - 1, z2) - sum(x2, y2, z1 - 1)
            - sum(x1 - 1, y2, z2) + sum(x2, y1 - 1, z1 - 1) + sum(x1 - 1, y2, z1 - 1)
            + sum(x1 - 1, y1 - 1, z2) - sum(x1 - 1, y1 - 1, z1 - 1);
            cout << endl;
        }
        if (temp == 3)
            return 0;
    }
    return 0;
}
