#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
//const int maxn = 100;
int n;
string deal (string s, int& e){
	int k = 0; //s的下标
	while(s.length() > 0 && s[0] == '0'){
		s.erase(s.begin()); //去掉s的前导零 
	}
	if(s[0] == '.'){
		s.erase(s.begin());
		while(s.length() > 0 && s[0] == '0') {//去掉小数点后非零位前的所有零
			s.erase(s.begin());
			e--; 
		}
	} else {
		while( k < s.length() && s[k] != '.'){//寻找小数点 
			k++;
			e++;
		}
		if(k < s.length()){//while结束后 k < s.lenth(),说明碰到了小数点 
			s.erase(s.begin() + k);//删除小数点 
		}
	}
		if(s.length() == 0){
			e = 0;//去除前导0后 s长度为0 说明这个数是0 
		}
		int num = 0;//精度 
		k = 0;
		string res;
		while(num < n){
			if(k < s.length()) res += s[k++];
			else res += '0';
			num++;
		}
		return res;  
}
int main() {
	string s1, s2, s3, s4;
	cin >> n >> s1>> s2;
	int e1 = 0, e2 = 0;
	s3 = deal(s1, e1);
	s4 = deal(s2, e2);
	if(s3 == s4 && e1 == e2){
		cout<<"YES 0."<< s3 <<"*10^"<<e1<<endl;
	} else {
		cout<<"NO 0."<<s3 <<"*10^"<< e1 <<" 0."<<s4<<"*10^"<<e2<<endl; 
	}
	
	return 0;
}
