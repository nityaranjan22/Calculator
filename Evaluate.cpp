#include "Evaluate.h"
#include "ADD.h"
#include "SUBTRACT.h"
#include "MULTIPLY.h"
#include "DIVIDE.h"
#include "MOD.h"
#include "INTEGER.h"

Evaluate::Evaluate (void){}

Evaluate::~Evaluate (void){}

//
// Visit Add Node
//
void Evaluate::Visit_ADD(ADD & ADD)
    {
        //visit left and right children
        ADD.getRightChild()->accept(*this);
        ADD.getLeftChild()->accept(*this);
        //pull first number from the stack
        int number1 = this->Result_Stack.top();
        this->Result_Stack.pop();
        //pull second number from the stack
        int number2 = this->Result_Stack.top();
        this->Result_Stack.pop();
        //evaluate expression
        int result = number1 + number2;
        //push result to the stack
        this->Result_Stack.push(result);
        return;
    }

//
// Visit Subtract Node
//
void Evaluate::Visit_SUBTRACT(SUBTRACT & SUBTRACT)
    {
        //visit left and right children
        SUBTRACT.getRightChild()->accept(*this);
        SUBTRACT.getLeftChild()->accept(*this);
        //pull first number from the stack
        int number1 = this->Result_Stack.top();
        this->Result_Stack.pop();
        //pull second number from the stack
        int number2 = this->Result_Stack.top();
        this->Result_Stack.pop();
        //evaluate expression
        int result = number1 - number2;
        //push result to the stack
        this->Result_Stack.push(result);
        return;
    }

//
// Visit Multiply Node
//
void Evaluate::Visit_MULTIPLY(MULTIPLY & MULTIPLY)
    {
        //visit left and right children
        MULTIPLY.getRightChild()->accept(*this);
        MULTIPLY.getLeftChild()->accept(*this);
        //pull first number from the stack
        int number1 = this->Result_Stack.top();
        this->Result_Stack.pop();
        //pull second number from the stack
        int number2 = this->Result_Stack.top();
        this->Result_Stack.pop();
        //evaluate expression
        int result = number1 * number2;
        //push result to the stack
        this->Result_Stack.push(result);
        return;
    }

//
// Visit Divide Node
//
void Evaluate::Visit_DIVIDE(DIVIDE & DIVIDE)
    {
        //visit left and right children
        DIVIDE.getRightChild()->accept(*this);
        DIVIDE.getLeftChild()->accept(*this);
        //pull first number from the stack
        int number1 = this->Result_Stack.top();
        this->Result_Stack.pop();
        //pull second number from the stack
        int number2 = this->Result_Stack.top();
        this->Result_Stack.pop();
        //evaluate expression
        if (number2 == 0)
        {
            throw divide_by_zero_exception();
            return;
        }
        int result = number1 / number2;
        //push result to the stack
        this->Result_Stack.push(result);
        return;
    }

//
// Visit Mod Node
//
void Evaluate::Visit_MOD(MOD & MOD)
    {
        //visit left and right children
        MOD.getRightChild()->accept(*this);
        MOD.getLeftChild()->accept(*this);
        //pull first number from the stack
        int number1 = this->Result_Stack.top();
        this->Result_Stack.pop();
        //pull second number from the stack
        int number2 = this->Result_Stack.top();
        this->Result_Stack.pop();
        //evaluate expression
        if (number2 == 0)
        {
            throw mod_by_zero_exception();
            return;
        }
        int result = number1 % number2;
        //push result to the stack
        this->Result_Stack.push(result);
        return;
    }

//
// Visit Integer Node
//
void Evaluate::Visit_INTEGER(INTEGER & INTEGER)
    {
        this->Result_Stack.push(INTEGER.getValue());
        return;
    }

//
// Result
//
int Evaluate::result(void)
    {
        //return the result
        return this->Result_Stack.top();
    }

