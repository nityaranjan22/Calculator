#include "MOD.h"
#include "Visitor.h"
MOD::MOD (void){}

MOD::~MOD (void){}

void MOD::accept (Visitor & visitor)
    {
        visitor.Visit_MOD(*this);
    }

int MOD::Priority (void)
    {
        return 2;
    }
