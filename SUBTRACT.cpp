#include "SUBTRACT.h"
#include "Visitor.h"
SUBTRACT::SUBTRACT (void){}
SUBTRACT::~SUBTRACT (void){}

void SUBTRACT::accept (Visitor & visitor)
    {
        visitor.Visit_SUBTRACT(*this);
    }

int SUBTRACT::Priority (void)
    {
        return 1;
    }
