#include <stdio.h>

int main()
{
    char str[50];
    int mileage=0;
    while (1)
    {
        scanf("%s",str);
        if (str[0]=='#')
            break;
        if (str[0]=='0')
        {
            printf("%d\n",mileage);
            mileage=0;
            continue;
        }
        if (str[0]>='0'&&str[0]<='9')
        {
            char classCode[2];
            scanf("%s",classCode);
            int actualMileage=0;
            int i=0;
            while (str[i]>='0'&&str[i]<='9')
            {
                actualMileage=actualMileage*10+str[i++]-'0';
            }
            if (classCode[0]=='F')
                mileage+=2*actualMileage;
            else if (classCode[0]=='B')
                mileage+=(actualMileage+1)/2+actualMileage;
            else if (actualMileage<=500)
                mileage+=500;
            else mileage+=actualMileage;
        }
    }
    return 0;
}