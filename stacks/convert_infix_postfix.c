#include<stdio.h>
#include<string.h>
#define MAX 100
char stack[MAX];
int top=-1;
void push(char item)
{
        if(top>MAX-1)
            printf("Stack overflow\n");
        else
            stack[++top]=item;
}
char pop()
{
    char item;
    item=stack[top];
    top--;
    return item;
}
int is_operator(char item)
{
    if(item=='^'||item=='%'||item=='*'||item=='+'||item=='-'||item=='/')
        return 1;
    else
        return 0;
}
int precedence(char item)
{
    if(item=='^')
        return 3;
    else if(item=='*'||item=='/')
        return 2;
    else if(item=='+'||item=='-')
        return 1;
    else
        return 0;
}
int main()
{
    char infix[MAX],postfix[MAX],item,temp;
    int i=0,j=0;
    printf("Enter the infix expression : ");
    gets(infix);
    while((item=infix[i])!='\0')
    {
        if(item=='(')
        {
            push(item);
        }
        else if((item>='A'&&item<='z')||(item>='a'&&item<='z'))
        {
            postfix[j]=item;
            j++;
        }
        else if(is_operator(item)==1)
        {
            temp=pop();
            while(is_operator(temp)==1&& (precedence(temp)>=precedence(item)))
            {
                postfix[j]=temp;
                j++;
                temp=pop();
            }
            push(temp);
            push(item);
        }
        else if(item==')')
        {
            temp=pop();
            while(temp!='(')
            {
                postfix[j]=temp;
                j++;
                temp=pop();
            }
        }
        else
        {
            printf("Invalid expression\n");
        }
        i++;
    }
    while(top>-1)
    {
        postfix[j]=pop();
        j++;
    }
    postfix[j]='\0';
    printf("Postfix expression : ");
    puts(postfix);
    return 0;
}
