#include <stdio.h>
#include <conio.h>
int  main()
{
int n,i;
float A[100];
int flag, flag1, flag2, flag3;
printf("\nNhap so n:");
scanf("%d",&n);
/********** DOC CAC GIA TRI MANG ********/
for(i=0;i<n;i++)
{
    printf("\nA[%d] =",i);
    scanf("%f",&A[i]);
}
  /********** IN MANG RA MAN HINH*********/
    printf("\nMang gom :");
for(i=0;i<n;i++)
    printf("%0.0f ",A[i]);
  /********** KIEM TRA CAP SO CONG *********/
for(i=0;i+2<n;i++)
    if(A[i+2]-A[i+1]!=A[i+1]-A[i])
{
 flag=0;
break;
}
 if(flag == 0)
    printf("\nKhong la csc");
 else
     printf("\nLa csc");
for(i=0;i+2<n;i++)
    if(A[i+2]/A[i+1]!=A[i+1]/A[i])
{
 flag1=0;
break;
}
if(flag1 == 0)
    printf("\nKhong la cap so nhan");
 else
     printf("\nLa cs nhan");
for(i=0;i+2<n;i++)
    if(A[i+1]/A[i]>0&&A[i+2]/A[i+1]>0)
{
 flag2=0;
break;
}
if(flag2 == 0)
    printf("\nKhong la dan dau");
 else
     printf("\nLa dan dau");
for(i=0;i+2<n;i++)
    if(A[i+1]/A[i]>0&&A[i+2]/A[i+1]>0&&A[i]>0)
{
 flag3=0;
break;
}
if(flag3 == 0)
    printf("\nDay toan duong");
 else
     printf("\nDay toan am");
    getch();
}
