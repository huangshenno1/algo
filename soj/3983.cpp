#include <stdio.h>

int abs(int a)
{
    return a>=0?a:-a;
}

int main()
{
    int mushroom[10];
    while (scanf("%d",&mushroom[0])==1)
    {
        for (int i=1;i<10;i++)
            scanf("%d",&mushroom[i]);
        int score=mushroom[0];
        for (int i=1;i<10;i++)
        {
            if (abs(score+mushroom[i]-100)<abs(score-100))
                score+=mushroom[i];
            else
            {
                if (abs(score+mushroom[i]-100)==abs(score-100))
                    score+=mushroom[i];
                break;
            }
        }
        printf("%d\n",score);
    }
    return 0;
}