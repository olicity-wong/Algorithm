/*
请编写程序输出前n个正整数的全排列（n<10），并通过9个测试用例（即n从1到9）观察n逐步增大时程序的运行时间。

输入格式:
输入给出正整数n（<10）。

输出格式:
输出1到n的全排列。每种排列占一行，数字间无空格。排列的输出顺序为字典序，
输入样例：
3
输出样例：
123
132
213
231
312
321
*/
#include<iostream>  
#include<algorithm>  
using namespace std;  
int main()  
{  
    int n;  
    cin>>n;  
    int a[100];  
    for(int i = 1; i <= n;i++)  
    {  
        a[i-1] = i;  
    }  
    do  
    {  
        for(int i = 0; i < n;i++)  
        {  
            cout<<a[i];  
        }  
        cout<<endl;  
    }  
    while (next_permutation(a,a+n));  
    return 0;  
} 

//全排列 
