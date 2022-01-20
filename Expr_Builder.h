#ifndef _EXPR_BUILDER_H_
#define _EXPR_BUILDER_H_
#include "Expr_Node.h"
#include "BinaryExpr.h"
#include "INTEGER.h"



/**
 * @class Eval Expr Tree
 *
 *  Abstraction of the expression tree builder
 */

class Expr_Builder
{
public:
  Expr_Builder (void);
   virtual ~Expr_Builder (void) =0;
  /// Build Add Node
  virtual void Build_ADD(void) =0;
  /// Build Subtract Node
  virtual void Build_SUBTRACT(void) =0;
  /// Build Multiply Node
  virtual void Build_MULTIPLY(void) =0;
  /// Build Divide Node
  virtual void Build_DIVIDE(void) =0;
  /// Build Mod Node
  virtual void Build_MOD(void) =0;
  /// Build Integer Node
  virtual void Build_INTEGER(int number) =0;
  /// Build Parentheses Node
  virtual void Build_OPEN_PARENTHESES(void) =0;
  /// Build Closed Parentheses Node
  virtual void Build_CLOSED_PARENTHESES(void) =0;

  int result(void);
private:

  int int_result;

};


#endif   // !defined _EXPR_BUILDER_H_
