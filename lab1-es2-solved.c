#include <stdio.h>

int main()
{
	int n,k,i,j;
	printf("Inserire n: ");
	scanf("%d",&n);
	printf("Inserire k: ");
	scanf("%d",&k);

	printf("\n");
	printf("   ");
	for (i=1; i<=k; i++)
		printf("%4d",i);
	printf("\n---");
	for (i=1; i<=k; i++)
		printf("----"); //removed , i
	printf("\n");
	for (i=2; i<=n; i++)
	{
		printf("%2d:",i);
		for (j=1; j<=k; j++)
			printf("%4d",i*j);
		printf("\n");
	}

	return 0;
}
