#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int n, x, y, a0;
    cin >> n >> x >> y >> a0;
    vector <long long> a;
    a.push_back(a0);
    for (int i = 1; i < n; i++) {
        a.push_back((x * a.back() + y) % (1 << 16));
    }

    for (int i = 1; i < n; i++)
        a[i] += a[i - 1];
    long  long m, z, t, b0;
    cin >> m >> z >> t >> b0;
    long long sum = 0;
    for (int i = 0; i < m; i++){
        int l,  r;
        if (b0 * z + t >= 0) {
            l = min(b0 % n, ((b0 * z + t) % (1 << 30)) % n);
            r = max(b0 % n, ((b0 * z + t) % (1 << 30)) % n);
            int b1 = (b0 * z + t) % (1 << 30);
            int b2 = (b1 * z + t) % (1 << 30);
            b0 = b2;
        } else {
            l = min(b0 % n, ((b0 * z + t) % (1 << 30) + (1 << 30)) % n);
            r = max(b0 % n, ((b0 * z + t) % (1 << 30) + (1 << 30)) % n);
            int b1 = (b0 * z + t) % (1 << 30);
            int b2 = (b1 * z + t) % (1 << 30);
            b0 = b2;
        }
        if (l > 0)
            sum += a[r] - a[l - 1];
        else
            sum += a[r];
    }
    cout << sum;
    return 0;
}
