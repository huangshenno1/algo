#include <stdio.h>

int main()
{
    double speed,weight,strength;
    int flag;
    while (scanf("%lf%lf%lf",&speed,&weight,&strength)==3)
    {
        if (speed==0&&weight==0&&strength==0)
            break;
        flag=0;
        if (speed<=4.5&&weight>=150&&strength>=200)
        {
            printf("Wide Receiver ");
            flag=1;
        }
        if (speed<=6.0&&weight>=300&&strength>=500)
        {
            printf("Lineman ");
            flag=1;
        }
        if (speed<=5.0&&weight>=200&&strength>=300)
        {
            printf("Quarterback ");
            flag=1;
        }
        if (!flag)
            printf("No positions");
        printf("\n");
    }
    return 0;
}