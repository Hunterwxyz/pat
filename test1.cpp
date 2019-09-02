#include <cstdio>
#include <algorithm>
#include <vector>
#include <cstring>
const int maxv = 510;
const int INF = 1000000000;
vector<int> pre[maxv];
int n, m, G[maxv][maxv], weight[maxv], st, ed;
int d[maxv], w[maxv];//d[u]代表起点到u的最短距离 
bool vis[maxv] = {false};
void Dijkstra(int s){
	fill(d, d+maxn, INF);
	d[s] = 0;
	for(int i = 0; i < n; i++){
		int u = -1, MIN = INF;
		for(int j = 0; j < n; j++){
			if(vis[j] == false && d[j] < MIN){
				u = j; 
				MIN = d[j];
			}
		}
		if(u == -1) return;
		vis[u] = true;
		for(int v = 0; v < n; v++){
			if(vis[v] == false && G[u][v] != INF){
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








