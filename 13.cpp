#include <stdio.h>
#include <math.h> 
#include <iostream>

using namespace std;

int main() 
{ 
float a[20]; 
int n; 
cout<<"nhap n: "; 
cin>>n; 

for(int i = 0;i < n;i++) 
{ 
cout<<"nhap a["<<i<<"]: "; 
cin>>a[i]; 
} 

float m = a[0]; 
int t = 0; 
float M = a[0]; 
int s = 0; 

for(int i = 1;i < n;i++) 
{ 
if(m > a[i]) 
{ 
t = i; 
m = a[i]; 
} 
else 
if(M < a[i]) 
{ 
s = i; 
M = a[i]; 
} 
} 

int tm = ceil(m); 
int tM = floor(M); 
for(int i = tm;i <= tM;i++) 
{ 
int found = 0; 
for(int j = 0;j < n;j++) 
{ 
if((float)i == a[j]) 
{ 
found = 1; 
break; 
} 
} 

if(found == 0) 
cout<<i<<" "; 
} 

system ("pause"); 
return 0;
}
