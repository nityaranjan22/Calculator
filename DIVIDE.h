#ifndef _DIVIDE_H_
#define _DIVIDE_H_

#include "BinaryExpr.h"

class DIVIDE : public BinaryExpr
{
public:
  DIVIDE (void);
   virtual ~DIVIDE (void);

  virtual void accept (Visitor & visitor);

  virtual int Priority (void);
};


#endif   // !defined _DIVIDE_H_
