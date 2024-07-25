#include <stdio.h>
#include <queue>
 
using namespace std;
 
struct s {
    int y;
    int x;
    int cnt;
};
 
queue <s> q;
 
int mx = 0;
int chk[51][51];
char a[51][51];
 
int main()
{
    int n,m,num=1;
    scanf("%d %d",&n,&m);
    for (int i=0; i<n; i++) scanf(" %s",a[i]);
     
    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            if (a[i][j] == 'L') {
                num++;
                q.push({i,j,0});
                chk[i][j] = num;
                while(!q.empty()) {
                    int y = q.front().y;
                    int x = q.front().x;
                    int cnt = q.front().cnt;
                    if (cnt > mx) mx = cnt;
                     
                    if (a[y+1][x] == 'L' && chk[y+1][x] != num) {
                        q.push({y+1,x,cnt+1});
                        chk[y+1][x] = num;
                    }
                    if (a[y-1][x] == 'L' && chk[y-1][x] != num) {
                        q.push({y-1,x,cnt+1});
                        chk[y-1][x] = num;
                    }
                    if (a[y][x+1] == 'L' && chk[y][x+1] != num) {
                        q.push({y,x+1,cnt+1});
                        chk[y][x+1] = num;
                    }
                    if (a[y][x-1] == 'L' && chk[y][x-1] != num) {
                        q.push({y,x-1,cnt+1});
                        chk[y][x-1] = num;
                    }
                    q.pop();
                }
            }
             
        }
    }
    printf("%d",mx);
}
