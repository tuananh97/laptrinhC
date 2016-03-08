#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <conio.h>

struct complex
{
	int real;
	int img;
};
struct complex add(struct complex n1, struct complex n2)
{
	struct complex temp;
	temp.real = n1.real + n2.real;
	temp.img = n1.img + n2.img;
	return temp;
}
struct complex sub(struct complex n1, struct complex n2)
{
	struct complex temp;
	temp.real = n1.real - n2.real;
	temp.img = n1.img - n2.img;
	return temp;
}
struct complex tich(struct complex n1, struct complex n2)
{
	struct complex temp;
	temp.real = n1.real * n2.real;
	temp.img = n1.img * n2.img;
	return temp;
}
struct complex thuong(struct complex n1, struct complex n2)
{
	struct complex temp;
	temp.real = n1.real / n2.real;
	temp.img = n1.img / n2.img;
	return temp;
}

int main()
{
	struct complex n1;
  struct complex n2;
  //struct complex temp;
	printf ("Enter the real of no 1: ");
	scanf ("%d", &n1.real);
	printf ("Enter the img of no 1: ");
	scanf ("%d", &n1.img);
	printf ("Enter the real of no 2: ");
	scanf ("%d", &n2.real);
	printf ("Enter the img of no 2: ");
	scanf ("%d", &n2.img);
	struct complex res = add(n1, n2);
	struct complex res1 = sub(n1, n2);
	struct complex res2 = tich(n1, n2);
	struct complex res3 = thuong(n1, n2);
	printf ("tong la: %d %d\n", res.real, res.img);
	printf ("hieu la: %d %d\n", res1.real, res1.img);
	printf ("tich la: %d %d\n", res2.real, res2.img);
	printf ("thuong la: %d %d\n", res3.real, res3.img);
	system ("pause");
	return 0;
}
