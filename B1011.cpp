#include<cstdio>
int main(){
	int k,cur=1;//����,��ǰ���� 
	scanf("%d", &k);
	while(k--){
		long long  A,B,C;
		scanf("%lld %lld %lld",&A, &B, &C);
		if(A+B>C){
			printf("Case #%d: true\n",cur++);
		}
		else{
			printf("Case #%d: false\n",cur++);
		}
	}
	return 0; 
} 
