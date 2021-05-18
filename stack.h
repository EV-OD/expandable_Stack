#include <limits.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

typedef struct Stack{
  int top;
  unsigned capacity;
  int* array;
} Stack;

Stack* createStack(unsigned capacity)
{
  Stack *stack = (Stack *) malloc(sizeof(Stack));
  stack->capacity = capacity;
  stack->top = -1;
  stack->array = (int *)malloc(stack->capacity * sizeof(int));
  return stack;
}

void increaseCapacity(Stack *stack,unsigned capacity)
{
  stack->capacity =  capacity;
  stack->array = (int *) realloc(stack->array, stack->capacity * sizeof(int));

}

void printStack(Stack *s)
{
  for(int i = 0;i<s->top + 1;i++)
  {
    printf("%d,",s->array[i]);
  }
  printf("\n");
}

int isFull(Stack *stack){
  return stack->top == stack->capacity - 1;
}

int isEmpty(Stack *stack){
  return stack->top == -1;
}

void push(Stack *stack, int item){
  if(isFull(stack)){
    increaseCapacity(stack,stack->capacity + 10);
  }
  stack->array[++stack->top] = item;
}



int pop(Stack *stack){
  if(isEmpty(stack)){
    return INT_MIN;
  }
  return stack->array[stack->top--];
}

