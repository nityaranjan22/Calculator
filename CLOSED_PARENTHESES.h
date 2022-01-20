#ifndef _CLOSED_PARENTHESES_H_
#define _CLOSED_PARENTHESES_H_

#include "Expr_Node.h"
#include <memory>

class CLOSED_PARENTHESES : public Expr_Node
{
public:
  CLOSED_PARENTHESES (void);
   virtual ~CLOSED_PARENTHESES (void);

  virtual void accept (Visitor & visitor);

  virtual int Priority (void);

  virtual std::shared_ptr<Expr_Node> getParent (void); //shared_ptr used for Proxy Pattern

  virtual void setParent (std::shared_ptr<Expr_Node> node); //shared_ptr used for Proxy Pattern


protected:
    std::shared_ptr<Expr_Node> Parent; //shared_ptr used for Proxy Pattern
};


#endif   // !defined _CLOSED_PARENTHESES_H_
