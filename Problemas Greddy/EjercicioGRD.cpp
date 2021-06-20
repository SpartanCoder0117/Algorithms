#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Segmento
{
    int L, R;
};

bool comp(const Segmento &sgt1, const Segmento &sgt2)
{
    return sgt1.L < sgt2.L;
}

int main()
{
    int T;
    cin >> T;

    while(T--)
    {
        int M;
        cin >> M;
        vector<Segmento> S(1);
        while(cin >> S[0].L >> S[0].R, !(S[0].L == 0 && S[0].R == 0))
            S.push_back(S[0]);

        sort(S.begin() + 1, S.end(), comp);
        int curL = 0, Alcan = 0;
        size_t i = 1;
        vector<Segmento> segmentos;
        while(Alcan < M)
        {
            int newL = curL;
            size_t lej = 0;
            for(; i < S.size(); ++i)
            {
                if(S[i].L > curL)
                    break;
                else if(S[i].R >= newL)    
                {
                    newL = S[i].R;
                    lej = i;
                }
            }

            if(lej == 0)
                break;
            segmentos.push_back(S[lej]);
            curL = Alcan = newL;  
        }
        if(Alcan >= M)
        {
            cout << segmentos.size() << endl;
            for(size_t i = 0; i < segmentos.size(); ++i)
                cout << segmentos[i].L << " " << segmentos[i].R << endl;
        }
        else    
            cout << "0" << endl;
        if(T)
            cout << endl;    
    }
    return 0;
}