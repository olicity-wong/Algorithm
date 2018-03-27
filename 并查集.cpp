/*
给定每个人的家庭成员和其自己名下的房产，请你统计出每个家庭的人口数、人均房产面积及房产套数。

输入格式：
输入第一行给出一个正整数N（≤1000），随后N行，每行按下列格式给出一个人的房产：

编号 父 母 k 孩子1 ... 孩子k 房产套数 总面积
其中编号是每个人独有的一个4位数的编号；父和母分别是该编号对应的这个人的父母的编号（如果已经过世，则显示-1）；k（0≤k≤5）是该人的子女的个数；孩子i是其子女的编号。

输出格式：
首先在第一行输出家庭个数（所有有亲属关系的人都属于同一个家庭）。随后按下列格式输出每个家庭的信息：

家庭成员的最小编号 家庭人口数 人均房产套数 人均房产面积
其中人均值要求保留小数点后3位。家庭信息首先按人均面积降序输出，若有并列，则按成员编号的升序输出。

输入样例：
10
6666 5551 5552 1 7777 1 100
1234 5678 9012 1 0002 2 300
8888 -1 -1 0 1 1000
2468 0001 0004 1 2222 1 500
7777 6666 -1 0 2 300
3721 -1 -1 1 2333 2 150
9012 -1 -1 3 1236 1235 1234 1 100
1235 5678 9012 0 1 50
2222 1236 2468 2 6661 6662 1 300
2333 -1 3721 3 6661 6662 6663 1 100
输出样例：
3
8888 1 1.000 1000.000
0001 15 0.600 100.000
5551 4 0.750 100.000
*/

/*
1.让 id 小的当父亲节点 解决最小编号问题，

2.重写cmp函数解决先输出面积大的，然后编号小的的问题
*/


#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <string>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <stack>
#include <sstream>
#include <string>

using namespace std;

const int maxn = 10000;
struct Data{///编号，父亲编号，母亲编号，房子套数，面积
    int  id, fid, mid, num, area;
    int child[7];
}data[maxn];

struct node{
    int id,people;
    double num,area;
    bool flag = 0;
}ans[maxn];

int father[maxn];
bool visit[maxn];

int findp(int x){
    int p = x;
    while(p != father[p])
        p = father[p];
    int nowx = x,nextx =x;
    while (father[nowx] != p){
        nextx = father[nowx];
        father[nowx] = p;
        nowx = nextx;
    }
    return p;
}

void update(int a,int b){
    int fa = findp(a);
    int fb = findp(b);
    if(fa<fb) father[fb] = fa;
    else if (fa>fb) father[fa] = fb;
}

int cmp1(node a,node b){
    if(a.area!=b.area)
        return a.area>b.area;
    else
        return a.id<b.id;

}

int main(){

    int n,cnt = 0;
    int k;
    for(int i = 0; i<maxn; ++i){
        father[i] = i;
    }


    scanf("%d",&n);
    for(int i = 0; i < n; ++i){
        scanf("%d",&data[i].id);
        visit[data[i].id] = 1;///编号为id的这个人存在
        scanf("%d %d %d",&data[i].fid,&data[i].mid,&k);

        if(data[i].fid != -1){
            visit[data[i].fid] = 1;
            update(data[i].id,data[i].fid);
        }

        if(data[i].mid != -1){
            visit[data[i].mid] = 1;
            update(data[i].id,data[i].mid);
        }

        for(int j = 0; j<k; ++j){
            scanf("%d",&data[i].child[j]);
            visit[data[i].child[j]] = 1;
            update(data[i].child[j],data[i].id);
        }

        scanf("%d %d",&data[i].num,&data[i].area);

    }

    ///处理根结点的房子数和面积
    for(int i = 0; i<n; ++i){
        int id = findp(data[i].id);
        ans[id].id = id;
        ans[id].num += data[i].num;
        ans[id].area += data[i].area;
        ans[id].flag = 1;///这是根
    }

    ///要在这里单独遍历出人数，而不能直接遍历data[]，因为可能有的家庭的孩子没有房产即data[]数组并没有存这个孩子的房产信息，但他仍要平分房产
    for(int i = 0; i<maxn; ++i){
        if(visit[i])///这个人存在
            ans[findp(i)].people++;

        if(ans[i].flag) cnt++;
    }

    ///处理平均房子数和平均面积
    for(int i = 0; i<maxn; ++i){
        if(ans[i].flag){
            ans[i].num =  (double)(ans[i].num * 1.0 / ans[i].people);
            ans[i].area = (double)(ans[i].area * 1.0 / ans[i].people);
        }
    }

    sort(ans,ans+maxn,cmp1);///这里注意是全部排序，因为编号不确定
    printf("%d\n",cnt);
    for(int i = 0; i < cnt; ++i){
        printf("%04d %d %.3lf %.3lf\n",ans[i].id,ans[i].people,ans[i].num,ans[i].area);

    }
    return 0;

}

/*
并查集不支持分割一个集合
求连通子图、求最小生成树
用集合中的某个元素来代表这个集合，该元素称为集合的代表元。
一个集合内的所有元素组织成以代表元为根的树形结构。
对于每一个元素 parent[x]指向x在树形结构上的父亲节点。如果x是根节点，则令parent[x] = x。
对于查找操作，假设需要确定x所在的的集合，也就是确定集合的代表元。可以沿着parent[x]不断在树形结构中向上移动，直到到达根节点。
判断两个元素是否属于同一集合，只需要看他们的代表元是否相同即可。 

初始化
我们将每一个结点的前导结点设置为自己，如果在join函数时未能形成连通，将独立成点

for(int i=0;i<n;i++)//n表示输入的结点的个数
{
    pre[i]=i;//将每一个结点的前导点设置为自己

}


路径压缩
 为了加快查找速度，查找时将x到根节点路径上的所有点的parent设为根节点，该优化方法称为压缩路径。
 使用该优化后，平均复杂度可视为Ackerman函数的反函数，实际应用中可粗略认为其是一个常数。
 
 结构体表示法
#define MAX 10000
struct Node
{
    int data;
    int rank;
    int parent;
 }node[MAX];
 
数组表示法
int set[max];//集合index的类别，或者用parent表示
int rank[max];//集合index的层次，通常初始化为0
int data[max];//集合index的数据类型
//初始化集合
void Make_Set(int i)
{
    set[i]=i;//初始化的时候，一个集合的parent都是这个集合自己的标号。没有跟它同类的集合，那么这个集合的源头只能是自己了。
    rank[i]=0;
}


查找 
 查找集合i（一个元素是一个集合）的源头（递归实现）。
 如果集合i的父亲是自己，说明自己就是源头，返回自己的标号；
 否则查找集合i的父亲的源头。
 结构体表示： 
int get_parent(int x)
{
    if(node[x].parent==x)
        return x;
    return get_parent(node[x].parent);
}
数组表示
int Find_Set(int i)
{ 
    //如果集合i的父亲是自己，说明自己就是源头，返回自己的标号
   if(set[i]==i)
       return set[i];
    //否则查找集合i的父亲的源头
    return  Find_Set(set[i]);        
} 


合并
结构体表示
void Union(int a,int b)
{
    a=get_parent(a);
    b=get_parent(b);
    if(node[a].rank>node[b].rank)
        node[b].parent=a;
    else
    {    
        node[a].parent=b;
        if(node[a].rank==node[b].rank)
            node[b].rank++;
    }
}
数组表示
void Union(int i,int j)
{
    i=Find_Set(i);
    j=Find_Set(j);
    if(i==j) return ;
    if(rank[i]>rank[j]) set[j]=i;
    else
    {
        if(rank[i]==rank[j]) rank[j]++;   
        set[i]=j;
    }
} 


优化并查集模板

int node[i]; //每个节点
int rank[i]; //树的高度

//初始化n个节点
void Init(int n){
    for(int i = 0; i < n; i++){
        node[i] = i;
        rank[i] = 0;
    }
}
//查找当前元素所在树的根节点(代表元素)
int find(int x){
    if(x == node[x])
        return x;
    return node[x] = find(node[x]); //在第一次查找时，将节点直连到根节点
}
//合并元素x， y所处的集合
void Unite(int x, int y){
    //查找到x，y的根节点
    x = find(x);
    y = find(y);
    if(x == y) 
        return ;
    //判断两棵树的高度，然后在决定谁为子树
    if(rank[x] < rank[y]){
        node[x] = y;
    }else{
        node[y] = x;
        if(rank[x] == rank[y]) rank[x]++:
    }
}
//判断x，y是属于同一个集合
bool same(int x, int y){
    return find(x) == find(y);
} 
*/
