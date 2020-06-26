#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    int sum = 0;
    vector <int> v;
    for (int i = 0; i < (1 << n); i++) {
        vector <int> temp;
        string s;
        cin >> s;
        int cur;
        cin >> cur;
        v.push_back(cur);
        for (int i = 0; i < v.size(); i++)
             temp.push_back(v[i]);
        int k = temp.size();
        while (k > 1) {
            for (int i = 0; i < k - 1; i++) {
                temp[i] = temp[i] ^ temp[i + 1];
            }
            k--;
        }
        cout << s << " " << temp[0] << endl;
    }
    return 0;
}











