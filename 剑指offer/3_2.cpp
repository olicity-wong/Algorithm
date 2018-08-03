//1.使用map进行标记 
#include <cstdio>
#include <algorithm>
#include <iostream>
#include <map>
using namespace std;
int main(){
	map <int,int> m;
	map <int,int>::iterator iter;
	int flag;
	int n,a;
	cin >> n;
	for(int i = 0; i < n; i++){
		cin >> a;
		if(m[a]!=1){
			m[a] = 1;
		}
		else{
			flag = a;
		}
	}
	cout << flag << endl;
	return 0;
} 

//2.二分 

