#include <stdio.h>
#include <conio.h>
#include <math.h>
#include <stdlib.h>
#define maxn 100+5

int main()
{
	int i, j, k;
	int a[maxn][maxn], b[maxn][maxn], c[maxn][maxn];
	//doc mang a
	for ( i =0; i<3; i++)
		for (j = 0; j<3; j++)
			{
				printf ("a[%d][%d] = ", i, j);
				scanf ("%d", &a[i][j]);
			}
	//doc mang b
	for ( i =0; i<3; i++)
		for (j = 0; j<3; j++)
			{
				printf ("b[%d][%d] = ", i, j);
				scanf ("%d", &b[i][j]);
			}
	//nhan
	for ( i =0; i<3; i++)
		for (j = 0; j<3; j++)
			{
				c[i][j] = 0;
				for (k = 0; k<3; k++)
				c[i][j] = c[i][j]+a[i][j]*b[i][j];
			}
	//in
	for ( i =0; i<3; i++){
		for (j = 0; j<3; j++)
			printf ("%4d", c[i][j]);printf ("\n");}
	system ("pause");
	return 0;
}
