#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;
const int maxv = 510;
const int inf = 1<<30; 
int n,m,st,ed,G[maxv][maxv], d[maxv], cost[maxv][maxv];
vector<int> pre[maxv];
bool visit[maxv];
vector<int> path, tempPath;
int minCost = inf;
void dfs(int v){
	tempPath.push_back(v);
	if(v == st){
		int tempCost = 0;
		for(int i = tempPath.size() - 1; i > 0; i--){
			int id = tempPath[i], idnext = tempPath[i - 1];
			tempCost += cost[id][idnext];
		}
		if(tempCost < minCost){
			minCost = tempCost;
			path = tempPath;
		}
		tempPath.pop_back();
		return;
	}
	for(int i = 0; i < pre[v].size(); i++){
		dfs(pre[v][i]);
	}
	tempPath.pop_back();
}
void dijkstra(int s){
	fill(d, d + maxv, inf);
	d[s] = 0;
	for(int i = 0; i < n; i++){
		int u = -1, MIN = inf;
		for(int j = 0; j < n; j++){
			if(visit[j] == false && d[j] < MIN){
				u = j;
				MIN = d[j];
			}
		}
		if(u == -1) return;
		visit[u] = true;
		for(int v = 0; v < n; v++){
			if(visit[v] == false && G[u][v] != inf){
				if(d[u] + G[u][v] < d[v]){
					d[v] = d[u] + G[u][v];
					pre[v].clear();
					pre[v].push_back(u); 
				} else if(d[u] + G[u][v] == d[v]){
					pre[v].push_back(u);
				}
			}
		}
	}
}

int main(){
	fill(G[0], G[0] + maxv * maxv, inf);
	scanf("%d%d%d%d", &n, &m, &st, &ed);
	for(int i = 0; i < m; i++){
		int u,v;
		scanf("%d%d", &u, &v);
		scanf("%d%d", &G[u][v], &cost[u][v]);
		G[v][u] = G[u][v];
		cost[v][u] = cost[u][v];
	}
	pre[st].push_back(st);
	dijkstra(st);
	dfs(ed);
	for(int i = path.size() - 1; i >= 0; i--){
		printf("%d ",path[i]);
	}
	printf("%d %d\n", d[ed], minCost);
	return 0;
}










