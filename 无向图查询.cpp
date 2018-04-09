/*
Jack likes to travel around the world, but he doesn’t like to wait. Now, he is traveling in the Undirected Kingdom. There are n cities and m bidirectional roads connecting the cities. Jack hates waiting too long on the bus, but he can rest at every city. Jack can only stand staying on the bus for a limited time and will go berserk after that. Assuming you know the time it takes to go from one city to another and that the time Jack can stand staying on a bus is x minutes, how many pairs of city (a,b) are there that Jack can travel from city a to b without going berserk?
Input
The first line contains one integer T,T≤5, which represents the number of test case. 

For each test case, the first line consists of three integers n,m and q where n≤20000,m≤100000,q≤5000. The Undirected Kingdom has n cities and m bidirectional roads, and there are q queries. 

Each of the following m lines consists of three integers a,b and d where a,b∈{1,...,n} and d≤100000. It takes Jack d minutes to travel from city a to city b and vice versa. 

Then q lines follow. Each of them is a query consisting of an integer x where x is the time limit before Jack goes berserk. 

Output
You should print q lines for each test case. Each of them contains one integer as the number of pair of cities (a,b) which Jack may travel from a to b within the time limit x. 

Note that (a,b) and (b,a) are counted as different pairs and a and b must be different cities.
Sample Input
1
5 5 3
2 3 6334
1 5 15724
3 5 5705
4 3 12382
1 3 21726
6000
10000
13000
Sample Output
2
6
12
*/

/*
题目大意：给定n个顶点，m条边的一个无向图，q个询问。
对于每个询问qq，从u，v的路径上权值要小于qq，可以记为有序对<u,v>,对于这个图里面有多少个这样的有序对。

解题思路：首先肯定要对每个路径的权值进行排序，在考虑满足条件的这些路径是否都能连在一棵树上，
如果可以的话，直接的有序对数就为：n*（n-1）；这样思路就清楚了，但是还有地方需要进行优化。
我们需要对查询进行排序，如果查询出现先大后小的情况，我们对于调用并查集的次数会增多，时间复杂度也大大提高，导致超时。
总的来说就是：先对边进行排序，然后并查集来处理各个顶点之间的连通关系，最后对询问进行处理就ok了~~~
*/
#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

#define N 20010

int num[N],fa[N],s,ans[N],n;

struct node
{
    int u,v,w;
} E[N*5];

struct que
{
    int qq,id;
} Q[N*5];

bool cmp(node a,node b)
{
    return a.w<b.w;
}

bool cmp1(que a,que b)
{
    return a.qq<b.qq;
}

void init()
{
    for (int i=0; i<=n; i++)
    {
        fa[i]=i;
        num[i]=1;
    }
}

int Find(int x)
{
    if (fa[x]==x)
        return x;
    return fa[x]=Find(fa[x]);
}
int get(int x)//表示点对的数量
{
    return x*(x-1);
}

void Union(int x,int y)
{
    x=Find(x);
    y=Find(y);
    if (x!=y)
    {
        s-=get(num[x])+get(num[y]);
        fa[y]=x,num[x]+=num[y];//孩子加到父亲身上
        s+=get(num[x]);
    }
}

int main()
{
    int t;
    scanf("%d",&t);
    while (t--)
    {
        int m,q;
        scanf("%d%d%d",&n,&m,&q);
        init();
        for (int i=0; i<m; i++)
            scanf("%d%d%d",&E[i].u,&E[i].v,&E[i].w);
        sort(E,E+m,cmp);
        for (int i=0; i<q; i++)
        {
            scanf("%d",&Q[i].qq);
            Q[i].id=i;
        }
        sort(Q,Q+q,cmp1);
        s=0;//表示当前点对数为0
        for (int j=0,i=0; i<q; i++)
        {
            for (j; j<m; j++)
            {
                if (Q[i].qq>=E[j].w)
                {
                    Union(E[j].u,E[j].v);
                }
                else break;
            }
            ans[Q[i].id]=s;
        }
        for (int i=0;i<q;i++)
            printf ("%d\n",ans[i]);
    }
    return 0;
}


