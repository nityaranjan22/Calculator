#include "DIVIDE.h"
#include "Visitor.h"
DIVIDE::DIVIDE (void){}

DIVIDE::~DIVIDE (void){}

void DIVIDE::accept (Visitor & visitor)
    {
        visitor.Visit_DIVIDE(*this);
    }

int DIVIDE::Priority (void)
    {
        return 2;
    }
