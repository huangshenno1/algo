#include <cstdio>
#include <cstring>
#include <set>
#include <algorithm>
using namespace std;

int T,t,k,order;

struct File
{
    int id;
    char name[12];
    File(char *filename) {strcpy(name,filename); id=order++;}
    bool operator < (File f) {return id<f.id;}
};

struct Dir
{
    int id;
    char name[12];
    Dir* parent;
    set<File*> fchild;
    set<Dir*> dchild;
    Dir(char *dirname,Dir* pa) {strcpy(name,dirname); parent=pa; id=order++;}
    bool operator < (Dir d) {return id<d.id;}
};

set<File*>::iterator queryfile(Dir* cur,char* filename)
{
    set<File*>::iterator it;
    for(it=cur->fchild.begin();it!=cur->fchild.end();it++)
    {
        if(strcmp((*it)->name,filename)==0) return it;
    }
    return it;
}

set<Dir*>::iterator querydir(Dir* cur,char* dirname)
{
    set<Dir*>::iterator it;
    for(it=cur->dchild.begin();it!=cur->dchild.end();it++)
    {
        if(strcmp((*it)->name,dirname)==0) return it;
    }
    return it;
}

int main()
{
    char cmd[6],str[12];
    set<File*>::iterator itf;
    set<Dir*>::iterator itd;
    scanf("%d",&T);
    for (t=1;t<=T;t++)
    {
        order=0;
        Dir* root=new Dir("root",0);
        Dir* cur=root;
        printf("Case #%d:\n",t);
        scanf("%d",&k);
        while (k--)
        {
            scanf("%s",cmd);
            if (strcmp(cmd,"cd")==0)
            {
                scanf("%s",str);
                if (strcmp(str,"..")==0)
                {
                    if (cur!=root) cur=cur->parent;
                    else puts("No parent directory!");
                }
                else
                {
                    itd=querydir(cur,str);
                    if (itd==cur->dchild.end()) puts("No such directory!");
                    else cur=*itd;
                }
            }
            else if (strcmp(cmd,"touch")==0)
            {
                scanf("%s",str);
                itf=queryfile(cur,str);
                if (itf!=cur->fchild.end()) puts("File already exists!");
                else
                {
                    File* f=new File(str);
                    cur->fchild.insert(f);
                }
            }
            else if (strcmp(cmd,"rm")==0)
            {
                scanf("%s",str);
                itf=queryfile(cur,str);
                if (itf==cur->fchild.end()) puts("No such file!");
                else cur->fchild.erase(itf);
            }
            else if (strcmp(cmd,"mkdir")==0)
            {
                scanf("%s",str);
                itd=querydir(cur,str);
                if (itd!=cur->dchild.end()) puts("Directory already exists!");
                else
                {
                    Dir* d=new Dir(str,cur);
                    cur->dchild.insert(d);
                }
            }
            else if (strcmp(cmd,"rmdir")==0)
            {
                scanf("%s",str);
                itd=querydir(cur,str);
                if (itd==cur->dchild.end()) puts("No such directory!");
                else cur->dchild.erase(itd);
            }
            else
            {
                itf=cur->fchild.begin();
                itd=cur->dchild.begin();
                while (itf!=cur->fchild.end() && itd!=cur->dchild.end())
                {
                    if ((*itf)->id<(*itd)->id)
                    {
                        printf("%s <F>\n",(*itf)->name);
                        itf++;
                    }
                    else
                    {
                        printf("%s <D>\n",(*itd)->name);
                        itd++;
                    }
                }
                while (itf!=cur->fchild.end()) 
                {
                    printf("%s <F>\n",(*itf)->name);
                    itf++;
                }
                while (itd!=cur->dchild.end())
                {
                    printf("%s <D>\n",(*itd)->name);
                    itd++;
                }
            }
        }
    }
    return 0;
}