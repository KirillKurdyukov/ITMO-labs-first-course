#include <bits/stdc++.h>

using namespace std; //w - 0, b - 1
long long mas[1000001];
long long ST[1000001][20];

long long lof(long long i) {
    int answer = 0;
    while (i > 1) {
        i /= 2;
        answer++;
    }
    return answer;
}
long long MIN (long long u1, long long v2){
    if (u1 > v2)
        swap(u1, v2);
    return min(ST[u1][lof(v2 - u1 + 1)], ST[v2 + 1 - (1 << lof(v2 - u1 + 1))][lof(v2 - u1 + 1)]);
}
int main() {
    long long n, m;
    cin >> n >> m >> mas[0];
    for (long long i = 1; i < n; i++) {
        mas[i] = (23 * mas[i - 1] + 21563) % 16714589;
    }
    for (long long j = 0; (1 << j) <= n; j++) {
        for (long long i = 0; i + (1 << j) <= n; i++) {
            if (j == 0) {
                ST[i][j] = mas[i];
            } else
                ST[i][j] = min(ST[i][j - 1], ST[i + (1 << j - 1)][j - 1]);
        }
    }
    long long u, v, u1, v2;
    cin >> u >> v;
    long long r = MIN(u - 1,  v -1);
    //cout << u << " " << v << " " << r << endl;
    for (long long i = 1; i < m; i++) {
        u1 = ((17 * u + 751 + r + 2 * (i)) % n) + 1;
        v2 = ((13 * v + 593 + r + 5 * (i)) % n) + 1;
        r = MIN(u1 - 1, v2 - 1);
        u = u1;
        v = v2;
        //cout << u1 << " " << v2 << " " << r << endl;
    }
    cout << u << " " << v << " " << r;
    return 0;
}
