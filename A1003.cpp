#include <cstdio>
#include <algorithm>
#include <cstring> 
using namespace std;
const int maxv = 510;
const int INF  =  1000000000;

//顶点数， 边数， 起点， 终点， 邻接矩阵， 点权 
int n, m, st, ed, G[maxv][maxv], weight[maxv];
//最短距离，最大点权， 最短路径条数 
int d[maxv], w[maxv], num[maxv];
bool visit[maxv] = {false};

void Dijkstra(int s){
	fill(d, d + maxv, INF);
	memset(num, 0, sizeof(num));
	memset(w, 0, sizeof(w));
	d[s] = 0;
	w[s] = weight[s];
	num[s] = 1;
	for(int i = 0; i < n; i++){//循环n次 
		int u = -1, MIN = INF;//使d[u]最小，MIN存放最小的d[u] 
		for(int j = 0; j < n; j++){//找到未访问顶点中d[]最小的 
			if(visit[j] == false && d[j] < MIN){
				u = j;
				MIN = d[j];
			}
		}
		if(u == -1) return; //说明剩下顶点与起点不连通 
		visit[u] = true;
		for(int v = 0; v < n; v++){
			if(visit[v] == false && G[u][v] != INF){
				if(d[u] + G[u][v] < d[v]){//以u为中介时能令d[v]变小
					d[v] = d[u] + G[u][v];
					w[v] = w[u] + weight[v];
					num[v] = num[u]; 
				} else if(d[u] + G[u][v] == d[v]){
					if(w[u] + weight[v] > w[v]){
						w[v] = w[u] + weight[v];
					}
					num[v] += num[u];
				}
			}
		} 
	}
}

int main(){
	scanf("%d %d %d %d",&n, &m, &st, &ed);
	for(int i = 0; i < n; i++){
		scanf("%d", &weight[i]);
	}
	int u,v;
	fill(G[0], G[0] + maxv*maxv, INF);//初始化图G 
	for(int i = 0; i < m; i++){
		scanf("%d%d", &u, &v);
		scanf("%d", &G[u][v]);
		G[v][u] = G[u][v];
	}
	Dijkstra(st);
	printf("%d %d\n", num[ed], w[ed]);
	return 0;
}
	
	
	
	
	

