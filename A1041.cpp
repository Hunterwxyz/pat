#include <cstdio>
int main(){
	int n,a,Hash[10011] = {0}; 
	scanf("%d", &n);
	int origin[100011] = {0};
	for(int i = 1; i <= n; i++){
		scanf("%d", &a);
		origin[i] = a;
		Hash[a]++;
	}
	int i;
	for( i = 1; i <= n; i++){
		if(Hash[origin[i]] == 1){
			printf("%d", origin[i]);
			break;
		}
	}
	if(i > n) printf("None\n"); 
	return 0;
}
