/*
设已知有两个堆栈S1和S2，请用这两个堆栈模拟出一个队列Q。

所谓用堆栈模拟队列，实际上就是通过调用堆栈的下列操作函数:

int IsFull(Stack S)：判断堆栈S是否已满，返回1或0；
int IsEmpty (Stack S )：判断堆栈S是否为空，返回1或0；
void Push(Stack S, ElementType item )：将元素item压入堆栈S；
ElementType Pop(Stack S )：删除并返回S的栈顶元素。
实现队列的操作，即入队void AddQ(ElementType item)和出队ElementType DeleteQ()。

输入格式:
输入首先给出两个正整数N1和N2，表示堆栈S1和S2的最大容量。随后给出一系列的队列操作：A item表示将item入列（这里假设item为整型数字）；D表示出队操作；T表示输入结束。

输出格式:
对输入中的每个D操作，输出相应出队的数字，或者错误信息ERROR:Empty。如果入队操作无法执行，也需要输出ERROR:Full。每个输出占1行。

输入样例:
3 2
A 1 A 2 A 3 A 4 A 5 D A 6 D A 7 D A 8 D D D D T
输出样例:
ERROR:Full
1
ERROR:Full
2
3
4
7
8
ERROR:Empty
*/




/*
栈只有出栈入栈的操作，要实现队列的效果，输出队头的元素，
必须将一个栈里的全部元素出栈，并入栈到另一个栈，最后出栈这个栈的栈顶元素，即得到队头元素。
所以有两个栈，我们可以把一个栈作为接受栈，另一个作为输出栈。
*/
#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <string.h>
#include <stack>
using namespace std;
int main() 
{  
	stack<int> in,out;
	int n,m;
	cin >> n >> m;
	
	if(n > m)
		n = m;		//取最小的，俩栈平衡 
	
	char a;
	int b;
	while(cin>>a)
	{
		if(a == 'T')	//T结束 
		{
			break;
		}
		
		else if(a == 'A')	//A入队，操作输入栈 
		{
			cin >> b;
			if(in.size() == n)	//输入栈满了，弹到输出栈 
			{
				//cout << in.size() << "**" << endl;
				if(out.size() > 0)	//输出栈必须为空 
				{
					cout<<"ERROR:Full"<<endl;
					continue;
				}
				else		//弹到输出栈，输出栈满 
				{	
					for(int i = 0; i < n; i++)
					{
						out.push(in.top());
						in.pop();
					}	
				}	
			}
			
			if(in.size() < n)	//输入栈未满，压栈 
			{
				in.push(b);
			}
			else		//输入输出栈都满 
			{
				cout << "ERROR:Full" << endl;
				continue;
			}
		}
		else if(a == 'D')	//D出队，操作输出栈 
		{
			if(out.size() == 0)
			{
				if(in.size() == 0)	//输出输入栈都为空，栈中无元素 
				{
					cout<<"ERROR:Empty"<<endl;
					continue;
				}
				int size_in = in.size();
				for(int i = 0; i < size_in; i++)	//输入栈弹到输出栈 
				{
					out.push(in.top());
					in.pop();
				}
			}
			cout<<out.top()<<endl;
			out.pop();
		} 
	}
    return 0;
}  
