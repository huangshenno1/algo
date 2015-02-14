#include <stdio.h>
#include <string.h>
#define N 900
void divide(char a[],char b[],char c[]);
int digit(int aa[],char b[],int k,int m,int n);

void main()
{
    char a[N],b[N],c[N];
    while (scanf("%s%s",a,b)==2)
    {
        divide(a,b,c);
        printf("%s\n",c);
    }
}

void divide(char a[],char b[],char c[])
{
    int m,n,i,j,count=0;
    int aa[N];
    m=strlen(a);
    n=strlen(b);
    for (i=0;i<m;i++)
        aa[i]=a[i]-'0';
    if (m==n)
    {
        while (aa[0]!=0)
        {
            for (i=m-1;i>=0;i--)
            {
                aa[i]=aa[i]-b[i]+'0';
                j=i;
                while (aa[j]<0)
                {
                    aa[j]+=10;
                    aa[j-1]--;
                    j--;                    
                }
            }
            count++;
        }
        c[0]=count+'0';
        c[1]=0;
    }
    if (m>n)
    {
        for (i=0;i<m-n;i++)
        {
            aa[i]=digit(aa,b,i,m,n);
        }
        if (aa[0]<10)
        {
            for (;i>=0;)
            {
                i--;
                c[i]=aa[i]+'0';
            }
            c[m-n]=0;
        }
        if (aa[0]>9)
        {
            for (;i>1;i--)
                c[i]=aa[i-1]+'0';
            c[1]=aa[0]%10+'0';
            c[0]=aa[0]/10+'0';
            c[m-n+1]=0;
        }
    }
}

int digit(int aa[],char b[],int k,int m,int n)
{
    int i,j,count=0;
    int t[N];
    for (i=0;i<=n;i++)
        t[i]=aa[k+i];
    while (t[0]>=0)
    {
        for (i=0;i<=n;i++)
            aa[k+i]=t[i];
        for (i=n;i>0;i--)
        {
            t[i]=t[i]-b[i-1]+'0';
            j=i;
            while (t[j]<0&&t[0]>=0)
            {
                t[j]+=10;
                t[j-1]--;
                j--;                    
            }
        }
        if (t[0]<0)
            break;
        count++;
    }
    return count;
}