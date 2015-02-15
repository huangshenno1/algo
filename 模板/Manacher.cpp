// Manacher

#include <cstdio>  
#include <cstring>  
  
const int maxn = 222222;  
char str[maxn],strr[maxn];  
int n,ans,p[maxn],mx,id;  
  
void init()  
{  
    n=strlen(strr);  
    str[0]='$'; str[1]='#';  
    for (int i=0;i<n;i++) {str[i*2+2]=strr[i]; str[i*2+3]='#';}  
    n=n*2+2;  
    str[n]='\0';  
}  
  
int main()  
{  
    while (scanf("%s",strr)==1)  
    {  
        init();  
        mx=0;  
        for (int i=1;i<n;i++)  
        {  
            if (mx>i) p[i]=min(p[id*2-i],p[id]+id-i);  
            else p[i]=1;  
            while (str[i+p[i]]==str[i-p[i]]) p[i]++;  
            if (p[i]+i>mx) {mx=p[i]+i; id=i;}  
        }  
        ans=0;  
        for (int i=1;i<n;i++) ans=max(ans,p[i]-1);  
        printf("%d\n",ans);  
    }  
    return 0;  
}  