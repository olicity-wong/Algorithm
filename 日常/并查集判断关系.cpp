/*
Today is Ignatius' birthday. He invites a lot of friends. Now it's dinner time. Ignatius wants to know how many tables he needs at least. You have to notice that not all the friends know each other, and all the friends do not want to stay with strangers. 

One important rule for this problem is that if I tell you A knows B, and B knows C, that means A, B, C know each other, so they can stay in one table. 

For example: If I tell you A knows B, B knows C, and D knows E, so A, B, C can stay in one table, and D, E have to stay in the other one. So Ignatius needs 2 tables at least. 
Input
The input starts with an integer T(1<=T<=25) which indicate the number of test cases. Then T test cases follow. Each test case starts with two integers N and M(1<=N,M<=1000). N indicates the number of friends, the friends are marked from 1 to N. Then M lines follow. Each line consists of two integers A and B(A!=B), that means friend A and friend B know each other. There will be a blank line between two cases.
Output
For each test case, just output how many tables Ignatius needs at least. Do NOT print any blanks. 
Sample Input
2
5 3
1 2
2 3
4 5

5 1
2 5
Sample Output
2
4
*/

/*
题目大意：一个人过生日请客，她希望认识的人在一个餐桌上，给出朋友之间的关系，问最少需要多少餐桌。

思路：并查集，用i-x和i-y两个集合代表熟人和陌生人组成并查集。对于每次输入关系，合并两人所属集合，最后统计有几个集合即可。
*/
#include <stdio.h>
#include <iostream>
#include <string.h>
#include <algorithm>
#include <stack>
using namespace std;
const int maxn=1005;
int pre[2005];
int t,n,m;
int f1,f2;


int find(int x)
{
    int r=x;
    while(pre[r]!=r)
    	r=pre[r];
    int i=x,j;
    while(i!=r)
    {
        j=pre[i];
        pre[i]=r;
        i=j;
    }
    return r;
}

void join(int x,int y)
{
    int a=find(x);
    int b=find(y);
    if(a!=b)
    {
        pre[a]=b;
    }
}
int main()
{
    scanf("%d",&t);
    while(t--)
    {
        int ans=0;
        scanf("%d%d",&n,&m);
        for(int i=0;i<=2*n;i++)
        	pre[i]=i;
        
        for(int i=0;i<m;i++)
        {
            scanf("%d%d",&f1,&f2);
            join(f1,f2);
        }
        for(int i=1;i<=n;i++)
            if(pre[i]==i)ans++;
        cout<<ans<<endl;
    }
    return 0;
}


