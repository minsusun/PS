#include <stdio.h>
int s[300001],n,l,x,y,c[300001];int F(int a){return s[a]==a?a:s[a]=F(s[a]);}int U(int a,int b){if(!c[F(a)]) c[F(a)]=1,s[F(a)]=F(b);else if(!c[F(b)]) c[F(b)]=1,s[F(b)]=F(a);else return 0;return 1; }int main(){scanf("%d%d",&n,&l);while(l--) s[l]=l;while(n--){scanf("%d%d",&x,&y);printf("%s\n",(U(x,y))?"LADICA":"SMECE");}}
