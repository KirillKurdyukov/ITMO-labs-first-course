//
// Created by sl771 on 09.05.2020.
//
#include <bits/stdc++.h>

using namespace std;

int jmp[100001][18];

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int temp;
        cin >> temp;
        jmp[i + 1][0] = temp;
    }
    for (int k = 1; k < 18; k++) {
        for (int i = 1; i <= n; i++) {
            jmp[i][k] = jmp[jmp[i][k - 1]][k - 1];
        }
    }
    for (int i = 1; i <= n; i++) {
        cout << i << ":";
        for (int k = 0; k < 18; k++) {
            if (jmp[i][k]) {
                cout << " " << jmp[i][k];
            }
        }
        cout << endl;
    }
}
