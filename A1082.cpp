#include <cstdio>
#include <cstring>
char num[10][5] = {"ling", "yi", "er","san","si", "wu","liu", "qi","ba", "jiu"};
char wei[5][5] = {"Shi","Bai","Qian","Wan","Yi"};
int main(){
	char str[15];
	scanf("%s", &str);
	int len = strlen(str);
	int left = 0, right = len - 1;
	if(str[0] == '-') {
		printf("fu");
		left++;
	}
	while(left + 4 <= right){
		right -= 4; //将right每次左移4位，直到left与right在同一节 
	}
	while(left < len){
		bool flag = false; // flag为false表示没有累积的0
		bool isPrint = false;
		while(left <= right){
			if(left > 0 && str[left] == '0'){
				
			}
		} 
		
	}
} 
