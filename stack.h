#ifndef STACK_H
#define STACK_H

#include <stdio.h>

/**
 * \def MAX_STACK
 * Defining the maximum stack size.
 */
#define MAX_STACK BUFSIZ

/**
 * \def LENGTH
 * Defining the maximum length.
 */
#define LENGTH 2048

typedef struct STACK STACK;

/**
 * The string is characterized by the pointer and the length.
 */
typedef struct {
    char str[MAX_STACK]; ///< Array the chars.
    int sp; ///< Stack pointer.
    int length; ///< String length.
}STRING;

/**
 * \typedef
 * \enum types
 * Defining the maximum length.
 */
typedef enum{Int,Double,Char,String,Array} Types;

/**
 * The stack elements can be of the following types: Integer, Double, Char, Array and String.
 */
typedef struct {
    Types elemType; ///< Assigning letters to each element type.
    union {
        int long i; ///< Assigning letter "i" to the type Integer.
        double d; ///< Assigning letter "d" to the type Double.
        char c; ///< Assigning letter "c" to the type Char.
        STRING* s; ///< Assigning letter "s" to the type String.
        STACK* a; ///< Assigning letter "a" to the type Array.
    }type; ///< Naming it as type.
} stackElem;

/**
 * The array is defined by the pointer and the capacity.
 */
typedef struct STACK{
    stackElem stack[MAX_STACK]; ///< Stack with maximum capacity.
    int sp; ///< Stack pointer.
    int cap; ///< Capacity of the array.

    stackElem vars['Z' - 'A' + 1]; ///< Variables by default.
} STACK;

/**
 * Creates a new Stack.
 */
STACK * new_stack(){
    return (STACK*) malloc(sizeof(STACK));
}

STACK *new_stack();

/**
 * Creates a new String.
 */
STRING * newString()
{
    return (STRING*) malloc(sizeof(STRING));
}

/**
 * Pushes an element to the top of the stack.
 */
void push(STACK *s,stackElem elem){
    s->sp++; /// Increments one unit to the stack pointer.
    s->stack[s->sp] = elem; /// Adds the element.
}

/**
 * Pops the element at the top of the stack.
 */
stackElem pop(STACK *s){

    stackElem ret = s->stack[s->sp]; /// Removes the element.
    s->sp--; /// Decreases one unit of the stack pointer.
    return ret; /// Returns the element.
}

/**
 * Peeks an element in a certain range.
 */
stackElem peek(STACK* s,int range)
{
    stackElem peek = s->stack[s->sp-range]; /*!< Stores the peeked element. */
    return peek; /// Return the peeked element.
}

/**
 * Setting variables by default.
 */
void defaultVars(STACK* s)
{
    /// 0 -> A e 25 -> Z

    int i = 0;

    /// Puts 10 - 15 in the variables A - F.
    while(i < 6)
    {
        s->vars[i].elemType = Int;
        s->vars[i].type.i = 10 + i;
        i++;
    }

    /// Assigns Enter to N
    s->vars[13].elemType = Char;
    s->vars[13].type.i = '\n';

    /// Assigns Space to S
    s->vars[18].elemType = Char;
    s->vars[18].type.i = ' ';

    i = 0;
    /// Puts 0 - 2 in variables X - Z
    while(i < 3)
    {
        s->vars[23 + i].elemType = Int;
        s->vars[23 + i].type.i = i;
        i++;
    }

}

/**
 * Verifies the char right after the colon
 */
void setVar(STACK* s, char var)
{
    stackElem elem = pop(s);
    int i = (int)var;
    int address;

    if(i >= 65 && i <= 90)
    {
        address = i - 65;
        s->vars[address] = elem;
    }
    push(s,elem);
}

/**
 * Gets the variable by address.
 */
stackElem getVar(STACK* s,char var)
{
    int i = (int)var;
    int address = i - 65;

    return s->vars[address];
}

#endif
