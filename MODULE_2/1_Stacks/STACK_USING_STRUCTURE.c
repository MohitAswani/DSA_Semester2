#include <stdio.h>
#define size 5
typedef struct structure_for_stack
{
    int sarr[size];
    int top;
} STACK;
STACK s;
void push(int);
int isFull();
void print();
void pop();
void peek();
int main()
{
    s.top = -1;
    print();
    push(69);
    print();
    pop();
    print();
    return 0;
}
void peek()
{
    if (s.top == -1)
    {
        printf("UNDERFLOW\n");
    }
    else
    {
        printf("CURRENT ELEMENT:%d\n", s.sarr[s.top]);
    }
}
int isFull()
{
    if (s.top == size - 1)
    {
        return 1;
    }
    else
        return 0;
}
void push(int data)
{
    if (!isFull())
    {
        s.top += 1;
        s.sarr[s.top] = data;
    }
    else
        printf("STACK IS FULL\n");
}
void print()
{
    if (s.top != -1)
    {
        printf("STACK: ");
        for (int i = 0; i <= s.top; i++)
        {
            printf("%d ", s.sarr[i]);
        }
        printf("\n");
    }
    else
    {
        printf("STACK IS EMPTY\n");
    }
}
void pop()
{
    if (s.top == -1)
    {
        printf("YOU CANNOT POP THE DATA SINCE THE STACK IS EMPTY");
        return;
    }
    s.top--;
}