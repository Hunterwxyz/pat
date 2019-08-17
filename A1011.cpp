#include<cstdio>
char s[3]={'W','T','L'};
int main(){
	double a, temp, ans = 1;
	
	int idx;
	for(int i = 0; i < 3; i++){
		temp = 0.0;
		for(int j = 0; j < 3; j++){ //寻找该行最大的数字存在tmp 
			scanf("%lf", &a);
			if(a > temp){
			temp = a;
			idx = j;
			}
		}
		ans *= temp;
		printf("%c ", s[idx]);
	}
	printf("%.2f", (ans * 0.65 - 1) * 2);
	return 0;
}
