#include<iostream>
#include<cmath>
using namespace std;
bool isPrime(int n){
	if(n <= 1) return false;
	int a = sqrt(n);
	for(int i = 2; i <= a; i++){
		if(n % i == 0) return false;
	}
	return true;
}
int main(){
	int n;
	cin >> n;
	bool f = true;
	if (isPrime(n)){
		if(isPrime(n - 6)) printf("Yes\n%d\n", n-6);
		else if(isPrime(n + 6)) printf("Yes\n%d\n", n + 6);
		else f = false;
	}
	else f = false;
	if(!f){
		printf("No\n");
		while(!isPrime(n) || !isPrime(n + 6) || !isPrime(n - 6)) n++;
		printf("%d",n);
	}
	return 0;
	 
} 
