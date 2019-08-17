#include <iostream>
#include<string> 
#include <map>
using namespace std;
const int maxn = 2010;//最大总人数
//const int INF = 1000000000;//最大10^9
 
map<string, int> stringToInt;//建立姓名与编号的映射
map<int, string> intToString;//姓名->编号
map<string, int> Gang; //head->人数

int G[maxn][maxn] = {0}, weight[maxn] = {0};
int n, k, numPerson=0; //n：点个数 k：阈值 numPerson：总人数
bool visit[maxn] = {false}; 

void dfs(int nowVisit, int& head, int& numMember, int& totalValue){
	numMember++;
	visit[nowVisit] = true;
	if(weight[nowVisit] > weight[head]){
		head = nowVisit;
	}
	for(int i = 0; i < numPerson; i++){
		if(G[nowVisit][i] > 0){
			totalValue += G[nowVisit][i];
			G[nowVisit][i] = G[i][nowVisit] = 0;
			if(visit[i] == false){
				dfs(i, head, numMember, totalValue);
			}
		}
	}
}

void dfsTrave(){
	for(int i = 0; i < numPerson; i++){
		if(visit[i] == false){
			int head = i, numMember = 0, totalValue = 0;
			dfs(i, head, numMember, totalValue);
			if(numPerson > 2 && totalValue > k){
				Gang[intToString[head]] = numMember;
			}
		}
	}
}
int change(string str){
	if(stringToInt.find(str) != stringToInt.end()){
		return stringToInt[str];
	} else {
		stringToInt[str] = numPerson;
		intToString[numPerson] = str;
		return numPerson++;
	}
}
int main(){
	int w;
	string str1,str2;
	cin >> n >> k;
	for(int i = 0; i < n; i++){
		cin >> str1 >> str2 >> w;
		int id1 = change(str1);
		int id2 = change(str2);
		weight[id1] += w;
		weight[id2] += w;
		G[id1][id2] += w;
		G[id2][id1] += w;		
	}
	dfsTrave();
	cout << Gang.size() << endl;
	for(auto it = Gang.begin(); it != Gang.end(); it++){
		cout << it->first << " " << it->second << endl;
	}
	return 0;
}
