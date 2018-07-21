/*
从n个不同元素中取出m个元素（m≤n）的组合数。
输入格式:
输入在一行中给出两个正整数m和n（m≤n），以空格分隔。

输出格式:
按照格式“result = 组合数计算结果”输出。题目保证结果在double类型范围内。

输入样例:
2 7
输出样例:
result = 21
*/
//排列组合问题。
//排列组合公式  递归的简单应用
#include <stdio.h>
#include<string.h>
#include<iostream>
#include <sstream>
using namespace std;
double fun(int n)
{   
    if(n<=1)  
        return 1;  
    return n*fun(n-1);  
}   
int main()
{  
    int m,n; 
	double result; 
    cin >> m >> n; 
    result=fun(n)/(fun(m)*fun(n-m));  
    cout << "result = "<< result << endl;  
    return 0;  
}  
  

