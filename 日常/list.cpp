/*
完成数组元素的移动功能：假设数组有n个元素，输入一个数x，把数组的第x个位置的元素删除了，后面的元素依次前进一个位置。 重复若干次这样的删除，得到最后的结果。

输入格式:
第一行包括一个整数n（1<=n<=100），表示数组元素的个数。 第二行输入n个数组元素，均为整数，用空格隔开。 第三行输入一个数k（1<=k<=100），表示要进行k次删除。 接下来k行，每行一个数x，表示要删除第x个元素。

输出格式:
输出经过k次删除后的数组，每两个元素之间用空格隔开。

输入样例:
10
1 2 3 4 5 6 7 8 9 10
4
3
2
4
6
输出样例:
1 4 5 7 8 10
*/
//从数组中删除元素并依次移动元素的位置，首先想到链式存储结构。使用stl库中的list数组
#include <iostream>
#include <string.h>
#include <algorithm>
#include <stdio.h>
#include <list>
using namespace std;

int main()
{
	list<int> l;
	int n;
	cin >> n;
	int a;
	for(int i = 0; i < n; i++)
	{
		cin >> a;
		l.push_back(a);    //push_front();
	}
	int k;
	cin >> k;
	list<int> :: iterator iter,iend;
	int b;
	while(k--)
	{	
		cin >> b;
		iter = l.begin();
		
		advance(iter,b-1);		//迭代器辅助函数。 使迭代器it偏移n，其中n为整数。
		
		l.erase(iter);
	}
	iend = l.end();
	iend--;
	for(iter = l.begin();iter!=iend;iter++)
		cout << *iter << " ";
	cout << *--l.end() <<endl;
	
	return 0;
}  
/*关于list数组的简单应用

 list就是数据结构中的双向链表(根据sgi stl源代码)，因此它的内存空间是不连续的,
 
 通过指针来进行数据的访问，这个特点使得它的随即存取变的非常没有效率，因此它没有提供[]操作符的重载。
 
 但由于链表的特点，它可以以很好的效率支持任意地方的删除和插入。
 
 需要大量的插入和删除，而不关心随即存取，则应使用list


**list中常用的函数

*list中的构造函数：

list() 声明一个空列表；

list(n) 声明一个有n个元素的列表，每个元素都是由其默认构造函数T()构造出来的

list(n,val) 声明一个由n个元素的列表，每个元素都是由其复制构造函数T(val)得来的

list(n,val) 声明一个和上面一样的列表

list(first,last) 声明一个列表，其元素的初始值来源于由区间所指定的序列中的元素


*begin()和end()：通过调用list容器的成员函数begin()得到一个指向容器起始位置的iterator，
				可以调用list容器的 end() 函数来得到list末端下一位置，
				相当于：int a[n]中的第n+1个位置a[n]，实际上是不存在的，不能访问，经常作为循环结束判断结束条件使用。

*push_back() 和push_front()：使用list的成员函数push_back和push_front插入一个元素到list中。
							其中push_back()从list的末端插入，而 push_front()实现的从list的头部插入。

*empty()：利用empty() 判断list是否为空。

*resize()： 如果调用resize(n)将list的长度改为只容纳n个元素，超出的元素将被删除，
			如果需要扩展那么调用默认构造函数T()将元素加到list末端。如果调用resize(n,val)，
			则扩展元素要调用构造函数T(val)函数进行元素构造，其余部分相同。

*clear()： 清空list中的所有元素。

*front()和back()： 通过front()可以获得list容器中的头部元素，通过back()可以获得list容器的最后一个元素。
					但是有一点要注意，就是list中元素是空的时候，这时候调用front()和back()会发生什么呢？实
					际上会发生不能正常读取数据的情况，但是这并不报错，那我们编程序时就要注意了，
					个人觉得在使用之前最好先调用empty()函数判断list是否为空。

*pop_back和pop_front()：通过删除最后一个元素，通过pop_front()删除第一个元素；
						序列必须不为空，如果当list为空的时候调用pop_back()和pop_front()会使程序崩掉。

*assign()：具体和vector中的操作类似，也是有两种情况，
			第一种是：l1.assign(n,val)将 l1中元素变为n个T(val）。
			第二种情况是：l1.assign(l2.begin(),l2.end())将l2中的从l2.begin()到l2.end()之间的数值赋值给l1。

*swap()：交换两个链表(两个重载)，一个是l1.swap(l2); 
		另外一个是swap(l1,l2)，都可能完成连个链表的交换。

*reverse()：通过reverse()完成list的逆置。

*merge()：合并两个链表并使之默认升序(也可改)，l1.merge(l2，greater<int>()); 
		 调用结束后l2变为空，l1中元素包含原来l1 和 l2中的元素，并且排好序，升序。
		 使用前必须使用sort排序。
		 其实默认是升序，greater<int>()可以省略，另外greater<int>()是可以变的，也可以不按升序排列。
		 //要想按照降序合并，可以使用reverse倒置
		 
*insert()：在指定位置插入一个或多个元素(三个重载)：
			l1.insert(l1.begin(),100); 在l1的开始位置插入100。
			l1.insert(l1.begin(),2,200); 在l1的开始位置插入2个100。	
			l1.insert(l1.begin(),l2.begin(),l2.end());在l1的开始位置插入l2的从开始到结束的所有位置的元素。
			
*erase()：删除一个元素或一个区域的元素(两个重载)
		  l1.erase(l1.begin()); 将l1的第一个元素删除。
		  l1.erase(l1.begin(),l1.end()); 将l1的从begin()到end()之间的元素删除。
		  l1.erase(iter)
*遍历：定义迭代器	list<int> :: iterator iter
		for(iter = l.begin();iter!=end;iter++)
 
*advance(iter,n) : 迭代器辅助函数,使迭代器it偏移n，其中n为整数。

*sort()：list.sort()  排序。
*/ 
