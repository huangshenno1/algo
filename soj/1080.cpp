#include <stdio.h>
#define N 110
void main()
{
    int stage,ammo,life;
    int monsternumber,ammosupport,lifesupport;
    int ammocost,damage;
    int i,flag,killnum;
    char monster[10];
    scanf("%d %d %d",&stage,&ammo,&life);
    while (stage!=0&&life!=0&&ammo!=0)
    {
        for (i=0;i<stage;i++)
        {
            scanf("%s",monster);
            scanf("%d %d %d",&monsternumber,&ammosupport,&lifesupport);
            flag=0;
            switch(monster[0])
            {
            case 'Z':
                ammocost=3;
                damage=1;
                break;
            case 'C':
                ammocost=4;
                damage=1;
                break;
            case 'S':
                ammocost=5;
                damage=2;
                break;
            case 'L':
                ammocost=6;
                damage=3;
                break;
            case 'T':
                ammocost=15;
                damage=4;
                break;
            case 'N':
                ammocost=20;
                damage=4;
                flag=1;
                break;
            }
            if (ammo>=(ammocost*monsternumber))
            {
                ammo=ammo-ammocost*monsternumber;
                if (!flag)
                {
                    ammo+=ammosupport*9;
                    life+=lifesupport*4;
                }                
            }
            else
            {
                life=life-damage*(monsternumber-ammo/ammocost);
                ammo=ammo%ammocost;
                if (life<1)
                {
                    printf("You are gonna die down here.\n");
                    break;
                }
            }
        }
        if (life>0)
            printf("You can survive in the last escape.\n");
        scanf("%d %d %d",&stage,&ammo,&life);
    }
}
