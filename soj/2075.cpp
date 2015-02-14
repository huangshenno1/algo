#include <stdio.h>
#include <math.h>
#include <algorithm>
using namespace std;

struct Island
{
    int x, y;
    double x1, x2;
    bool operator < (const Island &t) const
    {
        return x < t.x;
    }
};

int main()
{
    int n, d;
    int iCase = 1;
    while (scanf("%d%d", &n, &d) == 2 && (n||d))
    {
        bool noSolution=0;
        Island island[1005];
        for (int i=0;i<n;i++)
        {
            scanf("%d%d", &island[i].x, &island[i].y);
            if (island[i].y>d) noSolution=1;
        }
        if (noSolution)
        {
            printf("Case %d: -1\n", iCase++);
            continue;
        }
        for (int i=0;i<n;i++)
        {
            double distance=sqrt((double)(d*d-island[i].y*island[i].y));
            island[i].x1=island[i].x-distance;
            island[i].x2=island[i].x+distance;
        }
        sort(island, island+n);
        int count=0;
        for (int i=0;i<n;i++)
        {
            count++;
            double radar_x1=island[i].x1;
            double radar_x2=island[i].x2;
            while (i+1 < n && island[i+1].x1<=radar_x2)
            {
                radar_x2 = min(radar_x2,island[i+1].x2);
                i++;
            }
        }
        printf("Case %d: %d\n", iCase++, count);
    }
    return 0;
}
