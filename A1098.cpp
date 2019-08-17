#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;
//vector<int> origin, tempOri, changed; //ԭʼ���顢ԭʼ���鱸�ݡ�Ŀ������
int n;//Ԫ�ظ���
void downAdjust(vector<int> &nowheap, int low, int high){
	int i = low, j = 2 * i; //iΪ��������㣬 jΪ�ýڵ�����
	while(j <= high){ //���ں��ӽ�� 
		//����Һ��Ӵ������Һ��Ӵ�������
		if(j + 1 < high && nowheap[j + 1] > nowheap[j]) {
			//j�洢�Һ����±� 
			j = j + 1; 
		}
		//�������������Ȩֵ���������Ľ��iȨֵ�� 
		if(nowheap[j] > nowheap[i]){
			swap(nowheap[j], nowheap[i]);
			i = j;//����iΪ��������� 
			j = 2 * i; //jΪ�������ڵ�ĵ����� 
		} else break;//���ӽ��Ȩֵ�������������С�������� 
		
	} 
}

int main(){
	int p = 2;
	scanf("%d", &n);
	vector<int> origin(n + 1), aim(n + 1);//��1�ſ�ʼ�洢
	for(int i = 1; i <= n; i++){
		scanf("%d", &origin[i]);
	}
	for(int i = 1; i <= n; i++){
		scanf("%d", &aim[i]);
	}
	while(p <= n && aim[p - 1 ] <= aim[p]) p++;//ע�����ʱ��� 
	int index = p;
	//��p��ʼ����ÿһ��Ԫ�ض���ԭʼ�����Ԫ����ȱȽϽ��� p = n+1 
	while(p <= n && origin[p] == aim[p]) p++;
	if(p == n + 1)
	{
		printf("Insertion Sort\n");
		sort(aim.begin() + 1, aim.begin() + index + 1);
	} else {
		printf("Heap Sort\n");
		p = n;
		//�����һ�����ֿ�ʼ��ǰ�ҵ���һ��С�ڵ���aim[1]������aim[p] 
		//������Ѷ�Ԫ�ؽ��������Ѷ����Ԫ���Ƶ����������� �����µ��� 1~p-1λԪ�� 
		while(p > 2 && aim[p] >= aim[1]) p--;
			swap(aim[1], aim[p]);
			downAdjust(aim, 1, p - 1);
		}
		printf("%d", aim[1]);
		for(int i = 2; i <= n; i++){
			printf(" %d", aim[i]);
		}
		return 0;
}
	

