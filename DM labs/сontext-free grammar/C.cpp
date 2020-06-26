//
// Created by sl771 on 08.06.2020.
//

#include <bits/stdc++.h>

using namespace std;

map<char, set<string>> rules;
bool used[26];
bool used_generaring[26];
bool used_unattainable[26];
set<char> ans;

vector <string> split (string s) {
    vector <string> a;
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

bool check(string s) {
    for (auto i : s) {
        if (i > 'Z')
            continue;
        if (!used_generaring[i - 'A'])
            return false;
    }
    return true;
}
void generaring() {
    while(true) {
        int aye = 0;
        for (auto now : rules) {
            for (auto pr : now.second) {
                if (check(pr) && !used_generaring[now.first - 'A']) {
                    aye++;
                    used_generaring[now.first - 'A'] = true;
                }
            }
        }
        if (!aye)
            break;
    }
}

void delete_non_generaring() {
    generaring();
    for (int i = 0; i < 26; i++) {
        if (!used_generaring[i] && used[i]) {
            rules.erase(i + 'A');
            ans.insert(i + 'A');
        }
    }
    for (auto &now : rules) {
        while(true) {
            bool flag = true;
            for (auto i : now.second) {
                if (!check(i)) {
                    //   cout << i <<" "<< now.first << endl;
                    now.second.erase(i);
                    flag = false;
                    break;
                }
            }
            if(flag)
                break;
        }
    }
}

void unattainable(char c) {
    if (used_unattainable[c - 'A'])
        return;
    used_unattainable[c - 'A'] = true;
    for (auto now : rules[c]) {
        for (auto i : now)
            if (i <= 'Z')
                if (!used_unattainable[i - 'A'])
                    unattainable(i);
    }
}

int main() {
    freopen("useless.in", "r", stdin);
    freopen("useless.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    char start;
    cin >> start;
    used[start - 'A'] = true;
    string temp;
    getline(cin, temp);
    for (int i = 0; i < n; i++) {
        getline(cin, temp);
        vector <string> sp = split(temp);
        if (sp.size() == 2) {
            used[sp[0][0] - 'A'] = true;
            if (rules.find(sp[0][0]) == rules.end()) {
                set<string> t;
                t.insert("eps");
                rules[sp[0][0]] = t;
            } else {
                rules[sp[0][0]].insert("eps");
            }
        } else {
            used[sp[0][0] - 'A'] = true;
            for (auto item : sp[2]) {
                if (item <= 'Z')
                    used[item - 'A'] = true;
            }
            if (rules.find(sp[0][0]) == rules.end()) {
                set<string> t;
                t.insert(sp[2]);
                rules[sp[0][0]] = t;
            } else {
                rules[sp[0][0]].insert(sp[2]);
            }
        }
    }

    delete_non_generaring();
    /*  for (int i = 0; i < 26; i++) {
          if (!used_generaring[i] && used[i]) {
              cout << char (i + 'A') << endl;
          }
      }
      for (auto now : rules) {
          cout << now.first << ":";
          for (auto s : now.second) {
              cout << " " << s;
          }
          cout << endl;
      }*/
    unattainable(start);
    for (int i = 0; i < 26; i++) {
        if (!used_unattainable[i] && used[i]) {
            ans.insert(i + 'A');
        }
    }
    for (auto now : ans)
        cout << now << " ";
    return 0;
}