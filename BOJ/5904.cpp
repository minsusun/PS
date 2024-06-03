#include <iostream>
using namespace std;
long long int n;
long long int moo_arr[100]={3,};
long long int find_moo(int k)
{
  if(moo_arr[k]!=0)
      return moo_arr[k];
  else
  {
    moo_arr[k]=2*find_moo(k-1)+k+3;
    return moo_arr[k];
  }
}
int find_k(int a)
{
  int cnt=0;
  while(find_moo(++cnt)<a);
  return cnt;
}
char find_char(long long int target,int status)
{
  if(target==1||target==moo_arr[status-1]+1||target==moo_arr[status-1]+status+4)
      return 'm';
  else if(status==0)
      return 'o';
  else if(target<=moo_arr[status-1])
    return find_char(target,status-1);
  else if(target<=moo_arr[status-1]+status+3)
    return 'o';
  else
    return find_char(target-moo_arr[status-1]-status-3,status-1);
}
int main()
{
  cin >> n;
  cout << find_char(n,find_k(n));
}
