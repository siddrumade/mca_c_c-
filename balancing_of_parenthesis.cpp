// Algorithm:
// Algorithm to check balanced parenthesis
// Step 1: Initialize a character stack. Set top pointer of stack to -1.
// Step 2: Find length of input string using strlen function and store it in an
// integer variable "length".
// Step 3: Using a for loop, traverse input string from index 0 to length-1.
// Step 4: a.If current character is open parenthesis, then push it inside stack.
// b. If current character is closing parenthesis, then pop a character
// from stack.
// c. If stack is empty, then input string is invalid, it means there is
// no matching opening parenthesis corresponding to closing parenthesis.
// Step 5: After complete traversal of input string, If stack is empty then
// input expression is a Valid expression otherwise Invalid.

#include <string.h>
#include <iostream>
#define MAX 20
struct stack
{
    char stk[MAX];
    int top;
} s;
void push(char item)
{
    if (s.top == (MAX - 1))
        printf("Stack is Full\n");
    else
    {
        s.top = s.top + 1; // Push the char and increment top
        s.stk[s.top] = item;
    }
}
void pop()
{
    if (s.top == -1)
    {
        printf("Stack is Empty\n");
    }
    else
    {
        s.top = s.top - 1; // Pop the char and decrement top
    }
}
int main()
{
    char exp[MAX];
    int i = 0;
    s.top = -1;
    printf("\nINPUT THE EXPRESSION : ");
    scanf("%s", exp);
    for (i = 0; i < strlen(exp); i++)
    {
        if (exp[i] == '(' || exp[i] == '[' || exp[i] == '{')
        {
            push(exp[i]); // Push the open bracket
            continue;
        }
        else if (exp[i] == ')' || exp[i] == ']' || exp[i] == '}') // If a closed bracket is encountered
        {
            if (exp[i] == ')')
            {
                if (s.stk[s.top] == '(')
                {
                    pop(); // Pop the stack until closed bracket isfound
                }
                else
                {
                    printf("\nUNBALANCED EXPRESSION\n");
                    break;
                }
            }
            if (exp[i] == ']')
            {
                if (s.stk[s.top] == '[')
                {
                    pop(); // Pop the stack until closed bracket is found
                }
                else
                {
                    printf("\nUNBALANCED EXPRESSION\n");
                    break;
                }
            }
            if (exp[i] == '}')
            {
                if (s.stk[s.top] == '{')
                {
                    pop(); // Pop the stack until closed bracket is found
                }
                else
                {
                    printf("\nUNBALANCED EXPRESSION\n");
                    break;
                }
            }
        }
    }
    if (s.top == -1)
    {
        printf("\nBALANCED EXPRESSION\n"); // Finally if the stack is empty, display that the expression is balanced
    }
}
