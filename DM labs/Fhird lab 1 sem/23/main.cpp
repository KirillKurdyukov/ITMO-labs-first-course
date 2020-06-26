#include <bits/stdc++.h>

using namespace std;

int n;

vector < vector < int > > answer;

vector <int> defolt;

void gen(string s) {
    if (s.size() == n - 1) {
        vector <int> temp;
        int cur = 1;
        for (int i = 0; i < n - 1; i++){
            if (s[i] == '0') {
                cur += defolt[i + 1];
            } else {
                temp.push_back(cur);
                cur = 1;
            }
        }
         temp.push_back(cur);
        //cout << "Kirill" << endl;
        answer.push_back(temp);
        return;
    }
    gen(s + '0');
    gen(s + '1');
}

bool equals(vector <int> a1, vector <int> a2) {
    if (a1.size() != a2.size())
        return false;
    for (int i = 0; i < a1.size(); i++) {
        if (a1[i] != a2[i])
            return false;
    }
    return true;
}
int main() {
    /*freopen("partition.in", "r", stdin);
    freopen("partition.out", "w", stdout);*/
    cin >> n;
    for (int i = 0; i < n; i++) {
        defolt.push_back(1);
    }
    gen(string());
    for (int i = 0; i < answer.size(); i++) {
        sort(answer[i].begin(), answer[i].end());
    }
    sort(answer.begin(), answer.end());
    for (int i = 0; i < answer.size() - 1; i++){
        if (!equals(answer[i],answer[i + 1])) {
            for (int j = 0; j < answer[i].size(); j++){
                if (j != answer[i].size() - 1)
                    cout << answer[i][j] << " " << "+" << " ";
                else
                    cout << answer[i][j];
            }
            cout << endl;
        }
    }
    for (auto now : answer[answer.size() - 1])
        cout << now;
    return 0;
}
