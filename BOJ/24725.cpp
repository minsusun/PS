#include <stdio.h>
char MBTI[4][2]={{'E','I'},{'N','S'},{'T','F'},{'J','P'}};
char map[204][204];
int dir_arr[8][2]={{1,1},{1,0},{1,-1},{0,1},{0,-1},{-1,1},{-1,0},{-1,-1}};
int cnt,n,m,dir;
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=0;i<n;i++)
		scanf("%s",map[i]);
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			if(map[i][j]==MBTI[0][0]||map[i][j]==MBTI[0][1])
			{
				for(int k=0;k<8;k++)
				{
					int l;
					if(i+3*dir_arr[k][0]<0||i+3*dir_arr[k][0]>=n||j+3*dir_arr[k][1]<0||j+3*dir_arr[k][1]>=m)
						continue;
					for(l=1;l<4;l++)
					{
						if(map[i+l*dir_arr[k][0]][j+l*dir_arr[k][1]]==MBTI[l][0]||map[i+l*dir_arr[k][0]][j+l*dir_arr[k][1]]==MBTI[l][1])
							continue;
						else
							break;
					}
					if(l==4)
						cnt++;
				}
			}
		}
	}
	printf("%d",cnt);
}
