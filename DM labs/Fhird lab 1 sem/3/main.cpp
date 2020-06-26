#include <bits/stdc++.h>

using namespace std;

int n;
deque <int> v;
vector <int> cnt;

void clearV() {
   for (int i = 0; i < n; i++){
        cnt.push_back(v.front());
        v.pop_front();
        //cnt.push_back(v.front());
        //cout << "/" << v.front();
   }
  // cout << endl;
}

//vector<string> v;

void TroichCood(string s) {
    if (s.size() == n) {
       // v.push_back(s);
        for (int i = 0; i < s.size(); i++){
            v.push_back((int) s[i] - 48);
        }
        cout << s.size() << endl;
        return;
    }
    TroichCood(s + "0");
    TroichCood(s + "1");
    TroichCood(s + "2");
}
int main()
{
    /*freopen("antigray.in", "r", stdin);
    freopen("antigray.out", "w", stdout);*/
    cin >> n;
    int cur = pow (3, n);
    int i = 0;
    TroichCood("");
    cout << endl;
    while (i < cur) {
        clearV();
       // cout << endl;
        for (int j = 0; j < 3; j++) {
            for (int k = 0; k < cnt.size(); k++){
                if (cnt[k] < 3) {
                    cout << cnt[k];
                    cnt[k]++;
                } else {
                    cnt[k] = 0;
                    cout << cnt[k];
                    cnt[k]++;
                }
            }
            cout << endl;
            i++;
        }
        cnt.clear();
    }
    return 0;
}
