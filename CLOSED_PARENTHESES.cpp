#include "CLOSED_PARENTHESES.h"
#include "Evaluate.h"
#include <memory>

CLOSED_PARENTHESES::CLOSED_PARENTHESES (void){}


CLOSED_PARENTHESES::~CLOSED_PARENTHESES (void){}

void CLOSED_PARENTHESES::accept (Visitor & visitor){}

int CLOSED_PARENTHESES::Priority (void)
    {
        return 5;
    }

std::shared_ptr<Expr_Node> CLOSED_PARENTHESES::getParent(void) //shared_ptr used for Proxy Pattern
    {
        return this->Parent;
    }

void CLOSED_PARENTHESES::setParent(std::shared_ptr<Expr_Node> node) //shared_ptr used for Proxy Pattern
    {
        this->Parent = node;
    }
