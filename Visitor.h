#ifndef _VISITOR_H_
#define _VISITOR_H_

class ADD;
class SUBTRACT;
class MULTIPLY;
class DIVIDE;
class MOD;
class INTEGER;
class OPEN_PARENTHESES;
class CLOSED_PARENTHESES;

class Visitor
{
public:
  /// Constructor
  Visitor (void);

  /// Destructor
   virtual ~Visitor (void)=0;
  /// Visit Add Node
  virtual void Visit_ADD(ADD & ADD) =0;
  /// Visit Subtract Node
  virtual void Visit_SUBTRACT(SUBTRACT & SUBTRACT) =0;
  /// Visit Multiply Node
  virtual void Visit_MULTIPLY(MULTIPLY & MULTIPLY) =0;
  /// Visit Divide Node
  virtual void Visit_DIVIDE(DIVIDE & DIVIDE) =0;
  /// Visit Mod Node
  virtual void Visit_MOD(MOD & MOD) =0;
  /// Visit Integer Node
  virtual void Visit_INTEGER(INTEGER & INTEGER) =0;
};


#endif   // !defined _VISITOR_H_
