#include <stdio.h>
#include "stack.h"

int main(void) {
  printf("Hello World\n");
  Stack *s = createStack(10);
  push(s,10);
  push(s,3);
  push(s,5);
  push(s,10);
  push(s,3);
  push(s,5);
  push(s,10);
  push(s,3);
  push(s,5);
  push(s,10);
  increaseCapacity(s, s->capacity + 10);
  push(s,9);
  printStack(s);
  return 0;
}
