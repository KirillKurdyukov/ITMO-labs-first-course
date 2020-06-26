#include <bits/stdc++.h>

using namespace std;

int n;

int main()
{
    freopen("gray.in", "r", stdin);
    freopen("gray.out", "w", stdout);
    cin >> n;
    for (int i = 0; i < (1 << n); i++) {
        int temp = i ^ (i / 2);
        vector < int > answer;
        for (int j  = 0; j < n; j++) {
            answer.push_back(temp % 2);
            temp /= 2;
        }
        reverse(answer.begin(), answer.end());
        for (auto now : answer) {
            cout << now;
        }
        cout << endl;
    }
    return 0;
}
