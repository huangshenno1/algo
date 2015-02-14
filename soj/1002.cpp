#include<stdio.h>
#include<string.h>
#define N 500
void add(char a[],char b[],char c[]);
main()
{
    char a[N],b[N];   
    char str[N];   
    while (scanf("%s%s",a,b)==2)
    {
        add(a,b,str);   
        printf("%s\n",str);
    }
}   
  
void add(char a[],char b[],char c[])   
{   
    int i,e,d;   
    int n,m;   
    char temp;   
    n=strlen(a);   
    m=strlen(b);   
    for(i=0;i<n/2;i++) {temp=a[i];a[i]=a[n-1-i];a[n-1-i]=temp;}   
    for(i=0;i<m/2;i++) {temp=b[i];b[i]=b[m-1-i];b[m-1-i]=temp;}   
  
    e=0;   
    for(i=0;i<n&&i<m;i++)   
    {   
        d=a[i]-'0'+b[i]-'0'+e;   
        e=d/10;   
        c[i]=d%10+'0';   
    }   
    if(i<m)   
    {   
        for(;i<m;i++)   
        {   
            d=b[i]-'0'+e;   
            e=d/10;   
            c[i]=d%10+'0';   
        }   
    }   
    else  
    {   
        for(;i<n;i++)   
        {   
            d=a[i]-'0'+e;   
            e=d/10;   
            c[i]=d%10+'0';   
        }   
    }   
    if(e) c[i++]=e+'0';   
    c[i]=0;   
    n=i;
    for(i=0;i<n/2;i++) {temp=c[i];c[i]=c[n-1-i];c[n-1-i]=temp;}
}