#include <stdio.h>
#include <queue>
 
using namespace std;
 
int abss(int n){
    if(n>0)
        return n;
    else
        return -n;
}
 
struct Custom{
    int val;
    int abs;
    Custom(int value) : val(value), abs(abss(value)) {}
};
 
 
 
// 오름차순 정렬
struct cmp{
    bool operator()(Custom t, Custom u){
        if(t.abs > u.abs)
        {
            return true;
        }
        else if (t.abs < u.abs)
        {
            return false;
        }
        else
        {
            if(t.val > u.val)
            {
                return true;
            }
            else
            {
                return false;
            }
        }
    }
};
 
 
int main()
{
    priority_queue< Custom, vector<Custom>,  cmp > pq;
    int nownode=0;
    int m;
    scanf("%d",&m);
    for (int i=0; i<m; i++)
    {
        int mode;
        scanf("%d",&mode);
        if(mode==0)
        {
            //삭제
            if(!pq.empty()) {
 
                printf("%d\n",pq.top().val);
                pq.pop();
            }
            else
                printf("0\n");
 
        }
        else
        {
            //추가
            pq.push(Custom(mode));
 
 
 
        }
    }
 
}
