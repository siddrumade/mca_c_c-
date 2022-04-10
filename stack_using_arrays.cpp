// Algorithm:
// 1. Algorithm for push operation:
// begin
// if top = n then stack full
// top = top + 1
// stack (top) : = item;
// end
// 2. Algorithm for pop operation:
// begin
// if top = 0 then stack empty;
// item := stack(top);
// top = top - 1;
// end;

#include <stdio.h>
int stack[100], i, j, choice = 0, n, top = -1;
void push();
void pop();
void show();
int main()
{
    printf("Enter the number of elements in the stack ");
    scanf("%d", &n);
    printf("***Stack operations using array***");
    printf("\n---------------------------------\n");
    while (choice != 4)
    {
        printf("Chose one from the below options...\n");
        printf("\n1.Push\n2.Pop\n3.Show\n4.Exit");
        printf("\n Enter your choice \n");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
        {
            push();
            break;
        }
        case 2:
        {
            pop();
            break;
        }
        case 3:
            {
                show();
                break;
            }
        case 4:
        {
            printf("Exiting....");
            break;
        }
        default:
        {
            printf("Please Enter valid choice ");
        }
        }
    }
    return 0;
}
void push()
{
    int val;
    if (top == n)
        printf("\n Overflow");
    else
    {
        printf("Enter the value?");
        scanf("%d", &val);
        top = top + 1;
        stack[top] = val;
    }
}
void pop()
{
    if (top == -1)
        printf("Underflow");
    else
        top = top - 1;
}
void show()
{
    for (i = top; i >= 0; i--)
    {
        printf("%d\n", stack[i]);
    }
    if (top == -1)
    {
        printf("Stack is empty");
    }
}