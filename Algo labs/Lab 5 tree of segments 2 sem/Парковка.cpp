#include <bits/stdc++.h>
using namespace std;
bool mas[400002];
int n, m, k;
int next_pow() {
    int pow = 1;
    while(pow < n)
        pow *= 2;
    return pow;
}
void ex(int x) {
    x += (k - 1);
    mas[x] = true;
    while (x > 0) {
        x = (x - 1) / 2;
        mas[x] = mas[2 * x + 1] || mas[2 * x + 2];
    }
}
int enter (int i, int x, int lx, int rx) {
    if (rx - lx == 1) {
        if (!mas[x]) {
            return -1;
        }
       // cout << x << endl;
        mas[x] = false;
        return rx;
    }
    if (!mas[x]) {
        return -1;
    }
    int answer;
    int mm = (rx + lx) / 2;
    if (i < mm && mas[2 * x + 1]) {
        //cout << "left" << endl;
        answer = enter(i, 2 * x + 1, lx, mm);
        if (answer == -1) {
         //   cout << "right1" << endl;
            answer = enter(i, 2 * x + 2, mm, rx);
        }
    } else {
       // cout << "right2" << endl;
        answer = enter(i, 2 * x + 2, mm, rx);
    }
    mas[x] = mas[2 * x + 1] || mas[2 * x + 2];
    return answer;
}
int main()
{
    freopen("parking.in", "r", stdin);
    freopen("parking.out", "w", stdout);
   // ios::sync_with_stdio(false); cin.tie(nullptr);
    cin >> n >> m;

    k = next_pow();
    for (int i = 0; i < n; i++) {
        mas[k - 1 + i] = true;
    }
    for (int i = k - 2; i >= 0; i--)
        mas[i] = mas[2 * i + 1] || mas[2 * i + 2];
    /*for (int i = 0; i < 2 * k - 1; i++) {
        cout << mas[i] << " ";
    }*/
    //cout << endl;
    for (int i = 0; i < m; i++) {
        string s;
        cin >> s;
        if (s == "enter") {
            int x;
            cin >> x;
            int answer = enter(x - 1, 0, 0, k);
            if (answer != -1)
                cout << answer << endl;
            else
                cout << enter(0, 0, 0, k) << endl;
        }
        if (s == "exit") {
            int x;
            cin >> x;
            ex(x - 1);
        }
    }
    return 0;
}
