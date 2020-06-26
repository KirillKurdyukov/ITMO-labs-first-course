//
// Created by sl771 on 05.06.2020.
//

#include <bits/stdc++.h>

using namespace std;

map <char, vector <string>> rules;
set <char> Z;
vector <string> split (string s) {
    vector <string> ans;
    string temp;
    for (char i : s) {
        if (i != ' ') {
            temp += i;
        } else {
            ans.push_back(temp);
            temp.clear();
        }
    }
    ans.push_back(temp);
    return ans;
}
bool check (string s) {
    for (char i : s) {
        if (Z.find(i) == Z.end())
            return false;
    }
    return true;
}
int main () {
    freopen("epsilon.in", "r", stdin);
    freopen("epsilon.out", "w", stdout);
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int n;
    cin >> n;
    char start;
    cin >> start;
    string temp;
    getline(cin, temp);
    for (int i = 0; i < n; i++) {string temp1;
        getline(cin, temp1);
        vector <string> sp = split(temp1);
        if(sp.size() == 2) {
            if (rules.find(sp[0][0]) == rules.end()) {
                vector <string> t;
                t.push_back("eps");
                rules[sp[0][0]] = t;
            } else {
                rules[sp[0][0]].push_back("eps");
            }
        } else {
            if (rules.find(sp[0][0]) == rules.end()) {
                vector <string> t;
                t.push_back(sp[2]);
                rules[sp[0][0]] = t;
            } else {
                rules[sp[0][0]].push_back(sp[2]);
            }
        }
        temp1.clear();
    }
    while(true) {
        int prev = 0;
        for (auto now : rules) {
            for (auto pr : now.second) {
                if (pr == "eps" || check(pr)) {
                    Z.insert(now.first);
                    prev++;
                    rules.erase(now.first);
                }
            }
            if (prev)
                break;
        }
        if (!prev) {
            break;
        }
    }
    for (auto now : Z) {
        cout << now << " ";
    }
    return 0;
}