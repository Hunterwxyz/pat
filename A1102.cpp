#include <cstdio>
#include <queue>
#include <algorithm>
using namespace std;
const int maxn = 20;
struct node{
	int data;
	int lchild, rchild;
}Node[maxn];
bool notRoot[maxn] = {false};
int n, num = 0;//nΪ�������� numΪ��ǰ�Ѿ�����Ľ�����
void print(int id){
	printf("%d", id);
	num++;
	if(num < n) printf(" ");
	else printf("\n");
} 
void inOrder(int root){
	if(root == -1){
		return;
	}
	inOrder(Node[root].lchild);
	print(root);
	inOrder(Node[root].rchild);
}

void bfs(int root){
	queue<int> q;
	q.push(root);
	while(!q.empty()){
		int now = q.front();
		q.pop();
		print(now);
		if(Node[now].lchild != -1) q.push(Node[now].lchild);
		if(Node[now].rchild != -1) q.push(Node[now].rchild);
	}
}
void postOrder(int root){
	if(root == -1){
		return;
	}
	postOrder(Node[root].lchild);
	postOrder(Node[root].rchild);
	swap(Node[root].lchild, Node[root].rchild);
}
int strToNum(char c){
	if(c == '-') return -1;
	else {
		notRoot[c - '0'] = true; //���c���Ǹ��ڵ�
		return c - '0'; 
	}
}

int findRoot(){
	for(int i = 0; i < n; i++){
		if(notRoot[i] == false){
			return i;
		}
	}
}
int main() { 
	char lchild, rchild;
	scanf("%d", &n);
	for(int i = 0; i < n; i++){ 
		scanf("%*c%c %c", &lchild, &rchild);
		Node[i].lchild = strToNum(lchild);
		Node[i].rchild = strToNum(rchild);
	}	
	int root = findRoot();
	postOrder(root);
	bfs(root);
	num = 0; 
	inOrder(root);
	return 0;
}

