#include <cstdio>
#include <string>
#include <iostream>
using namespace std;

int main(){
	string str1,str2;
	getline(cin, str1);
	getline(cin, str2);
	for(int j = 0; j < str2.length(); j++){
		while(str1.find(str2[j]) != string::npos){	
			str1.erase(str1.begin()+(str1.find(str2[j])));			
		}
	}	
	cout << str1<<endl;
	return 0;
}
