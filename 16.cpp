#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#define maxn 100+5

int a[maxn], b[maxn];

int main()
{
	int i, n, j;
	printf ("Nhap so cac phan tu cua day\t");
	scanf ("%d", &n);
	for (i = 0; i<n; i++)
	{
		printf ("Nhap vao phan tu thu a[%d]\t", i);
		scanf ("%d", &a[i]);
	}
	for (i = 0; i<n; i++)
	{
		if (a[i]>0)
		{
			b[index] = a[i];
			index++;
		}
		
	}
	for (i = 0; i<index-1; i++)
		for (j = i+1; j<index; j++){
			if (b[j]<b[i]){
				temp = b[i];
				b[i] = b[j];
				b[j]=temp;
			}
		}
	printf ("Day so duong moi duoc sap xep lai la: \n");
	for (i = 0; i<index; i++)
	{
		printf ("%d ", b[i]);
	}
	printf ("\n");
	system ("pause");	
	return 0;
}
