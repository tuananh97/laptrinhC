#include <stdio.h>
#include <conio.h>
#include <math.h>
#include <stdlib.h>
#define maxn 100+5

int b[maxn];

void swap (int &a, int &b)
{
	a=a+b;
	b=a-b;
	a=a-b;
}
int main()
{	int i, n, index=0, j, temp;
	printf ("Nhap so cac phan tu cua day\t");
	scanf ("%d", &n);
	for (i = 0; i<n; i++)
	{
		printf ("Nhap vao phan tu thu a[%d]\t", i);
		scanf ("%d", &b[i]);
	}
	for (i = 0; i<n-1; i++)
		for (j = i+1; j<n; j++){
			if (b[j]<b[i]){
				swap(b[i], b[j]);
			}
		}
	for (i = 0; i<n; i++)
	{
		printf ("%d ", b[i]);
	}
	system ("pause");
	return 0;
}
