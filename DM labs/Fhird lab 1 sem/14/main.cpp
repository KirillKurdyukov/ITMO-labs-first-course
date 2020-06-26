#include <bits/stdc++.h>

using namespace std;
long long n;
long long a[100];

long long P[100];

vector <bool> was(1000, 0);
long long f (long long k) {
    if (k == 0)
        return 1;
    if (k == 1)
        return 1;
    return f(k - 1) * k;
}
long long permutation(long long n) {
    long long numOfPermutation = 0;
    for (long long i = 1; i <= n; i++) {
        for (long long j = 1; j <= a[i] - 1; j++){
            if (was[j] == false) {
                numOfPermutation += P[n - i];
            }
        }
        was[a[i]] = true;
    }
    return numOfPermutation;
}
int main() {
    freopen("perm2num.in", "r", stdin);
    freopen("perm2num.out", "w", stdout);
    cin >> n;
    for (long long i = 0; i <= n; i++){
        P[i] = f(i);
    }
    for (long long i = 1; i <= n; i++)
        cin >> a[i];
    cout << permutation(n);
    return 0;
}
