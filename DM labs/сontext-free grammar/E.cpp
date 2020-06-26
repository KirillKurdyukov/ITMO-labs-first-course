//
// Created by sl771 on 12.06.2020.
//
// Алгоритм Кока-Янгера-Касами, модификация для произвольной грамматики
#include <bits/stdc++.h>

using namespace std;

vector<pair<char, string>> rules;
bool d[26][105][105];
bool h[55][105][105][6];

vector<string> split(const string &s) {
    vector<string> a;
    string temp;
    for (char i : s) {
        if (i != ' ') {
            temp += i;
        } else {
            a.push_back(temp);
            temp.clear();
        }
    }
    a.push_back(temp);
    return a;
}

int main() {
//    freopen("cf.in", "r", stdin);
//    freopen("cf.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    char start;
    cin >> start;
    string temp;
    getline(cin, temp);
    for (int i = 0; i < n; i++) {
        getline(cin, temp);
        vector<string> sp = split(temp);
        if (sp.size() == 2) {
            rules.emplace_back(sp[0][0], "eps");
        } else {
            rules.emplace_back(sp[0][0], sp[2]);
        }
    }
    string w;
    cin >> w;
    for (int i = 0; i < rules.size(); i++) {
        for (int j = 0; j < w.size(); j++) {
            if (rules[i].second.size() == 3)
                d[rules[i].first - 'A'][j][j] = true;
            if (rules[i].second.size() == 1 && rules[i].second[0] == w[j]) {
                d[rules[i].first - 'A'][j][j + 1] = true;
            }
            h[i][j][j][0] = true;
        }
    }
    for (int len = 1; len <= w.size(); len++) {
        for (int i = 0; i + len <= w.size(); i++) {
            for (int j = 0; j < rules.size(); j++) {
                for (int k = 0; k < 6; k++) {

                }
            }
        }
    }
    if (d[start][0][n])
        cout << "yes";
    else
        cout << "no";
    return 0;
}