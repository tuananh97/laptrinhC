#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define maxn 100+5

int main()
{
	int i, j, index=0, flag;
	int a[maxn][maxn], tong =0, b[maxn];
	for ( i =0; i<3; i++)
		for (j = 0; j<3; j++)
			{
				printf ("a[%d][%d] = ", i, j);
				scanf ("%d", &a[i][j]);
			}
	for ( i =0; i<3; i++){
		for (j = 0; j<3; j++){
			tong = tong +a[i][j];
			b[index] = tong;
			index++;}}
	for (i = 0; i<index-1; i++)
		for (j = i+1; j<index; j++)
	{
		if (b[i]==b[j]) {flag = 0; break;}
	}
	if (flag==0) printf (" co hai hang bang nhau\n");		
	else printf ("ko co hai hang bang nhau\n");
	system ("pause");
	return 0;
}
