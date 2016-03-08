#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define maxn 100+5

int a[maxn], check[maxn];

int main()
{
	int n, i, j;
	memset(check, 0, sizeof(int));
	printf ("Nhap so cac phan tu cua day\t");
	scanf ("%d", &n);
	for (i = 0; i<n; i++)
	{
		printf ("Nhap vao phan tu thu a[%d]\t", i);
		scanf ("%d", &a[i]);
	}
	for( i=0;i<n;i++)
         for( j=i+1;j<n;j++)
            if(a[i]==a[j])
            {
                 check[j]=1;
                 check[i]=1;
            }
     for(int i=0;i<n;i++){
     if(check[i]==0)
        printf ("%d ", a[i]);}
  system ("pause");
	return 0;
}
