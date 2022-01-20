#ifndef _SUBTRACT_H_
#define _SUBTRACT_H_

#include "BinaryExpr.h"

class SUBTRACT : public BinaryExpr
{
public:
  SUBTRACT (void);
   virtual ~SUBTRACT (void);

  virtual void accept (Visitor & visitor);

  virtual int Priority (void);
};


#endif   // !defined _SUBTRACT_H_
