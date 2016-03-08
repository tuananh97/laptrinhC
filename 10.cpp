#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#define maxn 100+5

int a[maxn], n;

int sum(int n, int i)
{
	if (n == i) return a[i];
	return sum(n-1, i)+a[n];
}
void solve(int n)
{
	int i;
	for (i = n; i>=0; i--)
		if ((a[i] > a[i - 1]) && (i - 1)>=-1) {//printf ("%d \n", a[i]);
		 printf ("%d\n", sum(n, i));}
}
int main()
{
	int i;
	printf ("Nhap so cac phan tu cua day\t");
	scanf ("%d", &n);
	for (i = 0; i<n; i++)
	{
		printf ("Nhap vao phan tu thu a[%d]\t", i);
		scanf ("%d", &a[i]);
	}
	solve (n);
	system ("pause");
	return 0;
}
