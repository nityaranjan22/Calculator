#ifndef _BinaryExpr_H_
#define _BinaryExpr_H_

#include "Expr_Node.h"
#include <memory>

class BinaryExpr : public Expr_Node
{
public:
  BinaryExpr (void);
   virtual ~BinaryExpr (void);

  virtual void accept (Visitor & visitor) = 0;

  virtual int Priority (void) = 0;

  std::shared_ptr<Expr_Node> getRightChild(void); //shared_ptr used for Proxy Pattern

  std::shared_ptr<Expr_Node> getLeftChild(void); //shared_ptr used for Proxy Pattern

  void setRightChild(std::shared_ptr<Expr_Node> node); //shared_ptr used for Proxy Pattern

  void setLeftChild(std::shared_ptr<Expr_Node> node); //shared_ptr used for Proxy Pattern

  virtual std::shared_ptr<Expr_Node> getParent (void); //shared_ptr used for Proxy Pattern

  virtual void setParent (std::shared_ptr<Expr_Node> node); //shared_ptr used for Proxy Pattern
protected:
    //left child of the expr node
    std::shared_ptr<Expr_Node> leftChild; //shared_ptr used for Proxy Pattern
    //right child of the expr node
    std::shared_ptr<Expr_Node> rightChild; //shared_ptr used for Proxy Pattern
    //parent of the expr node
    std::shared_ptr<Expr_Node> Parent; //shared_ptr used for Proxy Pattern
};


#endif   // !defined _BinaryExpr_H_
