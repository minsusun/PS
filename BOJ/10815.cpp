#include <stdio.h>
#include <algorithm>
using namespace std;
int n,m;
int n_arr[500000], m_arr[500000];
bool find(int a)
{
	if(m_arr[a]>n_arr[n-1])
		return false;
	else if(m_arr[a]==n_arr[n-1]||m_arr[m]==n_arr[0])
		return true;
	bool flag=false;
	int left=0,right=n-1,mid=(left+right)/2;
	while(flag==false)
	{
		if(n_arr[mid]==m_arr[a])
			return true;
		else if(n_arr[mid]>m_arr[a])
			right=mid-1;
		else
			left=mid+1;
		if((left+right)/2==mid)
			return false;
		mid=(left+right)/2;
	}
}
int main()
{
	scanf("%d",&n);
	for(int i=0;i<n;i++)
		scanf("%d",&n_arr[i]);
	scanf("%d",&m);
	for(int i=0;i<m;i++)
		scanf("%d",&m_arr[i]);
	sort(n_arr,n_arr+n);
	for(int i=0;i<m;i++)
		printf("%d ",find(i));
}
