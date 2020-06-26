//
// Created by sl771 on 02.06.2020.
//
// Открытое хэшировние.
#include <bits/stdc++.h>

using namespace std;
long long P = 433494437;
long long A;
vector <pair<int, string> > hush(1000000, {0, "kukuha"});

bool contains(int x) {
    int i = ((A * x) % P) % hush.size();
    while (hush[i].second != "kukuha") {
        if (hush[i].first == x)
            return true;
        i = (i + 1) % hush.size();
    }
    return false;
}

void insert(int x) {
    int i = ((A * x) % P) % hush.size();
    if (!contains(x)) {
        while (hush[i].second != "kukuha") {
            i = (i + 1) % hush.size();
        }
        hush[i] = {x, "have"};
    }
}

void remov(int x) {
    int i = ((A * x) % P) % hush.size();
    while (hush[i].second != "kukuha") {
        if (hush[i].first == x) {
            hush[i].second = "kukuha";
            break;
        }
        i = (i + 1) % hush.size();
    }
    int k = i;
    i = (i + 1) % hush.size();
    while (hush[i].second != "kukuha") {
        if (((A * abs(hush[i].first)) % P) % hush.size() <= k) {
            swap(hush[i], hush[k]);
            k = i;
        }
        i = (i + 1) % hush.size();
    }
}
int main () {
    freopen("set.in", "r", stdin);
    freopen("set.out", "w", stdout);
    ios::sync_with_stdio(false); cin.tie(nullptr);
    A = rand();
    string s;
    int x;
    while(cin >> s >> x) {
        if (s == "insert") {
            insert(x + 1000000000);
        }
        if (s == "delete") {
            remov(x+ 1000000000);
        }
        if (s == "exists") {
            if (contains(x+ 1000000000))
                cout << "true" << endl;
            else
                cout << "false" << endl;
        }
    }
    return 0;
}