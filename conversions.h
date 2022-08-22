#ifndef CONVERSIONS_H
#define CONVERSIONS_H

#include "stack.h"
#include "stdlib.h"
#include "string.h"


/**
 * Function that converts an element into an Integer.
 * It works for the following input types: Integer, Double, Char and String.
 */
void toInt(STACK* s)
{
    char* trash;

    stackElem element = pop(s);  /*!< Stores the element. */
    stackElem res;  /*!< Stores the result. */
    res.elemType = Int; /// Defining the element type.

    if(element.elemType == Double) /// Case in which the element is a Double.
    {
        res.type.i = (long)element.type.d;
    }
    else if(element.elemType == Char) /// Case in which the element is a Char.
    {
        res.type.i = (long)element.type.c;
    }
    else if(element.elemType == String) /// Case in which the element is a String.
    {
        res.type.i = strtol(element.type.s->str,&trash,10);
    }
    else /// Case in which it is already an Integer.
    {
        res.type.i = (long)element.type.i;
    }
    push(s,res); /// Pushes the result to the top of the stack.
}

/**
 * Function that converts an element into a Double.
 * It works for the following input types: Integer, Double, Char and String.
 */
void toDouble(STACK* s)
{
    char* trash;

    stackElem element = pop(s); /*!< Stores the element. */
    stackElem res; /*!< Stores the result. */
    res.elemType = Double; /// Defining the type as Double.

    if(element.elemType == Int) /// Case in which the element is an Integer.
    {
        res.type.d = (double)element.type.i;
    }
    else if(element.elemType == Char) /// Case in which the element is a Char.
    {
        res.type.d = (double)element.type.c;
    }
    else if(element.elemType == String) /// Case in which the element is a String.
    {
        res.type.d = strtod(element.type.s->str,&trash);
    }
    else /// Case in which it's already a double.
    {
        res.type.d = (double)element.type.d;
    }
    push(s,res); /// Pushes the result to the stack.
}

/**
 * Function that converts an element into a Char.
 * It works for the following input types: Integer, Double, Char and String.
 */
void toChar(STACK* s)
{
    stackElem element = pop(s); /*!< Stores the element. */
    stackElem res; /*!< Stores the result. */
    res.elemType = Char; /// Defining the type as Char.

    if(element.elemType == Int) /// Case in which the element is an Integer.
    {
        res.type.c = (char)element.type.i;
    }
    else if(element.elemType == Double) /// Case in which the element is a Double.
    {
        res.type.c = (char)element.type.d;
    }
    else if(element.elemType == String) /// Case in which the element is a String.
    {
        res.type.c = element.type.s->str[0];
    }
    else /// Case in which it's already a Char.
    {
        res.type.c = (char)element.type.c;
    }
    push(s,res); /// Pushes the result to the top of the stack.
}

/**
 * Function that converts an element into a String.
 * It works for the following input types: Integer, Double, Char and String.
 */
void toString(STACK* s)
{
    stackElem element = pop(s); /*!< Stores the element. */
    stackElem res; /*!< Stores the result. */
    res.type.s = newString(); /// Creates the string.
    res.elemType = String; /// Defining the type as String.

    if(element.elemType == Int) /// Case in which the element is an Integer.
    {
        sprintf(res.type.s->str,"%ld",element.type.i);
        res.type.s->length = strlen(res.type.s->str);
        res.type.s->sp = --res.type.s->length;
    }
    else if(element.elemType == Double) /// Case in which the element is a Double.
    {
        sprintf(res.type.s->str,"%g",element.type.d);
        res.type.s->length = strlen(res.type.s->str);
        res.type.s->sp = --res.type.s->length;
    }
    else if(element.elemType == Char) /// Case in which the element is a Char.
    {
        res.type.s->str[0] = element.type.c;
        res.type.s->sp = 0;
        res.type.s->length = 1;
    }
    else /// Case in which it's already a String.
    {
        res.type.s = element.type.s;
    }
    push(s,res); /// Pushes the result to the stack.
}

#endif