// Algorithm:
// Step 1:Create a stack to store operands (or values).
// Step 2:Scan the given expression and do following for every scanned
// element.
// a) If the element is a number, push it into the stack.
// b) If the element is an operator, pop operands for the operator from
// stack. Evaluate the operator and push the result back to the stack.
// Step 3:When the expression is ended, the number in the stack is the final
// answer.

#include <stdio.h>
#include <string.h>
#include <iostream>
#include <cstdio>
#include <cstring>

#define MAX 50           // max size defined
int stack[MAX];          // a global stack
char post[MAX];          // a global postfix stack
int top = -1;            // initializing top to -1
void pushstack(int tmp) // definiton for push
{
    top++;                              // incrementing top
    stack[top] = (int)(post[tmp] - 48); // type casting the string to its integer value
}
void evaluate(char c) // evaluate function
{
    int a, b, ans;     // variables used
    a = stack[top];    // a takes the value stored in the top
    stack[top] = '\0'; // make the stack top NULL as its a string
    top--;             // decrement top's value
    b = stack[top];    // put the value at new top to b
    stack[top] = '\0'; // make it NULL
    top--;             // decrement top
    switch (c)         // check operator been passed to evaluate
    {
    case '+': // addition
        ans = b + a;
        break;
    case '-': // subtraction
        ans = b - a;
        break;
    case '*': // multiplication
        ans = b * a;
        break;
    case '/': // division
        ans = b / a;
        break;
    case '^': // power
        ans = b ^ a;
        break;
    default:
        ans = 0; // else 0
    }
    top++;            // increment top
    stack[top] = ans; // store the answer at top
}


void pushstack(int tmp); // push function
void evaluate(char c);   // calculate function
int main()
{
    int i, l;
    // clrscr();
    printf("Insert a postfix notation :: ");
    // gets(post);       // getting a postfix expression
    std::fgets(post, sizeof( post ), stdin );
    //post[ std::strcspn( post, "\n" ) ] = '\0';
    l = strlen(post); // string length
    for (i = 0; i < l; i++)
    {
        if (post[i] >= '0' && post[i] <= '9')
        {
            pushstack(i); // if the element is a number push it
        }
        if (post[i] == '+' || post[i] == '-' || post[i] == '*' ||
            post[i] == '/' || post[i] == '^') // if element is an operator
        {
            evaluate(post[i]); // pass it to the evaluate
        }
    } // print the result from the top
    printf("\n\nResult :: %d", stack[top]);
    return 0;
}
