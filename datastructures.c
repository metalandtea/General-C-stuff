#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include "error_msgs.h"

#define MAX_STACK_SIZE 250

///////////////////////////////
///         Stack           ///
///////////////////////////////

typedef struct{
    int top;
    int contents[MAX_STACK_SIZE];
} Stack;

//void stack_initialize(); // Initialize a stack with a size
bool stackIsFull();
void stackPush(); // push to a stack
int stackPop(); //pop from stack
void stackPeek(); // show a stack

bool stackIsFull(Stack* _stack){
    if (_stack->top >= MAX_STACK_SIZE){
        return true;
    }
    return false;
}

void stackPush(Stack* _stack, int _element){
    bool stack_full = stackIsFull(_stack);
    if (stack_full == true){
        throwError(ERR_DS_FULL);
        return;
    }

    _stack->top++;
    _stack->contents[_stack->top] = _element;
}

int stackPop(Stack* _stack){
    bool stack_full = stackIsFull(_stack);
    if (_stack->top < 0){
        throwError(ERR_DS_EMPTY_ON_CALL);
    }

    _stack->top--;
    return _stack->contents[_stack->top+1];
}

void stackPeek(Stack* _stack){
    if (_stack->top < 0){
        throwError(ERR_DS_EMPTY_ON_CALL);
    }
    printf("%i\n", _stack->contents[_stack->top]);
}

void stackInit(Stack* _stack){
    _stack->top = -1;
}

//////////////////////////////

int main(){

    Stack instruction_stack;
    Stack* ptr_stack = &instruction_stack;
    stackInit(ptr_stack);
    
    int i = 0;
    while (i<20){
        stackPush(ptr_stack, 32);
        stackPeek(ptr_stack);
        i++;
    }

    return 0;
}
