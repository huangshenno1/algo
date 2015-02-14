#include <cstdio>
#include <cstring>

int main()
{
    int T,n,i,k;
    char str[100];
    int count[26],ans[26];
    scanf("%d",&T);
    while (T--)
    {
        scanf("%d",&n);
        printf("document count: %d\n",n);
        memset(ans,0,sizeof(ans));
        k=1;
        while (n--)
        {
            scanf("%s",str);
            memset(count,0,sizeof(count));
            for (i=0;str[i]!='\0';i++)
                count[str[i]-'a']++;
            for (i=0;i<26;i++)
                if (count[i]) ans[i]++;
            printf("words count of document %d: %d\n",k++,strlen(str));
            printf("%d",count[0]);
            for (i=1;i<26;i++)
                printf(" %d",count[i]);
            printf("\n");
        }
        printf("\n%d",ans[0]);
        for (i=1;i<26;i++)
            printf(" %d",ans[i]);
        printf("\n\n");
    }
    return 0;
}