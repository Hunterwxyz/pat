/**
	根据中序和先序序列可以确定一棵二叉树 
	根据树求给定两个节点a和b的最近公共祖先 
	如果a和b在根节点的左边，则在左子树里找
	如果a和b在根节点的两边，当前根节点就是最近公共祖先
	如果a和b在根节点的右边，则在右子树里找
	在每一层递归中，可以得到树的根节点
	再加入lca算法可以确定两点的公共祖先 
	 
*/
#include <cstdio>
#include <vector>
#include <map>
using namespace std;
map<int,int> pos;
vector<int> in, pre;

void lca(int inL, int inR, int preRoot, int a, int b){
	if(inL > inR) return;
	int inRoot = pos[pre[preRoot]], aIn = pos[a], bIn = pos[b];
	if(aIn < inRoot && bIn < inRoot) 
}
