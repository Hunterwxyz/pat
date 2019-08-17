#include<cstdio>
const int N = 54;
char hs[5] = {'S', 'H', 'C', 'D', 'J'};
int start[N+1], end[N+1], next[N+1]; //next存放每个位置上的牌在操作后的位置
	 
int main(){
	int k;
	scanf("%d", &k);
	for(int i = 1; i <= N; i++){
		start[i] = i;//初始化牌的编号 
	}
	for(int i = 1; i <= N; i++){
		scanf("%d", &next[i]);//输入每个位置的牌在操作后的位置 
	} 
	for(int step = 1; step <= k; step++){
		for(int i = 1; i <= N; i++){
			end[next[i]] = start[i];//把原始第i个位置的牌号存放于位置next[i] 
		}
		for(int i = 1; i <= N; i++){
			start[i] = end[i];//留作下一次使用 
		} 
	}
	for(int i = 1; i <= N; i++){
		if(i != 1) printf(" ");
		start[i]--;
		printf("%c%d",hs[start[i]/13],start[i]%13+1 );
	} 
	
	return 0;
	
}
