#include <stdio.h>

void swap(int &a,int &b)
{
    int t=a;
    a=b;
    b=t;
}

void sort(int &a,int &b,int &c)
{
    if (a>b)
        swap(a,b);
    if (b>c)
        swap(b,c);
}

int main()
{
    int t;
    int iCase;
    int a,b,c;
    scanf("%d",&t);
    for (int iCase=0;iCase<t;iCase++)
    {
        scanf("%d%d%d",&a,&b,&c);
        sort(a,b,c);
        if (a+b<c)
            printf("NO\n");
        else printf("YES\n");        
    }
    return 0;
}