#include <cstdio>
#include <algorithm>

int main(){
	int a , b, sum, cnt = 0, num[10];
	scanf("%d %d" , &a, &b);
	sum = a + b;
	if(sum < 0){
		printf("-");
		sum = -sum;
	} 
	do{
		num[cnt++] = sum % 10;
		sum /= 10;
	}while(sum != 0);
	for(int i = cnt - 1; i >= 0; i--){
		printf("%d", num[i]);
		if(i > 0 && i % 3 == 0) printf(",");
		
	}
	return 0;
}
