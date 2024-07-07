#include <bits/stdc++.h>
using namespace std;
 
int N, M, S, E, T;
int A[3001][3001], B[3001];
int D[3001][3001], C[3001][3001];
 
struct Z{
    int v, t;
} mn[3001][3];
 
deque <Z> dq[3001];
 
int get_min(int day, int academy)
{
    if (mn[day][0].t != academy && mn[day][0].t != B[academy])
		return mn[day][0].v;
    if (mn[day][1].t != academy && mn[day][1].t != B[academy])
		return mn[day][1].v;
    return mn[day][2].v;
}
 
int main()
{
    scanf("%d%d%d%d%d", &N, &M, &S, &E, &T);
    for (int i=1;i<=N;i++)
		for (int j=1;j<=M;j++)
			scanf("%d", A[i]+j);
    for (int i=1;i<=N;i++)
		scanf("%d", B+i);
    for (int i=1;i<=N;i++)
		for (int j=1;j<=M;j++)
			C[i][j] = C[i][j-1] + A[i][j];
    for (int i=1;i<=M;i++){
        for (int j=1;j<=N;j++){
            if (i >= S){
                int v = get_min(i-S, j) - C[j][i-S];
                while (!dq[j].empty() && dq[j].back().v >= v)
					dq[j].pop_back();
                dq[j].push_back({v, i-S});
            }
            while (!dq[j].empty() && dq[j].front().t < i-E)
				dq[j].pop_front();
            if (dq[j].empty() || dq[j].front().v == 1e9)
				D[i][j] = 1e9;
            else
				D[i][j] = dq[j].front().v + T + C[j][i];
        }
        for (int j=0;j<3;j++)
			mn[i][j] = {(int)1e9, 0};
        for (int j=1;j<=N;j++)
			if (D[i][j] < 1e9)
			{
            	int v = D[i][j];
            	if (v < mn[i][0].v)
                	mn[i][2] = mn[i][1], mn[i][1] = mn[i][0], mn[i][0] = {v, j};
            	else if (v < mn[i][1].v)
                	mn[i][2] = mn[i][1], mn[i][1] = {v, j};
            	else if (v < mn[i][2].v)
                	mn[i][2] = {v, j};
        }
    }
    int ans = 1e9;
    for (int i=1;i<=N;i++){
        for (int j=M-E;j<M;j++){
            int v = get_min(j, i);
            if (v == 1e9)
				continue;
            ans = min(ans, v + C[i][M]-C[i][j]);
        }
    }
    printf("%d\n", ans);
}
