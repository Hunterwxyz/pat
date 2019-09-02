#include <cstdio>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;
const int maxv = 1010;
struct Node{
	int id;
	int layer;
};
vector<Node> v[maxv];
bool inq[maxv] = {false};

int BFS(int s, int L){
	int numForward = 0;
	queue<Node> q;
	Node start;
	start.id = s;
	start.layer = 0;
	q.push(start);
	inq[start.id] = true;
	while(!q.empty()){
		Node topNode = q.front();
		q.pop();
		int u = topNode.id;
		for(int i = 0; i < v[u].size(); i++){
			Node next  = v[u][i];
			next.layer = topNode.layer + 1;
			if(inq[next.id] == false && next.layer <= L){
				q.push(next);
				inq[next.id] = true;
				numForward++;
			}
		}
	}
	return numForward;
}

int main(){
	int n, L;
	Node user;
	scanf("%d %d", &n,&L);
	for(int i = 1 ; i <= n; i++){
		int m, idfollow; // 用户i关注的人数、关注的用户 
		user.id = i;
		scanf("%d", &m);
		for(int j = 0; j < m; j++){
			scanf("%d", &idfollow);
			v[idfollow].push_back(user);
		}
	}
	int numQuery, s;
	scanf("%d", &numQuery);
	for(int i = 0; i < numQuery; i++){
		memset(inq, false, sizeof(inq));
		scanf("%d", &s);
		int numForward = BFS(s, L);
		printf("%d\n", numForward);
	}
	return 0;
}










