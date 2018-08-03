/*
先找到人所在的位置，然后上下左右搜索，当满足 0<=x && x<row && 0<=y && y<col && !visited[x][y] && map[x][y]=='.'，统计并标记。 
*/
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
int row,col;
char s;
char map[30][30];
int visited[30][30];
int ct = 0; 
int pos[4][2] = {-1,0,1,0,0,1,0,-1};
void dfs(int i,int j){
	visited[i][j] = 1;
	for(int k = 0; k < 4; k++){
		int x = i + pos[k][0];
		int y = j + pos[k][1];
		if(0<=x && x<row && 0<=y && y<col && !visited[x][y] && map[x][y]=='.'){
			//cout << "(" << x << "," << y << ")" <<endl;
			ct++;
			dfs(x,y);
		}
			
	}
}
int main(){
	int x;
	int y;
	cin >> col >> row;
	ct = 1;
	memset(visited,0,sizeof(visited));
	memset(map,'\0',sizeof(map));
	for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            cin>>map[i][j];
            if(map[i][j]=='@'){
                x=i;
                y=j;
            }
        }
    }
		//cout << x << "***" << y << endl;
	dfs(x,y);	
	cout << ct << endl;
	return 0;
} 
