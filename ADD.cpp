#include "ADD.h"
#include "Visitor.h"
ADD::ADD (void){}

ADD::~ADD (void){}

void ADD::accept (Visitor & visitor)
    {
        visitor.Visit_ADD(*this);
    	return;
    }


int ADD::Priority (void)
    {
        return 1;
    }