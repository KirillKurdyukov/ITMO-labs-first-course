#include <bits/stdc++.h>

using namespace std;
int n;
int a[100001];
int b[100001];

void prevPermutation() {
   for (int i = n - 2; i >= 0; i--) {
       if (b[i] > b[i + 1]) {
            int m = i + 1;
            for (int j = i + 1; j < n; j++){
                if (b[j] > b[m] && b[j] < b[i]) {
                    m = j;
                }
            }
            swap(b[i], b[m]);
            int k = 1;
            for (int j = i + 1; j <= (n + i) / 2; j++){
                swap(b[j], b[n - k]);
                k++;
            }
            for (int i = 0; i < n; i++){
                cout << b[i] << " ";
            }
            return;
       }
   }
}
void nextPermutation() {
    for (int i = n - 2; i >= 0; i--) {
        if (a[i] < a[i + 1]){
            int m = i + 1;
            while (m < n - 1 && a[i] < a[m + 1]) {
                m++;
            }
            swap(a[i], a[m]);
            int k = 1;
            for (int j = i + 1; j <= (n + i) / 2; j++){
                swap(a[j], a[n - k]);
                k++;
            }
            for (int i = 0; i < n; i++){
                cout << a[i] << " ";
            }
            exit(false);
        }
    }
}
int main() {
    freopen("nextmultiperm.in", "r", stdin);
    freopen("nextmultiperm.out", "w", stdout);
    cin >> n;
    for (int i = 0; i < n; i++){
        cin >> a[i];
    }
    nextPermutation();
    for (int i = 0; i  < n; i++)
            cout << 0 << " ";
    cout << endl;
    return 0;
}
