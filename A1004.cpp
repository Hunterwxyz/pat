#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
using namespace std;
int n,m;
vector<int> v[110];//存放树 
int numOfLeaf [110] = {0};
int maxdepth = 1;//表示树的深度 输出时作为树的层次数 
void dfs(int index, int depth){
	maxdepth = max(maxdepth, depth);
	if(v[index].size() == 0){
		numOfLeaf[depth]++; //该层叶子结点个数++ 
		return;
	}
	for(int i = 0; i < v[index].size(); i++){
		dfs(v[index][i], depth + 1);
	}
}

int main(){
	int father,k,child;
	scanf("%d %d", &n, &m);
	//if(n == 0) return;
	for(int i = 0; i < m; i++){
		scanf("%d %d",&father, &k);
		for(int j = 0; j < k; j++){
			scanf("%d", &child);
			v[father].push_back(child);
		}
	}
	dfs(1, 1); //入口结点为1 深度为1
	printf("%d", numOfLeaf[1]);
	for(int i = 2; i <= maxdepth; i++){
		printf(" %d", numOfLeaf[i]);
	}
	return 0;
}
