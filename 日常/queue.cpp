#include <queue> 
#include <iostream>
#include<iostream>
#include<functional>
#include<queue>
using namespace std;
struct node
{
    friend bool operator< (node n1, node n2)
    {
        return n1.priority < n2.priority;//"<"为从大到小排列，">"为从小打到排列
    }
    int priority;
    int value;
};
int main()
{
    const int len = 5;
    int i;
    int a[len] = {3,5,9,6,2};
    
    //示例1
    priority_queue<int> qi;//普通的优先级队列，按从大到小排序
    for(i = 0; i < len; i++)
        qi.push(a[i]);
    for(i = 0; i < len; i++)
    {
        cout<<qi.top()<<" ";
        qi.pop();
    }
    cout<<endl;
    
    //示例2
    priority_queue<int, vector<int>, greater<int> > qi2;//从小到大的优先级队列，可将greater改为less，即为从大到小
    for(i = 0; i < len; i++)
        qi2.push(a[i]);
    for(i = 0; i < len; i++)
    {
        cout<<qi2.top()<<" ";
        qi2.pop();
    }
    cout<<endl;
    
    //示例3
    priority_queue<node> qn;//必须要重载运算符
    node b[len];
    b[0].priority = 6; b[0].value = 1;
    b[1].priority = 9; b[1].value = 5;
    b[2].priority = 2; b[2].value = 3;
    b[3].priority = 8; b[3].value = 2;
    b[4].priority = 1; b[4].value = 4;
 
    for(i = 0; i < len; i++)
        qn.push(b[i]);
    cout<<"优先级"<<'\t'<<"值"<<endl;
    for(i = 0; i < len; i++)
    {
        cout<<qn.top().priority<<'\t'<<qn.top().value<<endl;
        qn.pop();
    }
    return 0;
}

/*
队列是一种容器适配器，它给予程序员一种先进先出(FIFO)的数据结构。
定义一个queue的变量     queue<int> q;
1.back() 返回一个引用，指向最后一个元素
2.empty() 如果队列空则返回真
3.front() 返回第一个元素
4.pop() 删除第一个元素
5.push() 在末尾加入一个元素
6.size() 返回队列中元素的个数

优先队列类似队列，但是在这个数据结构中的元素按照一定的断言排列有序。
优先队列容器与队列一样，只能从队尾插入元素，从队首删除元素。
但是它有一个特性，就是队列中最大的元素总是位于队首，
所以出队时，并非按照先进先出的原则进行，而是将当前队列中最大的元素出队。
这点类似于给队列里的元素进行了由大到小的顺序排序。
元素的比较规则默认按元素值由大到小排序，可以重载“<”操作符来重新定义比较规则。
定义一个priority_queue的变量     priority_queue<T> q;
定义一个从小到大优先级的优先队列	  priority_queue<T, vector<T>, greater<T> > q; 可将greater改为less，即为从大到小

1.empty() 如果优先队列为空，则返回真
2.pop() 删除第一个元素
3.push() 加入一个元素
4.size() 返回优先队列中拥有的元素的个数
5.top() 返回优先队列中有最高优先级的元素*****

*/




