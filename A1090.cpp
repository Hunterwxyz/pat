#include<cstdio>
#include<cmath>
#include<vector>
using namespace std;
const int maxn = 100010;
vector<int> Node[maxn];
int num = 0, maxDepth = 0;
double ans, p, r;
void DFS(int index, int depth){
	if(Node[index].size() == 0){
		if(depth > maxDepth){
			maxDepth = depth;
			num = 1; 
		} else if(depth == maxDepth){
			num++;
		}
		return;
	}
	for(int  i = 0; i < Node[index].size(); i++){
		DFS(Node[index][i], depth + 1);
	}
}
int main(){
	int n,parent,root;
	scanf("%d%lf%lf", &n, &p, &r);
	r /= 100;
	for(int i = 0; i < n; i++){
		scanf("%d", &parent);
		if(parent != -1) Node[parent].push_back(i);
		else root = i;
	}
	DFS(root,0);
	ans = p * pow(1 + r, maxDepth);
	printf("%.2f %d", ans, num);
	return 0;
	
}


