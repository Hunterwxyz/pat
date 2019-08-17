#include<cstdio>
const int maxn = 2010;
int main(){
	int k, m, n, cnt = 0;
	double p[1001] ={0.0};
	double ans[maxn] = {0.0};
	double a;
	scanf("%d", &k);
	for(int i = 0; i < k; i++){
		scanf("%d %lf", &n, &a);
		p[n] = a;
	}
	scanf("%d", &m);
	for(int i = 0; i < m; i++){
		scanf("%d %lf", &n, &a);
		for(int j = 0; j < 1001; j++){
			ans[j + n] += a * p[j]; 
		}
	}
	for(int i = 0; i < maxn; i++){
		if(ans[i] != 0.0) cnt++;
	}
	printf("%d", cnt);
	for(int i = maxn-1; i >= 0; i--){
		if(ans[i] != 0.0){
			printf(" %d %.1f", i, ans[i]);
		}
	}
	return 0;
} 
