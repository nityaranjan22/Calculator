#ifndef _EXPR_TREE_BUILDER_H_
#define _EXPR_TREE_BUILDER_H_

#include "Expr_Builder.h"
#include "Stack.h"
#include "Expr_Node.h"
#include "Evaluate.h"
#include "ADD.h"
#include "SUBTRACT.h"
#include "DIVIDE.h"
#include "MULTIPLY.h"
#include "MOD.h"
#include "INTEGER.h"
#include "OPEN_PARENTHESES.h"
#include "CLOSED_PARENTHESES.h"
#include <memory>
/**
 * @class Expr Tree Builder
 *
 *  Builds an expression tree
 */

class Expr_Tree_Builder : Expr_Builder
{
public:
  /// Constructor
  Expr_Tree_Builder (void);

  /// Destructor
   virtual ~Expr_Tree_Builder (void);
  /// Build Add Node
  virtual void Build_ADD(void);
  /// Build Subtract Node
  virtual void Build_SUBTRACT(void);
  /// Build Multiply Node
  virtual void Build_MULTIPLY(void);
  /// Build Divide Node
  virtual void Build_DIVIDE(void);
  /// Build Mod Node
  virtual void Build_MOD(void);
  /// Build Integer Node
  virtual void Build_INTEGER(int number);
  /// Build Parentheses Node
  virtual void Build_OPEN_PARENTHESES(void);
  /// Build ClosedParentheses Node
  virtual void Build_CLOSED_PARENTHESES(void);

  void Build_Postfix(std::shared_ptr<Expr_Node> node);

  Expr_Node & Build_Tree(void);
  void findOpenParen(void);
private:

  Stack<std::shared_ptr<Expr_Node> > Operator_Stack;
  Stack<std::shared_ptr<Expr_Node> > Postfix_Stack;

};


#endif   // !defined _EXPR_TREE_BUILDER_H_
