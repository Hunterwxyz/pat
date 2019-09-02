#include <cstdio>
#include <iostream>
#include <string>
#include <map>
using namespace std;

string  gewei[13] = {"tret","jan", "feb", "mar", "apr", "may", "jun","jly","aug","sep","oct","nov","dec"};
string shiwei[13] = {"tret","tam","hel", "maa","huh","tou", "kes", "hei","elo","syy","lok","mer","jou"};
string numToStr[170];
map<string, int> strToNum;

void init(){
	for(int i = 0; i < 13; i++){
		numToStr[i] = gewei[i];
		strToNum[gewei[i]] = i;
		numToStr[i * 13] = shiwei[i];
		strToNum[shiwei[i]] = i * 13;
		
	}
	for(int i = 1; i < 13; i++){
		for(int j = 1; j < 13; j++){
			string str = shiwei[i] + " " + gewei[j];
			numToStr[i * 13 + j] = str;
			strToNum[str] = i * 13 + j;
		}
	}
}
int main(){
	init();
	int t;
	scanf("%d", &t);
	getchar();//getline之前要将上一行的换行符吸收掉 
	while(t--){
		string str;
		getline(cin, str);
		if(str[0] <= '9'&&str[0] >= '0'){
			int num = 0;
			for(int i = 0; i < str.length(); i++){
				num = num * 10 + (str[i] - '0');
			}
			cout << numToStr[num]<<endl;
		}
		else{
			cout << strToNum[str]<< endl;
		}	
	}
	return 0;
	
}









