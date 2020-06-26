#include <bits/stdc++.h>

using namespace std;

int n, k;

int Digit(vector < char > sim){
    int cur = 0;
    for (int i = 0; i < sim.size(); i++){
        cur *= 10;
        cur += ((int) sim[i] - 48);
    }
    return cur;
}
int main() {
   freopen("nextpartition.in", "r", stdin);
   freopen("nextpartition.out", "w", stdout);

    string s;

    getline(cin, s);

    vector <int> v;

    vector <char> sim;
    for (int i = 0; i < s.size(); i++){
        if (s[i] <= '9' && s[i] >= '0') {
            sim.push_back(s[i]);
        } else {
            v.push_back(Digit(sim));
            sim.clear();
        }
    }
    v.push_back(Digit(sim));
    int n = v.size();
    if (n == 2) {
        cout << "No solution";
        return 0;
    }
    v[v.size() - 1] --;
    v[v.size() - 2] ++;
    if (v[v.size() - 2] > v[v.size() - 1]){
        v[v.size() - 2] += v[v.size() - 1];
        v.pop_back();
    } else {
        while (v[v.size() - 2] * 2 <= v[v.size() - 1]) {
            v.push_back(v[v.size() - 1] - v[v.size() - 2]);
            v[v.size() - 2] = v[v.size() - 3];
        }
    }
    cout << v[0] << "=";
    for (int i = 1; i < v.size() - 1; i++) {
        cout << v[i] << "+";
    }
    cout<<v.back();
    return 0;
}
