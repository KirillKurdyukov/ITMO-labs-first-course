#include <bits/stdc++.h>

using namespace std; //w - 0, b - 1

struct Line {
    int length, amount, L, R;

    Line(int _l, int _a, int _L, int _R) :
            length(_l), amount(_a), L(_L), R(_R) {}
};

vector<Line> line(2097152, {0, 0, 0, 0});

vector<int> isVertex (2097152, 2);

void propagate(int x, int lx, int rx) {
    if (isVertex[x] == 2)
        return;
    if (rx - lx == 1)
        return;
    int m = (lx + rx) / 2;
    if (isVertex[x] == 1) {
        line[2 * x + 1] = {m - lx, 1, 1, 1};
        line[2 * x + 2] = {rx - m, 1, 1, 1};
        isVertex[2 * x + 1] = 1;
        isVertex[2 * x + 2] = 1;
    }
    if (isVertex[x] == 0) {
        line[2 * x + 1] = {0, 0, 0, 0};
        line[2 * x + 2] = {0, 0, 0, 0};
        isVertex[2 * x + 1] = 0;
        isVertex[2 * x + 2] = 0;
    }
    isVertex[x] = 2;
}
void pointW(int x, int l, int r, int lx, int rx) {
    propagate(x, lx, rx);
    if (l >= rx || lx >= r)
        return;
    if (lx >= l && r >= rx) {
        line[x] = {0, 0, 0, 0};
        isVertex[x] = 0;
        return;
    }
    int m = (lx + rx) / 2;
    pointW(2 * x + 1, l, r, lx, m);
    pointW(2 * x + 2, l, r, m, rx);
    if (line[2 * x + 1].R == 1 && line[2 * x + 2].L == 1)
        line[x] = {line[2 * x + 1].length + line[2 * x + 2].length,
                   line[2 * x + 1].amount + line[2 * x + 2].amount - 1,
                   line[2 * x + 1].L, line[2 * x + 2].R};
    else
        line[x] = {line[2 * x + 1].length + line[2 * x + 2].length,
                   line[2 * x + 1].amount + line[2 * x + 2].amount,
                   line[2 * x + 1].L, line[2 * x + 2].R};

}

void printB(int x, int l, int r, int lx, int rx) {
    propagate(x, lx, rx);
    if (l >= rx || lx >= r)
        return;
    if (lx >= l && r >= rx) {
        line[x] = {rx - lx, 1, 1, 1};
        isVertex[x] = 1;
        propagate(x, lx, rx);
        return;
    }
    int m = (lx + rx) / 2;
    printB(2 * x + 1, l, r, lx, m);
    printB(2 * x + 2, l, r, m, rx);
    if (line[2 * x + 1].R == 1 && line[2 * x + 2].L == 1)
        line[x] = {line[2 * x + 1].length + line[2 * x + 2].length,
                   line[2 * x + 1].amount + line[2 * x + 2].amount - 1,
                   line[2 * x + 1].L, line[2 * x + 2].R};
    else
        line[x] = {line[2 * x + 1].length + line[2 * x + 2].length,
                   line[2 * x + 1].amount + line[2 * x + 2].amount,
                   line[2 * x + 1].L, line[2 * x + 2].R};

}

int main() {
    long long n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        char a;
        cin >> a;
        int x, l;
        cin >> x >> l;
        if (a == 'W') {
            pointW(0, x - 1 + 500000, x + l - 1 + 500000, 0, 1048576);
        }
        if (a == 'B') {
            printB(0, x - 1 + 500000, x + l - 1 + 500000, 0, 1048576);
        }
        cout << line[0].amount << " " << line[0].length << endl;
    }
    return 0;
}
