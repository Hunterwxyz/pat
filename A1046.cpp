#include<cstdio>
#include<algorithm>
using namespace std;

const int maxn = 100010;
int dis[maxn],A[maxn];//A[i]存放i号与i+1号顶点的距离 
int main(){
	int sum = 0,query,n,left,right;
	scanf("%d", &n);
	for(int i = 1; i<=n; i++){
		scanf("%d",&A[i]);
		sum += A[i];
		dis[i] = sum;//预处理dis组 
	}
	scanf("%d",&query);
	for(int i = 0; i < query; i++){
		scanf("%d%d",&left,&right);
		if(left > right) swap(left, right);
		int temp = dis[right - 1]-dis[left - 1];
		printf("%d\n",min(temp ,sum - temp)); 
	}
	
	return 0;
}

