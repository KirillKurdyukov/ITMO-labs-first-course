#include<bits/stdc++.h>

using namespace std;

int n;

void gen(int close, int open, string s) {
    if (2 * n == s.size()) {
        cout << s << endl;
        return;
    }
    if (open < n) {
        gen(close, open + 1, s + '(');
    }
    if (open > close) {
        gen(close + 1, open, s + ')');
    }
}

int main() {
    freopen("brackets.in", "r", stdin);
    freopen("brackets.out", "w", stdout);
    cin >> n;
    gen(0, 0, "");
}
