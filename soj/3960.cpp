#include <stdio.h>

int main()
{
    int n;
    while (scanf("%d",&n)==1)
    {
        bool cow[250]={1};
        int p=0;
        while (!cow[(p+p+1)%n])
        {
            p=(p+p+1)%n;
            cow[p]=1;
        }
        printf("%d\n",p+1);
    }
    return 0;
}