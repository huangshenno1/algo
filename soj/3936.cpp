#include <stdio.h>
#include <string.h>

typedef struct team 
{
    char team_id[25];
    int ac;
    int penalty;
};

int main()
{
    int t;
    scanf("%d",&t);
    for (int iCase=0;iCase<t;iCase++)
    {
        int n;
        scanf("%d",&n);
        team temp,best;
        scanf("%s%d%d",best.team_id,&best.ac,&best.penalty);
        for (int i=1;i<n;i++)
        {
            scanf("%s%d%d",temp.team_id,&temp.ac,&temp.penalty);
            if (temp.ac>best.ac)
            {
                best=temp;
            }
            else if (temp.ac==best.ac)
            {
                if (temp.penalty<best.penalty)
                {
                    best=temp;
                }
                else if (temp.penalty==best.penalty)
                {
                    if (strcmp(temp.team_id,best.team_id)<0)
                    {
                        best=temp;
                    }
                }
            }
        }
        printf("%s\n",best.team_id);
    }
    return 0;
}