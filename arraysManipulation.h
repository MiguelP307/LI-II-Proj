#include "stack.h"
#include "conversions.h"
#include <ctype.h>
#include <string.h>

stackElem concatArray(stackElem, stackElem);
stackElem concatString(stackElem, stackElem);
stackElem createArray(int);
stackElem updateArray(stackElem,int);
stackElem lineToString();
stackElem cutStrNL(stackElem);
stackElem cutStrWS(stackElem);
stackElem cutStrForm(stackElem,stackElem);
stackElem updateArray2(stackElem);


/**
 * Pushes an array to the stack.
 */
void arrayToStack(STACK* s)
{
    stackElem elem = pop(s);
    int i;
    int length = elem.type.a->cap;

    if(elem.elemType == Array)
        for(i = 0 ; i < length ; i++ )
            push(s,elem.type.a->stack[i]);
}

/**
 * Concatenates two arrays.
 */
void concatenateArrays(STACK* s)
{
    stackElem fstElem = pop(s);
    stackElem sndElem = pop(s);

    stackElem res;

    if(fstElem.elemType == Array)
    {
        res.elemType = Array;
        res.type.a = new_stack();

        if(sndElem.elemType == Array)
        {
            res = concatArray(fstElem,sndElem);
        }
        else if(sndElem.elemType != String)
        {
            res.type.a->stack[0] = sndElem;
            res.type.a->cap = 1;
            res.type.a->sp = 0;

            res = concatArray(fstElem,res);
        }
        else
        {
            return;
        }
    }
    else if(fstElem.elemType == String)
    {
        res.elemType = String;

        if(sndElem.elemType == String)
        {
            res = concatString(fstElem,sndElem);

        }
        else if(sndElem.elemType != Array)
        {

            push(s,sndElem);
            toString(s);
            sndElem = pop(s);

            res = concatString(fstElem,sndElem);
        }
        else
        {
            return;
        }
    }
    else
    {
        if(sndElem.elemType == String)
        {
            res = sndElem;

            push(s,fstElem);
            toString(s);
            fstElem = pop(s);

            res.type.s->str[++res.type.s->sp] = fstElem.type.s->str[0];
            res.type.s->length++;
        }
        else if(sndElem.elemType == Array)
        {
            res.elemType = Array;
            res.type.a = sndElem.type.a;

            res.type.a->stack[++res.type.a->sp] = fstElem;
            res.type.a->cap++;
        }
        else
        {
            return;
        }
    }

    push(s, res);
}

/**
 * Concatenates arrays or string multiple times.
 */
void concatenateArrayMult(STACK* s)
{
    int x = pop(s).type.i - 1;
    stackElem array = pop(s);
    stackElem res = array;

    if(array.elemType == String)
    {
        while(x != 0)
        {
            res = concatString(array,res);
            x--;
        }
    }
    else
    {
        while(x != 0)
        {
            res = concatArray(array,res);
            x--;
        }
    }

}

/**
 * Length or range of an Array or String.
 */
void lengthOrRange(STACK* s)
{
    stackElem elem = pop(s);
    stackElem res;

    if(elem.elemType == String)
    {
        res.elemType = Int;
        res.type.i = elem.type.s->length;
    }
    else if(elem.elemType == Array)
    {
        res.elemType = Int;
        res.type.i = elem.type.a->cap;
    }
    else
    {
        if(elem.elemType == Int)
        {
            res = createArray(elem.type.i);
        }
        else if(elem.elemType == Double)
        {
            push(s,elem);
            toInt(s);
            elem = pop(s);
            res = createArray(elem.type.i);
        }
        else
        {
            return;
        }
    }
    push(s,res);
}

/**
 * Catches a value by its index.
 */
void catchIndice(STACK* s)
{
    stackElem index = pop(s);
    stackElem array = pop(s);

    stackElem res;

    int limit = index.type.i;

    if(array.elemType == String)
    {
        res.elemType = String;
        res.type.s = newString();

        res.type.s->str[0] = array.type.s->str[limit];
        res.type.s->length = 1;
        res.type.s->sp = 0;
    }
    else if(array.elemType == Array)
    {
        res = array.type.a->stack[limit];
    }
    else
    {
        return;
    }

    push(s,res);
}

/**
 * Catches the first element of the Array/String.
 */
void catchFirstElems(STACK* s)
{
    int numElem = pop(s).type.i;
    stackElem array = pop(s);

    stackElem rmArray;

    int i = 0;

    if(array.elemType == String)
    {
        rmArray.type.s = newString();
        rmArray.elemType = String;

        for(; i < numElem ; i++)
        {
            rmArray.type.s->str[i] = array.type.s->str[i];
        }
        rmArray.type.s->sp = numElem - 1;
        rmArray.type.s->length = numElem;

    }
    else if(array.elemType == Array)
    {
        rmArray.type.a = new_stack();
        rmArray.elemType = Array;

        for(; i < numElem ; i++)
        {
            rmArray.type.a->stack[i] = array.type.a->stack[i];
        }
        rmArray.type.a->sp = numElem - 1;
        rmArray.type.a->cap = numElem;
    }
    else
    {
        return;
    }

    push(s,rmArray);

}

/**
 * Catches the last element of the Array/String.
 */
void catchLastELems(STACK* s)
{
    int numElem = pop(s).type.i;
    stackElem array = pop(s);

    stackElem rmArray;

    if(array.elemType == String)
    {
        rmArray.type.s = newString();
        rmArray.elemType = String;

        int length = array.type.s->length;
        int i = length - numElem;

        for(; i < length; i++)
        {
            rmArray.type.s->str[i] = array.type.s->str[i];
        }
        rmArray.type.s->sp = numElem - 1;
        rmArray.type.s->length = numElem;

    }
    else if(array.elemType == Array)
    {
        rmArray.type.a = new_stack();
        rmArray.elemType = Array;

        int length = array.type.a->cap;
        int i = length - numElem;

        for(; i < numElem ; i++)
        {
            rmArray.type.a->stack[i] = array.type.a->stack[i];
        }
        rmArray.type.a->sp = numElem - 1;
        rmArray.type.a->cap = numElem;
    }
    else
    {
        return;
    }

    push(s,rmArray);
}

/**
 * Removes the first element and pushes the Array/String after.
 */
void rmFirstElem(STACK* s)
{
    stackElem elem = pop(s);
    stackElem rmElem;

    if(elem.elemType == String)
    {
        rmElem.type.s = newString();
        rmElem.type.s->str[0] = elem.type.s->str[0];
        rmElem.type.s->sp = 0;
        rmElem.type.s->length = 1;

        elem = updateArray(elem,1);

    }
    else if(elem.elemType == Array)
    {
       rmElem = elem.type.a->stack[0];
       elem = updateArray(elem,1);
    }
    else
    {
        return;
    }

    push(s,elem);
    push(s,rmElem);
}

/**
 * Removes the last element and pushes the Array/String after.
 */
void rmLastElem(STACK* s)
{
    stackElem elem = pop(s);
    stackElem rmElem;

    if(elem.elemType == String)
    {

        rmElem.type.s = newString();
        rmElem.type.s->str[0] = elem.type.s->str[elem.type.s->sp];
        rmElem.type.s->sp = 0;
        rmElem.type.s->length = 1;

        //Update da string
        elem = updateArray2(elem);

    }
    else if(elem.elemType == Array)
    {
        rmElem = elem.type.a->stack[elem.type.a->sp];

        //Update do array
        elem = updateArray2(elem);
    }
    else
    {
        return;
    }

    push(s,elem);
    push(s,rmElem);
}


/**
 * Searches a substring in a string and returns the index.
 */
void searchSubString(STACK* s)
{
    stackElem substring = pop(s);
    stackElem str = pop(s);

    stackElem res;
    res.elemType = Int;

    int i = 0;
    int counter = 0;
    int subSLength = substring.type.s->length;

    while(counter != subSLength || str.type.s->sp != i)
    {
        if(str.type.s->str[i] == substring.type.s->str[i])
        {
            counter++;
        }
        else
        {
            counter = 0;
        }
        i++;
    }

    if(counter == subSLength)
    {
        res.type.i = i - subSLength - 1;
    }
    else
    {
        res.type.i = -1;
    }
    push(s,res);
}

/**
 * Reads the whole input.
 */
void readAllLines(STACK* s)
{
    stackElem temp;
    stackElem str;

    str.type.s = newString();
    str.elemType = String;
    str.type.s->length = 0;
    str.type.s->sp = -1;

    int i = 1;

    while(i)
    {
        temp = lineToString();

        if(temp.elemType == Int)
            i = 0;
        else
        {
            str = concatString(temp,str);
        }
    }

    push(s,str);
}


/**
 * Cuts string by the substring.
 */
void cutString(STACK* s)
{
    stackElem str = pop(s);
    stackElem array = pop(s);

    stackElem res;
    res.type.a = new_stack();
    res.type.a->cap = 0;
    res.type.a->sp = -1;
    res.elemType = Array;

    int i = 0;

    while(array.type.s->length > 0)
    {
        res.type.a->stack[i] = cutStrForm(array,str);
        updateArray(array,res.type.a->stack[i].type.s->length + 1);
        i++;
    }
    push(s,res);
}

/**
 * Splits the string by white space.
 */
void cutStringWSpace(STACK* s)
{
    stackElem str = pop(s);
    stackElem substring;


    substring.type.a = new_stack();
    substring.type.a->cap = 0;
    substring.type.a->sp = -1;
    substring.elemType = Array;

    int i = 0;

    while(str.type.s->length > 0)
    {
        substring.type.a->stack[i] = cutStrWS(str);
        updateArray(str,substring.type.a->stack[i].type.s->length + 1);
        i++;
    }
    push(s,substring);
}

/**
 * Splits the string by enter.
 */
void cutStringEnter(STACK* s)
{
    stackElem str = pop(s);
    stackElem substring;


    substring.type.a = new_stack();
    substring.type.a->cap = 0;
    substring.type.a->sp = -1;
    substring.elemType = Array;

    int i = 0;

    while(str.type.s->length > 0)
    {
        substring.type.a->stack[i] = cutStrNL(str);
        updateArray(str,substring.type.a->stack[i].type.s->length + 1);
        i++;
    }

    push(s,substring);
}


/////////////// EXTRAS //////////////////
/**
 * Concat array extra function.
 */
stackElem concatArray(stackElem fstElem, stackElem sndElem)
{
    stackElem res;

    res.type.a = sndElem.type.a;

    int i = res.type.a->sp;
    int j = 0;
    int length = res.type.a->cap + fstElem.type.a->cap;

    for(i++; i < length ; i++)
    {
        res.type.a->stack[i] = fstElem.type.a->stack[j];
        j++;
    }

    res.type.a->cap = length;
    res.type.a->sp = i;
    return res;
}

/**
 * Concat string extra function.
 */
stackElem concatString(stackElem fstElem, stackElem sndElem)
{
    stackElem res;

    res = sndElem;

    int i = res.type.s->sp;
    int j = 0;
    int length = res.type.s->length + fstElem.type.s->length;


    for (++i; i < length; i++)
    {
        res.type.s->str[i] = fstElem.type.s->str[j];
        j++;
    }

    res.type.s->length = length;
    res.type.s->sp = --i;

    return res;
}

/**
 * Creates an Array.
 */
stackElem createArray(int range)
{
    stackElem array;
    stackElem in;
    in.elemType = Int;
    array.elemType = Array;
    array.type.a = new_stack();

    int i = 0;

    for(; i < range; i++)
    {
        in.type.i = i;
        array.type.a->stack[i] = in;
    }

    return array;
}

/**
 * Updates the Array, changing its length and pointer.
 */
stackElem updateArray(stackElem array, int range)
{
    stackElem res;

    if(array.elemType == String)
    {
        res.type.s = newString();
        res.elemType = String;

        int i = range;
        int length = array.type.s->sp;


        for(; i <= length ; i++)
        {
            res.type.s->str[i - range] = array.type.s->str[i];
        }

        res.type.s->length = length;
        res.type.s->sp = --length;
        return res;
    }
    else
    {
        res.type.a = new_stack();
        res.elemType = Array;

        int i = range;
        int length = array.type.a->sp;

        for(; i <= length ; i++ )
            res.type.a->stack[i-range] = array.type.a->stack[i];

        res.type.a->cap = length;
        res.type.a->sp = --length;
        return res;
    }

}

/**
 * Updates the Array, changing its length and pointer.
 */
stackElem updateArray2(stackElem array)
{
    stackElem res;

    if(array.elemType == String)
    {
        res.type.s = newString();
        res.elemType = String;

        int i = 0;
        int length = array.type.s->sp;


        for(; i < length ; i++)
        {
            res.type.s->str[i] = array.type.s->str[i];
        }

        res.type.s->length = length;
        res.type.s->sp = --length;
        return res;
    }
    else
    {
        res.type.a = new_stack();
        res.elemType = Array;

        int i = 0;
        int length = array.type.a->sp;

        for(; i <= length ; i++ )
            res.type.a->stack[i] = array.type.a->stack[i];

        res.type.a->cap = length;
        res.type.a->sp = --length;
        return res;
    }
}

/**
 * Converts the line to a string.
 */
stackElem lineToString()
{
    stackElem val;
    char num[2048];

    int i = 0;
    val.elemType = String;
    val.type.s = newString();

    if(fgets(num,2048,stdin) == NULL)
    {
        val.elemType = Int;
        return val;
    }

    while(num[i] != '\0')
    {
        val.type.s->str[i] = num[i];
        i++;
    }

    val.type.s->sp = --i;
    val.type.s->length = i;

    return val;
}

/**
 * Split a string by newlines extra function.
 */
stackElem cutStrNL(stackElem str)
{
    int i = 0;

    while(str.type.s->str[i] != '\n')
        i++;

    str.type.s->sp = --i;
    str.type.s->sp = i;

    return str;
}

/**
 * Split a string by whitespace extra function.
 */
stackElem cutStrWS(stackElem str)
{
    int i = 0;

    while(! isspace(str.type.s->str[i]))
        i++;

    str.type.s->sp = --i;
    str.type.s->sp = i;

    return str;
}

/**
 * Split string extra function.
 */
stackElem cutStrForm(stackElem str, stackElem form)
{
    int i = 0;
    int counter = 0;
    int formLength = form.type.s->length;

    while(counter != formLength || str.type.s->sp != i)
    {
        if(str.type.s->str[i] == form.type.s->str[i])
        {
            counter++;
        }
        else
        {
            counter = 0;
        }
        i++;
    }

    if(counter == formLength)
    {
        str.type.s->sp = i - counter;
        str.type.s->length = i - counter + 1;

        return str;
    }
    else
    {
        return str;
    }

}

