/*
由于是从左向右递增，从上向下递增，故从右上角/右下角开始遍历 
剩下的就是大小判断，删行删列 
*/
#include <iostream>
#include <algorithm>
using namespace std;
int main(){
	int num[100][100];
	int n;
	int result;
	cin >> n;
	for(int i = 0; i < n; i++)
		for(int j = 0; j < n; j++){
			cin >> num[i][j];
		}
	cin >> result;
	int row = 0;
	int columns = n-1;
	while(num[row][columns]!=result && row < n-1 && columns > 0){
		if(num[row][columns] > result){
			columns--;
		}
		if(num[row][columns] < result){
			row++;
		}
	}
	if(num[row][columns] == result){
		cout << "true" << endl;
	}
	else{
		cout << "false" << endl;
	}
	return 0;
} 
