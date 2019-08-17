#include<cstdio>
#include<vector>
using namespace std;
const int maxn = 110;
vector<int> Node[maxn];// ���ľ�̬д����Node[i]��Ž��i�ĺ��ӽ���� 
int hashTable[maxn] = {0};//�����ϣӳ�� ��¼ÿ������� 
void DFS(int index, int level){
	hashTable[level]++;// ��level��ڵ���+1
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
