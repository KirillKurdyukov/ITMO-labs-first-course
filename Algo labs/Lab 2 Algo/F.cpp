#include <bits/stdc++.h>

using namespace std;

long long p[400002];
long long expp[400002];
long long n;

int finD(int x){
    if (p[x] == x) {
        return p[x];
    }
    return finD(p[x]);
}
void join(int x, int y){
    x = finD(x); y = finD(y);
    n++;
    p[x] = n;
    p[y] = n;
    p[n] = n;
}
void add(int x, int v) {
    x = finD(x);
    expp[x] += v;
}
int v = 0;
int get (int x){
    v += expp[x];
    //cout << expp[x] << endl;
    if (p[x] == x) {
        return p[x];
    }
    return get(p[x]);
}
int main(){
    cin.tie(0); ios::sync_with_stdio(false);
    int m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++){
        p[i] = i;
    }
    int g = 0;
    int h= 1000000;
    for (int i = 0; i < m; i++){
        string s;
        cin >> s;
        if (s == "add") {
            int x, v;
            cin >> x >> v;
            add(x, v);
        }
        if (s == "join") {
            int x, y;
            cin >> x >> y;
            join(x, y);
        }
        if (s == "get") {
            int x;
            cin >> x;
            v = 0;
            get(x);
            cout << v << endl;
        }
        g++;
        h = h / 2;
        /*for (int i = 1; i <= n; i++){
            cout << p[i] << " ";
        } cout << endl;
        for (int i = 1; i <= n; i++){
            cout << expp[i] << " ";
        } cout << endl;*/
    }
    return 0;
}
