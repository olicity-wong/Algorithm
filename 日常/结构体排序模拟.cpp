/*
按要求，给国家进行排名。 
Input
有多组数据。 
第一行给出国家数N，要求排名的国家数M，国家号从0到N-1。 
第二行开始的N行给定国家或地区的奥运金牌数，奖牌数，人口数（百万）。 
接下来一行给出M个国家号。
Output
排序有4种方式: 金牌总数 奖牌总数 金牌人口比例 奖牌人口比例 
对每个国家给出最佳排名排名方式 和 最终排名 
格式为: 排名:排名方式 
如果有相同的最终排名，则输出排名方式最小的那种排名，对于排名方式，金牌总数 < 奖牌总数 < 金牌人口比例 < 奖牌人口比例 
如果有并列排名的情况，即如果出现金牌总数为 100,90,90,80.则排名为1,2,2,4. 
每组数据后加一个空行。
Sample Input
4 4
4 8 1
6 6 2
4 8 2
2 12 4
0 1 2 3
4 2
8 10 1
8 11 2
8 12 3
8 13 4
0 3
Sample Output
1:3
1:1
2:1
1:2

1:1
1:1
*/

//结构体排序模拟

#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm> 
#define N 1005

using namespace std;
struct Node
{
	int seq;
	double num;
}gold[N],medal[N],g_rate[N],m_rate[N];

bool cmp(Node a,Node b)
{
	return a.num>b.num;
}
int ranking[N][5];
int n,m;
double a[N],b[N],c[N];
int d[N];
void compute(Node x[],int k)//第k种排序方式 
{
	sort(x,x+m,cmp);//进行排序，大的在前 
	ranking[x[0].seq][k]=1;
	int cnt=2;
	for(int i=1;i<m;i++)
	{
		if(x[i].num==x[i-1].num)//如果和前面的大小相等，则排名和前面一样 
		{
			ranking[x[i].seq][k]=ranking[x[i-1].seq][k];
			
		}
		else//否则就是第cnt个数 
			ranking[x[i].seq][k]=cnt;
		cnt++;
	}
}
int main() {
	while(scanf("%d%d",&n,&m)!=EOF)
	{
		for(int i=0;i<n;i++)
		{
			scanf("%lf%lf%lf",&a[i],&b[i],&c[i]);
		}
		for(int i=0;i<m;i++)
		{
			scanf("%d",&d[i]);
		}
		for(int i=0;i<m;i++)//选择出需要排序得那一部分 
		{
			gold[i].num=a[d[i]];
			gold[i].seq=d[i];
			medal[i].num=b[d[i]];
			medal[i].seq=d[i];
			g_rate[i].num=a[d[i]]/c[d[i]];
			g_rate[i].seq=d[i];
			m_rate[i].num=b[d[i]]/c[d[i]];
			m_rate[i].seq=d[i];
		}
		memset(ranking,0,sizeof(ranking));
		compute(gold,1);//根据题目的意思，不同的排序方式 
		compute(medal,2);
		compute(g_rate,3);
		compute(m_rate,4);
		for(int i=0;i<m;i++)
		{
			int min=N,pos=1;
			for(int j=1;j<=4;j++)//找出四种排序方式中，排名最靠前的那种方式 
			{
				if(ranking[d[i]][j]<min)
				{
					min=ranking[d[i]][j];
					pos=j;
				}
			}
			printf("%d:%d\n",min,pos);
		}
		printf("\n");
	}
	return 0;
}






