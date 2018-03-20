/*
形如2的n次方-1的素数称为梅森数（Mersenne Number）。

编写程序，对任一正整数n（n<20），输出所有不超过2的n次方-1的梅森数。

输入格式：
输入在一行中给出正整数n（n<20）。

输出格式：
按从小到大的顺序输出所有不超过2的n次方-1的梅森数，每行一个。如果完全没有，则输出“None”。

输入样例：
6
输出样例：
3
7
31
*/
#include<iostream>
#include<algorithm>
#include<cstdlib>
#include<string.h> 
#include <cmath>
#define Max 1050000
using namespace std;
int main()
{
	bool a[Max];	
	memset(a, true, sizeof(a));
    a[0] = a[1] = false;
    a[2] = true;
    for(int i=3; i<=Max; i++)
        a[i] = i % 2 == 0 ? false : true;
    int t = sqrt(Max);
    for(int j=3; j<=t; j++)
        if(a[j])
            for(int i=j*j; i<=Max; i+=j+j)
                a[i] = false;
    //true is prime        false is not prime
    int n;
    cin >> n;
    int c = 2;	
    for(int i = 1; i < n; i++)
    {
    	c *= 2;
		if(a[c-1])
    		cout << c-1 << endl;
	}
	return 0;
}
/*
涉及到2的20次方的问题。1048576。 
一开始想到数比较大，直接计算的时间复杂度为O(n * sqrt(n))，
可能会超时，想直接使用素数筛先打个表。
	t = 2;
    memset(a, -1, sizeof(a));//-1 is prime    0 is not prime
    while(t <= 1000)
    {
        for(i=2; i<=1000; i++)
        {
            if(i * t >= 1000)
                break;
            a[i*t] = 0;
        }
        t ++;
        while(t <= 1000 && a[t] == 0)
            t ++;
    } 
原理： 
开一个标记数组，全部初始化为true，0、1不是素数，直接从数组里划掉。 
从2开始，凡是2的倍数、且小于100000的，全部标记为false。 
再找2以后的、是素数的下一位数，是3 
从3开始，凡是3的倍数、且小于100000的，全部标记为false。 
再找3以后的、是素数的下一位数，是5 
从5开始，凡是5的倍数、且小于100000的，全部标记为false。 
这样循环，直到开始的位置大于100000，退出循环。 
这样，所有标记为TRUE的元素的下标全是素数。 

后来看到一种优化后的素数筛。
	memset(a, -1, sizeof(a));
    a[0] = a[1] = 0;
    a[2] = -1;
    for(i=3; i<=5000001; i++)
        a[i] = i % 2 == 0 ? 0 : -1;
    t = sqrt(5000000);
    for(j=3; j<=t; j++)
        if(a[j])
            for(i=j*j; i<=5000000; i+=j+j)
                a[i] = 0;
    //-1 is prime        0 is not prime
解释一下for(i=j*j; i<=5000000; i+=j+j)这个循环 
首先从i+=j+j说起： 
首先在上面已经把所有的偶数位全部标记为false，
所以，当a[j]能进入在这个for循环上面if的时候，j一定是个奇数。
i的起始值是j*j所以，起始值也一定是个奇数。 
所以i一下加两个j，因为加上一个j后一定是个偶数。 
在说起始值为什么为j*j： 
像上面所说，j是个奇数。 
对于j*(j - 1)，因为j - 1是个偶数，
所以j * (j - 1)一定是个偶数，其所在位置一定标为false。 
对于j * (j - 2k) （k = 1, 2, 3…）j - 2k 一定是个奇数，
对于任意的j * (j - 2k)，一定有这样一个循环标记过j * (j - 2k)：for(i=(j-2k) * (j - 2k); i<=5000000; i+= j + j)，
所以j * (j - 2k)一定是一个确定了的位置
*/
