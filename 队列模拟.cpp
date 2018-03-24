/*
设某银行有A、B两个业务窗口，且处理业务的速度不一样，其中A窗口处理速度是B窗口的2倍 —— 即当A窗口每处理完2个顾客时，B窗口处理完1个顾客。给定到达银行的顾客序列，请按业务完成的顺序输出顾客序列。假定不考虑顾客先后到达的时间间隔，并且当不同窗口同时处理完2个顾客时，A窗口顾客优先输出。

输入格式:
输入为一行正整数，其中第1个数字N(≤1000)为顾客总数，后面跟着N位顾客的编号。编号为奇数的顾客需要到A窗口办理业务，为偶数的顾客则去B窗口。数字间以空格分隔。

输出格式:
按业务处理完成的顺序输出顾客的编号。数字间以空格分隔，但最后一个编号后不能有多余的空格。

输入样例:
8 2 1 3 9 4 11 13 15
输出样例:
1 3 2 9 11 4 13 15
*/

//队列模拟银行排队问题。比较恶心的是输出格式。 
//奇数存队列a，偶数存队列b；定义一个记录时间的变量t，当t为奇数队列a队头元素出队，偶数俩队列的队头元素都出队。 
#include <stdio.h>
#include <iostream>
#include <math.h>
#include <string.h>
#include <queue>
using namespace std;
int main()
{
	int n;
	int a;
	queue<int> q_a;
	queue<int> q_b;
	cin >> n;
	while(n--)
	{
		cin >> a;
		if(a%2 == 0)
			q_b.push(a);
		else
			q_a.push(a);
	}
	int t = 1;
	//int flag = 0;
	/*
	if(!q_a.empty())
	{
		cout << q_a.front();
		flag = 1;
	}
	*/
	
	while((!q_a.empty())&&(!q_b.empty()))
	{
	
		cout << q_a.front();
		q_a.pop();
		if(q_a.size()>0)
			cout << " ";
		else if((q_a.size()==0)&&(q_b.size()>0))
			cout << " ";
		if(t%2==0)
		{
			cout << q_b.front();
			q_b.pop();
			if(q_b.size()>0)
				cout << " ";
			else if((q_b.size()==0)&&(q_a.size()>0))
				cout << " ";
		}
		t++;
	}
	
	if(!q_a.empty())
	{
		for(int i = 0; (!q_a.empty()); i++)
		{
			cout << q_a.front();
			q_a.pop();
			if(q_a.size()>0)
				cout << " ";
			
		}
	}
	if(!q_b.empty())
	{
		for(int i = 0; (!q_b.empty()); i++)
		{
			cout <<q_b.front();
			q_b.pop();
			if(q_b.size()>0)
			cout << " ";
		
		}
	}
	return 0;
}
