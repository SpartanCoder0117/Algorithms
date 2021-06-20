#include <iostream>
#include <cstdio>
#include <cstring>
#define true 1
#define false 0

using namespace std;

int main()
{
    char A[9999995+5];
    int got;
    int i,j,tam;
    while(gets(A)&&A[0]!='.'){
        tam = strlen(A);
        got = true;
        for(i=1;i<tam-1;i++){
            if(tam%i!=0)continue;
            for(j=i;j<tam;j++)
                if(A[j]!=A[j%i]){
                    got = false;
                    break;
                }
        if(got)break;
        got = true;
        }
        if(got)printf("%d\n",tam/i);
        else printf("%d\n",tam);
    }
    return 0;
}
