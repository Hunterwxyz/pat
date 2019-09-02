#include <cstdio>
#include <iostream>
#include <cstring>
#include <string>
#include <algorithm>
#include <vector>
#include <map> 
using namespace std;
const int maxv = 210;
const int inf  = 1<<30;

int n, k, st,G[maxv][maxv], d[maxv],weight[maxv];
int maxW = 0, numPath = 0;
double maxAvg = 0;
vector<int> pre[maxv]; 
map<string, int> cityToint;
map<int, string> intTocity;
vector<int> path, tempPath;
bool visit[maxv] = {false};


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

void dfs(int v){
	tempPath.push_back(v);
	if(v == st){
		numPath++;
		int tempW = 0;
		for(int i = tempPath.size() - 2; i >= 0; i--){
			int id = tempPath[i];
			tempW += weight[id];
		}
		double tempAvg = 1.0 * tempW /(tempPath.size() - 1); 
		if(tempW > maxW){
			maxW = tempW;
			maxAvg = tempAvg;
			path = tempPath;
		} else if(tempW == maxW && tempAvg > maxAvg){
			maxAvg = tempW;
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

int main(){
	string start, city1, city2;
	cin >> n >> k >> start;
	cityToint[start] = 0;
	intTocity[0] = start;
	for(int i = 1; i <= n-1; i++){
		cin >> city1 >> weight[i];
		cityToint[city1] = i;
		intTocity[i] = city1;
	}
	fill(G[0], G[0] + maxv * maxv, inf);
	for(int i = 0; i < k; i++){
		int dis;
		cin >> city1 >> city2 ;
		int a = cityToint[city1], b = cityToint[city2];
		cin >> dis;
		G[a][b] = G[b][a] = dis;
	}
	pre[0].push_back(0);
	dijkstra(0);
	dfs(cityToint["ROM"]);
	printf("%d %d %d %d\n", numPath, d[cityToint["ROM"]], maxW, (int)maxAvg);
	for(int i = path.size() - 1; i >= 0; i--){
		cout << intTocity[path[i]];
		if(i > 0) cout << "->"; 
	}
	return 0;
}








