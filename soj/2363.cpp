#include <stdio.h>
#include <string.h>

int main()
{
    int score[5]={0,15,30,40,40};
    int t;
    scanf("%d",&t);
    for (int iCase=0;iCase<t;iCase++)
    {
        int n;
        scanf("%d",&n);
        char nameA[10],nameB[10];
        scanf("%s",nameA);
        scanf("%s",nameB);
        char nameWin[10];
        int scoreA=0,scoreB=0;
        for (int i=0;i<n;i++)
        {
            scanf("%s",nameWin);
            if (strcmp(nameWin,nameA)==0)
                scoreA++;
            else
                scoreB++;
            if (scoreA-scoreB>1&&scoreA>=4)
            {
                scoreA=0;
                scoreB=0;
                printf("+----------+--+\n|%-10s|%2d|\n+----------+--+\n|%-10s|%2d|\n+----------+--+\n|game %-8s|\n+-------------+\n",nameA,score[scoreA],nameB,score[scoreB],nameA);
            }
            else if (scoreB-scoreA>1&&scoreB>=4)
            {
                scoreA=0;
                scoreB=0;
                printf("+----------+--+\n|%-10s|%2d|\n+----------+--+\n|%-10s|%2d|\n+----------+--+\n|game %-8s|\n+-------------+\n",nameA,score[scoreA],nameB,score[scoreB],nameB);
            }
            else if (scoreA>=3&&scoreB>=3)
            {
                if (scoreA==scoreB)
                {
                    scoreA=3;
                    scoreB=3;
                    printf("+----------+--+\n|%-10s|%2d|\n+----------+--+\n|%-10s|%2d|\n+----------+--+\n|deuce        |\n+-------------+\n",nameA,score[scoreA],nameB,score[scoreB]);
                }
                else if (scoreA>scoreB)
                {
                    scoreA=4;
                    scoreB=3;
                    printf("+----------+--+\n|%-10s|%2d|\n+----------+--+\n|%-10s|%2d|\n+----------+--+\n|adv. %-8s|\n+-------------+\n",nameA,score[scoreA],nameB,score[scoreB],nameA);
                }
                else
                {
                    scoreA=3;
                    scoreB=4;
                    printf("+----------+--+\n|%-10s|%2d|\n+----------+--+\n|%-10s|%2d|\n+----------+--+\n|adv. %-8s|\n+-------------+\n",nameA,score[scoreA],nameB,score[scoreB],nameB);
                }
            }
            else
            {
                printf("+----------+--+\n|%-10s|%2d|\n+----------+--+\n|%-10s|%2d|\n+----------+--+\n|             |\n+-------------+\n",nameA,score[scoreA],nameB,score[scoreB]);
            }
        }
        printf("\n");
    }
    return 0;
}