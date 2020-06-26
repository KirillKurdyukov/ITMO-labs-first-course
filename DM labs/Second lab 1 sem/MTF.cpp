#include <bits/stdc++.h>
#include <fstream>

using namespace std;

int main(){
    ofstream fout;
    fout.open("mtf.out");
    ifstream fit;
    fit.open("mtf.in");
    string s;
    getline(fit, s);
    fit.close();
    string alfa = "abcdefghijklmnopqrstuvwxyz";
    for (int i = 0; i < s.size(); i++) {
        int temp;
        for (int j = 0; j < alfa.size();j++){
            if (s[i] == alfa[j]){
                fout << j + 1 << " ";
                temp = j;
                break;
            }
        }
        for (int j = temp; j > 0; j--){
            swap(alfa[j], alfa[j - 1]);
        }
    }
    fout.close();
    return 0;
}
