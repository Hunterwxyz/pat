
#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

vector<int> preO, preM, postO, postM;


struct node{
	int data;
	node *left, *right;
};

void insert(node* &root, int x){
	if(root == NULL){
		root = new node;
		root->data = x;
		root->left = root->right = NULL;
		return; 
	}
	if(x < root->data){
		insert(root->left, x);
	} else {
		insert(root->right, x);
	}
}

void preOrder(node* root, vector<int> &preO){
	if(root == NULL) return;
	preO.push_back(root->data);
	preOrder(root->left, preO);
	preOrder(root->right, preO);
}
void preOrderMirror(node* root, vector<int> &preM){
	if(root == NULL) return;
	preM.push_back(root->data);
	preOrderMirror(root->right, preM);
	preOrderMirror(root->left, preM);
}
void postOrder(node* root, vector<int> &postO){
	if(root == NULL) return;
	
	postOrder(root->left, postO);
	postOrder(root->right, postO);
	postO.push_back(root->data);
}

void postOrderMirror(node* root, vector<int> &postM){
	if(root == NULL) return;
	postOrderMirror(root->right, postM);
	postOrderMirror(root->left, postM);
	postM.push_back(root->data);
}
int main(){
	int n,v;
	
	scanf("%d", &n);
	vector<int> origin;
	node* root = NULL;
	for(int i = 0; i < n; i++){
		//scanf("%d", &origin[i]);
		scanf("%d", &v);
		origin.push_back(v);
		insert(root, v);
	}
	preOrder(root, preO);
	preOrderMirror(root, preM);
	postOrder(root, postO);
	postOrderMirror(root, postM);
	
	if(origin == preO){
		printf("YES\n");
		for(int i = 0; i < postO.size(); i++){
			printf("%d",postO[i]);
			if(i < postO.size() - 1) printf(" ");
		}
	} else if(origin == preM){
		printf("YES\n");
		for(int i = 0; i < postM.size(); i++){
			printf("%d", postM[i]);
			if(i < postM.size() - 1) printf(" ");
		}
	} else {
		printf("NO\n");
	}
	return 0;
}















