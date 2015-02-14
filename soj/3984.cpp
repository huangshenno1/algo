#include <stdio.h>

class time
{
public:
    int mm,ss;
public:
    time(int m=0,int s=0):mm(m),ss(s){}
    time &operator=(time oTime);
    time operator+(time oTime);
    time operator-(time oTime);
};

time &time::operator=(time oTime)
{
    mm=oTime.mm;
    ss=oTime.ss;
    return *this;
}

time time::operator+(time oTime)
{
    time ans;
    bool flag=0;
    ans.ss=ss+oTime.ss;
    if (ans.ss>=60)
    {
        flag=1;
        ans.ss-=60;
    }
    ans.mm=mm+oTime.mm;
    if (flag)
        ans.mm++;
    return ans;
}

time time::operator-(time oTime)
{
    time ans;
    bool flag=0;
    ans.ss=ss-oTime.ss;
    if (ans.ss<0)
    {
        flag=1;
        ans.ss+=60;
    }
    ans.mm=mm-oTime.mm;
    if (flag)
        ans.mm--;
    return ans;
}

int main()
{
    int n;
    while (scanf("%d",&n)==1)
    {
        int score[3]={0};
        time team[3];
        time last(0,0);
        int flag=0;
        for (int i=0;i<n;i++)
        {
            int win;
            int m,s;
            scanf("%d%d:%d",&win,&m,&s);
            score[win]++;
            time current(m,s);
            if (flag==1)
            {
                team[1]=team[1]+current-last;
            }
            else if (flag==2)
            {
                team[2]=team[2]+current-last;
            }
            last=current;
            if (score[1]==score[2])
                flag=0;
            else if (score[1]>score[2])
                flag=1;
            else flag=2;
        }
        time current(48,0);
        if (flag==1)
        {
            team[1]=team[1]+current-last;
        }
        else if (flag==2)
        {
            team[2]=team[2]+current-last;
        }
        for (int i=1;i<=2;i++)
            printf("%02d:%02d\n",team[i].mm,team[i].ss);
    }
    return 0;
}