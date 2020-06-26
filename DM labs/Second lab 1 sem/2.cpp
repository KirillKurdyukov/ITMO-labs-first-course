#include <bits/stdc++.h>
#include <fstream>

using namespace std;

int main(){
    ofstream fout;
    fout.open("bwt.out");
    ifstream fit;
    fit.open("bwt.in");
    string s;
    getline(fit, s);
    fit.close();
    vector <string> barr;
    barr.push_back(s);
    //cout << barr.back();
    //cout << endl;
    for (int i = 1; i < s.size(); i++){
        barr.push_back(barr.back().substr(s.size() - 1, 1) + barr.back().substr(0, s.size() - 1));
      //  cout << barr.back();
        //cout << endl;
    }
    sort(barr.begin(), barr.end());
    vector <char> answer;
    for (int i = 0; i < barr.size(); i++){
        answer.push_back(barr[i].back());
    }
    for (auto now : answer){
        fout << now;
    }
    fout.close();
    return 0;
}
