#ifndef _Evaluate_H_
#define _Evaluate_H_

#include "Stack.h"
#include "Visitor.h"
#include <exception>

class divide_by_zero_exception : public std::exception
  {
  public:
        divide_by_zero_exception (void):
                std::exception()
                {
                }
  };

class mod_by_zero_exception : public std::exception
  {
  public:
        mod_by_zero_exception (void):
                std::exception()
                {
                }
  };


class Evaluate : public Visitor
{
public:
  /// Constructor
  Evaluate (void);

  /// Destructor
   virtual ~Evaluate (void);
  /// Visit Add Node
  virtual void Visit_ADD(ADD & ADD);
  /// Visit Subtract Node
  virtual void Visit_SUBTRACT(SUBTRACT & SUBTRACT);
  /// Visit Multiply Node
  virtual void Visit_MULTIPLY(MULTIPLY & MULTIPLY);
  /// Visit Divide Node
  virtual void Visit_DIVIDE(DIVIDE & DIVIDE);
  /// Visit Mod Node
  virtual void Visit_MOD(MOD & MOD);
  /// Visit Integer Node
  virtual void Visit_INTEGER(INTEGER & INTEGER);
  int result();
private:

  Stack<int>  Result_Stack;

};


#endif   // !defined _Evaluate_H_
