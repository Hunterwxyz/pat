#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
int main(){
	int n, b, cnt = 0;
	vector<int> ans;
	scanf("%d %d", &n, &b);
	do{
		ans.push_back(n % b);
		cnt++;
		//ans[cnt++] = n % b;
		n /= b;
	}while(n != 0);
	
	int i;
	for(i = 0; i < ans.size() / 2; i++){
		if(ans[i] != ans[ans.size() -1- i]) break;
	}
	
	if(i == ans.size() / 2 ) printf("Yes\n");
	else printf("No\n");
	for(int k = ans.size() -1; k >= 0; k--){
		printf("%d", ans[k]);
		if(k > 0) printf(" ");
	}
	return 0;
}
