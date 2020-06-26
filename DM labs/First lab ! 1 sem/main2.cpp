#include <bits/stdc++.h>

using namespace std;
int SamoDvoist (string s) {
    int k = 0;
    for (int i = 0; i < s.size() / 2; i++) {
        if (s[i] != s[s.size() - 1 - i])
            k++;
    }
    return k == s.size() / 2;
}
int Monot (string s, int n) {
    int mas[(1 << n)][n];
    for (int i = 0; i < n; i++)
        mas[0][i] = 0;
    for (int k = 1; k < (1 << n); k++){
        int temp = k;
        int num = 0;
        while (num != n) {
            mas[k][num] = temp % 2;
            temp = temp / 2;
            num++;
        }
    }
    /*for (int i = 0; i < (1 << n); i++) {
        for (int j = 0; j < n; j++) {
            cout << mas[i][j] << " ";
        } cout << endl;
    }*/
    for (int i = 0; i < (1 << n) - 1; i++) {
        for (int j = i + 1; j < (1 << n); j++) {
            int cur = 0;
            for (int k = 0; k < n; k++) {
                if (mas[j][k] >= mas[i][k])
                    cur++;
            }
            if (cur == n) {
                if ((int)s[i] > (int) s[j]) {
                    return 0;
                }
            }
        }
    }
    return 1;
}
int Trey (int k, string s) {
    if (k == 1)
        return (int) s[0] - 48;
    vector <int> temp;
    for (int i = 0; i < k; i++)
         temp.push_back((int)s[i] - 48);
    int l = temp.size();
    while (l > 1) {
        for (int i = 0; i < l - 1; i++) {
            temp[i] = temp[i] ^ temp[i + 1];
        }
        l--;
    }
    return temp[0];
}
int Lin (string s, int n) {
    int mas[(1 << n)][n];
    for (int i = 0; i < n; i++)
        mas[0][i] = 0;
    for (int k = 1; k < (1 << n); k++){
        int temp = k;
        int num = 0;
        while (num != n) {
            mas[k][num] = temp % 2;
            temp = temp / 2;
            num++;
        }
    }
    /*for (int i = 0; i < (1 << n); i++) {
        for (int j = 0; j < n; j++) {
            cout << mas[i][j] << " ";
        } cout << endl;
    }*/
    vector <int> Giga;
    for (int i = 0; i < s.size(); i++) {
        Giga.push_back(Trey(i + 1, s));
        //cout << Trey(i + 1, s) << endl;
    }
    /*for (int i = 0; i < (1 << n); i++) {
        int cur = 0;
        int temp = 0;
        for (int j = 0; j < n; j++) {
            temp+=pow(mas[i][j] * 2,j);
            if (mas[i][j] == 1)
                cur++;
            if (s[temp] = '1' && cur > 1)
                return 0;
        }
    }*/
    for (int i = 0; i < Giga.size(); i++) {
        if (Giga[i] == 1) {
            int cur = 0;
            for (int j = 0; j < n; j++){
                if (mas[i][j] == 1) cur++;
            }
            if (cur > 1) {
                return 0;
            }
        }
    }
    return 1;
}
int main()
{
    int n;
    cin >> n;
    int Post[5];
    for (int i = 0; i < 5; i++) {
        Post[i] = 0;
    }
    for (int i = 0; i < n; i++) {
        int temp;
        cin >> temp;
        if (temp != 0) {
        string s;
        cin >> s;
        if (s[0] == '0') {
            Post[0]++;
        }
        if (s[s.size() - 1] == '1') {
            Post[1]++;
        }
        Post[2] += SamoDvoist(s);
        Post[3] += Monot(s, temp);
        Post[4] += Lin(s, temp);
        } else {
            string s;
            cin >> s;
            if (s[0] == '1') {
                Post[1]++;
                Post[4]++;
                Post[3]++;
            } else if (s[0] == '0') {
                Post[0]++;
                Post[4]++;
                Post[3]++;
            }
        }
    }
    for (int i = 0; i < 5; i++){
          //  cout << Post[i] << " ";
        if (Post[i] == n) {
            cout << "NO";
            return 0;
        }
    }
    cout << "YES";
    return 0;
}
