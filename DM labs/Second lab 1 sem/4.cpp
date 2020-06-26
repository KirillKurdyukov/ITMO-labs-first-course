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
    for (int i = 0; i < 26; i++){
        string ss (1, char (i + 97));
        mp[ss] = i;
    }
   /* for (auto now : mp){
        cout << now.first << " " << now.second;
        cout << endl;
    }*/
    fit.close();
    int temp = 26;
    string buf (1, s[0]);
    for (int i = 0; i < s.size();){
        //    cout << buf << endl;
        if (mp.count(buf)) {
            i++;
            if (i < s.size())
                buf += s[i];
        //    cout << buf << " ";
        //   cout << endl;
        } else {
            mp[buf] = temp;
            temp++;
            buf.pop_back();
            fout << mp[buf] << " ";
       //     cout << endl;
            buf.clear();
            buf += s[i];
        }
     //   cout << i << endl;
    }
    fout << mp[buf];
    fout.close();
    return 0;
}
