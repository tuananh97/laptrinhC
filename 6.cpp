#include<stdio.h>
#include<conio.h>
#include<math.h>
#include<malloc.h>
#include<stdlib.h>
int main()
{
    int *mang,n,k=0;
    do
    {
        printf("Nhap so luong phan tu: ");
        scanf("%d",&n);
        if(n<2)
        { 
            system("cls");
            printf("Ban phai nhap vao mot so lon hon 1\n");
        }
    }while(n<2);
    mang=(int*)malloc(n*sizeof(int));
    for(int i=0;i<n;i++)
    {
        printf("Nhap vao phan tu thu %d: ",i+1);
        scanf("%d",&mang[i]);    
        
    }
    do
    {
        printf("Nhap vao so k: ");
        scanf("%d",&k);
        if(k<1)
        { 
            system("cls");
            printf("Ban phai nhap vao mot so lon hon 1\n");
        }
    }while(k<1);
    int *mangphu1, *mangphu2, phu1=0,phu2=0;
    mangphu1=(int*)malloc(n*sizeof(int));
    mangphu2=(int*)malloc(n*sizeof(int));
    //XET K SO DUNG CANH NHAU;
    for(int i=0;i<n+1-k;i++)
    {
       int dem=0;
       int j=i+1;
             if(mang[i]>0)
               {
              do
                 {
                    
                    if(mang[j]>0)
                       {
                           dem++;
                           if(dem==k-1)
                           {
                               mangphu1[phu1]=i;
                                   phu1++;
                               mangphu2[phu2]=j;
                                   phu2++;
                           }
                      }
                    
               }while(dem<k-1&&j++-i<k-1);
                
            }
    }
    
    for(int i=0;i<phu1;i++)
        printf("\n%d::::%d",mangphu1[i],mangphu2[i]);
    if(phu1==0)
        printf("\nKhong co day %d phan tu duong ke nhau.\n",k);
    else
    {
        printf("\nCac mang co %d so la: \n",k);
        for(int i=0;i<phu1;i++)
        {
            int j=mangphu1[i];
            int dem=0;
            do
            {
                printf("%d ",mang[j]);    
                dem++;
                j++;
            }while(dem<k);
            printf("\n");
        }

        int *mangphu3, phu3=0;
        mangphu3=(int*)malloc(n*sizeof(int));
        for(int i=0;i<phu1;i++)
        {
            int j=mangphu1[i],flag=1;
            int congboi=mang[j+1]-mang[j];
            for(int k=j+2;k<=mangphu2[i];k++)
            {
                if(mang[k]-mang[k-1]!=congboi)
                    flag=0;
            }
            if(flag)
                mangphu3[phu3++]=j;
        }
        printf("\nDay so nguyen duong lap thanh cap so cong: \n");
        for(int i=0;i<phu3;i++)
        {
            int j=mangphu3[i];
            int dem=0;
            do
            {
                printf("%d ",mang[j]);    
                dem++;
                j++;
            }while(dem<k);
            printf("\n");
        }
        
     }
    getch();
    return 0;
}  
