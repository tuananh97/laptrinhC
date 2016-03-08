#include <stdio.h>
#include <conio.h>
#include <math.h>
#include <stdlib.h>
#define maxn 100+5
int a[maxn][maxn];

int main()
{
	int found = 0;
	int i, j, k;
	for ( i =0; i<3; i++)
		for (j = 0; j<3; j++)
			{
				printf ("a[%d][%d] = ", i, j);
				scanf ("%d", &a[i][j]);
			}
	for ( i =0; i<3; i++)
		for (j = 0; j<3; j++)
			{
				if (a[i][j]!= a[j][i]) {found = 0; break;}
				else found = 1;
		}
	if (found==1) printf ("Ma tran  doi xung\n");	
	else printf ("Ma tran ko doi xung\n");	
			//else
				//printf ("Ma tran ko doi xung");	
	system ("pause");
	return 0;
}
