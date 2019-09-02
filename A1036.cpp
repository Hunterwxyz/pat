#include <cstdio>
#include <algorithm>

struct stu{
	char name[15];
	char gender;
	char id[15];
	int grade;
}H,L,temp;
int main(){
	H.grade = -1;
	L.grade = 101;
	int n;
	scanf("%d", &n);
	int m = 0,f = 0;
	char gend;
	for(int i = 0; i < n; i++){
		scanf("%s %c %s %d", temp.name, &gend, temp.id, &temp.grade);	
		temp.gender = gend;
		if(gend == 'M') {
			++m;
			if(temp.grade < L.grade) L = temp;	
		}
		else if(gend == 'F'){
			++f;
			if(temp.grade > H.grade) H = temp;
		}
		
	}
	int ans = H.grade - L.grade;
	if(f == 0) printf("Absent\n");
	else printf("%s %s\n", H.name, H.id);
	if(m == 0) printf("Absent\n");
	else printf("%s %s\n", L.name, L.id);
	
	if(f == 0 || m == 0) printf("NA");
	else printf("%d", ans);
	return 0;
}
