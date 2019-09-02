#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
const int M = 26*26*26*10 + 1;

vector<int> selectCourse[M];//存放每个学生选择的课程编号 

int getId(char s[]){
	int id = 0;
	for(int i = 0; i < 3; i++){
		id = id * 26 +(s[i] - 'A');
	}
	
	id  =  id * 10 + s[3] - '0';
	return id;
}

int main(){
	int n, k, id;
	char name[5];
	scanf("%d %d", &n, &k);
	for(int i = 0; i < k; i++){
		int idx, person;//idx 课程下标 person选课人数 
		scanf("%d %d", &idx, &person);
		for(int j = 0; j < person; j++){
			scanf("%s", name);
			id = getId(name);
			selectCourse[id].push_back(idx); 
		}
	}
	for(int i = 0; i < n; i++){
		scanf("%s", name);
		id = getId(name);
		sort(selectCourse[id].begin(),selectCourse[id].end());
		printf("%s %d",name, selectCourse[id].size());
		for(int j = 0; j < selectCourse[id].size(); j++){
			printf(" %d", selectCourse[id][j]);
			//if(j == selectCourse[id].size() - 1 ) printf("\n");
		}
		printf("\n");
		//if(selectCourse[id].size() == 0)
		//printf("%s 0", name);
	}
	return 0;
	
}





















