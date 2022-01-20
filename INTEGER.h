#ifndef _INTEGER_H_
#define _INTEGER_H_

#include "Expr_Node.h"
#include "Visitor.h"
#include <memory>

class INTEGER : public Expr_Node
{
public:
  INTEGER (int number);
   virtual ~INTEGER (void);

  virtual void accept (Visitor & visitor);
  virtual int Priority (void);

  virtual std::shared_ptr<Expr_Node> getParent (void); //shared_ptr used for Proxy Pattern
 
  virtual void setParent ( std::shared_ptr<Expr_Node> node); //shared_ptr used for Proxy Pattern

  int getValue (void);


protected:
  std::shared_ptr<Expr_Node> Parent; //shared_ptr used for Proxy Pattern
private:

  int int_value;

};


#endif   // !defined _INTEGER_H_
