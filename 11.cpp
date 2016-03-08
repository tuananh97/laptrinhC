#include <stdio.h>
#include <stdlib.h>

void  xoatrung(int a[],int n)
{
    int i,j,k;
    for(i=0;i<n-1;i++)
        for(j=i+1;j<n;j++)
        {
            if(a[i]==a[j])
                {
                    for(k=j+1;k<n;k++)
                        a[k-1]=a[k];
                    n--;j--;
                }
           
        }
    for(i=0;i<n;i++)
    printf("%5d",a[i]);
}

int cmp_int( const void *a, const void *b )
{
    return (*(int*)a - *(int*)b);
}

int main( )
{
    int a[] = { 1, 2, 3, 4, 5, 6, 2, 5, 8 };//thay doi mang o day
   
    qsort( a, 9, sizeof (int), cmp_int );
    xoatrung( a, 9 );
    putchar('\n');
    system ("pause");
    return 0;
}
