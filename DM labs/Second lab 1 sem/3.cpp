#include <bits/stdc++.h>
#include <fstream>
using namespace std;

int main(){
    ofstream fout;
    fout.open("lzw.out");
    ifstream fit;
    fit.open("lzw.in");
    map <string, int> mp;
    string s;
    getline(fit, s);
    fit.close();
    for (int i = 0; i < 26; i++){
        string ss (1, char (i + 97));
        mp[ss] = i;
    }
   /* for (auto now : mp){
        cout << now.first << " " << now.second;
        cout << endl;
    }*/
    int temp = 26;
    string buf (1, s[0]);
    int i = 0;
    while ( i < s.size() ){
            //cout << buf << endl;
        if (mp.count(buf)) {
            buf += s[i + 1];
            i++;
            //cout << buf << " ";
           // cout << endl;
        } else {
            mp[buf] = temp;
            temp++;
            buf.pop_back();
            fout << mp[buf] << " ";
         //   cout << endl;
            buf.clear();
            buf += s[i];
        }
       // cout << i << endl;
    }
    fout << mp[buf];
    fout.close();
    return 0;
}
