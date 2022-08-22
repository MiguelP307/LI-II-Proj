#include "stack.h"
#include <math.h>
#include "auxiliarsFunctions.h"

/**
 * Function that sums the top two elements of the stack.
 * It works for the following input types: Integer; Double and Char.
 */
void add(STACK *s) {

    stackElem res; /*!< Stores the result. */

    stackElem x = pop(s); /*!< Stores the first element of the stack in "x". */
    stackElem y = pop(s); /*!< Stores the second element of the stack in "y". */


    if(x.elemType == Int) /// Case in which "x" is an Integer.
    {
        if(y.elemType == Int) /// Case in which "y" is also and Integer.
        {
            res.type.i = x.type.i + y.type.i;
            res.elemType = Int;
        }
        else if(y.elemType == Double) /// Case in which "y" is a Double.
        {
            res.type.d = x.type.i + y.type.d;
            res.elemType = Double;
        }
        else if(y.elemType == Char) /// Case in which "y" is a Char.
        {
            res.type.c = (char)(x.type.i + (long)y.type.c);
            res.elemType = Char;
        }
        else
        {
            return;
        }
    }
    else if(x.elemType == Double) /// Case in which "x" is a Double.
    {
        if(y.elemType == Int) /// Case in which "y" is an Integer.
        {
            res.type.d = x.type.d + y.type.i;
            res.elemType = Double;
        }
        else if(y.elemType == Double) /// Case in which "y" is also a Double.
        {
            res.type.d = x.type.d + y.type.d;
            res.elemType = Double;
        }
        else if(y.elemType == Char) /// Case in which "y" is a Char.
        {
            res.type.c = (char)(x.type.d + (long)y.type.c);
            res.elemType = Char;
        }
        else
        {
            return;
        }
    }
    else if(x.elemType == Char) /// Case in which "x" is a Char.
    {
        if(y.elemType == Int) /// Case in which "y" is an Integer.
        {
            res.type.c = (char)((long)x.type.c + y.type.i);
            res.elemType = Char;
        }
        else if(y.elemType == Double) /// Case in which "y" is a Double.
        {
            res.type.c = (char)((long)x.type.c + y.type.d);
            res.elemType = Char;
        }
        else if(y.elemType == Char) /// Case in which "y" is also a Char.
        {
            res.type.c = x.type.c + y.type.c;
            res.elemType = Char;
        }
        else
        {
            return;
        }
    }
    else
    {
        return;
    }
    push(s, res); /// Pushes the result to the top of the stack.
}

/**
 * Function that subtracts the top two elements of the stack.
 * It works for the following input types: Integer; Double and Char.
 */
void subtract(STACK *s) {
    stackElem res; /*!< Stores the result. */

    stackElem x = pop(s); /*!< Stores the first element of the stack in "x". */
    stackElem y = pop(s); /*!< Stores the second element of the stack in "y". */

    if(x.elemType == Int) /// Case in which "x" is an Integer.
    {
        if(y.elemType == Int) /// Case in which "y" is also an Integer.
        {
            res.type.i = y.type.i - x.type.i;
            res.elemType = Int;
        }
        else if(y.elemType == Double) /// Case in which "y" is a Double.
        {
            res.type.d = y.type.d - x.type.i;
            res.elemType = Double;
        }
        else if(y.elemType == Char) /// Case in which "y" is a Char.
        {
            res.type.c = (char)((long)y.type.c - x.type.i);
            res.elemType = Char;
        }
        else
        {
            return;
        }
    }
    else if(x.elemType == Double) /// Case in which "x" is a Double.
    {
        if(y.elemType == Int) /// Case in which "y" is an Integer.
        {
            res.type.d = y.type.i - x.type.d;
            res.elemType = Double;
        }
        else if(y.elemType == Double) /// Case in which "y" is also a Double.
        {
            res.type.d = y.type.d - x.type.d;
            res.elemType = Double;
        }
        else if(y.elemType == Char) /// Case in which "y" is a Char.
        {
            res.type.c = (char)((long)y.type.c - x.type.d);
            res.elemType = Char;
        }
        else
        {
            return;
        }
    }
    else if(x.elemType == Char) /// Case in which "x" is a Char.
    {
        if(y.elemType == Int) /// Case in which "y" is an Integer.
        {
            res.type.c = (char)(y.type.i - (long)x.type.c);
            res.elemType = Char;
        }
        else if(y.elemType == Double) /// Case in which "y" is a Double.
        {
            res.type.c = (char)(y.type.d - (long)x.type.c);
            res.elemType = Char;
        }
        else if(y.elemType == Char) /// Case in which "y" is also a Char.
        {
            res.type.c = y.type.c - x.type.c;
            res.elemType = Char;
        }
        else
        {
            return;
        }
    }
    else
    {
        return;
    }
    push(s, res); /// Pushes the result to the top of the stack.
}

/**
 * Function that multiplies the top two elements of the stack.
 * It works for the following input types: Integer; Double and Char.
 */
void multiplyElements(STACK* s)
{

    stackElem res; /*!< Stores the result. */

    stackElem x = pop(s); /*!< Stores the first element of the stack in "x". */
    stackElem y = pop(s); /*!< Stores the second element of the stack in "y". */


    if(x.elemType == Int) /// Case in which "x" is an Integer.
    {
        if(y.elemType == Int) /// Case in which "y" is also an Integer.
        {
            res.type.i = x.type.i * y.type.i;
            res.elemType = Int;
        }
        else if(y.elemType == Double) /// Case in which "y" is a Double.
        {
            res.type.d = x.type.i * y.type.d;
            res.elemType = Double;
        }
        else if(y.elemType == Char) /// Case in which "y" is a Char
        {
            res.type.c = (char)(x.type.i * (long)y.type.c);
            res.elemType = Char;
        }
        else
        {
            return;
        }
    }
    else if(x.elemType == Double) /// Case in which "x" is a Double.
    {

        if(y.elemType == Int) /// Case in which "y" is an Integer.
        {
            res.type.d = x.type.d * y.type.i;
            res.elemType = Double;

        }
        else if(y.elemType == Double) /// Case in which "y" is also a Double
        {
            res.type.d = x.type.d * y.type.d;
            res.elemType = Double;
        }
        else if(y.elemType == Char) /// Case in which "y" is a Char.
        {
            res.type.c = (char)(x.type.d * (long)y.type.c);
            res.elemType = Char;
        }
        else
        {
            return;
        }
    }
    else if(x.elemType == Char) /// Case in which "x" is a Char.
    {
        if(y.elemType == Int) /// Case in which "y" is an Integer.
        {
            res.type.c = (char)((long)x.type.c * y.type.i);
            res.elemType = Char;
        }
        else if(y.elemType == Double) /// Case in which "y" is a Double.
        {
            res.type.c = (char)((long)x.type.c * y.type.d);
            res.elemType = Char;
        }
        else if(y.elemType == Char) /// Case in which "y" is also a Char.
        {
            res.type.c = x.type.c * y.type.c;
            res.elemType = Char;
        }
        else
        {
            return;
        }
    }
    else
    {
        return;
    }
    push(s, res); /// Pushes the result to the top of the stack.
}

/**
 * Function that divides the top two elements of the stack.
 * It works for the following input types: Integer, Double and Char.
 */
void divideElements(STACK* s)
{
    stackElem res; /*!< Store the result. */

    stackElem x = pop(s); /*!< Stores the first element of the stack in "x". */
    stackElem y = pop(s); /*!< Stores the second element of the stack in "y". */


    if(x.elemType == Int) /// Case in which "x" is an Integer.
    {
        if(y.elemType == Int) /// Case in which "y" is also an Integer.
        {
            res.type.i = y.type.i / x.type.i;
            res.elemType = Int;
        }
        else if(y.elemType == Double) /// Case in which "y" is a Double.
        {
            res.type.d = y.type.d / x.type.i;
            res.elemType = Double;
        }
        else if(y.elemType == Char) /// Case in which "y" is a Char.
        {
            res.type.c = (char)((long)y.type.c / x.type.i);
            res.elemType = Char;
        }
        else
        {
            return;
        }
    }
    else if(x.elemType == Double) /// Case in which "x" is a Double.
    {
        if(y.elemType == Int) /// Case in which "y" is an Integer.
        {
            res.type.d = y.type.i / x.type.d ;
            res.elemType = Double;
        }
        else if(y.elemType == Double) /// Case in which "y" is also a Double.
        {
            res.type.d = y.type.d / x.type.d;
            res.elemType = Double;
        }
        else if(y.elemType == Char) /// Case in which "y" is a Char.
        {
            res.type.c = (char)((long)y.type.c / x.type.d);
            res.elemType = Char;
        }
        else
        {
            return;
        }
    }
    else if(x.elemType == Char) /// Case in which "x" is a Char.
    {
        if(y.elemType == Int) /// Case in which "y" is an Integer.
        {
            res.type.c = (char)(y.type.i / (long)x.type.c);
            res.elemType = Char;
        }
        else if(y.elemType == Double) /// Case in which "y" is a Double.
        {
            res.type.c = (char)(y.type.d / (long)x.type.c);
            res.elemType = Char;
        }
        else if(y.elemType == Char) /// Case in which "y" is also a Char.
        {
            res.type.c = y.type.c / x.type.c;
            res.elemType = Char;
        }
        else
        {
            return;
        }
    }
    else
    {
        return;
    }
    push(s, res); /// Pushes the result to the top of the stack.
}

/**
 * Function that increases the value of an element by one.
 * It works for the following input types: Integer, Double and Char.
 */
void incrementElement(STACK* s)
{
    stackElem x = pop(s); /*!< Stores the first element of the stack in "x". */

    if(x.elemType == Int) /// Case in which "x" is an Integer.
    {
        x.type.i++;
    }
    else if(x.elemType == Double) /// Case in which "x" is a Double.
    {
        x.type.d++;
    }
    else if(x.elemType == Char) /// Case in which "x" is a Char.
    {
        x.type.c++;
    }
    else
    {
        return;
    }

    push(s, x); /// Pushes the result to the top of the stack.
}

/**
 * Function that decreases the value of an element by one.
 * It works for the following input types: Integer, Double and Char.
 */
void decrementElement(STACK* s)
{
    stackElem x = pop(s); /*!< Stores the first element of the stack in "x". */

    if(x.elemType == Int) /// Case in which "x" is an Integer.
    {
        x.type.i--;
    }
    else if(x.elemType == Double) /// Case in which "x" is a Double.
    {
        x.type.d--;
    }
    else if(x.elemType == Char) /// Case in which "x" is a Char.
    {
        x.type.c--;
    }
    else
    {
        return;
    }

    push(s, x); /// Pushes the result to the top of the stack.
}

/**
 * Function that calculates the modulo (remainder of a division) of the top two elements of the stack.
 * It works for the following input types: Integer and Double.
 */
void moduloElement(STACK* s)
{
    stackElem res; /*!< Stores the result. */

    stackElem x = pop(s); /*!< Stores the first element of the stack in "x". */
    stackElem y = pop(s); /*!< Stores the second element of the stack in "y". */

    if(x.elemType == Int) /// Case in which "x" is an Integer.
    {
        if(y.elemType == Int) /// Case in which y" is also an Integer.
        {
            res.type.i = y.type.i % x.type.i;
            res.elemType = Int;
        }
        else if(y.elemType == Char) /// Case in which "y" is a Char.
        {
            res.type.c = y.type.i % x.type.c;
            res.elemType = Char;
        }
        else
        {
            return;
        }
    }
    else if(x.elemType == Char) /// Case in which "x" is a Char.
    {
        if(y.elemType == Int) /// Case in which "y" is an Integer.
        {
            res.type.c = (char)(y.type.i % (long)x.type.c);
            res.elemType = Char;
        }
        else if(y.elemType == Char) /// Case in which "y" is also a Char.
        {
            res.type.c = y.type.c % x.type.c;
            res.elemType = Char;
        }
        else
        {
            return;
        }
    }
    else
    {
        return;
    }
    push(s, res); /// Pushes the result to the top of the stack.
}

/**
 * Function that calculates "x" to the power of "y", "x" being the first element and "y" the second.
 * It works for the following input types: Integer, Double and Char.
 */
void exponenciacaoElement(STACK* s)
{
    stackElem res;  /*!< Stores the result. */

    stackElem x = pop(s);  /*!< Stores the first element of the stack in "x". */
    stackElem y = pop(s);  /*!< Stores the second element of the stack in "y". */

    if(x.elemType == Int) /// Case in which "x" is an Integer.
    {
        if(y.elemType == Int) /// Case in which "y" is also an Integer.
        {
            res.type.i = pow(y.type.i,x.type.i);
            res.elemType = Int;
        }
        else if(y.elemType == Double) /// Case in which "y" is a Double.
        {
            res.type.d = pow(y.type.d,x.type.i);
            res.elemType = Double;
        }
        else if(y.elemType == Char) /// Case in which "y" is a Char.
        {
            res.type.c = (char)pow((long)y.type.c,x.type.i);
            res.elemType = Char;
        }
        else
        {
            return;
        }
    }
    else if(x.elemType == Double) /// Case in which "x" is a Double.
    {
        if(y.elemType == Int) /// Case in which "y" is an Integer.
        {
            res.type.d = pow(y.type.i , x.type.d);
            res.elemType = Double;
        }
        else if(y.elemType == Double) /// Case in which "y" is also a Double.
        {
            res.type.d = pow(y.type.d , x.type.d);
            res.elemType = Double;
        }
        else if(y.elemType == Char) /// Case in which "y" is a Char.
        {
            res.type.c = (char)pow((long)y.type.c,x.type.d);
            res.elemType = Char;
        }
        else
        {
            return;
        }
    }
    else if(x.elemType == Char) /// Case in which "x" is a Char.
    {
        if(y.elemType == Int) /// Case in which "y" is an Integer.
        {
            res.type.c = (char)pow(y.type.i , (long)x.type.c);
            res.elemType = Char;
        }
        else if(y.elemType == Double) /// Case in which "y" is a Double.
        {
            res.type.c = (char)pow(y.type.d , (long)x.type.c);
            res.elemType = Char;
        }
        else if(y.elemType == Char) /// Case in which "y" is also a Char.
        {
            res.type.c = pow(y.type.c, x.type.c);
            res.elemType = Char;
        }
        else
        {
            return;
        }
    }
    else
    {
        return;
    }
    push(s, res); /// Pushes the result to the top of the stack.
}

/**
 * Function that does the operation AND (Bitwise).
 * It works for the following input types: Integer and Char.
 */
void andBitwise(STACK* s)
{
    stackElem res; /*!< Stores the result. */

    stackElem x = pop(s); /*!< Stores the first element of the stack in "x". */
    stackElem y = pop(s); /*!< Stores the second element of the stack in "y". */

    if(x.elemType == Int) /// Case in which "x" is an integer.
    {
        if(y.elemType == Int) /// Case in which "y" is also an Integer.
        {
            res.type.i = y.type.i & x.type.i;
            res.elemType = Int;
        }
        else if(y.elemType == Char) /// Case in which "y" is a Char.
        {
            res.type.c = y.type.i & x.type.c;
            res.elemType = Char;
        }
        else
        {
            return;
        }
    }
    else if(x.elemType == Char) /// Case in which "x" is a Char.
    {
        if(y.elemType == Int) /// Case in which "y" is an Integer.
        {
            res.type.c = (char)(y.type.i & (long)x.type.c);
            res.elemType = Char;
        }
        else if(y.elemType == Char) /// Case in which "y" is also a Char.
        {
            res.type.c = y.type.c & x.type.c;
            res.elemType = Char;
        }
        else
        {
            return;
        }
    }
    else
    {
        return;
    }
    push(s, res); /// Pushes the result to the top of the stack.
}

/**
 * Function that does the operation Or (Bitwise).
 * It works for the following input types: Integer and Char.
 */
void orBitwise(STACK* s)
{
    stackElem res; /*!< Stores the result. */

    stackElem x = pop(s); /*!< Stores the first element of the stack in "x". */
    stackElem y = pop(s); /*!< Stores the second element of the stack in "y". */

    if(x.elemType == Int) /// Case in which "x" is an Integer.
    {
        if(y.elemType == Int) /// Case in which "y" is also an Integer.
        {
            res.type.i = y.type.i | x.type.i;
            res.elemType = Int;
        }
        else if(y.elemType == Char) /// Case in which "y" is a Char.
        {
            res.type.c = y.type.i | x.type.c;
            res.elemType = Char;
        }
        else
        {
            return;
        }
    }
    else if(x.elemType == Char) /// Case in which "x" is a Char.
    {
        if(y.elemType == Int) /// Case in which "y" is an Integer.
        {
            res.type.c = (char)(y.type.i | (long)x.type.c);
            res.elemType = Char;
        }
        else if(y.elemType == Char) /// Case in which "y" is also a Char.
        {
            res.type.c = y.type.c | x.type.c;
            res.elemType = Char;
        }
        else
        {
            return;
        }
    }
    else
    {
        return;
    }
    push(s, res); /// Pushes the result to the top of the stack.
}

/**
 * Function that does the operation XOR (Bitwise) between two elements.
 * It works for the following input types: Integer and Char.
 */
void xorBitwise(STACK* s)
{
    stackElem res; /*!< Stores the result. */

    stackElem x = pop(s); /*!< Stores the first element of the stack in "x". */
    stackElem y = pop(s); /*!< Stores the second element of the stack in "y". */

    if(x.elemType == Int) /// Case in which "x" is an Integer.
    {
        if(y.elemType == Int) /// Case in which "y" is also an Integer.
        {
            res.type.i = y.type.i ^ x.type.i;
            res.elemType = Int;
        }
        else if(y.elemType == Char) /// Case in which "y" is a Char.
        {
            res.type.c = y.type.i ^ x.type.c;
            res.elemType = Char;
        }
        else
        {
            return;
        }
    }
    else if(x.elemType == Char) /// Case in which "x" is a Char.
    {
        if(y.elemType == Int) /// Case in which "y" is an Integer.
        {
            res.type.c = (char)(y.type.i ^ (long)x.type.c);
            res.elemType = Char;
        }
        else if(y.elemType == Char) /// Case in which "y" is also a Char.
        {
            res.type.c = y.type.c ^ x.type.c;
            res.elemType = Char;
        }
        else
        {
            return;
        }
    }
    else
    {
        return;
    }
    push(s, res); /// Pushes the result to the top of the stack.
}

/**
 * Function that inverts the logical value of the element.
 * It works for the following input types: Integer and Char.
 */
void notBitwise(STACK* s)
{
    stackElem x = pop(s); /*!< Stores the first element of the stack in "x". */

    if(x.elemType == Int) /// Case in which "x" is an Integer.
    {
        x.type.i = ~(x.type.i);
        x.elemType = Int;
    }
    else if(x.elemType == Char) /// Case in which "x" is a Char.
    {
        x.type.c = ~(x.type.c);
        x.elemType = Char;
    }
    else
    {
        return;
    }

    push(s, x); /// Pushes the new value of "x" to the top of the stack.
}
