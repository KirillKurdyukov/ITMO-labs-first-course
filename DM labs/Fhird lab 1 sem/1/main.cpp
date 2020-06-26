#include <iostream>

using namespace std;

int n;

void DvoichnyiCood(string s) {
    if (s.size() == n) {
        cout << s << endl;
        return;
    }
    DvoichnyiCood(s + "0");
    DvoichnyiCood(s + "1");
}
int main()
{
    freopen("allvectors.in", "r", stdin);
    freopen("allvectors.out", "w", stdout);
    cin >> n;
    DvoichnyiCood("");
    return 0;
}
