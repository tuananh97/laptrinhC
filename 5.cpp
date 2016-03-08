#include <stdio.h>
#include <conio.h>
#define m 8
 
int main()
{
    int a[m] = {1,4,5,9,2,6,7,10}; //d�y A
    int l[m]; //l[i]: d? d�i DC��TDN c?a d�y a[0],..,a[i] m� c� ch?a a[i]
    int t[m]; //t[i]: v? tr� ph?n t? ngay ph�a tru?c a[i] trong DC��TDN c?a d�y a[0],..,a[i]
 
    // Bu?c 1. L?p b?ng phuong �n (t�nh m?ng L v� T)
    l[0] = 1; t[0] = -1; 
    for (int i=1; i<m; i++)
    {
        int max = 1; //d? d�i DC��TDN c?a d�y a[0],..,a[i]
        for (int j=0; j<i; j++)
            if (a[j] < a[i] && max < l[j] + 1)
            {
                max = l[j] + 1;
                t[i] = j; //d? sau n�y truy v?t: ph?n t? ngay ph�a sau a[i] l� a[j]
            }
        l[i] = max;
    }
 
    //Bu?c 2. T�m v? tr� cu?i c?a DC��TDN
    int lMax = 0; //d? d�i DC��TDN c?a d�y A
    int viTriMax = 0; //a[viTriMax] s? l� ph?n t? cu?i c�ng trong DC��TDN c?a d�y A
    for (int i=1; i<m; i++)
        if (l[i] > lMax)
        {
            lMax = l[i];
            viTriMax = i;
        }
 
    //Bu?c 3. Truy v?t d? t�m DC��TDN (kq): d?a v�o T v� viTriMax
    int kq[m]; 
    int k = lMax-1;
    do {
        kq[k] = a[viTriMax];
        k--;
        viTriMax = t[viTriMax];
    }while (k>=0);
 
    //Bu?c 4. Xu?t k?t qu?
    printf("\n- Day A: "); //Hi?n th? d�y A
    for (int i=0; i<m; i++) printf("%d ", a[i]);
    printf("\n- Day con don dieu tang dai nhat: "); //Hi?n th? DC��TDN
    for (int i=0; i<lMax; i++) printf("%d ", kq[i]);
    printf("\n  (gom %d phan tu)", lMax);
    getch(); //d?ng m�n h�nh d? xem k?t qu?
}
