#include "INTEGER.h"
#include "Visitor.h"

INTEGER::INTEGER (int number):
    int_value(number),
    Parent(nullptr)
    {}

INTEGER::~INTEGER (void){}

void INTEGER::accept (Visitor & visitor)
    {
        visitor.Visit_INTEGER(*this);
    }

int INTEGER::Priority (void)
    {
        return 0;
    }

std::shared_ptr<Expr_Node> INTEGER::getParent(void) //shared_ptr used for Proxy Pattern
    {
        return this->Parent;
    }

void INTEGER::setParent(std::shared_ptr<Expr_Node> node) //shared_ptr used for Proxy Pattern
    {
        this->Parent = node;
    }

int INTEGER::getValue(void)
    {
        return int_value;
    }
