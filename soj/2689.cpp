#include <stdio.h>
#include <set>
using namespace std;

int main()
{
    int n;
    scanf("%d",&n);
    for (int iCase=1;iCase<=n;iCase++)
    {
        bool flag=1;
        int sudoku[9][9];
        for (int i=0;i<9;i++)
        {
            for (int j=0;j<9;j++)
            {
                scanf("%d",&sudoku[i][j]);
            }
        }
        if (flag)
        {
            for (int i=0;i<9;i++)
            {
                set<int> line;
                for (int j=0;j<9;j++)
                {
                    line.insert(sudoku[i][j]);
                }
                if (line.size()!=9)
                {
                    flag=0;
                    break;
                }
            }
        }
        if (flag)
        {
            for (int j=0;j<9;j++)
            {
                set<int> line;
                for (int i=0;i<9;i++)
                {
                    line.insert(sudoku[i][j]);
                }
                if (line.size()!=9)
                {
                    flag=0;
                    break;
                }
            }
        }
        if (flag)
        {
            for (int ii=0;ii<3;ii++)
            {
                for (int jj=0;jj<3;jj++)
                {
                    set<int> line;
                    for (int i=ii*3;i<ii*3+3;i++)
                    {
                        for (int j=jj*3;j<jj*3+3;j++)
                        {
                            line.insert(sudoku[i][j]);
                        }
                    }
                    if (line.size()!=9)
                    {
                        flag=0;
                        break;
                    }
                }
            }
        }
        printf("Case %d:\n",iCase);
        if (flag)
            printf("Yes!\n");
        else printf("No!\n");
    }
    return 0;
}