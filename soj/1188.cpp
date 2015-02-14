#include <stdio.h>

int main()
{
    int R[16],G[16],B[16];
    int r,g,b;
    int min,mr,mg,mb;
    int temp;
    int i;
    for (i=0;i<16;i++)
        scanf("%d%d%d",&R[i],&G[i],&B[i]);
    while (scanf("%d%d%d",&r,&g,&b)==3)
    {
        if (r==-1&&g==-1&&b==-1)
            break;
        min=2111111111;
        for (i=0;i<16;i++)
        {
            temp=(r-R[i])*(r-R[i])+(g-G[i])*(g-G[i])+(b-B[i])*(b-B[i]);
            if (temp<min)
            {
                min=temp;
                mr=R[i];
                mg=G[i];
                mb=B[i];
            }
        }
        printf("(%d,%d,%d) maps to (%d,%d,%d)\n",r,g,b,mr,mg,mb);
    }
    return 0;
}