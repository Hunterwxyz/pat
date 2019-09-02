#include <cstdio>
#include <algorithm>
#include <set>
using namespace std;

const int maxs = 10010;
const int maxq = 2010;
set<int> st[55];

int main(){
	int n, m, k,a,b;
	scanf("%d", &n);
	for(int  i = 1; i <= n; i++){
		scanf("%d", &m);
		for(int j = 0; j < m; j++){
			int temp;
			scanf("%d", &temp);
			st[i].insert(temp);
		}
	}
	scanf("%d", &k);
	for(int i = 0; i < k; i++){
		scanf("%d %d",&a, &b);
		int nc = 0, nt = st[b].size();
		for(auto it = st[a].begin(); it != st[a].end(); it++){
			if(st[b].find(*it) != st[b].end()) 
				nc++;
			else nt++;
		}
		double ans = nc * 100 / nt ;
		printf("%.1f%%\n",ans);
	}
	return 0;
} 

