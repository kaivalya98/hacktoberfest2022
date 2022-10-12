struct Node
{
    int data;               
    struct Node* next;    
};
 
int nodesCount;
 
void push(struct Node **top, int x)      
{
    struct Node* node = NULL;
    node = (struct Node*)malloc(sizeof(struct Node));
  if (!node)
    {
        printf("Heap Overflow\n");
        exit(-1);
    }
printf("Inserting %d\n", x);
 node->data = x;
 node->next = *top;
 *top = node;
 nodesCount += 1;
}
 int isEmpty(struct Node* top) {
    return top == NULL;
}
int peek(struct Node *top)
{
     if (!isEmpty(top)) {
        return top->data;
    }
    else {
        printf("The stack is empty\n");
        exit(EXIT_FAILURE);
    }
}
 
int pop(struct Node** top)        
{
    struct Node *node;
 
    if (*top == NULL)
    {
        printf("Stack Underflow\n");
        exit(EXIT_FAILURE);
    }
  int x = peek(*top);
  printf("Removing %d\n", x);
 node = *top;
 *top = (*top)->next;
 nodesCount -= 1;
   free(node);
 return x;
}
 int size() {
    return nodesCount;
}
int main(void)
{
    struct Node* top = NULL;
    push(&top, 1);
    push(&top, 2);
    push(&top, 3);
    printf("The top element is %d\n", peek(top));
    pop(&top);
    pop(&top);
    pop(&top);
    if (isEmpty(top)) {
    printf("The stack is empty\n");
 }
    else {
        printf("The stack is not empty\n");
    }
 return 0;
}
