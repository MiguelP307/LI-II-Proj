#include "stack.h"
#include "auxiliarsFunctions.h"
#include <stdlib.h>

/**
 * Function that reads a given line.
 */
void readLine(STACK* s)
{
    stackElem val; /*!< Stores the result. */
    char num[2048]; /*!< Creates the array to search on. */
    if(fgets(num,2048,stdin) == NULL) /// Goes through it.
        return;

    if(isDigit(num)) /// Case in which it's a Digit.
    {
        if(isFloat(num)) /// Case in which it's a Float.
        {
            val.elemType = Double;
            val.type.d = atof(num);
        }
        else /// Case in which it's a Integer.
        {
            val.elemType = Int;
            val.type.i = atoi(num);
        }
    }
    else if(isString(num)) /// Case in which it's a String.
    {
        int i = 0;
        val.elemType = String;
        val.type.s = newString();

        while(num[i] != '\0') /// Goes through the string.
        {
            val.type.s->str[i] = num[i];
            i++;
        }

        val.type.s->sp = --i;
        val.type.s->length = i;
    }
    else /// Case in which it's a Char.
    {
        val.elemType = Char;
        val.type.c = num[0];
    }

    push(s,val); /// Pushes the line read to the stack.
}
