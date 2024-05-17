#include <stdio.h>
#include <stdlib.h>
int n,w_size=1;
int *v,*w;
int idx_lb(int value){
    int idx=w_size;
    int left=0,right=w_size-1;
    while(left<=right){
        int pivot=(left+right)/2;
        if(w[pivot]>=value){
            if(idx>pivot)
                idx=pivot;
            right=pivot-1;
        }
        else
            left=pivot+1;
    }
    if(idx==w_size)
        return -1;
    else
        return idx;
}
int main(){
    scanf("%d",&n);
    v=(int*)malloc(sizeof(int)*n);
    w=(int*)malloc(sizeof(int)*n);
    for(int i=0;i<n;i++)
        scanf("%d",&v[i]);
    w[0]=v[0];
    for(int i=1;i<n;i++){
        if(v[i]>w[w_size-1])
            w[w_size++]=v[i];
        else{
            int tmp=idx_lb(v[i]);
            if(tmp==-1)
                continue;
            else
                w[tmp]=v[i];
        }
    }
    printf("%d",w_size);
}
