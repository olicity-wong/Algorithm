/*
请编写程序帮助研究人员统计每种树的数量，计算每种树占总数的百分比。

输入格式:
输入首先给出正整数N（≤100000），随后N行，每行给出卫星观测到的一棵树的种类名称。种类名称由不超过30个英文字母和空格组成（大小写不区分）。

输出格式:
按字典序递增输出各种树的种类名称及其所占总数的百分比，其间以空格分隔，保留小数点后4位。

输入样例:
29
Red Alder
Ash
Aspen
Basswood
Ash
Beech
Yellow Birch
Ash
Cherry
Cottonwood
Ash
Cypress
Red Elm
Gum
Hackberry
White Oak
Hickory
Pecan
Hard Maple
White Oak
Soft Maple
Red Oak
Red Oak
White Oak
Poplan
Sassafras
Sycamore
Black Walnut
Willow

输出样例:
Ash 13.7931%
Aspen 3.4483%
Basswood 3.4483%
Beech 3.4483%
Black Walnut 3.4483%
Cherry 3.4483%
Cottonwood 3.4483%
Cypress 3.4483%
Gum 3.4483%
Hackberry 3.4483%
Hard Maple 3.4483%
Hickory 3.4483%
Pecan 3.4483%
Poplan 3.4483%
Red Alder 3.4483%
Red Elm 3.4483%
Red Oak 6.8966%
Sassafras 3.4483%
Soft Maple 3.4483%
Sycamore 3.4483%
White Oak 10.3448%
Willow 3.4483%
Yellow Birch 3.4483%
*/
//简单的map插入与查询
 
#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<string.h>
#include<map>
using namespace std;
int main()
{
	map <string,int> m;
	map <string,int>::iterator iter;
	int n;
	cin >> n;
	int q = n;
	string s;
	getchar();
	while(n--)
	{
		getline(cin,s);
		m.insert(pair<string,int> (s,0));
		for(iter = m.begin(); iter != m.end();iter++)
		{
			if(iter->first == s)
			{
				iter->second += 1;
			}
		}
		/*
		for(iter = m.begin(); iter != m.end();iter++)
		{
			cout << iter->first << "---" << iter->second << endl;
		}
		*/
	}
	/*
	double sum = 0;
	for(iter = m.begin(); iter != m.end();iter++)
	{
		sum++;	
		//cout << q << "---"<< endl;
		//double p = iter->second / q * 100;
		//cout << iter->first << " ";
		//printf("%.6lf",p);	
		//cout << "%" << endl;
	}
	*/
	for(iter = m.begin(); iter != m.end();iter++)
	{
		//sum++;	
		//cout << q << "---"<< endl;
		double p = (double)iter->second / q * 100;
		cout << iter->first << " ";
		printf("%.4lf",p);	
		cout << "%" << endl;
	}
	//cout << sum;
	
	
	return 0;
}

//上面这种方法 插入时，采用的map.insert(pair<string,int> (key,value))的方式，每次插入时都得遍历一次map数组，超时。
//下面这种则是直接利用数组的方式插入。 
 
#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<string.h>
#include<map>
using namespace std;
int main()
{
	map <string,int> m;
	map <string,int>::iterator iter;
	int n;
	cin >> n;
	int q = n;
	string s;
	getchar();
//	memset(m,0,sizoef(m));
	while(n--)
	{
		getline(cin,s);
		m[s]++; 
		/*
		m.insert(pair<string,int> (s,0));
		for(iter = m.begin(); iter != m.end();iter++)
		{
			if(iter->first == s)
			{
				iter->second += 1;
			}
		}
		*/
		
	}
	
	for(iter = m.begin(); iter != m.end();iter++)
	{
		//sum++;	
		//cout << q << "---"<< endl;
		double p = (double)iter->second / q * 100;
		cout << iter->first << " ";
		printf("%.4lf",p);	
		cout << "%" << endl;
	}
	//cout << sum;
	
	
	return 0;
}
 
/*
Map是STL的一个关联容器，它提供一对一
（其中第一个可以称为关键字，每个关键字只能在map中出现一次，第二个可能称为该关键字的值）
的数据 处理能力，由于这个特性，它完成有可能在我们处理一对一数据的时候，在编程上提供快速通道。
map内部数据的组织，map内部自建一颗红黑树(一 种非严格意义上的平衡二叉树),
这颗树具有对数据自动排序的功能，所以在map内部所有的数据都是有序的.
自动建立Key － value的对应
它的特点是增加和删除节点对迭代器的影响很小
对于迭代器来说，可以修改实值，而不能修改key。

定义：map<int,string> m;   

数据的插入 
1.map.insert(pair<int, string>(key, value));
2.map.insert(map<int, string>::value_type (key, value));  
3. map[key] = value;  


map的大小  map.size();


map的遍历 
1.前向迭代器
map<int, string>::iterator iter;  
for(iter = map.begin(); iter != map.end();iter++)
	cout<<iter->first<<"  "<<iter->second<<endl;  
2.反向迭代器 
map<int, string>::reverse_iterator iter;
for(iter = map.rbegin(); iter != map.rend(); iter++)  
  	cout<<iter->first<<"  "<<iter->second<<endl;  
3.数组
int nSize = map.size();  
此处应注意，应该是 for(int nindex = 1; nindex <= nSize; nindex++)  
而不是 for(int nindex = 0; nindex < nSize; nindex++)  
for(int nindex = 1; nindex <= nSize; nindex++)  
    cout<<map[nindex]<<endl;  	


map的查询
1.count:其缺点是无法定位数据出现位置,由于map的特性，一对一的映射关系，就决定了count函数的返回值只有两个，要么是0，要么是1，出现的情况，当然是返回1了
2.find:它返回的一个迭代器，当数据出现时，它返回数据所在位置的迭代器，如果map中没有要查找的数据，它返回的迭代器等于end函数返回的迭代器。
		查找map中是否包含某个关键字条目用find()方法，传入的参数是要查找的key，
		在这里需要提到的是begin()和end()两个成员，分别代表map对象中第一个条目和最后一个条目，这两个数据的类型是iterator.
iter = map.find(1);  
if(iter != map.end())  
    cout<<"Find, the value is "<<iter->second<<endl;  
else  
    cout<<"Do not Find"<<endl;  
    
3.lower_bound函数用法，这个函数用来返回要查找关键字的下界(是一个迭代器)
  upper_bound函数用法，这个函数用来返回要查找关键字的上界(是一个迭代器)
例如：map中已经插入了1，2，3，4的话，如果lower_bound(2)的话，返回的2，而upper-bound（2）的话，返回的就是3
Equal_range函数返回一个pair，pair里面第一个变量是Lower_bound返回的迭代器，pair里面第二个迭代器是Upper_bound返回的迭代器，如果这两个迭代器相等的话，则说明map中不出现这个关键字，


map删除数据 
移除某个map中某个条目用erase（）
iterator erase（iterator it);//通过一个条目对象删除
iterator erase（iterator first，iterator last）//删除一个范围
size_type erase(const Key&key);//通过关键字删除

clear()就相当于enumMap.erase(enumMap.begin(),enumMap.end());

这里要用到erase函数，它有三个重载了的函数，下面在例子中详细说明它们的用法 
  
       //如果要删除1,用迭代器删除  
map<int, string>::iterator iter;  
iter = map.find(1);  
mapStudent.erase(iter);  
//如果要删除1，用关键字删除  
int n = map.erase(1);//如果删除了会返回1，否则返回0  
//用迭代器，成片的删除  
//一下代码把整个map清空  
map.erase( map.begin(), mapStudent.end() );  
//成片删除要注意的是，也是STL的特性，删除区间是一个前闭后开的集合    


map中的swap用法
map中的swap不是一个容器中的元素交换，而是两个容器所有元素的交换。
map_1.swap(map_2);
 

排序   
map中的sort问题。map中的元素是自动按Key升序排序，所以不能对map用sort函数；
排序问题，STL中默认是采用小于号来排序的，关键字是int 型，它本身支持小于号运算，
在一些特殊情况，比如关键字是一个结构体，涉及到排序就会出现问题，因为它没有小于号操作，
insert等函数在编译的时候过不去，下面给出两个方法解决这个问题。

第一种：小于号重载
#include <iostream>  
#include <string>  
#include <map>  
using namespace std; 
typedef struct tagStudentinfo  
{  
    int  niD;  
    string strName;  
    bool operator < (tagStudentinfo const& _A) const  //这个函数指定排序策略，按niD排序，如果niD相等的话，按strName排序  
    {     
        if(niD < _A.niD)
			return true;  
        if(niD == _A.niD)  
  			return strName.compare(_A.strName) < 0;  
        return false;  
    }  
}Studentinfo, *PStudentinfo; //学生信息  
int main()  
{  
    int nSize;   //用学生信息映射分数  
    map<Studentinfo, int>mapStudent;  
    map<Studentinfo, int>::iterator iter;  
    Studentinfo studentinfo;  
    studentinfo.niD = 1;  
  	studentinfo.strName = "student_one";  
    mapStudent.insert(pair<Studentinfo, int>(studentinfo, 90));  
    studentinfo.niD = 2;  
    studentinfo.strName = "student_two";  
    mapStudent.insert(pair<Studentinfo, int>(studentinfo, 80));  
    for (iter=mapStudent.begin(); iter!=mapStudent.end(); iter++)  
        cout<<iter->first.niD<<' '<<iter->first.strName<<' '<<iter->second<<endl;  
    return 0;  
}  

第二种：仿函数的应用，这个时候结构体中没有直接的小于号重载
#include <iostream>  
#include <map>  
#include <string>  
using namespace std;  
typedef struct tagStudentinfo  
{  
    int  niD;  
	string  strName;  
}Studentinfo, *PStudentinfo; //学生信息  
class sort  
{  
public:  
    bool operator() (Studentinfo const &_A, Studentinfo const &_B) const  
    {  
        if(_A.niD < _B.niD)  
            return true;  
        if(_A.niD == _B.niD)  
            return _A.strName.compare(_B.strName) < 0;  
    return false;  
    }  
};  
int main()  
{   //用学生信息映射分数  
    map<Studentinfo, int, sort>mapStudent;  
    map<Studentinfo, int>::iterator iter;  
    Studentinfo studentinfo;  
    studentinfo.niD = 1;  
    studentinfo.strName = "student_one";  
    mapStudent.insert(pair<Studentinfo, int>(studentinfo, 90));  
    studentinfo.niD = 2;  
    studentinfo.strName = "student_two";  
    mapStudent.insert(pair<Studentinfo, int>(studentinfo, 80));  
    for (iter=mapStudent.begin(); iter!=mapStudent.end(); iter++)  
        cout<<iter->first.niD<<' '<<iter->first.strName<<' '<<iter->second<<endl;  
}  


map在空间上的特性
由于map的每个数据对应红黑树上的一个节点，这个节点在不保存你的数据时，是占用16个字节的，
一个父节点指针，左右孩子指针，还有一个枚举值（标示红黑的，相当于平衡二叉树中的平衡因子），很费内存


map的基本操作函数： 
     C++ maps是一种关联式容器，包含“关键字/值”对
     begin()         返回指向map头部的迭代器
     clear()        删除所有元素
     count()         返回指定元素出现的次数
     empty()         如果map为空则返回true
     end()           返回指向map末尾的迭代器
     equal_range()   返回特殊条目的迭代器对
     erase()         删除一个元素
     find()          查找一个元素
     get_allocator() 返回map的配置器
     insert()        插入元素
     key_comp()      返回比较元素key的函数
     lower_bound()   返回键值>=给定元素的第一个位置
     max_size()      返回可以容纳的最大元素个数
     rbegin()        返回一个指向map尾部的逆向迭代器
     rend()          返回一个指向map头部的逆向迭代器
     size()          返回map中元素的个数
     swap()           交换两个map
     upper_bound()    返回键值>给定元素的第一个位置
     value_comp()     返回比较元素value的函数
*/
