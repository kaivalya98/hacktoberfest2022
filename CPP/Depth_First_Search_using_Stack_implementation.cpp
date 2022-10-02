#include <bits/stdc++.h>
using namespace std;
struct stackStructure
{
    int top = -1;
    int size = 7;
    int *arr; // for intializing memory of the stack.
};

void createStack(stackStructure *S)
{
    S->arr = new int[S->size];
}

bool isFull(stackStructure *ptr)
{
    if (ptr->top == ptr->size - 1)
    {
        return true;
    }
    return false;
}

bool isEmpty(stackStructure *ptr)
{
    if (ptr->top == -1)
    {
        return true;
    }
    return false;
}

int push(stackStructure *ptr, int value)
{
    if (isFull(ptr))
    {
        cout << "Stack Overflow!!!!!!!!" << endl;
        return -1;
    }
    else
    {
        if (ptr->top == -1)
        {
            ptr->top = 0;
            ptr->arr[ptr->top] = value;
        }
        else
        {
            ptr->top++;
            ptr->arr[ptr->top] = value;
        }
    }
}

int pop(stackStructure *ptr)
{
    int value = -1;
    if (isEmpty(ptr))
    {
        cout << "Stack UnderFlow!!!!!!!!" << endl;
    }
    value = ptr->arr[ptr->top];
    ptr->top--;
    return value;
}

int main()
{
    // I am doing it for the seven nodes.

    int i = 2;
    stackStructure ptr;
    int visited[7] = {0, 0, 0, 0, 0, 0, 0};
    createStack(&ptr);

    int graphmapping[7][7] = {
        {0, 1, 1, 1, 0, 0, 0},
        {1, 0, 0, 1, 0, 0, 0},
        {1, 1, 0, 1, 1, 0, 0},
        {1, 0, 1, 0, 1, 0, 0},
        {0, 0, 1, 1, 0, 1, 1},
        {0, 0, 0, 0, 1, 0, 0},
        {0, 0, 0, 0, 1, 0, 0}};

    cout << i << " "; // The nodes which is visited shall be printed here.
    push(&ptr, i);
    visited[i] = 1; // for recording the value whether the given value is visited or not.
    while (!isEmpty(&ptr))
    {
        int node = pop(&ptr);
        for (int i = 0; i < 7; i++)
        {
            if (graphmapping[node][i] == 1 && visited[i] == 0)
            { // exploration proceduree is done here etc.
                cout << i << " ";
                visited[i] = 1;
                push(&ptr, i);
            }
        }
    }

    return 0;
}