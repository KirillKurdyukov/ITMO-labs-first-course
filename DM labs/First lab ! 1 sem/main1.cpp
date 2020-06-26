#include <bits/stdc++.h>

using namespace std;
int mas[100004][3];
int boolean[31][31];
int main()
{
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++){
        cin >> mas[i][0];
        cin >> mas[i][1];
        boolean[mas[i][0] + 15][mas[i][1] + 15]++;
    }
    int index[n];
    for (int i = 0; i < n; i++)
        index[i] = 0;
    for (int k = 0; k < (1 << n);k++){
        int temp = k;
        int num = 0;
        while (temp > 0) {
            index[num] = temp % 2;
            temp = temp / 2;
            num++;
        }
        int cur = 0;
        for (int i = 0; i < 31; i++) {
            for (int j = 0; j < 31; j++) {
                if (boolean[i][j] >= 1) {
                    if (index[abs(i - 15) - 1] == 1 && i - 15 > 0) {
                        cur+=boolean[i][j]  ;
                    } else if (index[abs(i - 15)- 1] == 0 && i - 15 < 0) {
                        cur+=boolean[i][j] ;
                    } else if (index[abs(j - 15)- 1] == 1 && j - 15 > 0) {
                        cur+=boolean[i][j] ;
                    } else if (index[abs(j - 15)- 1] == 0 && j - 15 < 0) {
                        cur+=boolean[i][j] ;
                    }
                    //cout << cur << endl;
                }
            }
        }
        if (cur == m) {
            cout << "NO";
            return 0;
        }
    }
    cout << "YES";
    return 0;
}
