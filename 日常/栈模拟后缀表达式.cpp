/*
读入一个只包含 +, -, *, / 的非负整数计算表达式，计算该表达式的值。 
Input
测试输入包含若干测试用例，每个测试用例占一行，每行不超过200个字符，整数和运算符之间用一个空格分隔。没有非法表达式。当一行中只有0时输入结束，相应的结果不要输出。 
Output
对每个测试用例输出1行，即该表达式的值，精确到小数点后2位。 
Sample Input
1 + 2
4 + 2 * 5 - 7 / 11
0
*/

//用栈模拟后缀表达式

#include<iostream>
#include<stdio.h>
#include<stack>
#include<cstring>
using namespace std;
char str[205]; 

int change(char c)  
{  
    if(c=='+')      return 1;  
    if(c=='-')      return 2;  
    if(c=='*')      return 3;  
    if(c=='/')      return 4;  
    return -1;  
}  

int cmp(int a,int b)  
{  
    if(a==1||a==2)  a=1;  
    else a=2;  
    if(b==1||b==2)  b=1;  
    else b=2;  
    
    if(a>=b)  
        return 1;  
    return 0;  
  
}  
void cal()
{
	stack<double>a;  //后缀结果栈 
    stack<int>b; // 运算符栈  
    int i,len=strlen(str);
	double s;
	 
    for(i=0;i<len;i++)  
    {  
        if(str[i]==' ')  
            continue;  
        if(str[i]>='0'&&str[i]<='9') //数字 
        {  
            s=0;  
            while(str[i]>='0'&&str[i]<='9')  
            {  
                s=s*10+str[i]-'0';  
                i++;  
            }  
            a.push(s); 
        }  
        if(str[i]=='+'||str[i]=='-'||str[i]=='*'||str[i]=='/')  
        {  
            int temp;  
            temp=change(str[i]);  
            if(b.empty())  
            {  
                b.push(temp);  
                continue;  
            }  
            else  
            {  
                int t=b.top();//运算符栈里的优先级大于当前的，将运算符栈里的压入到后缀  
                while(cmp(t,temp))             
                {     
					double a1=a.top(); a.pop();  //弹出2个操作数 
                    double b1=a.top(); a.pop();  
                    
                    int c=b.top(); b.pop();//弹出运算符栈里的运算符  
                      
                    switch(c)
					{
                    	case 1:   
                        	a.push(a1+b1);
							break;
						case 2:  
                        	a.push(b1-a1); 
                        	break;
						case 3: 
                        	a.push(a1*b1);
                        	break;
						case 4:   
                        	a.push(b1/a1);
							break;
                    }
                    
                    if(b.empty()) //如果这样写要判断为空否  
                        break;  
                    else  		  //否则继续比较运算符栈顶运算 
                    	t=b.top();  
          
                }  
                b.push(temp); // 将这个运算符压入运算符栈    
            }  
              
        }  
    }  
    
    while(!b.empty())  
    {  
        double a1=a.top(); a.pop();  //弹出2个操作数 
        double b1=a.top(); a.pop();  
                    
        int c=b.top(); b.pop();//弹出运算符栈里的运算符  
                      
        switch(c)
		{
            case 1:   
           		a.push(a1+b1);
				break;
			case 2:  
                a.push(b1-a1); 
                break;
			case 3: 
                a.push(a1*b1);
                break;
			case 4:   
                a.push(b1/a1);
				break;
        } 
    }  
    printf("%.2lf\n",a.top());    
}

int main()
{
	while(gets(str),strcmp(str,"0"))
	{
		cal();
	}
	return 0;
} 
