#include <stdio.h>
#include <conio.h>
#include <math.h>
#include <stdlib.h>
#define maxn 100+5
int a[maxn];
int main()
{
	int n, i, c, d, j;
	printf ("Nhap vao so phan tu n: ");
	scanf ("%d", &n);
	for (i = 0; i<n; i++)
	{
		printf ("Nhap vao phan tu a[%d]: ", i);
		scanf ("%d", &a[i]);
	}
	int max = a[c];
	for (i = 0; i<n; i++)
	{
		if(max<a[i])
		max = a[i];
		 //c = i;
	}
	for (i = 0; i<n; i++)
	{
		if (a[i]==max) printf ("Chi so vi tri lon nhat la %d\n", i+1);
	}
	printf ("Phan tu lon nhat la %d\n", max);
	int min = a[d];
	for (j = 0; j<n; j++)
	{
		if(min>a[j])
		min = a[j];
		 //d = j;
	}
	for (j = 0; j<n; j++)
	{
		if (a[j]==min) printf ("Chi so vi tri nho nhat la %d\n", j+1);
	}
	//printf ("Phan tu lon nhat la %d\n", max);
	printf ("Phan tu nho nhat la %d \n", min);
	system ("pause");
	return 0;
}
