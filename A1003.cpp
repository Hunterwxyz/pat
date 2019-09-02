#include <cstdio>
#include <algorithm>
#include <cstring> 
using namespace std;
const int maxv = 510;
const int INF  =  1000000000;

//�������� ������ ��㣬 �յ㣬 �ڽӾ��� ��Ȩ 
int n, m, st, ed, G[maxv][maxv], weight[maxv];
//��̾��룬����Ȩ�� ���·������ 
int d[maxv], w[maxv], num[maxv];
bool visit[maxv] = {false};

void Dijkstra(int s){
	fill(d, d + maxv, INF);
	memset(num, 0, sizeof(num));
	memset(w, 0, sizeof(w));
	d[s] = 0;
	w[s] = weight[s];
	num[s] = 1;
	for(int i = 0; i < n; i++){//ѭ��n�� 
		int u = -1, MIN = INF;//ʹd[u]��С��MIN�����С��d[u] 
		for(int j = 0; j < n; j++){//�ҵ�δ���ʶ�����d[]��С�� 
			if(visit[j] == false && d[j] < MIN){
				u = j;
				MIN = d[j];
			}
		}
		if(u == -1) return; //˵��ʣ�¶�������㲻��ͨ 
		visit[u] = true;
		for(int v = 0; v < n; v++){
			if(visit[v] == false && G[u][v] != INF){
				if(d[u] + G[u][v] < d[v]){//��uΪ�н�ʱ����d[v]��С
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
	fill(G[0], G[0] + maxv*maxv, INF);//��ʼ��ͼG 
	for(int i = 0; i < m; i++){
		scanf("%d%d", &u, &v);
		scanf("%d", &G[u][v]);
		G[v][u] = G[u][v];
	}
	Dijkstra(st);
	printf("%d %d\n", num[ed], w[ed]);
	return 0;
}
	
	
	
	
	

