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
//全排列 

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

/*
next_permutation

函数实现原理如下：
在当前序列中，从尾端往前寻找两个相邻元素，前一个记为*i，后一个记为*ii，并且满足*i < *ii。
然后再从尾端寻找另一个元素*j，如果满足*i < *j，即将第i个元素与第j个元素对调，
并将第ii个元素之后（包括ii）的所有元素颠倒排序，即求出下一个序列了。

在STL中，除了next_permutation外，还有一个函数prev_permutation，两者都是用来计算排列组合的函数。前者是求出下一个排列组合，而后者是求出上一个排列组合。
prev_permutation实现类似，就是反向查找
虽然最后一个排列没有下一个排列，用next_permutation会返回false，但是使用了这个方法后，序列会变成字典序列的第一个，如cba变成abc。prev_permutation同理。

复杂度
最好的情况为pn的最右边的2个元素构成一个最小的增序子集，交换次数为1，复杂度为O(1)，
最差的情况为1个元素最小，而右面的所有元素构成减序子集，这样需要先将第1个元素换到最右，然后反转右面的所有元素。交换次数为1+(n-1)/2，复杂度为O(n)。
因为各种排列等可能出现，所以平均复杂度即为O(n)。

代码实现
#include <algorithm>
#include <iostream>
#include <string>
using namespace std;
//主函数，算法详见相关说明
int main(void) {
    //循环处理输入的每一个字符串
    for (string str; cin >> str;) {
        if (str.empty()) {
            continue;
        }
        //如果字符串只有1个字符，则直接输出结束
        if (str.length() <= 1) {
            cout << "No more Permutation" << endl;
        }
        //iPivot为右边最大减序子集左边相邻的一个元素
        string::iterator iPivot = str.end(), iNewHead;
        //查找右边最大的减序子集
        for (--iPivot; iPivot != str.begin(); --iPivot) {
            if (*(iPivot - 1) <= *iPivot ) {
                break;
            }
        }
        //如果整个序列都为减序，则重排结束。
        if (iPivot == str.begin()) {
            cout << "No more Permutation" << endl;
        }
        //iPivot指向子集左边相邻的一个元素
        iPivot--;
        //iNewHead为仅比iPivot大的元素，在右侧减序子集中寻找
        for (iNewHead = iPivot + 1; iNewHead != str.end(); ++iNewHead) {
            if (*iNewHead < *iPivot) {
                break;
            }
        }
        //交换iPivot和iNewHead的值，但不改变它们的指向
        iter_swap(iPivot, --iNewHead);
        //反转右侧减序子集，使之成为最小的增序子集
        reverse(iPivot + 1, str.end());
        //本轮重排完成，输出结果
        cout << str << endl;
    }
    return 0;
}
*/
