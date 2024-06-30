#include <stdio.h>
#include <vector>
using namespace std;

int max_depth=22;
vector<int> x;
vector<int> y;

bool contain(int ix,int iy){
	int length=x.size();
	for(int i=length-6;i>=0;i--)
		if(x[i]==ix&&y[i]==iy)
			return true;
	return false;
}

int find_path(int depth,int current_x,int current_y,int direction){
	if(contain(current_x,current_y)){
		if(depth==max_depth) return 1;
		else return 0;
	}
	if(depth==max_depth) return 0;
	x.push_back(current_x); y.push_back(current_y);
	int sum=0;
	if((current_x+current_y)%2==0&&direction!=2)
		sum+=find_path(depth+1,current_x,current_y+1,1);
	if((current_x+current_y)%2!=0&&direction!=1)
		sum+=find_path(depth+1,current_x,current_y-1,2);
	if(direction!=4)
		sum+=find_path(depth+1,current_x+1,current_y,3);
	if(direction!=3)
		sum+=find_path(depth+1,current_x-1,current_y,4);
	x.pop_back(); y.pop_back();
	return sum;
}

int main(void){
	scanf("%d",&max_depth);
	x.push_back(0); y.push_back(0);
	printf("%d",find_path(0,0,1,1));
}
