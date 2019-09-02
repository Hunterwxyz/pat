#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
struct record{
	char id[20];
	int h, m, s;
}temp, ans1, ans2;
bool cmp(record a, record b){//a的时间比b大返回true 
	if(a.h != b.h) return a.h > b.h;
	if(a.m != b.m) return a.m > b.m;
	return a.s > b.s;
}
int main(){
	int n;
	scanf("%d", &n);
	ans1.h = 24, ans1.m = 60, ans1.s = 60;//初始签到设成最大
	ans2.h = 0, ans2.m = 0, ans2.s = 0;//初始签退设为最小
	for(int  i = 0; i < n; ++i){
		scanf("%s %d:%d:%d",temp.id, &temp.h, &temp.m, &temp.s);
		if(cmp(temp, ans1) == false) ans1 = temp;
		//temp再作为签离时间读入
		scanf("%d:%d:%d", &temp.h, &temp.m, &temp.s);
		if(cmp(temp, ans2) == true) ans2 = temp; 
		
	} 
	printf("%s %s\n", ans1.id, ans2.id);
	return 0; 
}
