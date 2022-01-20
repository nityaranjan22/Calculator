#include "MULTIPLY.h"
#include "Visitor.h"

MULTIPLY::MULTIPLY (void){}
MULTIPLY::~MULTIPLY (void){}
void MULTIPLY::accept (Visitor & visitor)
    {
        visitor.Visit_MULTIPLY(*this);
    }

int MULTIPLY::Priority (void)
    {
        return 2;
    }
