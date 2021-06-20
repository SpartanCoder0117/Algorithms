#include <bits/stdc++.h>
using namespace std;

int TBL[1000002];
void KMTBL(string &stri)
{
    int i = 0, j = -1, m = stri.size();
    TBL[0] = -1;
    while(i < m)
    {
        while(j >= 0 && stri[i] != stri[j])
            j = TBL[j];
            TBL[++i] = ++j;
    }
}

int main()
{
    string s;
    cin >> s;
    KMTBL(s);
    int res = TBL[s.size()];
    bool r = false;
    while(res > 0)
    {
        for(int i = s.size() - 1; i > res && !r; i--)
            r = TBL[i] >= res;
        if(r)
            break;
        res = TBL[res];
    }
    if(r)
        cout << s.substr(0, res);
    else
        cout << "Just a legend";
    cout << endl;        
}