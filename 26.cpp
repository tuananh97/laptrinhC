#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
int timmin(int a[20][20], int sh, int sc)
{
    int k, min=a[sh][0];
    for (k=1;k<sc;k++)  if (a[sh][k]<min)   min = a[sh][k];
    return min;
}
int timmax(int a[20][20], int sh, int sc)
{
    int k, max=a[0][sc];
    for (k=1;k<sh;k++)  if (a[k][sc]>max)   max = a[k][sc];
    return max;
}
int main()
{
    int i,j,n,m,a[20][20],kt=0;
    nhaplai:
    printf ("Nhap so hang va so cot cua ma tran :  ");
    scanf ("%d%d", &n,&m);
    if (n<0||m<0) goto nhaplai;
    for (i=0;i<n;i++)
    for (j=0;j<m;j++)
    {
        printf ("A[%d][%d] = ", i,j);
        scanf ("%d", &a[i][j]);
    }
    for (i=0;i<n;i++)
    {    
         for (j=0;j<m;j++)
         if (a[i][j]==timmin(a,i,m) && a[i][j] == timmax(a,n,j))  
            {
               printf ("A[%d][%d] = %d la mot diem yen ngua \n", i,j,a[i][j]);
               kt++;
            }
    }
    if (kt==0) printf ("\n Khong co diem yen ngua nao ");
    getch();
    return 0;
}
