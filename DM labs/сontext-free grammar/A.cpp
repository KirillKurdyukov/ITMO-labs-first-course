//
// Created by sl771 on 05.06.2020.
//

#include <bits/stdc++.h>

using namespace std;

map <char, vector <string>> rules;
string kirill;

bool check (int index, char cur) {
    if (kirill.size() - index - 1 > 0) {
        bool res = false;
        for (auto now : rules[cur]) {
            if (now.size() == 2)
                if (now[0] == kirill[index])
                    res |= check(index + 1, now[1]);
        }
        return res;
    } else {
        bool res = false;
        for (auto now : rules[cur]) {
            if (now.size() == 1)
                if (now[0] == kirill[index])
                    return true;
        }
        return res;
    }
}
int main () {
    freopen("automaton.in", "r", stdin);
    freopen("automaton.out", "w", stdout);
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int n;
    char start;
    cin >> n >> start;
    for (int i = 0; i < n; i++) {
        char N;
        string skip, pr;
        cin >> N >> skip >> pr;
        if (rules.find(N) == rules.end()) {
            vector <string> t;
            t.push_back(pr);
            rules[N] = t;
        } else {
            rules[N].push_back(pr);
        }
    }
    int m;
    cin >> m;
    for (int i = 0; i < m; i++) {
        cin >> kirill;
        if (check(0, start)) {
            cout << "yes" << endl;
        } else
            cout << "no" << endl;
    }
    return 0;
}