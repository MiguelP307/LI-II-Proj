#include "stack.h"
#include "auxiliarsFunctions.h"

/**
 * Function that verifies if an element is lower than the other(logical).
 * It works for the following input types: Integer; Double and Char.
 */
void lowerLogical(STACK* s)
{
    stackElem res; /*!< Stores the result. */
    res.elemType = Int; /// Defining the element type

    stackElem x = pop(s); /*!< Stores the first element in "x". */
    stackElem y = pop(s); /*!< Stores the second element in "y". */


    if(x.elemType == Int) /// Case in which "x" is an Integer.
    {
        if(y.elemType == Int) /// Case in which "y" is also an Integer.
        {
            if(y.type.i < x.type.i)
                res.type.i = 1;
            else
                res.type.i = 0;
        }
        else if(y.elemType == Double) /// Case in which "y" is a Double.
        {
            if(y.type.d < x.type.i)
                res.type.i = 1;
            else
                res.type.i = 0;
        }
        else if(y.elemType == Char) /// Case in which "y" is a Char.
        {
            if((long)y.type.c < x.type.i)
                res.type.i = 1;
            else
                res.type.i = 0;
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
            if(y.type.i < x.type.d)
                res.type.i = 1;

            else
                res.type.i = 0;
        }
        else if(y.elemType == Double) /// Case in which "y" is also a Double.
        {
            if(y.type.d < x.type.d)
                res.type.i = 1;
            else
                res.type.i = 0;
        }
        else if(y.elemType == Char) /// Case in which "y" is a Char.
        {
            if((long)y.type.c < x.type.d)
                res.type.i = 1;
            else
                res.type.i = 0;
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
            if(y.type.i < (long)x.type.c)
                res.type.i = 1;
            else
                res.type.i = 0;
        }
        else if(y.elemType == Double) /// Case in which "y" is a Double.
        {
            if(y.type.d < (long)x.type.c)
                res.type.i = 1;
            else
                res.type.i = 0;
        }
        else if(y.elemType == Char) /// Case in which "y" is also a Char.
        {
            if((long)y.type.c < (long)x.type.c)
                res.type.i = 1;
            else
                res.type.i = 0;
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
 * Function that verifies if an element if higher than the other(logical).
 * It works for the following input types: Integer; Double and Char.
 */
void higherLogical(STACK* s)
{
    stackElem res; /*!< Stores the result. */
    res.elemType = Int; /// Defining element type.

    stackElem x = pop(s); /*!< Stores the first element in "x". */
    stackElem y = pop(s); /*!< Stores the first element in "y". */


    if(x.elemType == Int) /// Cases in which "x" is an Integer and "y" is either Integer, Double or Char.
    {
        if(y.elemType == Int)
        {
            if(y.type.i > x.type.i)
                res.type.i = 1;
            else
                res.type.i = 0;
        }
        else if(y.elemType == Double)
        {
            if(y.type.d > x.type.i)
                res.type.i = 1;
            else
                res.type.i = 0;
        }
        else if(y.elemType == Char)
        {
            if((long)y.type.c > x.type.i)
                res.type.i = 1;
            else
                res.type.i = 0;
        }
        else
        {
            return;
        }
    }

    else if(x.elemType == Double) /// Cases in which "x" is a Double and "y" is either Integer, Double or Char.
    {
        if(y.elemType == Int)
        {
            if(y.type.i > x.type.d)
                res.type.i = 1;

            else
                res.type.i = 0;
        }
        else if(y.elemType == Double)
        {
            if(y.type.d > x.type.d)
                res.type.i = 1;
            else
                res.type.i = 0;
        }
        else if(y.elemType == Char)
        {
            if((long)y.type.c > x.type.d)
                res.type.i = 1;
            else
                res.type.i = 0;
        }
        else
        {
            return;
        }
    }

    else if(x.elemType == Char) /// Cases in which "x" is a Char and "y" is either Integer, Double or Char.
    {
        if(y.elemType == Int)
        {
            if(y.type.i > (long)x.type.c)
                res.type.i = 1;
            else
                res.type.i = 0;
        }
        else if(y.elemType == Double)
        {
            if(y.type.d > (long)x.type.c)
                res.type.i = 1;
            else
                res.type.i = 0;
        }
        else if(y.elemType == Char)
        {
            if((long)y.type.c > (long)x.type.c)
                res.type.i = 1;
            else
                res.type.i = 0;
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
 * Function that compares two elements and verifies if they are equal or not(logical).
 * It works for the following input types: Integer; Double and Char.
 */
void equalOp(STACK *s){
    stackElem x = pop(s); /*!< Stores the first element in "x". */
    stackElem y = pop(s); /*!< Stores the second element in "y". */
    stackElem res; /*!< Stores the result. */
    res.elemType = Int; /// Defining element type as Int.

    if(x.elemType == Int && y.elemType == Int) /// Case in which they are both Integers.
    {
        if (x.type.i == y.type.i)
            res.type.i = 1;

        else
            res.type.i = 0;

        push(s, res);
    }

    else if (x.elemType == Double && y.elemType == Double) /// Case in which both are Double.
    {
        if (x.type.d == y.type.d)
            res.type.i = 1;

        else
            res.type.i = 0;

        push(s, res);
    }

    else if (x.elemType == Int && y.elemType == Double) /// Case in which "x" is an Int and "y" is a Double.
    {
        if ((double) x.type.i == y.type.d)
            res.type.i = 1;

        else
            res.type.i = 0;

        push(s, res);
    }

    else if (x.elemType == Double && y.elemType == Int) /// Case in which "x" is a Double and "y" is an Integer.
    {
        if ( x.type.d == (double) y.type.i)
            res.type.i = 1;

        else
            res.type.i = 0;

        push(s, res);
    }

    else if (x.elemType == Int && y.elemType == Char) /// Case in which "x" is an Int and "y" is a Char.
    {
        if (x.type.i == (int) y.type.c)
            res.type.i = 1;

        else
            res.type.i = 0;

        push(s, res);
    }

    else if (x.elemType == Char && y.elemType == Int) /// Case in which "x" is a Char and "y" is an Integer.
    {
        if ((int) x.type.c == y.type.i)
            res.type.i = 1;

        else
            res.type.i = 0;

        push(s, res);
    }
    else if (x.elemType == String && y.elemType == String) /// Case in which both are strings.
    {

        if (strcmp(x.type.s->str,y.type.s->str) == 0)
            res.type.i = 1;

        else
            res.type.i = 0;

        push(s, res);
    }

}


/**
 * Function that inverts the logical value of an element.
 * It works for the following input types: Integer; Double and Char.
 */
void notOp(STACK *s){
    //x !     <=>
    stackElem x = pop(s); /*!< Stores the first element in "x". */
    stackElem res; /*!< Stores the result. */
    res.elemType = Int;

    if(x.elemType == Int) /// "x" is an Int
    {
        res.type.i = !x.type.i;
        push(s, res);
    }
    if(x.elemType == Double) /// "x" is a Double
    {
        res.type.i = !x.type.d;
        push(s, res);
    }
    if(x.elemType == Char) /// "x" is a Char
    {
        res.type.i = !x.type.c;
        push(s, res);
    }

}

/**
 * Function "and"(logical with shortcut)
 * It works for the following input types: Integer, Double, Char and String.
 */
void andWShortcut(STACK* s)
{
    stackElem res; /*!< Stores the result. */

    stackElem x = pop(s); /*!< Stores the first element in "x". */
    stackElem y = pop(s); /*!< Stores the second element in "y". */


    if(x.elemType == Int) /// Cases in which "x" is an Integer and "y" is either an Integer, Double, Char or String.
    {
        if(y.elemType == Int)
        {
            if(y.type.i)
                res.type.i = x.type.i;
            else
                res.type.i = y.type.i;

            res.elemType = Int;
        }
        else if(y.elemType == Double)
        {
            if(y.type.i)
            {
                res.type.i = x.type.i;
                res.elemType = Int;
            }
            else
            {
                res.type.d = y.type.d;
                res.elemType = Double;
            }
        }
        else if(y.elemType == Char)
        {
            if(y.type.i)
            {
                res.type.i = x.type.i;
                res.elemType = Int;
            }
            else
            {
                res.type.c = y.type.c;
                res.elemType =Char;
            }
        }
        else if(y.elemType == String)
        {
            if(y.type.i)
            {
                res.type.i = x.type.i;
                res.elemType = Int;
            }
            else
            {
                res.type.s = y.type.s;
                res.elemType = String;
            }
        }
        else
        {
            return;
        }
    }

    else if(x.elemType == Double) /// Cases in which "x" is a Double and "y" is either an Integer, Double, Char or String.
    {
        if(y.elemType == Int)
        {
            if(y.type.d)
            {
                res.type.d = x.type.d;
                res.elemType = Double;
            }
            else
            {
                res.type.i = y.type.i;
                res.elemType = Int;
            }
        }
        else if(y.elemType == Double)
        {
            if(y.type.d)
                res.type.d = x.type.d;
            else
                res.type.d = y.type.d;

            res.elemType = Double;
        }
        else if(y.elemType == Char)
        {
            if(y.type.d)
            {
                res.type.d = x.type.d;
                res.elemType = Double;
            }
            else
            {
                res.type.c = y.type.c;
                res.elemType = Char;
            }
        }
        else if(y.elemType == String)
        {
            if(y.type.d)
            {
                res.type.d = x.type.d;
                res.elemType = Double;
            }
            else
            {
                res.type.s = y.type.s;
                res.elemType = String;
            }
        }
        else
        {
            return;
        }
    }
    else if(x.elemType == Char) /// Cases in which "x" is a Char and "y" is either an Integer, Double, Char or String.
    {
        if(y.elemType == Int)
        {
            if(y.type.c)
            {
                res.type.c = x.type.c;
                res.elemType = Char;
            }
            else
            {
                res.type.i = y.type.i;
                res.elemType = Int;
            }
        }
        else if(y.elemType == Double)
        {
            if(y.type.c)
            {
                res.type.c = x.type.c;
                res.elemType = Char;
            }
            else
            {
                res.type.d = y.type.d;
                res.elemType = Double;
            }
        }
        else if(y.elemType == Char)
        {
            if(y.type.c)
                res.type.c = x.type.c;
            else
                res.type.c = y.type.c;

            res.elemType = Char;
        }
        else if(y.elemType == String)
        {
            if(y.type.c)
            {
                res.type.c = x.type.c;
                res.elemType = Char;
            }
            else
            {
                res.type.s = y.type.s;
                res.elemType = String;
            }
        }
        else
        {
            return;
        }
    }
    else if(x.elemType == String) /// Cases in which "x" is a String and "y" is either an Integer, Double, Char or String.
    {
        if(y.elemType == Int)
        {
            if(y.type.s)
            {
                res.type.s = x.type.s;
                res.elemType = String;
            }
            else
            {
                res.type.i = y.type.i;
                res.elemType = Int;

            }
        }
        else if(y.elemType == Double)
        {
            if(y.type.s)
            {
                res.type.s = x.type.s;
                res.elemType = String;
            }
            else
            {
                res.type.d = y.type.d;
                res.elemType = Double;
            }
        }
        else if(y.elemType == Char)
        {
            if(y.type.s)
            {
                res.type.s = x.type.s;
                res.elemType = String;
            }
            else
            {
                res.type.c = y.type.c;
                res.elemType = Char;
            }
        }
        else if(y.elemType == String)
        {
            if(y.type.s)
                res.type.s = x.type.s;
            else
                res.type.s = y.type.s;

            res.elemType = String;
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
 * Function "or"(logical with shortcut)
 * It works for the following input types: Integer, Double, Char and String.
 */
void orWShortcut(STACK* s)
{
    stackElem res; /*!< Stores the result. */

    stackElem x = pop(s); /*!< Stores the first element in "x". */
    stackElem y = pop(s); /*!< Stores the second element in "y". */


    if(x.elemType == Int) /// Cases in which "x" is an Integer and "y" is either an Integer, Double, Char or String.
    {
        if(y.elemType == Int)
        {
            if(y.type.i)
                res.type.i = y.type.i;
            else
                res.type.i = x.type.i;

            res.elemType = Int;
        }
        else if(y.elemType == Double)
        {
            if(y.type.i)
            {
                res.type.d = y.type.d;
                res.elemType = Double;
            }
            else
            {
                res.type.i = x.type.i;
                res.elemType = Int;
            }
        }
        else if(y.elemType == Char)
        {
            if(y.type.i)
            {
                res.type.c = y.type.c;
                res.elemType =Char;
            }
            else
            {
                res.type.i = x.type.i;
                res.elemType = Int;
            }
        }
        else if(y.elemType == String)
        {
            if(y.type.i)
            {
                res.type.s = y.type.s;
                res.elemType = String;
            }
            else
            {
                res.type.i = x.type.i;
                res.elemType = Int;
            }
        }
        else
        {
            return;
        }
    }

    else if(x.elemType == Double) /// Cases in which "x" is a Double and "y" is either an Integer, Double, Char or String.
    {
        if(y.elemType == Int)
        {
            if(y.type.d)
            {
                res.type.i = y.type.i;
                res.elemType = Int;
            }
            else
            {
                res.type.d = x.type.d;
                res.elemType = Double;
            }
        }
        else if(y.elemType == Double)
        {
            if(y.type.d)
                res.type.d = y.type.d;
            else
                res.type.d = x.type.d;

            res.elemType = Double;
        }
        else if(y.elemType == Char)
        {
            if(y.type.d)
            {
                res.type.c = y.type.c;
                res.elemType = Char;
            }
            else
            {
                res.type.d = x.type.d;
                res.elemType = Double;
            }
        }
        else if(y.elemType == String)
        {
            if(y.type.d)
            {
                res.type.s = y.type.s;
                res.elemType = String;
            }
            else
            {
                res.type.d = x.type.d;
                res.elemType = Double;
            }
        }
        else
        {
            return;
        }
    }
    else if(x.elemType == Char) /// Cases in which "x" is a Char and "y" is either an Integer, Double, Char or String.
    {
        if(y.elemType == Int)
        {
            if(y.type.c)
            {
                res.type.i = y.type.i;
                res.elemType = Int;
            }
            else
            {
                res.type.c = x.type.c;
                res.elemType = Char;
            }
        }
        else if(y.elemType == Double)
        {
            if(y.type.c)
            {
                res.type.d = y.type.d;
                res.elemType = Double;
            }
            else
            {
                res.type.c = x.type.c;
                res.elemType = Char;
            }
        }
        else if(y.elemType == Char)
        {
            if(y.type.c)
                res.type.c = y.type.c;
            else
                res.type.c = x.type.c;

            res.elemType = Char;
        }
        else if(y.elemType == String)
        {
            if(y.type.c)
            {
                res.type.s = y.type.s;
                res.elemType = String;
            }
            else
            {
                res.type.c = x.type.c;
                res.elemType = Char;
            }
        }
        else
        {
            return;
        }
    }
    else if(x.elemType == String) /// Cases in which "x" is a String and "y" is either an Integer, Double, Char or String.
    {
        if(y.elemType == Int)
        {
            if(y.type.s)
            {
                res.type.i = y.type.i;
                res.elemType = Int;
            }
            else
            {
                res.type.s = x.type.s;
                res.elemType = String;
            }
        }
        else if(y.elemType == Double)
        {
            if(y.type.s)
            {
                res.type.d = y.type.d;
                res.elemType = Double;
            }
            else
            {
                res.type.s = x.type.s;
                res.elemType = String;
            }
        }
        else if(y.elemType == Char)
        {
            if(y.type.s)
            {
                res.type.c = y.type.c;
                res.elemType = Char;
            }
            else
            {
                res.type.s = x.type.s;
                res.elemType = String;
            }
        }
        else if(y.elemType == String)
        {
            if(y.type.s)
                res.type.s = y.type.s;
            else
                res.type.s = x.type.s;

            res.elemType = String;
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
 * Function that receives two elements and selects the higher one.
 * It works for the following input types: Integer, Double, Char and String.
 */
void higher(STACK *s) {

    stackElem res; /*!< Stores the result. */

    stackElem x = pop(s); /*!< Stores the first element in "x". */
    stackElem y = pop(s); /*!< Stores the second element in "y". */


    if(x.elemType == Int) /// Cases in which "x" is an Integer and "y" is either an Integer, Double, Char or String.
    {
        if(y.elemType == Int)
        {
            if(y.type.i > x.type.i)
                res.type.i = y.type.i;
            else
                res.type.i = x.type.i;

            res.elemType = Int;
        }
        else if(y.elemType == Double)
        {
            if(y.type.d > x.type.i)
            {
                res.type.d = y.type.d;
                res.elemType = Double;
            }
            else
            {
                res.type.i = x.type.i;
                res.elemType = Int;
            }
        }
        else if(y.elemType == Char)
        {
            if(y.type.c > x.type.i)
            {
                res.type.c = y.type.c;
                res.elemType = Char;

            }
            else
            {
                res.type.i = x.type.i;
                res.elemType = Int;
            }
        }
        else
        {
            return;
        }
    }

    else if(x.elemType == Double) /// Cases in which "x" is a Double and "y" is either an Integer, Double, Char or String.
    {
        if(y.elemType == Int)
        {
            if(y.type.i > x.type.d)
            {
                res.type.i = y.type.i;
                res.elemType = Int;
            }
            else
            {
                res.type.d = x.type.d;
                res.elemType = Double;

            }
        }
        else if(y.elemType == Double)
        {
            if(y.type.d > x.type.d)
                res.type.d = y.type.d;
            else
                res.type.d = x.type.d;

            res.elemType = Double;

        }
        else if(y.elemType == Char)
        {
            if(y.type.c > x.type.d)
            {
                res.type.c = y.type.c;
                res.elemType = Char;
            }
            else
            {
                res.type.d = x.type.d;
                res.elemType = Double;
            }
        }
        else
        {
            return;
        }
    }

    else if(x.elemType == Char) /// Cases in which "x" is a Char and "y" is either an Integer, Double, Char or String.
    {
        if(y.elemType == Int)
        {
            if(y.type.i > x.type.c)
            {
                res.type.i = y.type.i;
                res.elemType = Int;
            }
            else
            {
                res.type.c = x.type.c;
                res.elemType = Char;

            }

        }
        else if(y.elemType == Double)
        {
            if(y.type.d > x.type.c)
            {
                res.type.d = y.type.d;
                res.elemType = Double;
            }
            else
            {
                res.type.c = x.type.c;
                res.elemType = Char;
            }
        }
        else if(y.elemType == Char)
        {
            if(y.type.c > x.type.c)
                res.type.c = y.type.c;
            else
                res.type.c = x.type.c;

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
 * Function that receives two elements and selects the lower one.
 * It works for the following input types: Integer, Double, Char and String.
 */
void lower(STACK *s) {

    stackElem res; /*!< Stores the result. */

    stackElem x = pop(s); /*!< Stores the first element in "x". */
    stackElem y = pop(s); /*!< Stores the second element in "y". */


    if(x.elemType == Int) /// Cases in which "x" is an Integer and "y" is either an Integer, Double, Char or String.
    {
        if(y.elemType == Int)
        {
            if(y.type.i < x.type.i)
            {
                res.type.i = y.type.i;
            }
            else
            {
                res.type.i = x.type.i;
            }
            res.elemType = Int;
        }
        else if(y.elemType == Double)
        {
            if(y.type.d < x.type.i)
            {
                res.type.d = y.type.d;
                res.elemType = Double;
            }
            else
            {
                res.type.i = x.type.i;
                res.elemType = Int;
            }
        }
        else if(y.elemType == Char)
        {
            if(y.type.c < x.type.i)
            {
                res.type.c = y.type.c;
                res.elemType = Char;

            }
            else
            {
                res.type.i = x.type.i;
                res.elemType = Int;
            }
        }
        else
        {
            return;
        }
    }

    else if(x.elemType == Double) /// Cases in which "x" is a Double and "y" is either an Integer, Double, Char or String.
    {
        if(y.elemType == Int)
        {
            if(y.type.i < x.type.d)
            {
                res.type.i = y.type.i;
                res.elemType = Int;
            }
            else
            {
                res.type.d = x.type.d;
                res.elemType = Double;

            }
        }
        else if(y.elemType == Double)
        {
            if(y.type.d < x.type.d)
                res.type.d = y.type.d;
            else
                res.type.d = x.type.d;

            res.elemType = Double;

        }
        else if(y.elemType == Char)
        {
            if(y.type.c < x.type.d)
            {
                res.type.c = y.type.c;
                res.elemType = Char;
            }
            else
            {
                res.type.d = x.type.d;
                res.elemType = Double;
            }
        }
        else
        {
            return;
        }
    }

    else if(x.elemType == Char) /// Cases in which "x" is a Char and "y" is either an Integer, Double, Char or String.
    {
        if(y.elemType == Int)
        {
            if(y.type.i < x.type.c)
            {
                res.type.i = y.type.i;
                res.elemType = Int;
            }
            else
            {
                res.type.c = x.type.c;
                res.elemType = Char;

            }

        }
        else if(y.elemType == Double)
        {
            if(y.type.d < x.type.c)
            {
                res.type.d = y.type.d;
                res.elemType = Double;
            }
            else
            {
                res.type.c = x.type.c;
                res.elemType = Char;
            }
        }
        else if(y.elemType == Char)
        {
            if(y.type.c < x.type.c)
                res.type.c = y.type.c;
            else
                res.type.c = x.type.c;

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
 * Function "if"(logical) in which the first parameter is the condition, the second is the result if the condition has a
 * true value and the third is the result if the condition has a False value.
 * It works for the following input types: Integer, Double, Char and String.
 */
void ifThenElse(STACK *s){
    //x y z ?
    stackElem z = pop(s); /*!< Stores the first element in "z". */
    stackElem y = pop(s); /*!< Stores the second element in "y". */
    stackElem x = pop(s); /*!< Stores the third element in "x". */
    stackElem res; /*!< Stores the result. */

    if (x.elemType != String)  /// Case in which "x" is not a String.
    {
        if (x.type.i != 0 && x.type.d != 0 && x.type.c != 0)
        {
            res.elemType = y.elemType;
            res = y;
        }
        else
        {
            res.elemType = z.elemType;
            res = z;
        }
    }

    if (x.elemType == String) /// Case in which "x" is a String.
    {
        if (x.type.s->length > 0) /// Tests if the string length is higher than 0.
        {
            res.elemType = y.elemType;
            res = y;
        }
        else
        {
            res.elemType = z.elemType;
            res = z;
        }
    }
    push(s, res); /// Pushes the result to the top of the stack.
}
