#include<cstdio>
const int maxn = 1010;
int main(){
	double p[maxn] = {};
	int k,n,cnt = 0;
	double a;
	scanf("%d", &k);
	for(int i = 0; i < k; i++){
		scanf("%d %lf",&n, &a);
		p[n] += a;
	}
	 
	scanf("%d", &k);
	for(int i = 0; i < k; i++){
		scanf("%d %lf",&n, &a);
		p[n] += a;
	}
	for(int i = 0; i < maxn; i++){
		if(p[i] != 0){
			cnt++;     
		}   
	}
	printf("%d",cnt);
	for(int i = maxn-1; i >= 0; i--){
		if(p[i] != 0){
			printf(" %d %.1lf", i, p[i]);
			
		}              
	}
	return 0;
}
