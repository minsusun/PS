#include <bits/stdc++.h>
using namespace std;
 
int dy[] = {-1, 0, 1, 0}, dx[] = {0, 1, 0, -1};
int N, K, X, C;
int D[2001][2001], num[2001][2001];
int par[2000*2000+9];
bool vis[2001][2001];
 
int find(int n)
{
	return par[n] == n ? n : (par[n] = find(par[n]));
}
 
int main()
{
    scanf("%d%d", &N, &K);
    for (int i=1;i<=N;i++)
		for (int j=1;j<=N;j++)
			D[i][j] = 2e9, num[i][j] = ++X;
    for (int i=1;i<=X;i++)
		par[i] = i;
    queue <int> que;
    for (int i=1;i<=K;i++){
        int r, c;
		scanf("%d%d", &r, &c);
        D[r][c] = 0;
		que.push(r);
		que.push(c);
    }
    int ans = 0;
    for (;;ans++){
        while (!que.empty()){
            int y = que.front();
			que.pop();
            int x = que.front();
			que.pop();
            if (D[y][x] != ans){
                que.push(y);
				que.push(x);
                break;
            }
            vis[y][x] = 1; C++;
            for (int d=0;d<4;d++){
                int ny = y+dy[d], nx = x+dx[d];
                if (ny < 1 || ny > N || nx < 1 || nx > N)
					continue;
                if (vis[ny][nx])
				{
                    int a = find(num[ny][nx]), b = find(num[y][x]);
                    if (a != b)
						C--;
                    par[b] = a;
                }
				else if (D[ny][nx] == 2e9)
				{
                    D[ny][nx] = D[y][x]+1;
                    que.push(ny);
					que.push(nx);
                }
            }
        }
        if (C == 1)
			break;
    }
    printf("%d\n", ans);
}
