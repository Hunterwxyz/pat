#include <iostream>
#include <unordered_map>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

bool cmp(string a, string b){
	return a.substr(6, 8) < b.substr(6, 8);
}
int main(){
	int n,m;
	string name;
	scanf("%d", &n);
	//cin >> n;
	unordered_map<string, bool> al;
	vector<string> gst,ans; 
	for(int i = 0; i < n; i++){
		cin >> name; 
		al[name] = true;
	}
	scanf("%d", &m);
	//cin >> m;
	for(int i = 0; i < m; i++){
		cin >> name;
		gst.push_back(name);
		if(al[name])
		ans.push_back(name);
	}
	printf("%d\n", ans.size());
	if(!ans.empty()){
		sort(ans.begin(), ans.end(), cmp);
	//	printf("%s", ans[0].c_str());
		cout << ans[0];
	} else {
		sort(gst.begin(), gst.end(), cmp);
	//	printf("%s", gst[0].c_str());
		cout << gst[0];
	}
	return 0;
}
