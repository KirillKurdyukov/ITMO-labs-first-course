//
// Created by sl771 on 10.06.2020.
//

#include <bits/stdc++.h>

using namespace std;

map<char, vector<string>> rules;
long long d[26][101][101];

int main() {
    freopen("nfc.in", "r", stdin);
    freopen("nfc.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    char start;
    cin >> start;
    for(int i = 0; i < n; i++) {
        char N;
        string skip, pr;
        cin >> N >> skip >> pr;
        if (rules.find(N) == rules.end()) {
            rules[N] = vector<string>();
            rules[N].push_back(pr);
        } else {
            rules[N].push_back(pr);
        }
    }
    string w;
    cin >> w;
    // База отработала
    for (auto now : rules) {
        for (auto kek : now.second) {
            if (kek.size() == 1 && kek[0] > 'Z') {
                for (int i = 0; i < w.size(); i++) {
                    if(kek[0] == w[i])
                        d[now.first - 'A'][i][i] = 1;
                }
            }
        }
    }
    /*for(auto now : rules) {
        for (int i = 0; i < w.size(); i++) {
            if (d[now.first - 'A'][i][i])
                cout << d[now.first - 'A'][i][i] << " " << now.first << " " << i << endl;
        }
    }*/
    for(int len = 1; len < w.size(); len++) {
        for (int i = 0; i + len < w.size(); i++) {
            for (auto now : rules) {
                for (auto lol : now.second) {
                    if(lol.size() > 1) {
                        long long cnt = 0;
                        for (int k = i; k < i + len; k++) {
                            cnt += (d[lol[0] - 'A'][i][k] *
                                    d[lol[1] - 'A'][k + 1][i + len]) % 1000000007;
                            cnt %= 1000000007;
                        }
                        d[now.first - 'A'][i][i + len] += cnt;
                        d[now.first - 'A'][i][i + len] %= 1000000007;
                    }
                }
            }
        }
    }
    cout << d[start - 'A'][0][w.size() - 1];
    return 0;
}