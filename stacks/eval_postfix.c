#include<stdio.h>
#include<ctype.h>
#define SIZE 50
int stack[SIZE];
int top=-1;
void push(int ele)
{
	stack[++top]=ele;
}
int pop()
{
	return stack[top--];
}
int main()
{
	char postfix[SIZE],ch;
	int i=0,op1,op2;
	printf("Enter the postfix expression:\n");
	gets(postfix);
	while((ch=postfix[i])!='\0')
	{
		i++;
		if(isdigit(ch))
		{
			push(ch-'0');
		}
		else
		{
			op2=pop();
			op1=pop();
			switch(ch)
			{
				case '+': push(op1+op2);
						  break;
				case '-': push(op1-op2);
						  break;
				case '*': push(op1*op2);
						  break;
				case '/': push(op1/op2);
						  break;
				case '%': push(op1%op2);
						  break;
			}
		}
	}
	printf("Given postfix expression is : %s\n",postfix);
	printf("Result : %d\n",stack[top]);
	return 0;
}
