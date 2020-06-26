#include <bits/stdc++.h>
#include <vector>
using namespace std;
vector <int>  v[30];
vector <int> table[30];
vector <int> Answer;
vector <int> lis;
vector <int> Global;
int main(){
    int n;
    cin >> n;
    int ii = 0;
    for (int i = 0; i < n; i++){
        int temp;
        cin >> temp;
        if (temp == 0){
            ii++;
            lis.push_back (i);
        }
        if (temp != 0){
            //v[i].push_back(i);
            for (int j = 0; j < temp; j++) {
                int cur;
                cin >> cur;
                v[i].push_back(cur);
            }
            for (int j = 0; j < (1 << temp); j++) {
                int cur;
                cin >> cur;
                table[i].push_back(cur);
            }
        }
    }
    for (int i = 0; i < n; i++){
        if (table[i].size() == 0)
            table[i].push_back(0);
    }
    /*for (int i = 0; i < n; i++) {
        for (int j = 0; j < v[i].size() ; j++)
            cout << v[i][j] << " ";
        cout << endl;
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < table[i].size() ; j++)
            cout << table[i][j] << " ";
        cout << endl;
    }
    */
    for (int k = 0; k < (1 << ii);k++){
        Global.clear();
        int temp = k;
        for (int i = lis.size() - 1; i >= 0; i--) {
            table[lis[i]][0] = temp%2;
            temp /= 2;
        }
        vector <int> tp;
        for (int i = 0; i < n; i++) {
            if(v[i].size() != 0){
                int sum = 0;
                int cur = 0;
                for (int j = v[i].size() - 1; j >= 0; j--){
                    sum += (tp[v[i][j] - 1] << (v[i].size() - j - 1));
                    if (Global[v[i][j] - 1] > cur)
                        cur = Global[v[i][j] - 1];
                }
                tp.push_back(table[i][sum]);
                Global.push_back(cur + 1);
            } else {
                tp.push_back(table[i][0]);
                Global.push_back(0);
            }
        }
        Answer.push_back(tp.back());
    }
    cout << Global[Global.size() - 1] << endl;
    for (auto now : Answer)
        cout << now;
    return 0;
    }
