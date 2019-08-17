#include <cstdio>
#include <algorithm>
using namespace std;

const int maxn = 1010;
int father[maxn]; // 存放父亲结点 
int isRoot[maxn] = {0}; // 记录每个结点是否作为某个集合的结点 
int course[maxn] = {0}; // course[h]记录任意一个喜欢活动h的人的编号 

int findFather(int x){
	int a = x;
	while(x != father[x]){
		x = father[x];
	}
	while(a != father[a]){
		int z = a;
		a = father[a];
		father[z] = x;
	}
	return x;
}
void Union(int a, int b){
	int faA = findFather(a);
	int faB = findFather(b);
	if(faA != faB){
		father[faA] = faB;
	}
}

void init(int n){ // 初始化father[i]为i，且flag[i]为false 
	for(int i = 1; i < n; i++){
		father[i] = i;
		isRoot[i] = false;
	}
}
bool cmp(int a, int b){
	return a > b;
}
int main(){
	int n, k, h;
	scanf("%d", &n);
	init(n);
	for(int i = 1; i <= n; i++){
		scanf("%d:", &k);
		for(int j = 0; j < k; j++){
			scanf("%d:", &h);
			if(course[h] == 0) {
				course[h] = i; //如果活动h第一次有人喜欢，令i喜欢活动h 
			}
			Union(i, findFather(course[h])); 
		}
	}
	for(int i = 1; i <= n; i++){
		isRoot[findFather(i)]++; //i的根节点是findFather(i), 人数加1 
	}
	int ans = 0; //记录集合数目
	for(int i = 1; i <= n; i++){
		if(isRoot[i] != 0) ans++;
	}
	printf("%d\n", ans);
	sort(isRoot + 1, isRoot + n + 1, cmp);
	for(int i = 1; i <= ans; i++){
		printf("%d", isRoot[i]);
		if(i < ans) printf(" "); 
	}
	return 0;
}

