#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;
//vector<int> origin, tempOri, changed; //原始数组、原始数组备份、目标数组
int n;//元素个数
void downAdjust(vector<int> &nowheap, int low, int high){
	int i = low, j = 2 * i; //i为待调整结点， j为该节点左孩子
	while(j <= high){ //存在孩子结点 
		//如果右孩子存在且右孩子大于左孩子
		if(j + 1 < high && nowheap[j + 1] > nowheap[j]) {
			//j存储右孩子下标 
			j = j + 1; 
		}
		//如果孩子中最大的权值比欲调整的结点i权值大 
		if(nowheap[j] > nowheap[i]){
			swap(nowheap[j], nowheap[i]);
			i = j;//保持i为欲调整结点 
			j = 2 * i; //j为欲调整节点的的左孩子 
		} else break;//孩子结点权值都比欲调整结点小，不调整 
		
	} 
}

int main(){
	int p = 2;
	scanf("%d", &n);
	vector<int> origin(n + 1), aim(n + 1);//从1号开始存储
	for(int i = 1; i <= n; i++){
		scanf("%d", &origin[i]);
	}
	for(int i = 1; i <= n; i++){
		scanf("%d", &aim[i]);
	}
	while(p <= n && aim[p - 1 ] <= aim[p]) p++;//注意等于时情况 
	int index = p;
	//从p开始后面每一个元素都与原始数组的元素相等比较结束 p = n+1 
	while(p <= n && origin[p] == aim[p]) p++;
	if(p == n + 1)
	{
		printf("Insertion Sort\n");
		sort(aim.begin() + 1, aim.begin() + index + 1);
	} else {
		printf("Heap Sort\n");
		p = n;
		//从最后一个数字开始往前找到第一个小于等于aim[1]的数字aim[p] 
		//将其与堆顶元素交换即将堆顶最大元素移到已排序序列 再向下调整 1~p-1位元素 
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
	

