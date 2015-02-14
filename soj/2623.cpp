#include <stdio.h>

int main()
{
    char sentence[260];
    int length=0;
    scanf("%c",&sentence[length++]);
    while (sentence[length-1]!='#'&&sentence[length-1]!='.'&&sentence[length-1]!='?'&&sentence[length-1]!='!')
    {
        scanf("%c",&sentence[length++]);
    }
    while (sentence[0]!='#')
    {
        int count=0;
        for (int i=0;i<length;i++)
        {
            if (sentence[i]=='a'||sentence[i]=='A'||sentence[i]=='e'||sentence[i]=='E'||sentence[i]=='i'||sentence[i]=='I'||sentence[i]=='o'||sentence[i]=='O'||sentence[i]=='u'||sentence[i]=='U')
                count++;
        }
        printf("%d\n",count);

        char c;
        do
        {
            c=getchar();
        }while (c=='\r'||c=='\n'||c==' ');
        length=0;
        sentence[length++]=c;
        while (sentence[length-1]!='#'&&sentence[length-1]!='.'&&sentence[length-1]!='?'&&sentence[length-1]!='!')
        {
            scanf("%c",&sentence[length++]);
        }
    }
    return 0;
}