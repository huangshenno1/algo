#include <stdio.h>
#include <string.h>

char convert[128]={0,0,0,0,0,0,0,0,0,0,10,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,' ',0,0,0,0,0,0,';',0,0,0,0,'M','0',',','.','9','`','1','2','3','4','5','6','7','8',0,'L',0,'-',0,0,0,0,'V','X','S','W','D','F','G','U','H','J','K','N','B','I','O',0,'E','A','R','Y','C','Q','Z','T',0,'P',']','['};

int main()
{
    char c;
    while (scanf("%c",&c)==1)
    {
        printf("%c",convert[c]);
    }
    return 0;
}