#include <iostream>


using namespace std;
int  n, k;
const long long INF = 2000000000000000001LL;
long long mas[500000], add[500000], setK[500000];
int next_pow() {
    int pw = 1;
    while (pw < n)
        pw *= 2;
    return pw;
}
void propogate(int x, int lx, int rx) {
    if (rx - lx == 1)
        return;
    if (setK[x] != INF) {
        setK[2 * x + 1] = setK[x];
        setK[2 * x + 2] = setK[x];
        mas[2 * x + 1] = setK[x];
        mas[2 * x + 2] = setK[x];
        add[2 * x + 1] = 0;
        add[2 * x + 2] = 0;

    }
    add[2 * x + 1] += add[x];
    add[2 * x + 2] += add[x];
    mas[2 * x + 1] += add[x];
    mas[2 * x + 2] += add[x];
    setK[x] = INF;
    add[x] = 0;
}
void add_do(int l, int r, long long v, int x, int lx, int rx) {

    if (l >= rx || lx >= r)
        return;
    if (lx >= l && r >= rx){
        add[x] += v;
        mas[x] += v;
       // cout << x << " " << setK[x] << " " << add[x] << " " << mas[x] << endl;
        return;
    }
    propogate(x, lx, rx);
    int m = (lx + rx) / 2;
    add_do(l, r, v, 2 * x + 1, lx, m);
    add_do(l, r, v, 2 * x + 2, m, rx);
    mas[x] = min(mas[2 * x + 1], mas[2 * x + 2]);
}
void set_do(int l, int r, long long v, int x, int lx, int rx) {
    if (l >= rx || lx >= r)
        return;
    if (lx >= l && r >= rx) {
        setK[x] = v;
        add[x] = 0;
        mas[x] = v;
       // cout << x << " " << setK[x] << " " << add[x] << " " << mas[x] << endl;
        return;
    }
    propogate(x, lx, rx);
    int m = (lx + rx) / 2;
    set_do(l, r, v, 2 * x + 1, lx, m);
    set_do(l, r, v, 2 * x + 2, m, rx);
    mas[x] = min(mas[2 * x + 1], mas[2 * x + 2]);
}
long long min_do(int l, int r, int x, int lx, int rx){
    propogate(x, lx, rx);
    if (l >= rx || r <= lx) {
        return INF;
    }
    if (lx >= l && r >= rx) {
        return mas[x];
    }
    long long sl = min_do(l, r, 2 * x + 1, lx, (lx + rx) / 2);
    long long sr = min_do(l, r, 2 * x + 2, (lx + rx) / 2, rx);
    return min(sl, sr);
}
int main()
{
    ios::sync_with_stdio(false); cin.tie(nullptr);
    cin >> n;
    k = next_pow();
    for (int i = 0; i < 2 * k - 1; i++) {
        mas[i] = INF;
        setK[i] = INF;
    }
    for (int i = 0; i < n; i++)
        cin >> mas[i + k - 1];
    for (int i = k - 2; i >= 0; i--){
        mas[i] = min(mas[2 * i + 1], mas[2 * i + 2]);
    }
    string s;
    while(cin >> s){
        if (s == "min"){
            int l, r;
            cin >> l >> r;
            cout << min_do(l - 1, r, 0, 0, k) << endl;
        }
        if (s == "set"){
            int l, r;
            long long x;
            cin >> l >> r >> x;
            set_do(l - 1, r, x, 0, 0, k);
        }
        if (s == "add"){
            int l, r;
            long long x;
            cin >> l >> r >> x;
            add_do(l - 1, r, x, 0, 0, k);
        }
    }
    return 0;
}
