#include <cstdio>
#include <algorithm>
using namespace std;

int main(){
	int n,floor,start = 0, up = 0, down = 0;
	scanf("%d", &n);
	for(int i = 0; i < n; i++){
		scanf("%d",&floor);
		if(floor > start) {
			up += floor - start;
			start = floor;
		}
		if(floor < start){
			down += start - floor ;
			start = floor;
		} 
	}
	int ans = up * 6 + down * 4 + n * 5;
	printf("%d\n", ans);	
	return 0;
}
