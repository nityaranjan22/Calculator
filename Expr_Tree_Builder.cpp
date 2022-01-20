#include "Expr_Tree_Builder.h"
#include "Iterator.h"
#include <memory>

Expr_Tree_Builder::Expr_Tree_Builder (void):
	Operator_Stack(),
	Postfix_Stack()
    {

    }
Expr_Tree_Builder::~Expr_Tree_Builder (void)
    {

        //HANDLED BY SHARED POINTERS IN PROXY PATTERN
    }

/* These functions build our nodes using the builder pattern*/
void Expr_Tree_Builder::Build_ADD(void)
    {
        std::shared_ptr<Expr_Node> node(new ADD()); //shared_ptr used for Proxy Pattern
        Build_Postfix(node);
    }

void Expr_Tree_Builder::Build_SUBTRACT(void)
    {
        std::shared_ptr<Expr_Node> node(new SUBTRACT()); //shared_ptr used for Proxy Pattern
        Build_Postfix(node);
    }

void Expr_Tree_Builder::Build_MULTIPLY(void)
    {
        std::shared_ptr<Expr_Node> node(new MULTIPLY()); //shared_ptr used for Proxy Pattern
        Build_Postfix(node);
    }

void Expr_Tree_Builder::Build_DIVIDE(void)
    {
        std::shared_ptr<Expr_Node> node(new DIVIDE()); //shared_ptr used for Proxy Pattern
        Build_Postfix(node);
    }

void Expr_Tree_Builder::Build_MOD(void)
    {
        std::shared_ptr<Expr_Node> node(new MOD()); //shared_ptr used for Proxy Pattern
        Build_Postfix(node);
    }

void Expr_Tree_Builder::Build_INTEGER(int number)
    {
        std::shared_ptr<Expr_Node> node(new INTEGER(number)); //shared_ptr used for Proxy Pattern
        Build_Postfix(node);
    }

void Expr_Tree_Builder::Build_OPEN_PARENTHESES(void)
    {
        std::shared_ptr<Expr_Node> node(new OPEN_PARENTHESES()); //shared_ptr used for Proxy Pattern
        Build_Postfix(node);
    }
void Expr_Tree_Builder::Build_CLOSED_PARENTHESES(void)
    {
        std::shared_ptr<Expr_Node> node(new CLOSED_PARENTHESES()); //shared_ptr used for Proxy Pattern
        Build_Postfix(node);
    }


void Expr_Tree_Builder::findOpenParen(void)
{
    //check for open paren
    while(this->Operator_Stack.top()->Priority() != 4)
    {
        //for all other operators push to postfix stack and pop
        this->Postfix_Stack.push(this->Operator_Stack.top());
        this->Operator_Stack.pop();
    }
    //pop the open paren
    this->Operator_Stack.pop();
    return;
}

void Expr_Tree_Builder::Build_Postfix(std::shared_ptr<Expr_Node> node) //shared_ptr used for Proxy Pattern
    {
        //push all integers directly to the Postfix Stack
        if(node->Priority() == 0)
        {
            this->Postfix_Stack.push(node);
        }
        //push the first node onto the Operator stack
        else if(this->Operator_Stack.is_empty())
        {
            this->Operator_Stack.push(node);
            return;
        }
        //check if the node is a parentheses
        else if(node->Priority() == 4)
        {
            this->Operator_Stack.push(node);
            return;
        }
        //check for closed parentheses
        else if(node->Priority() == 5)
        {

            this->findOpenParen();
            return;
        }
        //compare priority of node with that on the operator stack
        else if(node->Priority() > this->Operator_Stack.top()->Priority())
        {
            this->Operator_Stack.push(node);
            return;
        }
        //for all other cases push operators to postfix stack and pop stack (until we find an open parentheses)
        else
        {
            for(Iterator<std::shared_ptr<Expr_Node> > s_iter(Operator_Stack); !s_iter.is_done() && (*s_iter)->Priority() != 4; s_iter.advance() ) //shared_ptr used for Proxy Pattern
            {
                this->Postfix_Stack.push(*s_iter);
            }
            //push operator to stack
            this->Operator_Stack.push(node);
            return;
        }
    }

//builds a tree from a Postfix expression contained in Postfix_Stack
//Checks right children until it finds a number_node/nullptr
Expr_Node & Expr_Tree_Builder::Build_Tree(void)
    {
        //create a root and current node
        std::shared_ptr<Expr_Node> root; //shared_ptr used for Proxy Pattern
        std::shared_ptr<BinaryExpr> current; //shared_ptr used for Proxy Pattern

        //empty the operator stack first
        for(Iterator<std::shared_ptr<Expr_Node> > s_iter(Operator_Stack); !s_iter.is_done(); s_iter.advance() ) //shared_ptr used for Proxy Pattern
            {
                this->Postfix_Stack.push(*s_iter);
            }
        root = this->Postfix_Stack.top();
        this->Postfix_Stack.pop();
        current = std::dynamic_pointer_cast<BinaryExpr>(root); //Dynamic casting used to convert the type of our shared pointer
        current->setLeftChild(nullptr);
        current->setRightChild(nullptr);
        while(this->Postfix_Stack.is_empty() == false)
        {
            if(current->getRightChild() == nullptr)
            {

                current->setRightChild(this->Postfix_Stack.top());
                this->Postfix_Stack.top()->setParent(current);

                if(Postfix_Stack.top()->Priority() != 0)
                    {
                        //Dynamic casting used to convert the type of our shared pointer
                        current = std::dynamic_pointer_cast<BinaryExpr>(this->Postfix_Stack.top()); //set new current node
                    }
                this->Postfix_Stack.pop();
            }
            else if (current->getLeftChild() == nullptr)
            {

                current->setLeftChild(this->Postfix_Stack.top());
                this->Postfix_Stack.top()->setParent(current);
                if(Postfix_Stack.top()->Priority() != 0) //check for nonintegers
                    {
                        //Dynamic casting used to convert the type of our shared pointer
                        current = std::dynamic_pointer_cast<BinaryExpr>(this->Postfix_Stack.top()); //set new current node
                    }
                this->Postfix_Stack.pop();
            }
            else
            {

                //set current leaf to its parent
                if(current == root)
                {
                }
                else
                {
                    //Dynamic casting used to convert the type of our shared pointer
                    current = std::dynamic_pointer_cast<BinaryExpr>(current->getParent()); //set current to current's parent node
                }
            }
        }
        return *root;
    }

