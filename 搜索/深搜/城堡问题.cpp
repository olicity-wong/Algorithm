/*
深搜城堡问题----栈 
1.block数组存储方块的墙，visited记录方块是否被访问 
2.编写Dfs（v）
3.按位&运算。得0说明此方向未被堵 
*/ 
#include <iostream>
#include <algorithm>
#include <stack>
#include <cstring>
using namespace std;
int row,column;
int block[60][60];
int visited[60][60];
int area = 0;
int room = 0;
int maxArea;
struct Room {
	int row;
	int column;
	Room(int r,int c):row(r),column(c){}	
};
void Dfs(int i , int j){

	stack<Room> stk;
	stk.push(Room(i,j));
	while(!stk.empty()){
		Room rm = stk.top();
		int i = rm.row;
		int j = rm.column;
		if(visited[i][j])	//访问过 
			stk.pop();
		else{
			visited[i][j] = room;	//标记为访问过
			area++;
			//遍历与v相邻的点
			if((block[i][j] & 1) == 0)
				Dfs(i,j-1);	
			if((block[i][j] & 2)== 0)
				Dfs(i-1,j);		
			if((block[i][j] & 4) == 0)
				Dfs(i,j+1);
			if((block[i][j] & 8) == 0)
				Dfs(i+1,j);
		}
		
	}	
} 

int main(){
	cin >> row >> column;
	for(int i = 0; i < row; i++)
		for(int j = 0; j < column; j++){
			cin >> block[i][j];
		}
	memset(visited,0,sizeof(visited));
	for(int i = 0; i < row; i++)
		for(int j = 0; j < column; j++){
			if(!visited[i][j]){
				//未访问过
				area = 0;
				room++;
				Dfs(i,j);
				maxArea = max(maxArea,area);
			}
		}
	cout << room << endl;
	cout << maxArea << endl;
	return 0;
}
