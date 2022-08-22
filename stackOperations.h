#include "stack.h"

/**
 * Function that duplicates the first elements of the stack.
 */
void duplicate(STACK* s)
{
    stackElem element = pop(s); /*!< Stores the element. */
    push(s,element); /// Pushes once.
    push(s,element); /// Pushes twice.
}

/**
 * Function that swaps two elements in the stack.
 */
void swap(STACK *s)
{
    stackElem x = pop(s); /*!< Stores an element in "x". */
    stackElem y = pop(s); /*!< Stores the other in "y". */
    push (s, x); /// Pushes "x".
    push (s, y); /// Pushes "y".
}

/**
 * Function that rotates the elements at the top of the stack.
 */
void rotateElements(STACK *s)
{
    stackElem x = pop(s); /*!< Stores an element in "x". */
    stackElem y = pop(s); /*!< Stores other in "y". */
    stackElem z = pop(s); /*!< Stores the third in "z". */
    push(s, y); /// Pushes "y".
    push(s, x); /// Pushes "x".
    push(s, z); /// Pushes "z"
}

/**
 * Function that copies an element to the top of the stack.
 */
void copyElement(STACK* s)
{
    stackElem element = pop(s); /*!< Stores the element that's on the top of the stack. */
    if (element.elemType == Int)
    {
        int adress = s->sp - element.type.i;
        push(s,s->stack[adress]); /// Pushes the element in the address to the top of the stack.
    }
}
