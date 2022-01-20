#ifndef _MOD_H_
#define _MOD_H_

#include "BinaryExpr.h"

class MOD : public BinaryExpr
{
public:
  MOD (void);
   virtual ~MOD (void);

  virtual void accept (Visitor & visitor);

  virtual int Priority (void);
};


#endif   // !defined _MOD_H_
