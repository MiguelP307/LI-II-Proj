#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "mathExpressions.h"
#include "stackOperations.h"
#include "conversions.h"
#include "commands.h"
#include "logicalExpressions.h"
#include "arraysManipulation.h"

/**
 * Function that identifies and executes the wanted operation.
 */
void handle(STACK *s, char *token) {
    Types temp1 = peek(s,0).elemType; /*!< Stores the first peeked element. */
    Types temp2 = peek(s,1).elemType; /*!< Stores the second peeked element. */

    stackElem tempElem;

    if (strcmp(token, "+") == 0) /// "+" symbol has two functions associated: concat and add.
    {
        if(temp1 == String || temp1 == Array || temp2 == String || temp2 == Array) /// Case in which the at least one of the peeked elements is an Array/String.
            concatenateArrays(s);
        else /// Case in which the peeked elements are digits.
            add(s);
    }

    else if (strcmp(token, "-") == 0) /// Calling the function subtract
        subtract(s);

    else if(strcmp(token, "*") == 0) /// "*" symbol has two functions associated: concatenateArrayMult and multiply Elements.
    {
        if(temp1 == Int && (temp2 == String || temp2 == Array)) /// Case in which the first peeked element is an Integer and the second is either a String/Array.
            concatenateArrayMult(s); /// Calls the function  concatenateArrayMult.
        else /// Case in which the elements peeked are both digits.
            multiplyElements(s); /// Calls the function multiplyElements.
    }

    else if(strcmp(token, "/") == 0)  /// "/" symbol has two functions associated: cutString and divideElements.
    {
        if(temp1 == String && temp2 == String) /// Case in which the peeked elements are both strings.
            cutString(s); /// Calls the function cutString.
        else /// Case in which the elements are digits.
            divideElements(s); /// Calls the function  divideElements.
    }

    else if(strcmp(token, ")") == 0) /// ")" symbol has two functions associated: rmLastElem and incrementElement.
    {
        if(temp1 == Array || temp1 == String) /// Case in which the element peeked is an Array/String.
            rmLastElem(s); /// Calls the function rmLastElem.
        else /// Case in which the peeked element is a Digit.
            incrementElement(s); /// Calls the function incrementElement.
    }

    else if(strcmp(token, "(") == 0) /// "(" symbol has two functions associated: rmFirstElem and decrementElement.
    {
        if(temp1 == Array || temp1 == String) /// Case in which the element peeked is an Array/String.
            rmFirstElem(s); /// Calls the function rmFirstElem.

        else /// Case in which the peeked element is a Digit.
            decrementElement(s); /// Calls the function decrementElement.
    }

    else if(strcmp(token, "%") == 0) /// Calling the function moduloElement.
        moduloElement(s);

    else if(strcmp(token, "#") == 0) /// "#" symbol has two functions associated: searchSubString and exponenciacaoElement.
    {
        if(temp1 == String && temp2 == String) /// Case in which the elements peeked are Strings.
            searchSubString(s); /// Calls the function searchSubString.
        else /// Case in which the elements peeked are Digits.
            exponenciacaoElement(s); /// Calls the exponenciacaoElement.
    }

    else if(strcmp(token, "&") == 0) /// Calling the function andBitwise.
        andBitwise(s);

    else if(strcmp(token, "|") == 0) /// Calling the function orBitwise.
        orBitwise(s);

    else if(strcmp(token, "^") == 0) /// Calling the function xorBitwise.
        xorBitwise(s);

    else if(strcmp(token, "~") == 0) /// The symbol has two functions associated: arrayToStack and notBitwise.
    {
        if(temp1 == Array) /// Case in which the element peeked is an Array.
            arrayToStack(s); /// Calls the function arrayToStack.
        else /// Case in which the element peeked is a Digit.
            notBitwise(s); /// Calls the function notBitwise.
    }

    else if(strcmp(token, "_") == 0) /// Calling the function duplicate.
        duplicate(s);

    else if(strcmp(token, ";") == 0) /// Calling the function pop.
        pop(s);

    else if(strcmp(token, "\\") == 0) /// Calling the function swap.
        swap(s);

    else if(strcmp(token,"@") == 0) /// Calling the function rotateElements.
        rotateElements(s);

    else if(strcmp(token, "$") == 0) /// Calling the function copyElement.
        copyElement(s);

    else if(strcmp(token, "i") == 0) /// Calling the function toInt.
        toInt(s);

    else if(strcmp(token, "f") == 0) /// Calling the function toDouble.
        toDouble(s);

    else if(strcmp(token, "c") == 0) /// Calling the function toChar.
        toChar(s);

    else if(strcmp(token, "s") == 0) /// Calling the function toString.
        toString(s);

    else if(strcmp(token, "l") == 0) /// Calling the function readLine.
        readLine(s);

    else if(token[0] == ':') /// Calling the function setVar.
        setVar(s,token[1]);

    else if(strcmp(token, "=") == 0) /// "=" symbol has two functions associated: catchIndice and equalOp.
    {
        if(temp1 == Int && (temp2 == String || temp2 == Array)) /// Case in which the first peeked elements is an Integer and the second is either a String or an Array.
            catchIndice(s); /// Calls the function catchIndice.
        else /// Calling the function equalOp.
            equalOp(s);

    }

    else if(strcmp(token, "<") == 0) /// "<" symbol has two functions associated: catchFirstElems and lowerLogical.
    {
        if(temp1 == Int && (temp2 == String || temp2 == Array)) /// Case in which the first peeked elements is an Integer and the second is either a String or an Array.
            catchFirstElems(s); /// Calls the function catchFirstElem.
        else /// Otherwise calls the function lowerLogical.
            lowerLogical(s);
    }

    else if(strcmp(token, ">") == 0) /// ">" symbol has two functions associated: catchLastElem and higherLogical.
    {
        if(temp1 == Int && (temp2 == String || temp2 == Array)) /// Case in which the first peeked elements is an Integer and the second is either a String or an Array.
            catchLastELems(s); /// Calls the function catchLastElem.
        else /// Otherwise calls the function higherLogical.
            higherLogical(s);
    }

    else if(strcmp(token, "!") == 0) /// Calling the function notOp.
        notOp(s);

    else if(token[0] == 'e') /// "e" symbol has two functions associated depending on the symbol that follows it ( "&", "|", "<", ">").
    {
        if(token[1] == '&') /// Calling the function andWShortCut.
            andWShortcut(s);

        else if(token[1] == '|') /// Calling the function orWShortCut.
            orWShortcut(s);

        else if(token[1] == '<') /// Calling the function lower.
            lower(s);

        else if(token[1] == '>') /// Calling the function higher.
            higher(s);
    }

    else if(strcmp(token, "?") == 0) /// Calling the function ifThenELse.
        ifThenElse(s);

    else if(strcmp(token, "t") == 0) /// Calling the function readAllLines.
        readAllLines(s);

    else if(strcmp(token, ",") == 0) /// Calling the function lengthOrRange.
        lengthOrRange(s);

    else if(token[0] == 'N' && token[1] == '/' ) /// Calling the function cutStringWSpace.
        cutStringWSpace(s);

    else if(token[0] == 'S' && token[1] == '/' ) /// Calling the function cutStringEnter.
        cutStringEnter(s);

    else
    {

        stackElem val;
        char num[2048];
        sscanf(token, "%s", num);

        if(isDigit(num)) /// Check is the elements is a Digit.
        {
            if(isFloat(num))
            {
                val.elemType = Double;
                val.type.d = atof(num); /// Converting the string element to a Float.
            }
            else
            {
                val.elemType = Int;
                val.type.i = atoi(num); /// Converting the string element to an Integer.
            }
        }
        else if(token[0] >= 'A' && token[0] <= 'Z') /// Search the letters "A" to "Z" to call the function getVar.
        {
            push(s, getVar(s,token[0]));
            return;
        }
        else if(token[0] == '"') /// Searching the first '"' to start the String
        {
            tempElem.type.s = newString(); /// Creates a new string.
            tempElem.elemType = String; /// Defining the elemType as String.
            int i = 0;

            while(token[i+1] != '"' ) /// Searching the second '"' to end the String.
            {
                tempElem.type.s->str[i] = token[i+1];
                i++;
            }


            tempElem.type.s->sp = i - 1; /// Decreases stack pointer by one.
            tempElem.type.s->length = i; /// Defining string length as "i".
            push(s,tempElem);
            return;
        }
        else if(token[0] == '[') /// Search the square bracket to create an Array.
        {
            val = createNewArray(token,1);
        }
        else
        {
            return;
        }
        push(s,val); /// Pushes the result to the stack.
    }
    return;
}

/**
 * Main function.
 * Goes through the lines, calling the function handle and checking the starts and ends of Strings, Arrays and Blocks.
 */
int main() {
    STACK *s = new_stack(); /// Creating the stack.
    defaultVars(s); /// Introducing the default variables.
    char line[BUFSIZ]; /*!< Stores the line array. */
    char token[BUFSIZ]; /*!< Stores the token array. */
    int isArray = 0; /*!< Variable that stores the information if element is an Array or not. */
    int isString = 0; /*!< Variable that stores the information if element is a String or not. */
    int isBloc = 0; /*!< Variable that stores the information if element is a Bloc or not. */
    int c = 0 ;
    int j = 0;

    if (fgets(line, BUFSIZ, stdin) != NULL) /// Calling the function fgets to go through the lines.
    {
        while(line[c] != '\0') /// Going through the given string.
        {
            if(line[c] == ' ' && !isString && !isArray && !isBloc && line[c-1] != ' ')  /// Case in which it neither a String or Array or Block and it doesn't have a space right behind.
            {
                handle(s, token); /// Calls the handle function.
                memset(token,0,strlen(token)); /// Copies the character "0" to the n(strlen(token)) elements of the token.
                j = -1;
            }
            else if(line[c] == '"') /// Checks if the string element is the symbol '"'
            {
                if(!isString) /// Case in which it's not a String.
                {
                    isString++; /// Adds 1 to isString.
                    token[j] = line[c];
                }
                else
                {
                    isString = 0; /// Closes the string by setting isString to 0.
                    token[j] = line[c];
                }
            }
            else if(line[c] == '[') /// Searches the square bracket to start an Array.
            {
                isArray++; /// Adds 1 to isArray.
                token[j] = line[c];
            }
            else if(line[c] == ']') /// Searches the square bracket to end the Array.
            {
                if(isArray == 1)
                    isArray = 0; /// Sets isArray to 0.
                else
                    isArray--;
                token[j] = line[c];
            }
            else if(line[c] == '{') /// Searches the curly bracket to start the Block..
            {
                isBloc++; /// Sets isBLock to 1.
                token[j] = line[c];
            }
            else if(line[c] == '}') /// Searches the curly bracket
            {
                if(isBloc == 1)
                    isBloc= 0; /// Sets isBLoc to 0.
                else
                    isBloc--; /// Decrements isBlock by one.
                token[j] = line[c];
            }
            else if(line[c] == ' ' && !isString && !isArray && isBloc)
            {
                j = -1;
            }
            else if(line[c] != '\n')
                token[j] = line[c];

            else
            {

            }

            j++;
            c++;
        }
        handle(s, token); /// Calls the function handle.

        printStack(s,1); /// Calls the function printStack.

        printf("\n");
    }

    return 0;
}


