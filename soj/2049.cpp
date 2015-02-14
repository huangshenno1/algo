#include <stdio.h>
#include <string.h>

char index_string[1000010];

int main()
{
    long long index[256];
    int exist_index[256];
    char str[1010];
    long long s;
    int t,n,i;
    scanf("%d",&t);
    getchar();
    while (t--)
    {
        memset(index,0,sizeof(index));
        gets(index_string);
        for (i=0;index_string[i]!='\0';i++)
        {
            index[index_string[i]]+=(i+1);
        }
        scanf("%d",&n);
        getchar();
        while (n--)
        {
            memset(exist_index,0,sizeof(exist_index));
            gets(str);
            s=0;
            for (i=0;str[i]!='\0';i++)
            {
                if (!exist_index[str[i]])
                {
                    exist_index[str[i]]=1;
                    s+=index[str[i]];
                }
            }
            printf("%lld\n",s);
        }
        printf("\n");
    }
    return 0;
}