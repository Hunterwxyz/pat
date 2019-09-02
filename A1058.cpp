#include <cstdio>

using namespace std;
int main(){
	long long g[3], s[3], k[3];
	scanf("%lld.%lld.%lld %lld.%lld.%lld", &g[0], &s[0], &k[0],&g[1], &s[1], &k[1]);
	int carry = 0;//½øÎ» 
	k[2] = (k[0] + k[1]) % 29;
	carry =(k[0] + k[1]) / 29; 
	s[2] = (s[0] + s[1] + carry) % 17;
	carry = (s[0] + s[1] + carry) / 17;
	g[2] = (g[0] + g[1] + carry);
	printf("%lld.%lld.%lld", g[2], s[2], k[2]);
	return 0;
}
