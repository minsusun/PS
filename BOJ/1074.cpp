#include <iostream>
#include <math.h>
using namespace std;
int n,r,c;
int cnt;
bool src(int x,int y,int size)
{
  if(x==r&&y==c)
      return true;
  if(x<=r&&r<=x+size-1&&y<=c&&c<=y+size-1)
  {
    if(src(x,y,size/2)||src(x,y+size/2,size/2)||src(x+size/2,y,size/2)||src(x+size/2,y+size/2,size/2))
      return true;
  }
  else
    cnt+=size*size;
  return false;
}
int main()
{
  cin >> n >> r >> c;
  src(0,0,pow(2,n));
  cout << cnt;
}
