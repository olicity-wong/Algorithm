/*
问题描述： 括号匹配 对输入的括号串进行判断是否遵循数学上的括号的使用原则。

例如： (()) true ; ())( false ;

我们这里括号仅仅包括 () 和 {} 两种。

输入格式:
第一行给出n(n > 0 && n < 100000) , 代表输入的括号数量。接下来一行进行括号的输入。。

输出格式:
对输入的括号进行判断， 如果遵循数学上括号的使用原则，输出True , 否则输出False。

输入样例:
6
()}{()
输出样例:
False
*/

//匹配问题，压栈弹栈判断是否匹配
#include <stdio.h>
#include <stack>
#include <iostream>
using namespace std;
bool isMatch(char right,char left)  //判断左右括号是否匹配 
{
	if(right == ')')
	{
		right = '(';
		if(right == left)
			return true;
		return false;
	}
	else if(right == '}')
	{
		right = '{';
		if(right == left)
			return true;
		return false;
	}
}

int main()
{
	int n;
	char s;
	while(cin >> n)
	{
		stack<char> stk;
		int flag = 0;
		if(n % 2 != 0)    //奇数直接不符合条件 
		{
			flag = 1;
		}
			while(n--)
			{
				cin >> s;
				if(s == '('||s == '{')
					stk.push(s);
				else
				{
					if((!stk.empty()) && (isMatch(s,stk.top())))    //栈非空！！！ 
						stk.pop();
					else
					{
						flag = 1;
						break;
					}
				}
			}
		
		
		if((flag == 0)&&stk.empty())
			cout << "True" <<endl;
		else
			cout << "False" << endl;
		
	}
	return 0;	
}


/*
先进后出 
由系统自动分配。 例如，声明在函数中一个局部变量 int b; 系统自动在栈中为b开辟空间 。在 WINDOWS下，栈的大小是2M。
存取中，在栈上的数组比指针所指向的字符串(例如堆)快。 
push(): 向栈内压入一个成员；
pop(): 从栈顶弹出一个成员；
empty(): 如果栈为空返回true，否则返回false；
top(): 返回栈顶，但不删除成员；
size(): 返回栈内元素的大小；

*/
