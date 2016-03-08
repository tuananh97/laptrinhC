#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <conio.h>
#define maxn 100+5

int a[maxn];

int main()
{//Nhap va in ra mang gia tri
	int n, i, temp, j, vt, x, k, k1;
	printf ("Moi ban nhap vao so phan tu n: ");
	scanf ("%d", &n);
	for (i = 0; i<n; i++)
	{
		printf ("Nhap vao phan tu a[%d]: ", i);
		scanf ("%d", &a[i]);
	}
	printf ("Day so vua nhap la: \n");
	for (i = 0; i<n; i++)
	{
		printf ("%d ", a[i]);
	}
	printf ("\n");
//Sap xep mang theo gia tri tang hoac giam dan
	for (i = 0; i<n-1; i++)
		for (j = i+1; j<n; j++){
			if (a[j]>a[i]){
				temp = a[i];
				a[i] = a[j];
				a[j]=temp;
			}
		}
	printf ("Day so moi duoc sap xep tang la: \n");
	for (i = 0; i<n; i++)
	{
		printf ("%d ", a[i]);
	}
	printf ("\n");
	//Chen them so khong pha vo tinh chat tang giam cua day:
	printf ("Nhap vao phan tu can chen: ");
	scanf ("%d", &x);
	for (i = 0; i<n; i++)
		if (x > a[i])
		{
			vt = i;
			for (j = n; j>vt; j--)
				a[j] = a[j - 1];
				a[vt] = x;
				n++;
				break;
		}
	printf ("Day so moi sau khi chen la: \n");
	for (i = 0; i<n; i++)
	{
		printf ("%d ", a[i]);
	}
	printf ("\n");
	system ("pause");
	return 0;
}
