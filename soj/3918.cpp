#include <stdio.h>

int main()
{
    int a,b,v;
    while (scanf("%d%d%d",&a,&b,&v)==3)
    {
        printf("%d\n",1+((v-a)%(a-b)?(v-a)/(a-b)+1:(v-a)/(a-b)));
    }
    return 0;
}