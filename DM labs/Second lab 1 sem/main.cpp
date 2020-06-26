#include <bits/stdc++.h>
#include <fstream>
using namespace std;
void Sort(int l, int m, int r, vector<long long> &mas){
    int b[r - l + 1];
    int k = 0;
    int i = l;
    int j = m + 1;
    while ( k < r - l + 1 ) {
        if (j == r + 1 || (mas[i] <= mas[j] && i < m + 1)) {
            b[k++] = mas[i++];
        } else {
            b[k++] = mas[j++];
        }
    }
    for (int s = 0; s < k; s++) {
        mas[l] = b[s];
        l++;
    }
}
void MergeSort(int l, int r, vector<long long> &mas){
    if (l < r){
        int m = (l + r) / 2;
        MergeSort(l, m, mas);
        MergeSort(m + 1 , r, mas);
        Sort(l, m, r, mas);
    }
}
int main(){
   /* ofstream fout;
    fout.open("huffman.out");
    ifstream fit;
    fit.open("huffman.in ");*/
    int n;
    //fit >> n;
    cin >> n;
    vector <long long> p;
    int ans = 0;
    for (int i = 0; i < n; i++) {
        int temp;
       // fit >> temp;
        cin >> temp;
        p.push_back(temp);
    }
    //fit.close();
    MergeSort(0, n - 1, p);
    for (int k = 0; k < n; k++) {
        if (p.size() > 1){
            ans+=(p[1] + p[0]);
            int minn1 = p[1] + p[0];
            swap(p[1],p[p.size() - 1]);
            p.pop_back();
            swap(p[0],p[p.size() - 1]);
            p.pop_back();
          //  cout << minn1 << endl;
            p.push_back(minn1);
            MergeSort(0, p.size() - 1, p);
        }
    }
    cout << ans;
    //fout << ans;
    //fout.close();
    return 0;
}
