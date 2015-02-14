#include <cstdio>
#include <cstring>

int iCase;
int n,h;
int fi[25],di[25],ti[25];
int tt,tsum[25];
int ansfish,totalfish,currentfish[25];
int anstime[25],currenttime[25];

int main()
{
    int i,j;
    int imax,tmax;
    scanf("%d",&iCase);
    while (iCase--)
    {
        while (scanf("%d",&n)==1 && n)
        {
            scanf("%d",&h);
            for(i=0;i<n;i++)
                scanf("%d",fi+i);
            for(i=0;i<n;i++)
                scanf("%d",di+i);
            for(i=0;i<n-1;i++)
                scanf("%d",ti+i);

            tsum[0]=0;
            for (i=1;i<n;i++)
                tsum[i]=tsum[i-1]+ti[i-1];

            ansfish=-1;

            for (i=0;i<n;i++)
            {
                tt=h*12-tsum[i];
                memcpy(currentfish,fi,sizeof(fi));
                memset(currenttime,0,sizeof(currenttime));
                totalfish=0;

                while (tt>0)
                {
                    tmax=-1;
                    for (j=0;j<=i;j++)
                    {
                        if (tmax<currentfish[j])
                        {
                            tmax=currentfish[j];
                            imax=j;
                        }
                    }
                    if (tmax<=0)
                    {
                        currenttime[0]+=tt;
                        break;
                    }
                    totalfish+=currentfish[imax];
                    currentfish[imax]-=di[imax];
                    currenttime[imax]++;
                    tt--;
                }

                if (totalfish>ansfish)
                {
                    ansfish=totalfish;
                    memcpy(anstime,currenttime,sizeof(currenttime));
                }
            }

            for(i=0;i<n-1;i++)
                printf("%d, ",anstime[i]*5);
            printf("%d\n",anstime[n-1]*5);
            printf("Number of fish expected: %d\n\n",ansfish);

        }
    }
    return 0;
}