#include <stdio.h>
#include <string.h>

int min(int a,int b)
{
    return a<b?a:b;
}

int main()
{
    char a[1010],b[1010];
    while (gets(a))
    {
        gets(b);
        int lettera[26]={0},letterb[26]={0};
        int la=strlen(a),lb=strlen(b);
        for (int i=0;i<la;i++)
        {
            if (a[i]>='a'&&a[i]<='z')
                lettera[a[i]-'a']++;
        }
        for (int i=0;i<lb;i++)
        {
            if (b[i]>='a'&&b[i]<='z')
                letterb[b[i]-'a']++;
        }
        for (int i=0;i<26;i++)
        {
            int count=min(lettera[i],letterb[i]);
            for (int j=0;j<count;j++)
                printf("%c",i+'a');
        }
        printf("\n");
    }
    return 0;
}