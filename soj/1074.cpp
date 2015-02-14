#include <stdio.h>
#include <string.h>
#define N 51
void minus(char a[],char b[],char c[]);

void main()
{
    char a[N],b[N],c[N];
    int m,n,i,flag;
    while (scanf("%s%s",a,b)==2)
    {
        m=strlen(a);
        n=strlen(b);
        flag=1;
        if (m<n)
            printf("are you crazy?\n");
        else if (m==n)
        {
            for (i=0;i<m;i++)
                if (a[i]!=b[i])
                    flag=0;
            if (flag==1)
                printf("well done!\n");
            else
            {
                minus(a,b,c);
                if (c[0]=='0')
                    printf("are you crazy?\n");
                else printf("%s\n",c);
            }
        }
        else
        {
            minus(a,b,c);
            printf("%s\n",c);
        }
    }
}

void minus(char a[],char b[],char c[])
{
    int i,j,e;
    int n,m;
    char temp;
    m=strlen(a);
    n=strlen(b);
    if (m==n)
    {
        for (i=0;i<m;i++)
        {
            if (a[i]>b[i])
                break;
            else if (a[i]<b[i])
            {
                c[0]='0';
                c[1]=0;
                return;
            }
        }
    }
    for(i=0;i<m/2;i++) {temp=a[i];a[i]=a[m-1-i];a[m-1-i]=temp;}
    for(i=0;i<n/2;i++) {temp=b[i];b[i]=b[n-1-i];b[n-1-i]=temp;}
    for(i=n;i<m;i++)
        b[i]='0';
    b[i]=0;
    e=0;
    for (i=0;i<m;i++)
    {
        c[i]=a[i]-b[i]+'0'-e;
        if (c[i]<'0')
        {
            c[i]+=10;
            e=1;
        }
        else e=0;
    }
    for (j=m-1;j>0;j--)
    {
        if (c[j]=='0')
            c[j]=0;
        else if (c[j]!='0')
        {
            c[j+1]=0;
            break;
        }
    }
    for(i=0;i<(j+1)/2;i++)
        {temp=c[i];c[i]=c[j-i];c[j-i]=temp;}
}