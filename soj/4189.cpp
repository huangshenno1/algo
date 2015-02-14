#include <stdio.h>
#include <string.h>

int main()
{
//    freopen("in.txt","r",stdin);
    char plaintext[10010],changetext[10010],ciphertext[10010];
    int n;
    int i,j,k,l,cl,count;
    while (scanf("%d",&n)==1 && n)
    {
        getchar();
        gets(plaintext);
        l=strlen(plaintext);
        for (i=j=0;i<l;i++)
        {
            if (plaintext[i]>='a'&&plaintext[i]<='z')
                changetext[j++]=plaintext[i]-'a'+'A';
            else if (plaintext[i]==' ');
            else changetext[j++]=plaintext[i];
        }
        count=cl=j;
        i=j=k=0;
        while (count)
        {
            ciphertext[i]=changetext[j];
            j++;
            i=i+n;
            if (i>=cl)
            {
                i=++k;
            }
            count--;
        }
        ciphertext[cl]='\0';
        printf("%s\n",ciphertext);
    }
    return 0;
}