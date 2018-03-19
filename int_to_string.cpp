/*
读入一个自然数n，计算其各位数字之和，用汉语拼音写出和的每一位数字。

输入格式：每个测试输入包含1个测试用例，即给出自然数n的值。这里保证n小于10100。

输出格式：在一行内输出n的各位数字之和的每一位，拼音数字间有1 空格，但一行中最后一个拼音数字后没有空格。

输入样例：
1234567890987654321123456789
输出样例：
yi san wu
*/

/*方法一 
使用栈完成sum各个位数的判断 
*/
#include <iostream>
#include <string>
#include <stack>
using namespace std;

int main()
{
 	string a;
 	string s[] = {"ling","yi","er","san","si","wu","liu","qi","ba","jiu"};
 	
 	while(cin >> a)
 	{
 		stack<int> stk;
 		//cout << a.length() << endl;
 		int sum = 0;
 		for(int i = 0; i < a.length(); i++)
 		{
            sum += a[i]-'0';
	 	}
	 	//cout << sum << endl;

		while(sum/10 != 0)
		{
			stk.push(sum%10);
			sum /= 10;
		}
		cout << s[sum];
		if(stk.size())
		{
			for(int i = 0; i < stk.size()+1; i++)
			{
				cout << " " << s[stk.top()];
				stk.pop();
			}
		}
		cout << endl;
	 	
	}
	return 0;
}

/*方法二 
标准库定义了三种类型字符串流：istringstream,ostringstream,stringstream
除了从iostream继承来的操作

1.sstream类型定义了一个有string形参的构造函数，

即：stringstream stream(s); 创建了存储s副本的stringstream对象,s为string类型对象

2.定义了名为str的成员，用来读取或设置stringstream对象所操纵的string值：

stream.str(); 返回stream中存储的string类型对象

stream.str(s); 将string类型的s复制给stream，返回void
*/

/*int 转 string类型 
string Int_to_String(int n)

{

ostringstream stream;

stream<<n;  //n为int类型

return stream.str();

}
*/
#include <iostream>
#include <string>
#include <sstream>
using namespace std;

int main()
{
 	string a;
 	string s[] = {"ling","yi","er","san","si","wu","liu","qi","ba","jiu"};
 	
 	while(cin >> a)
 	{
 		//cout << a.length() << endl;
 		int sum = 0;
 		for(int i = 0; i < a.length(); i++)
 		{
            sum += a[i]-'0';
	 	}
	 	//cout << sum << endl;
	 	
	 	stringstream ss;      
	 	ss << sum;
	 	string b = ss.str();
	 	
	 	for(int i = 0; i < b.length()-1; i++)
	 	{
             cout << s[b[i]-'0'] <<" ";
        }
        cout << s[b[b.length()-1]-'0'] << endl;
	}
	return 0;
}




