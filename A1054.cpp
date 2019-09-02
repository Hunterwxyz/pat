#include <cstdio>
#include <iostream>
#include <string>
#include <map>
using namespace std;
int main(){
	int m, n, col;
	scanf("%d %d", &m, &n);
	map<int, int> count;
	for(int i = 0; i < n; i++){
		for(int j = 0 ;j < m; j++){
			scanf("%d", &col);
			if(count.find(col) != count.end()) count[col]++;
			else count[col] = 1;
		}
	}
	int k = 0, max = 0;
	for(auto it  = count.begin(); it != count.end(); it++){
		if(it->second > max){
			k = it->first;
			max = it->second;
		}
	}
	printf("%d\n", k);
	return 0;
}
