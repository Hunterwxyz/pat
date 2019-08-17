#include <iostream>
#include <stack>
#include <vector>
using namespace std;
int main(){
	int m,n,k;
	scanf("%d%d%d",&m, &n, &k);
	for(int i = 0; i < k; i++){
		stack<int> st;
		vector<int> v(n+1); // ´æ·Å³öÕ»ÐòÁÐ 
		bool flag = false; 
		for(int i = 1; i <= n; i++){
			scanf("%d", &v[i]);
		}
		int current = 1;
		for(int i = 1; i <= n; i++){
			st.push(i);
			if(st.size() > m) break;
			while(!st.empty() && st.top() == v[current]){
				st.pop();
				current++;
			}	
		}
		if(current == n+1) flag = true;
		if(flag) printf("YES\n");
		else printf("NO\n"); 
	}
	return 0;
}

