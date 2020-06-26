#include <bits/stdc++.h>

using namespace std;

int n;
int cnt;
vector <string> answer;
void DvoichnyiCood(string s) {
    if (s.size() == n) {
        answer.push_back(s);
        cnt++;
        return;
    }
    DvoichnyiCood(s + "0");
    if (s[s.size() - 1] != '1')
        DvoichnyiCood(s + "1");
}
int main()
{
    freopen("vectors.in", "r", stdin);
    freopen("vectors.out", "w", stdout);
    cin >> n;
    DvoichnyiCood("");
    cout << cnt << endl;
    for (auto now : answer){cout << now << endl;}

    return 0;
}
