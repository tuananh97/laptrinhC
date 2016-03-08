#include <stdio.h>
#include <string.h>
#include<conio.h>

char *doics(char *number, int n, int m)
{
static char ketqua[17];
char chuso[16] = {"0", "1", "2", "3", "4", "5", "6", "7", "8", "9", "A", "B", "C", "D", "E", "F"};
int i = 0, giatri = 0, len;

len = strlen(number);
while(i<len)
{
giatri = giatri * n + (strchr(chuso, number[i]) - &chuso);
i++;
}
i=16;
ketqua[17] = 0;
do {
ketqua[i] = chuso[giatri % m];
giatri /= m;
i--;
} while (giatri > 0);
return (ketqua + i + 1);
}

void main()
{ int n, m; char number[17], *ketqua; clrscr();
do
{ printf("\nNhap co so N cua he dem xuat phat(2 - 16):");
scanf("%d", &n);
}
while (n<2 || n>16);
getchar();
printf("Gia tri nguyen thuoc he dem co so %d : ", n);
gets(number);
do {
printf("Nhap co so M cua he dem moi (2 - 16):");
scanf("%d", &m);
} while (m<2 || m>16);
printf(" So %s o he dem ",number);
printf("co so %d bieu dien o he dem co so %d",n,m);
printf(" co gia tri la:");
ketqua = doics(number, n, m);
puts(ketqua);
getch();
}


