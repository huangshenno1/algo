#include <cstdio>
#include <cstring>
#include <cctype>

int T,n,m;
char key[20][30],excuse[20][100];
int b,j,k,s,l;
int f[20],ff;
char word[30];

int main()
{
    int i;
    T=1;
    while (scanf("%d%d",&n,&m)==2)
    {
        for (i=0;i<n;i++)
            scanf("%s",key[i]);
        ff=0;
        getchar();
        for (i=0;i<m;i++)
        {
            gets(excuse[i]);
            f[i]=0;
            l=strlen(excuse[i]);
            b=0;
            while (b!=l)
            {
                k=0;
                for (j=b;(excuse[i][j]>='A'&&excuse[i][j]<='Z')||(excuse[i][j]>='a'&&excuse[i][j]<='z');j++)
                    word[k++]=tolower(excuse[i][j]);
                word[k]='\0';
                for (s=0;s<n;s++)
                {
                    if (strcmp(word,key[s])==0)
                    {
                        f[i]++;
                        break;
                    }
                }
                while (!((excuse[i][j]>='A'&&excuse[i][j]<='Z')||(excuse[i][j]>='a'&&excuse[i][j]<='z')) && j<l)
                    j++;
                b=j;
            }
            if (f[i]>ff)
                ff=f[i];
        }
        printf("Excuse Set #%d\n",T++);
        for (i=0;i<m;i++)
        {
            if (f[i]==ff)
                printf("%s\n",excuse[i]);
        }
        printf("\n");
    }
    return 0;
}