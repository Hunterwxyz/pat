#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
//const int maxn = 100;
int n;
string deal (string s, int& e){
	int k = 0; //s���±�
	while(s.length() > 0 && s[0] == '0'){
		s.erase(s.begin()); //ȥ��s��ǰ���� 
	}
	if(s[0] == '.'){
		s.erase(s.begin());
		while(s.length() > 0 && s[0] == '0') {//ȥ��С��������λǰ��������
			s.erase(s.begin());
			e--; 
		}
	} else {
		while( k < s.length() && s[k] != '.'){//Ѱ��С���� 
			k++;
			e++;
		}
		if(k < s.length()){//while������ k < s.lenth(),˵��������С���� 
			s.erase(s.begin() + k);//ɾ��С���� 
		}
	}
		if(s.length() == 0){
			e = 0;//ȥ��ǰ��0�� s����Ϊ0 ˵���������0 
		}
		int num = 0;//���� 
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
