#ifndef AUXILIARSFUNCTIONS_H
#define AUXILIARSFUNCTIONS_H

#include "stack.h"
#include <string.h>
#include <stdlib.h>

/**
 * Function that tests if the input is a Float.
 */
int isFloat(char input[])
{
    int i = 0;
    while(input[i++] != '\0') /// Goes through the input sentence.
    {
        if(input[i] == '.')
            return 1; /// Returns "1" if True.
    }

    return 0; /// Returns "0" if False.
}

/**
 * Function that tests if the input is a Digit.
 */
int isDigit(char num[])
{
    int i = 0;
    while(num[i] != '\0')  /// Goes through the input sentence.
    {
        if(num[i] >= 48 && num[i] <= 57)
        {
            return 1; /// Returns "1" if True.
        }
        i++;
    }
    return 0; /// Returns "0" if False.
}

/**
 * Function that tests if the input is a String.
 */
int isString(char num[])
{
    int i = 0;

    while(num[i] !='\0') /// Goes through the input sentence.
    {
        if(i > 0)
            return 1; /// Returns "1" if True.
        i++;

    }
    return 0; /// Returns "0" if False.

}

/**
 * Function that tests if the input is an Integer.
 */
int isInteger(double num)
{
    if((num - (int)num) == 0)
        return 1; /// Returns "1" if True.
    else
        return 0; /// Returns "1" if False.
}

/**
 * Function that updates the string when its length is modified.
 */
char* updateString(char* str, int range)
{
    int length = strlen(str); /*!< Stores the length of the string. */
    char* tempStr[length-range]; /*!< Stores the modified string. */
    int i = 0;

    while(length != 1)
    {
        tempStr[i] = &str[i+range];
        length--;
    }

    return *tempStr; /// Returns the new string.
}

/**
 * Function that creates an array of Floats or Integers.
 */
stackElem createNewArray(char* token, int cnt)
{
    stackElem val;
    val.type.a = new_stack();
    val.elemType = Array;

    stackElem temp;

    int i = 2;
    int j = 0;

    do
    {
        if(token[i] == '[') /// Finding the first square bracket to initiate the array.
        {
            token = updateString(token,i+1);
            val.type.a->stack[j] = createNewArray(token,cnt);
            j++;
            cnt++;
        }
        else if(token[i] == ']') /// Finding the second square bracket to end the array.
        {
            cnt--;
        }
        else if(isDigit(&token[i]) && cnt <= 1) /// Testing if the element is a Digit.
        {
            if(isFloat(&token[i])) /// Case in which the element is a Float.
            {
                temp.elemType = Double;
                temp.type.d = atof(&token[i]);
                val.type.a->stack[j] = temp;
            }
            else /// Case in which the element is an Integer.
            {
                temp.elemType = Int;
                temp.type.i = atoi(&token[i]);
                val.type.a->stack[j] = temp;
            }
            j++;
        }
        i++;
    }
    while(cnt > 0);

    val.type.a->sp = j - 1;
    val.type.a->cap = j;

    return val;
}

/**
 * Function that prints the stack elements.
 */
void printStack(STACK* s,int i)
{
    for(; i <= s->sp; i++)
    {
        if(s->stack[i].elemType == Int) /// Case in which they're Integers.
        {
            printf("%ld", s->stack[i].type.i);
        }
        else if(s->stack[i].elemType == Double) /// Case in which they're Doubles.
        {
            printf("%g", s->stack[i].type.d);
        }
        else if(s->stack[i].elemType == Char) /// Case in which they're Chars.
        {
            printf("%c", s->stack[i].type.c);
        }
        else if(s->stack[i].elemType == String) /// Case in which they're Strings
        {
            printf("%s", s->stack[i].type.s->str);
        }
        else if(s->stack[i].elemType == Array) /// Case in which they're Arrays.
        {
            printStack(s->stack[i].type.a,0);
        }
        else
        {
            return;
        }
    }
}

#endif

