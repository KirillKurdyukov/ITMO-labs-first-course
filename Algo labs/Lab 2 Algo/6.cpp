#include <iostream>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

int main(){
    cin.tie(0); ios::sync_with_stdio(false);
    int n;
    cin >> n;
    vector <string> Stek;
    vector <int> Stek1;
    vector <int> out;
    for (int i = 0; i < n; i++){
        int cur;
        cin >> cur;
        if (Stek1.size() == 0) {
            Stek1.push_back(cur);
            Stek.push_back("push");
        } else {
            for (int j = 0; j < out.size(); j++){
                if (cur < out[j]) {
                    cout <<"impossible" << endl;
                    return 0;
                }
            }
            while (cur > Stek1.back() && Stek1.size() > 0) {
                Stek.push_back("pop");
                out.push_back(Stek1.back());
                Stek1.pop_back();
            }
            Stek.push_back("push");
            Stek1.push_back(cur);
        }
    }
    while (Stek1.size() > 0) {
        Stek.push_back("pop");
        Stek1.pop_back();
    }
    for (auto now : Stek) {
        cout << now << endl;
    }
    return 0;
}
