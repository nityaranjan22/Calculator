#include "OPEN_PARENTHESES.h"
#include "Evaluate.h"
#include <memory>

OPEN_PARENTHESES::OPEN_PARENTHESES (void){}

OPEN_PARENTHESES::~OPEN_PARENTHESES (void){}

void OPEN_PARENTHESES::accept (Visitor & visitor){}

int OPEN_PARENTHESES::Priority (void)
    {
        return 4;
    }

std::shared_ptr<Expr_Node> OPEN_PARENTHESES::getParent(void) //shared_ptr used for Proxy Pattern
    {
        return this->Parent;
    }

void OPEN_PARENTHESES::setParent(std::shared_ptr<Expr_Node> node) //shared_ptr used for Proxy Pattern
    {
        this->Parent = node;
    }
