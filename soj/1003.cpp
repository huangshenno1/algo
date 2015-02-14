#include<stdio.h>
#include<string.h>
#define N 1000
void multi(char a[],char b[],char c[]);

main()
{
    char a[N],b[N];   
    char c[N];
    int n,m,i,flag;
    while (scanf("%s%s",a,b)==2)
    {
        flag=0;
        if (a[0]=='0'||b[0]=='0')
        {
            printf("0\n");
            continue;
        }
        if (a[0]=='-'&&b[0]!='-')
        {
            n=strlen(a);
            for (i=0;i<n-1;i++)
                a[i]=a[i+1];
            a[i]=0;
            flag=1;
        }
        if (a[0]!='-'&&b[0]=='-')
        {
            n=strlen(b);
            for (i=0;i<n-1;i++)
                b[i]=b[i+1];
            b[i]=0;
            flag=1;
        }
        if (a[0]=='-'&&b[0]=='-')
        {
            m=strlen(a);
            n=strlen(b);
            for (i=0;i<m-1;i++)
                a[i]=a[i+1];
            a[i]=0;
            for (i=0;i<n-1;i++)
                b[i]=b[i+1];
            b[i]=0;
        }
        multi(a,b,c);
        if (flag)
            putchar('-');
        printf("%s\n",c);
    }
}   
  
void multi(char a[],char b[],char c[])   
{   
    int i,j,e,t;   
    int m,n;   
    char temp;   
    m=strlen(a);   
    n=strlen(b);   
    for(i=0;i<m/2;i++) {temp=a[i];a[i]=a[m-1-i];a[m-1-i]=temp;}   
    for(i=0;i<n/2;i++) {temp=b[i];b[i]=b[n-1-i];b[n-1-i]=temp;}     
    for(i=0;i<m+n-1;i++)
        c[i]='0';
    for (j=0;j<n;j++)
    {
        e=0;
        for (i=0;i<m;i++)
        {
            t=(a[i]-'0')*(b[j]-'0')+c[i+j]-'0'+e;
            c[i+j]=t%10+'0';
            e=t/10;
        }
        if(e)
            c[i+j]=e+'0';
    }
    t=m+n-1;
    if(e)
        t++;
    c[t]=0;
    for(i=0;i<t/2;i++) {temp=c[i];c[i]=c[t-1-i];c[t-1-i]=temp;}   
}
