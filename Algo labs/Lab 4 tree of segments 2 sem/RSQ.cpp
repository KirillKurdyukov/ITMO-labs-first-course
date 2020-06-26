#include <iostream>


using namespace std;
long long mas[10000000];
long long next_pow(int n) {
    long long pw = 1;
    while (pw < n)
        pw *= 2;
    return pw;
}

void seT(int i, int v, int x, int lx, int rx){
    if (rx - lx == 1) {
        mas[x] = v;
        return;
    }
    long long m = (lx + rx) / 2;
    if (i < m)
        seT(i, v, 2 * x + 1, lx, m);
    else
        seT(i, v, 2 * x + 2, m, rx);
    mas[x] = mas[2 * x + 1] + mas[2 * x + 2];
}

long long sum(int l, int r, int x, int lx, int rx){
    if (l >= rx || lx >= r)
        return 0;
    if (lx >= l && rx <= r)
        return mas[x];
    long long m =(lx + rx) / 2;
    //cout << l << r << 2 * x + 1 << lx << m << endl;
    long long sl = sum(l, r, 2 * x + 1, lx, m);
    //cout << l << r << 2 * x + 2 << m << rx << endl;
    long long sr = sum(l, r, 2 * x + 2, m, rx);
    return sl + sr;
}
int main()
{
    int n;
    cin >> n;
    long long k = next_pow(n);
    for (int i = 0; i < n; i++){
        long long temp;
        cin >> temp;
        mas[k - 1 + i] = temp;
    }
    for (int i = n; i < 2 * k - 1; i++){
        mas[k - 1 + i] = 0;
    }
    for (int i = k - 2; i >= 0; i--){
        mas[i] = mas[2 * i + 1] + mas[2 * i + 2];
    }
    /*for (int i = 0; i < 2 * k - 1; i++)
        cout << mas[i] << " "; */
    string s;
    while (cin >> s){
        long long a1, a2;
        cin >> a1 >> a2;
        if (s == "sum") {
            cout << sum(a1 - 1, a2, 0, 0, k) << endl;
        }
        if (s == "set") {
            seT(a1 - 1, a2, 0, 0, k);

        }
    }
    return 0;
}
