#include <cstdio>
#include <stack>
using namespace std;
int pre[50], in[50], post[50];
int n;
struct node{
	int data;
	node *lchild, *rchild;
};

node* newnode(int x){
	node* root = new node;
	root->data = x;
	root->lchild = root->rchild = NULL;
	return root;
}
node* create(int preL, int preR, int inL, int inR){
	if(preL > preR){
		return NULL;
	}
	node* root = newnode(pre[preL]);
	int k;
	for(k = inL; k <= inR; k++){
		if(in[k] == pre[preL]){
			break;
		}
	}
	int numLeft = k - inL;
	root->lchild = create(preL + 1, preL + numLeft, inL, k-1);
	root->rchild = create(preL + numLeft + 1, preR, k + 1, inR);
	return root;
}
int num = 0;
void postorder(node* root){
	if(root == NULL) return;
	postorder(root->lchild);
	postorder(root->rchild);
	printf("%d", root->data);
	if(num++ < n - 1) printf(" ");
	else printf("\n");
}
int main(){
	int num1 = 0, num2 = 0;
	scanf("%d", &n);
	stack<int> st;
	for(int i = 0; i < 2 * n; i++){
		char s[5];
		scanf("%s", s);
		if(s[1] == 'u'){
			scanf("%d", &pre[num1]);
			st.push(pre[num1++]);
		} else {
			in[num2++] = st.top();
			st.pop(); 
		}
	}
	node* root = create(0, n - 1, 0, n-1);
	postorder(root);
	return 0;
}











