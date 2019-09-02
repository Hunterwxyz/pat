#include <cstdio>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;
const int N = 40010;
const int M = 2510;

char name[M][5];
vector<int> selectCourse[M]; // 每门课程的选课学生编号 

bool cmp(int a, int b){
	return strcmp(name[a], name[b]) < 0;
}

int main(){
	int n, k, c,idx;// n：学生数  k:课程数   c：选课数  index of course			   
	scanf("%d %d", &n, &k);
	for(int i = 0; i < n; i++){
		scanf("%s %d", name[i], &c);
		for(int j = 0; j < c; j++){
			scanf("%d", &idx);
			selectCourse[idx].push_back(i); //将学生i加入第idx门课中 
		}
	}
	
	for(int i = 1; i <= k; i++){
		printf("%d %d\n", i, selectCourse[i].size());
		sort(selectCourse[i].begin(), selectCourse[i].end(), cmp);
		for(int j = 0; j < selectCourse[i].size(); j++){
			printf("%s\n", name[selectCourse[i][j]]);
		}
	}
	return 0;
} 





















