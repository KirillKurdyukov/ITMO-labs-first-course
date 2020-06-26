#include <bits/stdc++.h>


using namespace std;

int n, k;
char Simp(int i) {
    return (char)(i + 48);
}
void Generate(deque <char> s, int cnt) {
    if (n == s.size()) {
        while(!s.empty()){
            cout << s.front();
            s.pop_front();
        }
        cout << endl;
        return;
    }
    if (!(cnt % 2)) {
        for (int i = 0; i < k; i++) {
            s.push_back(Simp(i));
            Generate(s, cnt + (i % 2));
            s.pop_back();
        }
    }
    else {
        for (int i = k - 1; i >= 0; i--) {
            s.push_back(Simp(i));
            Generate(s, cnt + (i % 2));
            s.pop_back();
        }
    }
}
int main()
{
    freopen("telemetry.in", "r", stdin);
    freopen("telemetry.out", "w", stdout);

    cin >> n >> k;
    deque <char> s;
    Generate(s, 0);

    return 0;
}
