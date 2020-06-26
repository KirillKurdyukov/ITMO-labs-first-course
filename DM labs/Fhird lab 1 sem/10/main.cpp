#include <bits/stdc++.h>

using namespace std;

int n;

vector <bool> was;

int permutation[10000];

int alreadyWas;
int f(int k) {
    if (k == 1)
        return 1;
    if (k == 0)
        return 1;
    return f(k - 1) * k;
}
void  num2permutation(int k) {

    for (int i = 1; i <= n; i++){
        alreadyWas = k / f(n - i);
        k %= f(n - i);
        int curFree = 0;
        for (int j = 1; j <= n; j++) {
            if (was[j - 1] == false) {
                curFree++;
                if (curFree == alreadyWas + 1) {
                    permutation[i - 1] = j;
                    was[j - 1] = true;
                }
            }
        }
    }
    for (int i = 0; i < n; i++)
        cout << permutation[i] << " ";
}
int main() {
    freopen("num2perm.in", "r", stdin);
    freopen("num2perm.out", "w", stdout);
    int k;
    cin >> n >> k;
    for (int i = 0; i <= n; i++)
        was.push_back(false);
    num2permutation(k);
    return 0;
}

