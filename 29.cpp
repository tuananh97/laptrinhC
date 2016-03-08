#include <stdio.h>
#include <string.h>
int strInStr(char* papaStr,char* kidStr)
{
    char* tmp;
    if (tmp = strstr(papaStr,kidStr))
    {
        return (tmp - papaStr);
    }
    else
    {
        return -1;
    }
}
int main ()
{
    char str1[] ="This is a simple string";
    char str2[]="is a";
    
    printf("\n%d\n",strInStr(str1,str2));
    system ("pause");
    return 0;
}
