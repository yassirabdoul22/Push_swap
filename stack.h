# ifndef STACK_H
#define STACK_H

#include <stdlib.h>
#include<stdio.h>


typedef struct  stack{
    int element;
    struct stack *next;
}stack;




#endif