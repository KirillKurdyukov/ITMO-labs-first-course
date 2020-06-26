#include <bits/stdc++.h>

using namespace std;

int n;
int k = 524288;
int mod = 200000;
vector<int> adD(4 * k, 0);
vector<pair<int, int>> y(4 * k);

struct Window {
    int ly, ry, open, x;

    Window(int _ly, int _ry, int _open, int _x) : ly(_ly), ry(_ry),
                                                  open(_open), x(_x) {}
};

pair<int, int> fun(pair<int, int> a, pair<int, int> b) {
    if (a.first >= b.first)
        return a;
    else return b;
}

void build(int v, int l, int r) {
    if (r - l == 1) {
        y[v] = {0, l};
        return;
    }
    int m = (l + r) / 2;
    build(v * 2 + 1, l, m);
    build(v * 2 + 2, m, r);
    y[v] = fun(y[v * 2 + 1], y[v * 2 + 2]);
}

vector<Window> windows;

bool comp(Window a, Window b) {
    if (a.x == b.x) {
        if (a.open == b.open) {
            return a.ly < b.ly;
        }
        return a.open > b.open;
    }
    return a.x < b.x;
}

void propagate(int x, int lx, int rx) {
    if (adD[x] == 0)
        return;
    y[x].first += adD[x];
    if (rx - lx != 1) {
        adD[2 * x + 1] += adD[x];
        adD[2 * x + 2] += adD[x];
    }
    adD[x] = 0;
}

void add(int l, int r, int v, int x, int lx, int rx) {
    propagate(x, lx, rx);
    if (l >= rx || lx >= r) {
        return;
    }
    if (lx >= l && r >= rx) {
        adD[x] += v;
        propagate(x, lx, rx);
        return;
    }
    int m = (lx + rx) / 2;
    add(l, r, v, 2 * x + 1, lx, m);
    add(l, r, v, 2 * x + 2, m, rx);
    y[x] = fun(y[2 * x + 1], y[2 * x + 2]);
}

int main() {
    cin >> n;
    build(0, 0, k);
    for (int i = 0; i < n; i++) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        windows.emplace_back(y1, y2, 1, x1);
        windows.emplace_back(y1, y2, -1, x2);
    }
    sort(windows.begin(), windows.end(), comp);
    pair<int, int> answer;
    int mx = 0;
    for (int i = 0; i < windows.size(); i++) {
        add(windows[i].ly + mod, windows[i].ry + mod + 1, windows[i].open,
            0, 0, k);
        if (mx < y[0].first) {
            answer = make_pair(windows[i].x, y[0].second - mod);
            mx = y[0].first;
        }

    }
    cout << mx << endl;
    cout << answer.first << " " << answer.second;
    return 0;
}
