#include <stdio.h>
#include <math.h>
int ax,ay,bx,by,cx,cy,dx,dy;
double find(double st,double et){
    if((float)st==(float)et)
        return pow((ax+st*(bx-ax))-(cx+st*(dx-cx)),2)+pow((ay+st*(by-ay))-(cy+st*(dy-cy)),2);
    double t1=st+(et-st)/3, t2=t1*2-st,d1=pow((ax+t1*(bx-ax))-(cx+t1*(dx-cx)),2)+pow((ay+t1*(by-ay))-(cy+t1*(dy-cy)),2),d2=pow((ax+t2*(bx-ax))-(cx+t2*(dx-cx)),2)+pow((ay+t2*(by-ay))-(cy+t2*(dy-cy)),2);
    if(d1>d2) return find(t1,et);
    else return find(st,t2);
}
int main(){
    scanf("%d%d%d%d%d%d%d%d",&ax,&ay,&bx,&by,&cx,&cy,&dx,&dy);
    printf("%lf",pow(find(0,1),0.5));
}
