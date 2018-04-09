/*
Problem Description
小w来到百度之星的赛场上，准备开始实现一个程序自动分析系统。

这个程序接受一些形如 或  的相等/不等约束条件作为输入，判定是否可以通过给每个 w 赋适当的值，来满足这些条件。

输入包含多组数据。
然而粗心的小w不幸地把每组数据之间的分隔符删掉了。
他只知道每组数据都是不可满足的，且若把每组数据的最后一个约束条件去掉，则该组数据是可满足的。

请帮助他恢复这些分隔符。
 

Input
第行：一个数字，表示后面输入的总行数。

之后行，每行包含三个整数，，描述一个相等/不等的约束条件，若，则该约束条件为 ，若，则该约束条件为  。



Output
输出共行。

第一行一个整数，表示数据组数。

接下来行的第行，一个整数，表示第i组数据中的约束条件个数。
 

Sample Input
6 2 2 1 2 2 1 1 1 1 3 1 1 1 3 1 1 3 0
 

Sample Output
1 6
*/ 


/*
思路：我们这样处理，把=号关系用并查集解决，把！=号关系用边来解决，那么分4种情况讨论，
若当前约束条件为a[i]==a[j]，那么若a[i]所在集合和a[j]所在集合存在边，则矛盾，
否则把两个集合并起来，并的时候要连边关系一同并集，若当前约束条件为a[i]!=a[j]，那么若a[i]和a[j]在同一个集合，则矛盾，
否则把a[i]的集合和a[j]的集合建边。如此就解决了。
*/
#include<iostream>  
#include<cmath>  
#include<queue>  
#include<cstdio>  
#include<queue>  
#include<algorithm>  
#include<cstring>  
#include<string>  
#include<utility>
#include<set>
#include<map>
#include<stack>
#include<vector>
#define maxn 100005
#define inf 0x3f3f3f3f
using namespace std;
typedef long long LL;
const double eps = 1e-5;
const int mod = 998244353;
int vis[maxn], size[maxn], ans[maxn], pre, len;
queue<int>q;
vector<int>v[maxn];
int getfa(int x){
	if (vis[x] != x)
		return vis[x] = getfa(vis[x]);
	return x;
}
void solve(int i){
	ans[len++] = i - pre;
	pre = i;
	while (!q.empty()){
		int now = q.front();
		q.pop();
		vis[now] = now;
		size[now] = 1;
		v[now].clear();
	}
}
void merge(int x, int y){
	if (size[x] > size[y]){
		size[x] += size[y];
		for (int i = 0; i < v[y].size(); i++){
			v[x].push_back(v[y][i]);
			v[v[y][i]].push_back(x);
		}
		vis[y] = x;	
	}
	else{
		size[y] += size[x];
		for (int i = 0; i < v[x].size(); i++){
			v[y].push_back(v[x][i]);
			v[v[x][i]].push_back(y);
		}
		vis[x] = y;
	}
}
bool check(int x, int y){
	int size1 = v[x].size();
	int size2 = v[y].size();
	if (size1 > size2){
		for (int i = 0; i < size2; i++)
			if (v[y][i] == x)
				return true;
	}
	else{
		for (int i = 0; i < size1; i++)
			if (v[x][i] == y)
				return true;
	}
	return false;
}
int main(){
	int l;
	scanf("%d", &l);
	for (int i = 0; i < maxn; i++){
		vis[i] = i;
		size[i] = 1;
	}
	for (int index = 1; index <= l;index++){
		int i, j, e;
		scanf("%d%d%d", &i, &j, &e);
		q.push(i);
		q.push(j);
		int x = getfa(i);
		int y = getfa(j);
		if (e){	
			if (check(x, y))
				solve(index);
			else if (x != y)
				merge(x, y);
		}
		else{
			if (x == y)
				solve(index);
			else{
				v[x].push_back(y);
				v[y].push_back(x);
			}
		}
	}
	printf("%d\n", len);
	for (int i = 0; i < len; i++)
		printf("%d\n", ans[i]);
}
