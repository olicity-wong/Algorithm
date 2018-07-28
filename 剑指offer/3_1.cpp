/*
1.直接从第一个数开始暴力遍历整个数组，每个数遍历一次。
2.先排序，然后遍历数组前后比较。
3.开一个标记数组a[]初始化0，从头遍历，a[num[i]]++，每次加都判断，或者最后判是否>1。同理map 
4.如果num[i]==i 往下遍历。else 交换 num[num[i]]和num[i] 
*/

#include <cstdio>
#include <iostream>
#define maxn 10000
using namespace std;

bool dup(int num[], int n, int* flag){
	if(n<=0){
		return false;
	}
	/*
	记录一下
	假设题目没有描述0~n-1 
	如果存在负数或者大于n-1的数，那么是跳过还是继续统计。
	这种做法存在问题。 
	*/ 
	for(int i = 0; i < n ; ++i){
		if(num[i] < 0 || num[i] > n-1){
			return false;
		} 
	} 
	for(int i = 0; i < n; ++i){
		if(num[i]==i){
			continue;
		}
		else{
			if(num[i]==num[num[i]]){
				*flag = num[i];
				return true;
			}
			else{
				int temp = num[i];
				num[i] = num[num[i]];
				num[temp] = temp;
			}
			
		}
	}
	return false;
}
int main(){
	int n;
	int num[maxn];
	int flag;
	cin >> n;
	for(int i = 0; i < n; ++i){
		cin >> num[i];
	}
	if(dup(num, n, &flag)){
		cout << flag << endl;
	}
	else{
		cout << "NULL" << endl;
	}
	return 0;
} 
