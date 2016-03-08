#include <stdio.h>
#include <conio.h>
#include <math.h>
#include <stdlib.h>
#define maxn 100+5

int a[maxn], b[maxn];

int nto(int a)
{
	int i, count = 0 ;
	for (i = 2; i<a; i++){
	if (a%i==0){
	count++;}}
	if (count == 0) return 1;
	return 0;
}
int main()
{	int i, n, j, index=0;
	printf ("Nhap so cac phan tu cua day\t");
	scanf ("%d", &n);
	for (i = 0; i<n; i++)
	{
		printf ("Nhap vao phan tu thu a[%d]\t", i);
		scanf ("%d", &a[i]);}
	printf ("Chi so cua cac so nguyen to la: \n");
	for (i = 0; i<n; i++)
	{
		if(nto(a[i])==1)
		{
			printf ("%d ", i);
			b[index] = a[i];
			index++;
	  }}
	printf ("\n");
	printf ("Danh sach cac so nguyen to la: \n");
	for (j = 0; j<index; j++)
	{
		printf ("%d ", b[j]);
	}
	printf ("\n");
	int min = b[0];
	for (j = 0; j<index; j++)
	{
		if (min>b[j])
		min = b[j];
	}
	printf ("So nguyen to nho nhat la: %d\n", min);
	system ("pause");
	return 0;
	}
