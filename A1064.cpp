#include <cstdio>
#include <algorithm>
using namespace std;
const int maxn = 1010;
//n为结点数 number存放结点权值 cbt存放完全二叉树 
int n, number[maxn], CBT[maxn], index = 0; 
void inOrder(int root){
	if(root > n) return;
	inOrder(root * 2);
	CBT[root] = number[index++]; //根节点处赋值number[index]
	inOrder(root * 2 +1); 
}

int main(){
	scanf("%d", &n);
	for(int i = 0; i < n ; i++){
		scanf("%d", &number[i]);
	}
	sort(number, number + n);
	inOrder(1); //1号位为根节点
	for(int i = 0; i <= n; i++){
		printf("%d", CBT[i]);
		if(i < n) printf(" "); 
	} 
	return 0;
}
