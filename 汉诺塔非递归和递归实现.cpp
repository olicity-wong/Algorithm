/*
借助堆栈以非递归（循环）方式求解汉诺塔的问题（n, a, b, c），即将N个盘子从起始柱（标记为“a”）通过借助柱（标记为“b”）移动到目标柱（标记为“c”），并保证每个移动符合汉诺塔问题的要求。

输入格式:
输入为一个正整数N，即起始柱上的盘数。

输出格式:
每个操作（移动）占一行，按柱1 -> 柱2的格式输出。

输入样例:
3
*/
//非递归实现 
/*
汉诺塔的非递归算法描述如下：
首先容易证明，当盘子的个数为n时，移动的次数应等于2^n - 1。
一位美国学者发现一种出人意料的方法，只要轮流进行两步操作就可以了。
首先把三根柱子按顺序排成品字型，把所有的圆盘按从大到小的顺序放在柱子A上。
根据圆盘的数量确定柱子的排放顺序：若n为偶数，按顺时针方向依次摆放 A B C；
若n为奇数，按顺时针方向依次摆放 A C B。
（1）按顺时针方向把圆盘1从现在的柱子移动到下一根柱子，即当n为偶数时，若圆盘1在柱子A，则把它移动到B；
若圆盘1在柱子B，则把它移动到C；若圆盘1在柱子C，则把它移动到A。
（2）接着，把另外两根柱子上可以移动的圆盘移动到新的柱子上。
即把非空柱子上的圆盘移动到空柱子上，当两根柱子都非空时，移动较小的圆盘
这一步没有明确规定移动哪个圆盘，你可能以为会有多种可能性，其实不然，可实施的行动是唯一的。
（3）反复进行（1）（2）操作，最后就能按规定完成汉诺塔的移动。
*/
#include<iostream>  
#include<algorithm>  
#include <stack>  
#include <cstdio>  
#include<cmath>  
using namespace std;  
int temp1=-1, temp2=-1;  
char s[4] = { 'q','a','b','c' };//为了解题简便，我是从1开始算的  
stack<int> a[4];  
int c1 = 0;  
int rank1[4];  
bool compare(int a1,int b1) { //给栈顶元素排序用  
    if (a[a1].top() >= a[b1].top())  
        return true;  
    if (a[a1].top() < a[b1].top())  
        return false;  
    return false;  
}  
bool move1(int before,int after) {   //移动物块  
    if ((a[after].top() - a[before].top())%2==0)  
        return false;  
    a[after].push(a[before].top());  
    a[before].pop();  
    temp1 = before; temp2 = after;  //记录上一次移动的物块位置  
    printf("%c -> %c\n",s[temp1],s[temp2]);//printf比cout要快  
    c1++;  
    return true;  
}  
int main()
{  
    int n;  
    cin >> n;  
    a[1].push(n+1);          //保证栈不会为空  
    for (int i = 0; i < n; i++)  
        a[1].push(N-i);   //初始化  
    a[2].push(N + 2);  
    a[3].push(N+3);  
    if (N % 2 == 1) {        //N为奇数还是偶数，第一次移物块到哪里是不同的  
        move1(1, 3);  
        temp1 = 1;  
        temp2 = 3;  
    }  
    else {  
        move1(1, 2);  
        temp1 = 1; temp2 = 2;  
    }  
    for (i = 1; i <= 3; i++)//初始化栈排序表  
        rank1[i] = i;  
    int tt;  
    while (c1 < pow(2, N) -1) {  
        sort(rank1 + 1, rank1 + 4, compare);//按compare函数排序  
            if (temp2 == rank1[2]) { //刚移动过的物块不会再被移动  
                if(tt==temp1)   //别问我为什么，找规律找出来的  
                    move1(rank1[3], rank1[2]);  
                else  
                    move1(rank1[3], rank1[1]);  
            }  
            else  
                move1(rank1[2], rank1[1]);  
        tt = rank1[2];   
    }  
}  

//递归实现
#include <stdio.h>
#include <iostream>
#include <math.h>
#include <string.h>
#include <stack>
using namespace std;
struct Quad 
{  
    Quad();  
    Quad(int n, char a, char b, char c): _n(n), _x(a), _y(b), _z(c) 
	{  
	
    }  
    int _n;         // 要移动的盘子数量  
    char _x, _y, _z;    // 保存柱子名称  
}; // 保存当前状态  
void hanoi(int n, char x, char y, char z)  
{  
    stack<Quad> s;  
    s.push(Quad(n, x, y, z));  
    while (!s.empty()) {  
        Quad q = s.top();  
        s.pop();  
        n = q._n;  
        x = q._x;  
        y = q._y;  
        z = q._z;  
        if (n == 1) {  
            std::cout << "Move top disk from peg " << q._x  
                 << " to peg " << q._z << "\n";  
        }  
        else {  
            s.push(Quad(n - 1, y, x, z));  
            s.push(Quad(1, x, y, z));  
            s.push(Quad(n - 1, x, z, y));  
        }  
    }  
}
int main(int argc, char *argv[])  
{  
	int n;
	cin >> n;
    hanoi(n, 'a', 'b', 'c');  
    return 0;  
}  
   
/*
汉诺塔的非递归算法描述如下：
首先容易证明，当盘子的个数为n时，移动的次数应等于2^n - 1。
一位美国学者发现一种出人意料的方法，只要轮流进行两步操作就可以了。
首先把三根柱子按顺序排成品字型，把所有的圆盘按从大到小的顺序放在柱子A上。
根据圆盘的数量确定柱子的排放顺序：若n为偶数，按顺时针方向依次摆放 A B C；
若n为奇数，按顺时针方向依次摆放 A C B。
（1）按顺时针方向把圆盘1从现在的柱子移动到下一根柱子，即当n为偶数时，若圆盘1在柱子A，则把它移动到B；
若圆盘1在柱子B，则把它移动到C；若圆盘1在柱子C，则把它移动到A。
（2）接着，把另外两根柱子上可以移动的圆盘移动到新的柱子上。
即把非空柱子上的圆盘移动到空柱子上，当两根柱子都非空时，移动较小的圆盘
这一步没有明确规定移动哪个圆盘，你可能以为会有多种可能性，其实不然，可实施的行动是唯一的。
（3）反复进行（1）（2）操作，最后就能按规定完成汉诺塔的移动。
*/
