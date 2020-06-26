#include <bits/stdc++.h>

#include <utility>

using namespace std;
vector <list<pair<string, string>>> hashMap (1000000);

long long P = 200003;
long long fun(string s) {
    long long ans = 0;
    long long pow = 1;
    for (int i = 0; i < s.size(); i++) {
        ans += (ans + s[i] * pow) % P;
        pow *= 19;
        pow %= P;
    }
    return ans % hashMap.size();
}

bool contains(const string& key) {
    long long i = fun(key);
    for (const auto& element : hashMap[i])
        if (element.first == key) {
            cout << element.second << endl;
            return true;
        }
    cout << "none" << endl;
    return false;
}

bool contains1(const string& key) {
    long long i = fun(key);
    for (const auto& element : hashMap[i])
        if (element.first == key) {
            return true;
        }
    return false;
}

void insert(const string& key, string value) {
    long long i = fun(key);
    if (!contains1(key)) {
        hashMap[i].push_back({key, value});
    } else {
        for (auto &now : hashMap[i]) {
            if (now.first == key)
                now.second = value;
        }
    }
}

void remov(string key) {
    long long i = fun(key);
    string value;
    for (auto now = hashMap[i].begin(); now != hashMap[i].end();) {
        if (now->first == key)
            now = hashMap[i].erase(now);
        else now++;
    }
}

int main () {
    freopen("map.in", "r", stdin);
    freopen("map.out", "w", stdout);
    ios::sync_with_stdio(false); cin.tie(nullptr);
    string s;
    string key, value;
    while(cin >> s >> key) {
        if (s == "put") {
            cin >> value;
            insert(key, value);
        }
        if (s == "delete") {
            remov(key);
        }
        if (s == "get") {
            contains(key);
        }
    }
    return 0;
}