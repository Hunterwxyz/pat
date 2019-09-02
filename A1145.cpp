#include <cstdio>
#include <cmath>
#include <vector>
using namespace std;

bool isPrime(int x){
	for(int i = 2; i * i <= x; i++){
		if(x % i == 0) return false;
	}
	return true;
}
int main(){
	int msize, n, m, a;
	scanf("%d %d %d", &msize, &n, &m);
	while(isPrime(msize) == false) msize++;
	vector<int> v(msize);
	for(int i = 0; i < n; i++){
		scanf("%d", &a);
		int flag = 0;//是否成功插入 
		for(int j = 0; j < msize; j++){
			int pos = (a + j * j)%msize;
			if(v[pos] == 0) {
				v[pos] = a;
				flag = 1;
				break;
			} 
		}
		if(!flag) printf("%d cannot be inserted.\n",a);
	}
	int ans = 0;
	for(int i = 0; i < m; i++){
		scanf("%d", &a);
		for(int j = 0; j <= msize; j++){
			ans++;
			int pos = (a + j * j) % msize;
			if(v[pos] == a || v[pos] == 0) break;
		}
	}
	printf("%.1lf\n", ans * 1.0 / m);
	return 0;
}







