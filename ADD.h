#ifndef _ADD_H_
#define _ADD_H_

#include "BinaryExpr.h"
#include "Visitor.h"

class ADD: public BinaryExpr
{
public:
  ADD (void);
  virtual ~ADD (void);

  virtual void accept (Visitor & visitor);
  virtual int Priority (void);
};


#endif
