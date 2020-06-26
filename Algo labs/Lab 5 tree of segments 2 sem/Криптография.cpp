#include <bits/stdc++.h>
using namespace std;
int r, n, m;
long long next_pow() {
    long long pw = 1;
    while (pw < n)
        pw *= 2;
    return pw;
}

struct Matrix {
    int a, b, c, d;
    Matrix(int _a, int _b, int _c, int _d) : a(_a % r), b(_b % r), c(_c % r), d(_d % r) { }
};

struct Matrix mul(struct Matrix m1, struct Matrix m2) {
    return {(m1.a * m2.a + m1.b * m2.c) % r, (m1.a * m2.b + m1.b * m2.d) % r,
            (m1.c * m2.a + m1.d * m2.c) % r, (m1.c * m2.b + m1.d * m2.d) % r};
}

vector < Matrix > matrix;

Matrix pr(int l, int r, int x, int lx, int rx){
    if (lx >= r || rx <= l){
        return {1, 0, 0, 1};
    }
    if (lx >= l  && rx <= r)
        return matrix[x];
    Matrix sl = pr(l, r, 2 * x + 1, lx, (lx + rx) / 2);
    Matrix sr = pr(l, r, 2 * x + 2, (lx + rx) / 2, rx);
    return mul(sl, sr);
}


int main()
{
    ios::sync_with_stdio(false); cin.tie(nullptr);
    freopen("crypto.in", "r", stdin);
    freopen("crypto.out", "w", stdout);
    cin >> r >> n >> m;
    int k = next_pow();
    for (int i = n; i <= 2 * k; i++) {
        matrix.emplace_back(1, 0, 0, 1);
    }
    for (int i = 0; i < n; i++){
        int a1, a2, a3, a4;
        cin >> a1 >> a2 >> a3 >> a4;
        matrix[k - 1 + i] = {a1, a2, a3, a4};
    }
    for (int i = k - 2; i >= 0; i--) {
        matrix[i] = mul(matrix[2 * i + 1], matrix[2 * i + 2]);
    }
    for (int i = 0; i < m; i++){
        int l, r;
        cin >> l >> r;
        Matrix temp = pr(l - 1, r, 0, 0, k);
        cout << temp.a << " " << temp.b << endl;
        cout << temp.c << " " << temp.d << endl;
        cout << endl;
    }
    return 0;
}
