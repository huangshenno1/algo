#include <stdio.h>
#include <string.h>
#define N 1001
#define M 101
typedef struct twords
{
    char character[M];
    int length;
    int count;
}words;
void main()
{
    char ch;
    int state=0,i,j,l,k=0,flag,e;
    char current[M];
    words word[N];
    ch=getchar();
    while(1)
    {
        if (state==0&&((ch>='A'&&ch<='Z')||(ch>='a'&&ch<='z')))
        {
            state=1;
            i=0;
            current[i]=ch;
        }
        else if (state==1&&((ch>='A'&&ch<='Z')||(ch>='a'&&ch<='z')))
        {
            current[++i]=ch;
        }
        else if (state==1&&(ch<'A'||ch>'Z')&&(ch<'a'||ch>'z'))
        {
            state=0;
            flag=0;
            current[i+1]='\0';
            l=strlen(current);
            for (i=0;i<k;i++)
            {
                if (l==word[i].length)
                {
                    e=1;
                    for (j=0;j<l;j++)
                        if (current[j]!=word[i].character[j])
                            e=0;
                    if (e==1)
                    {
                        word[i].count++;
                        flag=1;
                    }
                }
            }
            if (flag==0)
            {
                for (j=0;j<l;j++)
                    word[k].character[j]=current[j];
                word[k].character[l]='\0';
                word[k].count=1;
                word[k].length=l;
                k++;
            }
            current[0]='\0';
        }
        if (ch=='@')
            break;
        ch=getchar();
    }
    for (i=0;i<k;i++)
    {
        printf("%s %d\n",word[i].character,word[i].count);
    }
}