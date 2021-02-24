#include<stdio.h>
#define MAX 50
int stack[MAX],top=-1;
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
    int val,n,i,arr[MAX];
    printf("Enter the no.of elements into the stack : ");
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        printf("Enter the value into the stack : ");
        scanf("%d",&arr[i]);
    }
    for(i=0;i<n;i++)
    {
        push(arr[i]);
    }
    for(i=0;i<n;i++)
    {
        val=pop();
        arr[i]=val;
    }
    printf("The elements of the stack after reversing the stack : \t");
    for(i=0;i<n;i++)
    {
        printf("%d\t",arr[i]);
    }
    return 0;
