#include <bits/stdc++.h>

using namespace std;

vector < int > V[5];

int main(){
    int n;
    cin >> n;
    for (int i = 0; i < n; i++){
        int temp;
        cin >> temp;
        if (temp == 0) {
            cout << "Impossible";
            return 0;
        }
        while(temp > 0){
            V[i].push_back(temp%2);
            temp /= 2;
        }
    }
    int MaxSize = 0;
    for (int i = 0; i < n; i++) {
        if(MaxSize < V[i].size()) {
            MaxSize = V[i].size();
        }
    }
    for (int i = 0; i < n; i++) {
        while(V[i].size() < MaxSize)
            V[i].push_back(0);
    }
    for (int i = 0; i < n; i++){
        for (int j = 0; j <  MaxSize; j++) {
            cout <<V[i][j]<<" ";
        }
        cout << endl;
    }
    int s;
    cin >> s;
    vector <int> S;

    return 0;
    }
