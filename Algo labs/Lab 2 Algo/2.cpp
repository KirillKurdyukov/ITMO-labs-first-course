#include <iostream>
#include <vector>
using namespace std;

int main(){
    cin.tie(0); ios::sync_with_stdio(false);
    vector <int> Stek;
    int n;
    cin >> n;
    int temp;
    cin >> temp;
    Stek.push_back(temp);
    int Shar = 0;
    int chec = 1;
    for (int i = 1; i < n; i++) {
        int cur;
        cin >> cur;
        if (cur == Stek.back()) {
            chec++;
            Stek.push_back(cur);
        } else {
            if (chec > 2) {
                Shar+=chec;
                while (chec > 0){
                   // cout << Stek.back() << endl;
                    Stek.pop_back();
                    chec--;
                }
            }
            if (cur == Stek.back())
                chec = 2;
            if (Stek.back() == Stek[Stek.size() - 2])
                chec++;
            if (cur != Stek.back())
                chec = 1;
            Stek.push_back(cur);
        }
    }
    int YES = 1;
    Stek.push_back(-1);
    for (int i = 0; i < Stek.size() - 1; i++) {
        if (Stek[i] == Stek[i + 1])
            YES++;
        else {
            if (YES > 2) {
                Shar+=YES;
            }
            YES = 1;
        }
    }
    cout << Shar;
    return 0;
}
