#include <bits/stdc++.h>

using namespace std;

const int SIZE = 300001;

int p[SIZE];
int minn[SIZE];
int maxx[SIZE];
int length[SIZE];

int finD(int x){
    if (p[x] == x) {
        return p[x];
    }
    return (p[x] = finD(p[x]));
}
int get(int cur){
    cur = finD(cur);
    cout << minn[cur] << " " << maxx[cur] << " " << length[cur];
}
void unioN (int x, int y){
    x = finD(x);
    y = finD(y);
    if (x == y) return;
    //cout << "here\n";
    if (length[x] > length[y]){
        swap(x, y);
    }
    p[x] = y;
    length[y] += length[x];
    // cout << "\nboss = " << y << "size = " << length[y] << "\n";
    maxx[y] = max(maxx[y], maxx[x]);
    minn[y] = min(minn[y], minn[x]);
}
int main(){
    cin.tie(0); ios::sync_with_stdio(false);
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++){
        p[i] = i;
        length[i] = 1;
        maxx[i] = i;
        minn[i] = i;
    }
    string s;
    while (cin >> s) {
        if (s == "union"){
            int mn1;
            int mn2;
            cin >> mn1 >> mn2;
            unioN(mn1, mn2);
           // cout << "dsadas";
        }
        if (s == "get"){
            int cur;
            cin >> cur;
            get(cur);
            cout << endl;
        }
    }
    return 0;
}


