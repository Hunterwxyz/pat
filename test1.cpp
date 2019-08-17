#include<iostream>
#include<map>
#include<string>
#include <queue> 
using namespace std;
int main(){
	priority_queue<int, vector<int>, greater<int>> q;
	q.push(3);
	q.push(4);
	q.push(1);
	printf("%d\n", q.top());
	 
	return 0;
}
