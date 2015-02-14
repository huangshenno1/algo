#include <stdio.h>

int main()
{
    int n;
    while (scanf("%d",&n)==1)
    {
        int sequence[1010]={-1};
        int length[1010]={0};
        int max=0;
        for (int i=1;i<=n;i++)
        {
            scanf("%d",&sequence[i]);
            for (int j=0;j<i;j++)
            {
                if (sequence[j]<sequence[i]&&length[j]>=length[i])
                    length[i]=length[j]+1;
            }
            if (length[i]>max)
                max=length[i];
        }
        printf("%d\n",max);
        
    }
    return 0;
}