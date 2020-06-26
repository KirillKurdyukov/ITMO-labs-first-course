#include <iostream>
#include <vector>
using namespace std;

int main(){
    cin.tie(0); ios::sync_with_stdio(false);
    vector <int> Minn;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int temp;
        cin >> temp;
        if (temp == 1) {
            int cur;
            cin >> cur;
            if (Minn.size() > 0)
                Minn.push_back(min(cur, Minn.back()));
            else
                Minn.push_back(cur);
        }
        if (temp == 3)
            cout << Minn.back() << endl;
        if (temp == 2) {
            Minn.pop_back();
        }
    }
    return 0;
}
