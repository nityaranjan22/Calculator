//********* Stack, Array, and Base Array **********
#include "BaseArray.h"
#include "Array.h"
#include "Stack.h"

//********* include nodes **********************

#include "Expr_Node.h"

#include "BinaryExpr.h"
#include "ADD.h"
#include "SUBTRACT.h"
#include "MULTIPLY.h"
#include "DIVIDE.h"
#include "MOD.h"
#include "OPEN_PARENTHESES.h"
#include "CLOSED_PARENTHESES.h"
#include "INTEGER.h"


//**********Other Includes*************************

#include "Expr_Builder.h"
#include "Expr_Tree_Builder.h"
#include "Evaluate.h"
#include "Visitor.h"

//********** C++ libraries ************************
#include "stdio.h"
#include <iostream>
#include <stdexcept>
#include <cstdlib>
#include <cstring>          // for size_t definition
#include <sstream>
//
// main
//



bool checkIsValidExpression(const std::string & inputStr);
int Build (const std::string & inputStr);

int main (int argc, char * argv [])
{
    std::string inputStr;
    std::string quitStr;
    std::string postFixStr;
    std::string tempStr;
    quitStr = "QUIT";

  printf("Please enter a valid expression or 'QUIT' to quit:\n");
    getline(std::cin, inputStr);
    while (inputStr.compare(quitStr) != 0)
    {
        //check for a valid expression
	if (checkIsValidExpression(inputStr) == true)
	{
        try
		{
		    //compute the expression
			printf("Result: %d \n", Build(inputStr));
		}
		// catch "divide by" exceptions
		catch(divide_by_zero_exception)
		{
			printf("Divide by zero error, try again.\n");

		}

		catch(mod_by_zero_exception)
		{
			printf("Mod by zero error, try again.\n");

		}


	}
	else
	{
		//print this message if we dont have a valid expression, get new line
		printf("Invalid Expression, please retype. \n");
	}

	printf("Please enter a valid expression or 'QUIT' to quit:\n");
	getline(std::cin, inputStr);
    }



}



//
//infix_to_postfix
//
int Build (const std::string & infix)
 {
	std::istringstream input(infix); // create a input stream parser
	std::string token; // current token in string/stream

	//create our builder and visitor
    Expr_Tree_Builder builder;
    Evaluate visitor;

	int count = 0; //count the position in the array
	int number = 0;
	//loop until the end of the string
	while (!input.eof())
	{
		//parse the istringstream
		input >> token;
		//create our command based on the token
		if (token == "+")
			builder.Build_ADD();
		else if (token == "-")
			builder.Build_SUBTRACT();
		else if (token == "*")
			builder.Build_MULTIPLY();
		else if (token == "/")
            		builder.Build_DIVIDE();
		else if (token == "%")
            		builder.Build_MOD();
		else if (token == "(")
			builder.Build_OPEN_PARENTHESES();
		else if (token == ")")
		    builder.Build_CLOSED_PARENTHESES();
		//uses stoi to convert the string to an integer to be used as input for build_integer_command(int integer)
		else
		{
			number = std::stoi(token.c_str());
			builder.Build_INTEGER(number);

		}
	}

    //build our tree and visit the nodes
    builder.Build_Tree().accept(visitor);

    //return the result of our visitations
    return visitor.result();

 }



//
//checkIsValidExpression
//
bool checkIsValidExpression(const std::string & inputStr)
{
        std::istringstream input(inputStr); // create a input stream parser
        std::string token; // current token in string/stream
	// Flags to check if we have two operators next to each other or two operands next to each other
	bool SecondOperatorFlag = false;
	bool SecondOperandFlag = false;
	bool firstToken = true;
	//counts parantheses both opened and closed
	int numOpenParen = 0;
	int numCloseParen = 0;
	int number = 0;
	//loop until the end of file
        while (!input.eof())
        {
        	input >> token;
		//check to ensure the first token is an integer or an open paren
		if (firstToken == true)
		{
			firstToken = false;
			if(token == "(")
			{
				//do nothing
			}
			else
			{
				SecondOperandFlag == true;
				try
                        	{
                                	//convert a string into an integer
                                        number = std::stoi(token.c_str());
                                }
                                catch(const std::invalid_argument& err)
                                {
 	                               return false;
                                }
                        }
		}

		//check if token is an operator token
        	if (token == "+" || token == "-" || token == "*" || token == "/" || token == "%" || token == "(" || token == ")")
        	{
			if(SecondOperatorFlag && token != "(")
			{
				return false;
			}
			//set operator flag to true and operand flag to false (next token we want is an operand)
			SecondOperandFlag = false;
			SecondOperatorFlag = true;
			//increment respective parentheses counter
			if(token == "(")
			{
				numOpenParen++;
			}
			else if(token == ")")
			{
				numCloseParen++;
				SecondOperatorFlag = false; // this is done to ensure an operator can follow a closed paren
				SecondOperandFlag = true;
			}
			//if we have more closed parentheses than open at any time it cannot be a valid expression
			if(numOpenParen < numCloseParen)
			{
				return false;
			}
			if(numCloseParen == 1)
			{
				//remove a close and open parentheses from our count
				numCloseParen--;
				numOpenParen--;
			}
		}
		//if it is not an operator token it must be an operand token
        	else
       		{
			//check for two operands in a row, if found return false
                	if(SecondOperandFlag)
			{
				return false;
			}
			//this try catch will cause this function to return false for any invalid input ie: "1 ++ 1"
			try
			{
				//convert a string into an integer
				number = std::stoi(token.c_str());
			}
			catch(const std::invalid_argument& err)
			{
				return false;
			}
			//set operand flag to true and operator flag to false (next token we want is an operator)
        		SecondOperandFlag = true;
			SecondOperatorFlag = false;

		}
	}
	//check the number of close parentheses matches the number of open parentheses
	//last token should be an integer or a closen parentheses, so this will check that and return false if that is not the case
	if(token != ")")
	{
		try
        	{
        		//convert a string into an integer
        		number = std::stoi(token.c_str());
        	}
        	catch(const std::invalid_argument& err)
        	{
      			return false;
        	}
	}
	//check the number of closed parentheses matches the number of open parentheses
        if(numCloseParen != numOpenParen)
	{
		return false;
	}
	//return true if the expression passes all of the tests
	return true;
}
