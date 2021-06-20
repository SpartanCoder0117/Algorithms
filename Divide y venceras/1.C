#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char const *argv[])
{
	char *A=NULL,*B=NULL;
	int n,i;
	scanf("%d",&n);
	scanf("%d",&A);	
	B = strtok(A," ");
	printf("%d\n", A);
	
	return 0;
}