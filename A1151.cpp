/**
	����������������п���ȷ��һ�ö����� 
	����������������ڵ�a��b������������� 
	���a��b�ڸ��ڵ����ߣ���������������
	���a��b�ڸ��ڵ�����ߣ���ǰ���ڵ���������������
	���a��b�ڸ��ڵ���ұߣ���������������
	��ÿһ��ݹ��У����Եõ����ĸ��ڵ�
	�ټ���lca�㷨����ȷ������Ĺ������� 
	 
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
