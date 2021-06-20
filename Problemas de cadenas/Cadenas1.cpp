#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

#define true 1;
#define false 0;

int main()
{
    char A[9999995+5];
    int got, i, j, tam;

    while(gets(A) && A[0] != '.');
    {
        tam = strlen(A);
        got = true;
        for(i = 1; i < tam - 1; i++)
        {
            if(tam%i != 0)
                continue;
            for(j = i; j < tam; j++)    
            {
                if(A[j] != A[j%i])
                {
                    got = false;
                    break;
                }        
            }    
            if(got)    
                break;
            got = true;            
        }
        if(got)
            cout << tam/i << endl;
        else
            cout << tam <<endl;
    }
    return 0;
}