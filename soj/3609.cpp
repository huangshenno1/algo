#include <stdio.h>

int main()
{
    int t;
    scanf("%d",&t);
    for (int iCase=0;iCase<t;iCase++)
    {
        int n,m;
        scanf("%d%d",&n,&m);
        int count_wrong[12]={0};
        int count_AC=0;
        bool IfAC[12]={0};
        int penalty=0;
        int h,mm;
        char problem;
        char result[5];
        for (int i=0;i<m;i++)
        {
            scanf("%d:%d %c %s",&h,&mm,&problem,result);
            if (IfAC[problem-'A']);
            else if (result[0]=='Y')
            {
                penalty+=h*60+mm;
                IfAC[problem-'A']=1;
                count_AC++;
            }
            else count_wrong[problem-'A']++;
        }
        for (int i=0;i<n;i++)
        {
            if (IfAC[i])
                penalty+=count_wrong[i]*20;
        }
        printf("%d %d\n",count_AC,penalty);
    }
    return 0;
}