#include <iostream>
using namespace std;
int n,m,left=1,right=-1;
int main(){
    scanf("%d%d",&n,&m);
    int *v=(int*)malloc(sizeof(int)*n);
    for(int i=0;i<n;i++){
        scanf("%d",&v[i]);
        if(v[i]>right)
            right=v[i];
    }
    while(left<=right){
        int pivot=(left+right)/2;
        long long int sum=0;
        for(int i=0;i<n;i++)
            sum+=max(v[i]-pivot,0);
        if(sum>=m)
            left=pivot+1;
        else
            right=pivot-1;
    }
    printf("%d",right);
}
