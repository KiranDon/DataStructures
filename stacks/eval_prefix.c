#include<stdio.h>
#include<string.h>
#include<ctype.h>
#define SIZE 50
int stack[SIZE],top=-1;
void push(int ele)
{
	stack[++top]=ele;
}
int pop()
{
	return (stack[top--]);
}
int main()
{
	char prefix[SIZE],ch;
	int len,i,op1,op2;
	printf("Enter the prefix expression : ");
	gets(prefix);
	len=strlen(prefix);
	for(i=len-1;i>=0;i--)
	{
		if((ch=prefix[i])!='\0')
		{
			if(isdigit(ch))
			{
				push(ch-'0');
			}
			else
			{
				op1=pop();
				op2=pop();
				switch(ch)
				{
					case '+' : push(op1+op2);
								break;
					case '-' : push(op1-op2);
								break;
					case '*' : push(op1*op2);
								break;
					case '/' : push(op1/op2);
								break;
					case '%' : push(op1%op2);
								break;
				}
			}
		}
	}
	printf("Given prefix expression : %s\n",prefix);
	printf("Result : %d\n",stack[top]);
	return 0;
}
								
