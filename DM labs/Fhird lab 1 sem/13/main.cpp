#include <bits/stdc++.h>

using namespace std;

vector <bool> was(1000, 0);
long long n, k;
long long permutation[1000];

long long f (long long k) {
    if (k == 0)
        return 1;
    if (k == 1)
        return 1;
    return f(k - 1) * k;
}
void num2permutation(long long k){
    for (long long i = 1; i <= n; i++){
        long long alreadyWas = k / f(n - i);
        k %= f(n - i);
        long long curFree = 0;
        for (long long j = 1; j <= n; j++){
            if (was[j] == false) {
                curFree++;
                if (curFree == alreadyWas + 1) {
                    permutation[i] = j;
                    was[j] = true;
                }
            }
        }
    }
    for (long long i = 1; i <= n; i++){
        cout << permutation[i] << " ";
    }
}
int main() {
    //freopen("num2perm.in", "r", stdin);
    //freopen("num2perm.out", "w", stdout);
    cin >> n >> k;
    num2permutation(k);

    return 0;
}
