лио#include <bits/stdc++.h>

using namespace std;

int n;
vector <vector <int>> answer;

vector<int> posled(string cur) {
    vector<int> tmp;
    for (int i = 0; i < cur.size(); i++) {
        if (cur[i] == '1') {
            tmp.push_back(i + 1);
        }
    }
    return tmp;
}

void Dvoich(string s){
    if (s.size() == n) {
        int cur = 0;
        for (int i = 0; i < s.size(); i++){
            if (s[i] == '1')
                cur++;
        }
        answer.push_back(posled(s));
        return;
    }
    Dvoich(s + "0");
    Dvoich(s + "1");
}

int main()
{
    freopen("subsets.in", "r", stdin);
    freopen("subsets.out", "w", stdout);
    cin >> n;
    Dvoich("");
    sort(answer.begin(), answer.end());
    for (int i = 0; i < answer.size(); i++) {
        for (int j = 0; j < answer[i].size(); j++) {
            cout << answer[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}
