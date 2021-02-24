#include<stdio.h>
#include<string.h>
#define MAX 50
int stack[MAX],top=-1;
void push(int ele)
{
	stack[++top]=ele;
}
int pop()
{
	return stack[top--];
}
int isEmpty()
{
	if(top==-1)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}
int pair(char open,char close)
{
	if(open=='('&& close==')')
	{
		return 1;
	}
	else if(open=='{' && close=='}')
	{
		return 1;
	}
	else if(open=='['&& close==']')
	{
		return 1;
	}
	else
    {
        return 0;
    }
}
int balanced_paranthesis(char exp[])
{
	int len=strlen(exp);
	int i;
	for(i=0;i<len;i++)
	{
		if(exp[i]=='('||exp[i]=='['||exp[i]=='{')
		{
			push(exp[i]);
		}
		else if(exp[i]==')'||exp[i]==']'||exp[i]=='}')
		{
			if(!(pair(stack[top],exp[i])))
			{
				return 0;
			}
			else
			{
				pop();
			}
		}
	}
	return isEmpty();
}
int main()
{
	char exp[MAX];
	printf("Enter any expression : ");
	gets(exp);
	if(balanced_paranthesis(exp))
	{
		printf("The paranthesis are balanced\n");
	}
	else
	{
		printf("The paranthesis are not balanced\n");
	}
	return 0;
}
