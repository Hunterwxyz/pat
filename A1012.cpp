#include <cstdio>
#include <algorithm>
#include <cmath>
#include <iostream>
using namespace std;

int Rank[1000000][4] = {0};
struct node{
	int id;
	int a, c, m, e;
}stu[2010];

char course[4] = {'A', 'C', 'M','E'};
bool cmp1(node a, node b){
	return a.a > b.a;
}
bool cmp2(node a, node b){
	return a.c > b.c;
}
bool cmp3(node a, node b){
	return a.m > b.m;
}
bool cmp4(node a, node b){
	return a.e > b.e;
}
int main(){
	int n, m;
	scanf("%d %d", &n, &m);
	for(int i = 0; i < n; i++){
		scanf("%d %d %d %d", &stu[i].id, &stu[i].c, &stu[i].m, &stu[i].e);
		stu[i].a = round((stu[i].c + stu[i].m + stu[i].e) / 3.0) + 0.5;
	}
	sort(stu, stu+n, cmp1);
	Rank[stu[0].id][0] = 1;
	for(int i = 1; i < n; i++){
		if(stu[i].a == stu[i - 1].a){
			Rank[stu[i].id][0] = Rank[stu[i-1].id][0];
		} else {
			Rank[stu[i].id][0] = i + 1;
		}
	}
	
	sort(stu, stu+n, cmp2);
	Rank[stu[0].id][1] = 1;
	for(int i = 1; i < n; i++){
		if(stu[i].c == stu[i - 1].c){
			Rank[stu[i].id][1] = Rank[stu[i-1].id][1];
		} else {
			Rank[stu[i].id][1] = i + 1;
		}
	}
	
	sort(stu, stu+n, cmp3);
	Rank[stu[0].id][2] = 1;
	for(int i = 1; i < n; i++){
		if(stu[i].m == stu[i - 1].m){
			Rank[stu[i].id][2] = Rank[stu[i-1].id][2];
		} else {
			Rank[stu[i].id][2] = i + 1;
		}
	}
	
	sort(stu, stu+n, cmp4);
	Rank[stu[0].id][3] = 1;
	for(int i = 1; i < n; i++){
		if(stu[i].e == stu[i - 1].e){
			Rank[stu[i].id][3] = Rank[stu[i-1].id][3];
		} else {
			Rank[stu[i].id][3] = i + 1;
		}
	}
	
	int query;
	for(int i = 0; i < m ; i++){
		scanf("%d", &query);
		if(Rank[query][0] == 0){
			printf("N/A\n");
		} else {
			int k = 0;
			for(int j = 0; j < 4; j++){
				if(Rank[query][j] < Rank[query][k]) k = j;
			}
			printf("%d %c\n", Rank[query][k], course[k]);
		}
	}
	return 0;
}




