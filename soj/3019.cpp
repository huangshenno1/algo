
# include<stdio.h>
# include<string.h>
struct node{
    int left,right,mid,num;///如果num==-1，说明该节点以下，出现了至少两种颜色！如果为一个正数，则存的是颜色的类型！
}a[400001];
int visit[32];
void make(int ans1 ,int ans2,int step)
{
    a[step].left=ans1;
    a[step].right=ans2;
    a[step].mid=(ans1+ans2)/2;
    a[step].num=1;
    if(ans1==ans2) return;
    make(ans1,a[step].mid,2*step);
    make(a[step].mid+1,ans2,2*step+1);
}
void update(int ans1,int ans2,int c,int step)
{
    if(a[step].left==ans1 && a[step].right==ans2)  
    {
        a[step].num=c;
        return;
    }
    if(a[step].num==c) return;
    if(a[step].num!=-1)
    {
        a[2*step].num=a[step].num;
        a[2*step+1].num=a[step].num;
        a[step].num=-1;
    }
    if(ans1>a[step].mid) update(ans1,ans2,c,2*step+1);
    else if(ans2<=a[step].mid) update(ans1,ans2,c,2*step);
    else
    {
        update(ans1,a[step].mid,c,2*step);
        update(a[step].mid+1,ans2,c,2*step+1);
    }
}
void query(int ans1,int ans2,int step)
{
    if(a[step].num!=-1) {visit[a[step].num]=1;return;}
    if(ans2<=a[step].mid) query(ans1,ans2,2*step);
    else if(ans1>a[step].mid) query(ans1,ans2,2*step+1);
    else
    {
        query(ans1,a[step].mid,2*step);
        query(a[step].mid+1,ans2,2*step+1);
    }
}
int main()
{
    int i,n,m,t,a,b,temp,c,count;
    char s[3];
    while(scanf("%d%d%d",&n,&t,&m)!=EOF)
    {
        make(1,n,1);
        while(m--)
        {
            scanf("%s%d%d",s,&a,&b);
            if(a>b)
            {
                temp=a;
                a=b;
                b=temp;
            }
            if(s[0]=='C')
            {
                scanf("%d",&c);
                update(a,b,c,1);
            }
            else
            {
                memset(visit,0,sizeof(visit));
                query(a,b,1);
                count=0;
                for(i=1;i<=30;i++)
                    if(visit[i]==1) count++;
                printf("%d\n",count);
            }
        }
    }
    return 0;
}