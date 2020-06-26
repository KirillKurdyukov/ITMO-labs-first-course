#include <iostream>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

int main(){
    cin.tie(0); ios::sync_with_stdio(false);
    int n;
    cin >> n;
    deque < int > part1;
    deque < int > part2;
    for (int i = 0; i < n; i++){
        char temp;
        cin >> temp;
        if (temp == '+') {
            int cur;
            cin  >> cur;
            if (part1.size() == part2.size()) {
                part2.push_back(cur);
            } else {
                part1.push_back(part2.front());
                part2.pop_front();
                part2.push_back(cur);
            }
        }
        if (temp == '*') {
            int cur;
            cin  >> cur;
            if (part1.size() == part2.size()){
                part2.push_front(cur);
            } else {
                part1.push_back(part2.front());
                part2.pop_front();
                part2.push_front(cur);
            }
        }
        if (temp == '-') {
            if (part1.size() == 0) {
                cout << part2.front()<< endl;
                part2.pop_front();

            } else {
                if (part1.size() == part2.size()) {
                    cout << part1.front() << endl;
                    part1.pop_front();
                } else {
                    part1.push_back(part2.front());
                    part2.pop_front();
                    cout << part1.front() << endl;
                    part1.pop_front();
                }
            }
        }

    }
    return 0;
}
