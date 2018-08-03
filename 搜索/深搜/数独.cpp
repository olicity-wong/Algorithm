/*
每3*3，每行，每列1-9都会出现
poj2676 
每行，每列，没个子3*3格都标记
注意下标规律3*（row_下标/3）+（col_下标/3）=child_下标 
转换成1-9即   3*（（row-1）/3）+（（col-1）/3）= child
*/
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
int map[10][10];
bool row[10][10];	//某数字在某行是否出现 
bool col[10][10];	//某数字在某列是否出现 
bool child[10][10];	//某数字在某子格是否出现 
bool dfs(int i,int j){
	if(i == 10)		//越界 
		return true;
	bool flag = false;
	
	if(map[i][j]){	//控制遍历每行每列 
		//遍历下/右
		if(j==9)
			flag = dfs(i+1,1);
		else
			flag = dfs(i,j+1);
		//判断flag回溯 
		if(flag)
			return true;
		else
			return false;
	}
	else{
		int ch = 3*((i-1)/3)+((j-1)/3)+1;		//找到属于哪个子格
		for(int a = 1; a <= 9; a++){
			//1-9枚举搜索
			if(!row[i][a] && !col[j][a] && !child[ch][a]){
				//在此行、此列、此子格中都未出现
				map[i][j] = a;
				row[i][a] = true;
				col[j][a] = true;
				child[ch][a] = true;
				if(j == 9)
					flag = dfs(i+1,1);
				else
					flag = dfs(i,j+1);
				if(!flag){
					//回溯 
					map[i][j] = 0;
					row[i][a] = false;
					col[j][a] = false;
					child[ch][a] = false;
				}
				else
					return true;
			} 
		} 
	} 
	//该方法不行 
	return false;
}
int main(){
	int n;
	cin >> n;
	while(n--){
		memset(row,false,sizeof(row));
		memset(col,false,sizeof(col));
		memset(child,false,sizeof(child));
		memset(map,0,sizeof(map));
		char in;
		for(int i = 1; i <= 9; i++)
			for(int j = 1; j <= 9; j++){
				cin >> in;
				map[i][j] = in-'0';
				if(map[i][j]){
					int ch = 3*((i-1)/3)+((j-1)/3)+1;
					row[i][map[i][j]] = true;
					col[j][map[i][j]] = true;
					child[ch][map[i][j]] = true;
				}
			}
		dfs(1,1);
		cout << endl;
		for(int i = 1; i <= 9; i++){
			for(int j = 1; j <= 9; j++){
				cout << map[i][j];
			}
			cout << endl;
		}
			
	} 
	return 0;
} 
