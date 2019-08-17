#include<cstdio>
#include<vector>
using namespace std;
const int maxn = 110;
vector<int> Node[maxn];// 树的静态写法，Node[i]存放结点i的孩子结点编号 
int hashTable[maxn] = {0};//数组哈希映射 记录每层结点个数 
void DFS(int index, int level){
	hashTable[level]++;// 第level层节点数+1
	for(int i = 0; i < Node[index].size(); i++){
		DFS(Node[index][i], level + 1);
	} 
} 
int main(){
	int n, m, father, k, child;
	scanf("%d%d", &n, &m);
	for(int i = 0; i < m; i++){
		scanf("%d%d", &father, &k);
		for(int j = 0; j < k; j++){
			scanf("%d", &child);
			Node[father].push_back(child);
		}
	
	}
	DFS(1, 1);
	int maxLevel = -1, maxValue = 0;
	for(int i = 1; i < maxn; i++){
		if(hashTable[i] > maxValue){
			maxValue = hashTable[i];
			maxLevel = i;
		}
	}
	printf("%d %d\n", maxValue, maxLevel);
	return 0;
	
}
