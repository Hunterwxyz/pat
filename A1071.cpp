#include <cstdio>
#include <iostream>
#include <string>
#include <map>
using namespace std;

bool judge(char c){
	if(c >='0'&& c <= '9') return true;
	if(c >= 'A' && c <= 'Z') return true;
	if(c >= 'a' && c <= 'z') return true;
	return false;
}
int main(){
	string str;
	map<string, int> count;
	getline(cin, str);
	int len = str.length();
	int i = 0;
	while(i < len){
		string word;
		while(i < len && judge(str[i]) == true){
			if(str[i] >= 'A' && str[i] <= 'Z'){
				str[i] += 32;
			}
			word += str[i];
			i++;
		}
		if(word != " "){
			if(count.find(word) != count.end()) count[word]++;
			else count[word] = 1;
			//if(count.find(word) == count.end()) count[word] = 1;
			//else count[word]++;
		}
		while( i < len && judge(str[i]) == false){
			i++;
		}	
	}
	
	string ans;
	int max = 0;
	for(auto it = count.begin(); it != count.end(); it++){
		if(it->second > max){
			max = it->second;
			ans = it->first;
		}
	}
	printf("%s %d",ans.c_str(), max);
	return 0;
	
} 
