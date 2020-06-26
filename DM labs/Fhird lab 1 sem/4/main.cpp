#include <bits/stdc++.h>

using namespace std;

int n;
map < string , int > mp;
bool inS(string pr, string s[], int k) {
    for (int i = 0; i < k; i++) {
        if (s[i] == pr) {
            return true;
        }
    }
    return false;
}
int main()
{
    freopen("telemetry.in", "r", stdin);
    freopen("telemetry.out", "w", stdout);
    cin >> n;
    string current;
    for (int i = 0; i < n; i++){
        current += '0';
    }
    int i = 0;
    cout << current << endl;
    mp[current] = i;
    while (true) {
        string prefix;
        for (int j = 1; j < n; j++) {
            prefix += current[j];
        }
       // cout << prefix << endl;
        if (!mp.count(prefix + "1")) {
            current = prefix + "1";
            cout << current << endl;
        } else if (!mp.count(prefix + "0")) {
            current = prefix + "0";
            cout << current << endl;
        } else
            break;
        mp[current] = ++i;
    }
    return 0;
}
