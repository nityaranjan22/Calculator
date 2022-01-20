#ifndef _OPEN_PARENTHESES_H_
#define _OPEN_PARENTHESES_H_

#include "Expr_Node.h"
#include <memory>

class OPEN_PARENTHESES : public Expr_Node
{
public:
  OPEN_PARENTHESES (void);
   virtual ~OPEN_PARENTHESES (void);
  virtual void accept (Visitor & visitor);

  virtual int Priority (void);

  virtual std::shared_ptr<Expr_Node> getParent (void); //shared_ptr used for Proxy Pattern
  virtual void setParent (std::shared_ptr<Expr_Node> node); //shared_ptr used for Proxy Pattern


protected:
    std::shared_ptr<Expr_Node> Parent; //shared_ptr used for Proxy Pattern
};


#endif   // !defined _OPEN_PARENTHESES_H_
