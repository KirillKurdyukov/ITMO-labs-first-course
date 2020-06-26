#include <bits/stdc++.h>

using namespace std;
int IndexSoloX;
int SoloX;
int Kirill[101];
int cur;
vector < vector <int> > v;

int haveSingl(int n, int k) {
    for (int i = 0; i < k; i++) {
        int temp = 0;
        if (Kirill[i] == 0) {
            for (int j = 0; j < n; j++) {
                if(v[i][j] == -1)
                    temp++;
            }
            if (temp == n - 1) {
                Kirill[i] = -1;
                return i;
            }
        }
    }
    return -1;
}
int turn(int n, int k) {
    for (int i = 0; i < k; i++) {
        if (Kirill[i] == 0) {
            if (v[i][IndexSoloX] == SoloX) {
                Kirill[i] = -1;

            } else {
                v[i][IndexSoloX] = -1;
            }
        }
    }
}
void Find(int n, int k) {
    for (int i = 0; i < n; i++) {
        if (v[cur][i] != -1){
            IndexSoloX = i;
            SoloX = v[cur][i];
        }
    }
}
bool NoDicided(int n, int k) {
    for (int i = 0; i < k; i++) {
        int temp = 0;
        if (Kirill[i] == 0) {
            for (int j = 0; j < n; j++) {
                if(v[i][j] == -1)
                    temp++;
            }
            if (temp == n - 1) {
                if (v[i][IndexSoloX] == 0 && SoloX == 1) {
                    return true;
                }
                if (v[i][IndexSoloX] == 1 && SoloX == 0) {
                    return true;
                }
                if (v[i][IndexSoloX] == SoloX) {
                    Kirill[i] = -1;
                }
            }
        }
    }
    return false;
}
int main() {
    int n, k;
    cin >> n >> k;
    v.resize(k, vector<int> (n));
    for (int i = 0; i < k; i++){
        for (int j = 0; j < n; j++){
            cin >> v[i][j];
        }
    }
    cur = haveSingl(n, k);
    if (cur == -1){
        cout << "NO";
        return 0;
    } else {
        while(cur!= -1) {
            Find(n, k);
            if (NoDicided(n, k)) {
                cout<<"YES";
                return 0;
            }
            turn(n, k);
            cur = haveSingl(n, k);
            /*/// cout << cur << " " << IndexSoloX << " ";
            /// cout << endl;
            for (int i = 0; i < k; i++){
                for (int j = 0; j < n; j++){
                    cout << v[i][j] << " ";
                }
                cout << endl;
            }
            cout << endl;*/
        }
    }
    cout << "NO";
    return 0;
}
