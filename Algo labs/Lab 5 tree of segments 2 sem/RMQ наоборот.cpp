#include <bits/stdc++.h>

using namespace std;

struct Inquiries {
    int l, r, minn;
    Inquiries(int _l, int _r, int _minn) : l(_l), r(_r), minn(_minn){}
};
vector <Inquiries> inq;

bool comp(Inquiries a, Inquiries b) {
    return a.minn < b.minn;
}

int next_pow(int n) {
    int pw = 1;
    while (pw < n) {
        pw *= 2;
    }
    return pw;
}
long long E = INT_MAX + 10000LL;
vector <int> v(600000, INT_MAX);
vector <long long> seT(600000, E);
void propagate(int x, int lx, int rx) {
    if (seT[x] == E)
        return;
    v[x] =  seT[x];
    if (rx - lx != 1) {
        seT[2 * x + 1] = seT[x];
        seT[2 * x + 2] = seT[x];
    }
    seT[x] = E;
}
void get_mas(int x, int lx, int rx) {
    propagate(x, lx, rx);
    if (rx - lx == 1) {
        return;
    }
    int m = (lx + rx) / 2;
    get_mas(2 * x + 1, lx, m);
    get_mas(2 * x + 2, m, rx);
}
void assignment(int l, int r, int vv, int x, int lx, int rx) {
    propagate(x, lx, rx);
    if (l >= rx || lx >= r) {
        return;
    }
    if (lx >= l && r >= rx) {
        seT[x] = vv;
        propagate(x, lx, rx);
        return;
    }
    int m = (lx + rx) / 2;
    assignment(l, r, vv, 2 * x + 1, lx, m);
    assignment(l, r, vv, 2 * x + 2, m, rx);
   // propagate(2 * x + 1, lx, m);
   // propagate(2 * x + 2, m, rx);
    v[x] = min(v[2 * x + 1], v[2 * x + 2]);
}
int minN(int l, int r, int x, int lx, int rx) {
    propagate(x, lx, rx);
    if (l >= rx || lx >= r) {
        return INT_MAX;
    }
    if (lx >= l && r >= rx) {
        return v[x];
    }
    int  m = (lx + rx) / 2;
    int  sl = minN(l, r, 2 * x + 1, lx, m);
    int  sr = minN(l, r, 2 * x + 2, m, rx);
    return min(sl, sr);
}

int main() {
    freopen("rmq.in", "r", stdin);
    freopen("rmq.out", "w", stdout);
    int n, m;
    int k;
    cin >> n >> m;
    k = next_pow(n);
    for(int i = 0; i < m; i++) {
        int l, r, minn;
        cin >> l >> r >> minn;
        inq.push_back({l - 1, r, minn});
    }
    sort(inq.begin(), inq.end(), comp);
    for (int i = 0; i < m; i++) {
        assignment(inq[i].l, inq[i].r, inq[i].minn, 0, 0, k);
    }
    for (int i = 0; i < m; i++) {
        if (minN(inq[i].l, inq[i].r, 0, 0, k) != inq[i].minn) {
            cout << "inconsistent";
            return 0;
        }
    }
    cout << "consistent" << endl;
    for (int i = 0; i < n; i++) {
        cout << minN(i, i + 1, 0, 0, k) << " ";
    }
    return 0;
}
