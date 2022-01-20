#ifndef _EXPR_NODE_H_
#define _EXPR_NODE_H_
#include <memory>
//forward declaring the Visitor class
class Visitor;

class Expr_Node
{
public:
  Expr_Node (void);
   virtual ~Expr_Node (void)=0;

  virtual void accept (Visitor & visitor) = 0;
  virtual int Priority (void) = 0;
  virtual std::shared_ptr<Expr_Node> getParent (void) =0; //shared_ptr used for Proxy Pattern
  virtual void setParent (std::shared_ptr<Expr_Node> node) =0; //shared_ptr used for Proxy Pattern
};


#endif   // !defined _EXPR_NODE_H_
