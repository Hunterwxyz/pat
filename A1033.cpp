#include <cstdio>
#include <algorithm>
#include <cmath>
using namespace std;
const int maxn = 510;
const int INF = 1000000000;

struct station{
	double price;
	double distance;
}st[maxn];

bool cmp(station a, station b){
	return a.distance < b.distance;
}

int main(){
	double cmax, D, Davg;
	int n;
	scanf("%lf %lf %lf %d", &cmax, &D, &Davg, &n);
	for(int i = 0; i < n; i++){
		scanf("%lf %lf", &st[i].price, &st[i].distance);
	}
	st[n].price = 0;
	st[n].distance = D;
	sort(st, st+n ,cmp);
	if(st[0].distance != 0){
		printf("The maximum travel distance = 0.00\n");
	} else {
		int now = 0;
		//总花费， 当前油量， 最大行驶距离 
		double ans = 0, nowTank = 0, Max = cmax * Davg;
		while(now < n){
			int k = -1; //最低油价加油站编号
			double priceMin = INF; //最低油价 
			for(int i = now + 1; i <= n && st[i].distance - st[now].distance <= Max; i++){
				if(st[i].price < priceMin){
					priceMin = st[i].price;
					k = i;
					if(priceMin < st[now].price){
						break;
					}
				}
			}
			if(k == -1) break;
			double need  = (st[k].distance - st[now].distance) / Davg;
			if(priceMin < st[now].price){
				if(nowTank < need){
					ans += (need - nowTank) * st[now].price;
					nowTank = 0;
				} else {
					nowTank -= need;
				}
			} else {
				ans += (cmax - nowTank) * st[now].price;
				nowTank = cmax - need;
			}
			now = k;
		}
		if(now == n){
			printf("%.2f\n", ans);
		} else {
			printf("The maximum travel distance = %.2f\n",st[now].distance + Max);
		}
	}
	return 0;
	
}
