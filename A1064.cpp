#include <cstdio>
#include <algorithm>
using namespace std;
const int maxn = 1010;
//nΪ����� number��Ž��Ȩֵ cbt�����ȫ������ 
int n, number[maxn], CBT[maxn], index = 0; 
void inOrder(int root){
	if(root > n) return;
	inOrder(root * 2);
	CBT[root] = number[index++]; //���ڵ㴦��ֵnumber[index]
	inOrder(root * 2 +1); 
}

int main(){
	scanf("%d", &n);
	for(int i = 0; i < n ; i++){
		scanf("%d", &number[i]);
	}
	sort(number, number + n);
	inOrder(1); //1��λΪ���ڵ�
	for(int i = 0; i <= n; i++){
		printf("%d", CBT[i]);
		if(i < n) printf(" "); 
	} 
	return 0;
}
