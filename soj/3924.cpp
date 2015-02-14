#include <stdio.h>
#include <map>
#include <string>
using namespace std;

int main()
{
    int t;
    scanf("%d",&t);
    for (int iCase=0;iCase<t;iCase++)
    {
        map<string,int> course;
        map<string,int>::iterator p;
        int n;
        scanf("%d",&n);
        int count=0;
        char temp[32];
        string coursename;
        int score;
        for (int i=0;i<n;i++)
        {
            scanf("%s%d",temp,&score);
            coursename=temp;
            p=course.find(coursename);
            if (p==course.end())
                course.insert(map<string,int>::value_type(coursename,score));
            else if (p->second<score)
            {
                p->second=score;
                count++;
            }
        }
        printf("%d\n",count);
    }
    return 0;
}