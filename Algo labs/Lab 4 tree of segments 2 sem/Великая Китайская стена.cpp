#include <bits/stdc++.h>

using namespace std;
int n, m, k;
const int INF = 100000001;
vector<pair<int, int> > wall(5000000);
vector<int> kirill(5000000, INF);
pair<int, int> e = {INF, 2 * k};

int next_pow() {
    int pow = 1;
    while (pow < n)
        pow *= 2;
    return pow;
}

void new_min(int i) {
    if (wall[i * 2 + 1].first > wall[2 * i + 2].first)
        wall[i] = wall[2 * i + 2];
    else
        wall[i] = wall[2 * i + 1];
}

void propagate(int x, int lx, int rx) {
    if (kirill[x] == INF) {
        return;
    }
    if (wall[x].first >= kirill[x])
        return;
    wall[x].first = kirill[x];
    if (rx - lx != 1) {
        kirill[2 * x + 1] = kirill[x];
        kirill[2 * x + 2] = kirill[x];
    }
    kirill[x] = INF;
}

void defend(int l, int r, int v, int x, int lx, int rx) {
    propagate(x, lx, rx);
    if (l >= rx || lx >= r)
        return;
    if (lx >= l && r >= rx) {
        kirill[x] = v;
        propagate(x, lx, rx);
        return;
    }
    int m = (lx + rx) / 2;
    defend(l, r, v, 2 * x + 1, lx, m);
    defend(l, r, v, 2 * x + 2, m, rx);
    new_min(x);
}

pair<int, int> attack(int l, int r, int x, int lx, int rx) {
    propagate(x, lx, rx);
    //cout << x << endl;
    if (l >= rx || r <= lx) {
        //cout << e.first << " kek " << e.second << endl;
        return e;
    }
    if (lx >= l && r >= rx) {
        //cout << wall[x].first << " " << wall[x].second << endl;
        return wall[x];
    }
    pair<int, int> sl = attack(l, r, 2 * x + 1, lx, (lx + rx) / 2);
    pair<int, int> sr = attack(l, r, 2 * x + 2, (lx + rx) / 2, rx);
    if (sl.first > sr.first)
        return sr;
    else
        return sl;
}

int main() {
    cin >> n >> m;
    k = next_pow();
    for (int i = 0; i < n; i++) {
        wall[i + k - 1] = {0, i + 1};
    }
    for (int i = n + k - 1; i < 2 * k - 1; i++) {
        wall[i] = {10000002, i};
    }
    for (int i = k - 2; i >= 0; i--) {
        new_min(i);
    }
    /*for (int i = 0; i < 2 * k - 1; i++)
        cout << wall[i].first << " " << wall[i].second << endl;*/
    for (int i = 0; i < m; i++) {
        string s;
        cin >> s;
        if (s == "defend") {
            int l, r, v;
            cin >> l >> r >> v;
            // cout << "kek" << endl;
            defend(l - 1, r, v, 0, 0, k);
            // cout << "kek" << endl;
        }
        if (s == "attack") {
            int l, r;
            cin >> l >> r;
            pair<int, int> answer = attack(l - 1, r, 0, 0, k);
            cout << answer.first << " " << answer.second << endl;
        }
        /*for (int i = 0; i < 2 * k - 1; i++)
            cout << wall[i].first << " " << wall[i].second << kirill[i] << endl;*/
    }
    return 0;
}
