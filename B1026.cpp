#include<cstdio>
int main(){
	int c1,c2,ans;
	scanf("%d %d",&c1, &c2);
	ans = c2 - c1;
	if(ans % 100 >= 50){
		ans = ans / 100 +1;
	} else {
		ans = ans / 100;
	}
	printf("%02d:%02d:%02d", ans/3600, ans%3600/60,ans%60);
	
	return 0;
}
