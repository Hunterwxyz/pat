#include <cstdio>
#include <cstring>
const int maxn = 1010;
int cnt = 0;
struct Node{
	char name[12];
	char pwd[12];
	bool ischange = false;
}node[maxn];

void changejudge(Node& node, int& cnt){
	int len = strlen(node.pwd);
	for(int i = 0; i < len; i++){
		if(node.pwd[i] == '1') {
			node.pwd[i] = '@';
			node.ischange = true;
			continue;
		}
		if(node.pwd[i] == '0') {
			node.pwd[i] = '%';
			node.ischange = true;
			continue;
		}
		if(node.pwd[i] == 'l') {
			node.pwd[i] = 'L';
			node.ischange = true;
			continue;	
		}
		if(node.pwd[i] == 'O') {
			node.pwd[i] = 'o';
			node.ischange = true;
			continue;
		}
	}
	if (node.ischange == true) cnt++;
}
int main(){
	int m;
	scanf("%d", &m);
	for(int i = 0; i < m; i++){
		scanf("%s %s", node[i].name, node[i].pwd);
		changejudge(node[i],cnt);
	}
	if(cnt == 0 && m == 1) printf("There is 1 account and no account is modified");
	else if(cnt == 0 && m != 1) printf("There are %d accounts and no account is modified", m);
	else printf("%d\n", cnt);
	for(int i = 0; i < m; i++){
		if(node[i].ischange == true) 
			printf("%s %s\n", node[i].name, node[i].pwd);
	}
	
}
