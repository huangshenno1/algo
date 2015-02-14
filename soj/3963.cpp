#include <stdio.h>
#include <string.h>

void Swap(char &a,char &b)
{
    char t=a;
    a=b;
    b=t;
}

void Reverse(char str[],int l)
{
    for (int i=0;i<l/2;i++)
    {
        Swap(str[i],str[l-1-i]);
    }
}

int main()
{
    int t;
    while (scanf("%d",&t)==1)
    {
        for (int iCase=0;iCase<t;iCase++)
        {
            int n,c;
            char str[410000];
            scanf("%d%d%s",&n,&c,str);
            int l=strlen(str);
            Reverse(str,l);
            for (int k=0;k<c;k++)
            {
                for (int i=0;i<l-n;i++)
                {
                    str[l+i]=str[i];
                }
                l=2*l-n;
            }
            Reverse(str,l);
            str[l]='\0';
            printf("%s\n",str);
        }
    }
    return 0;
}