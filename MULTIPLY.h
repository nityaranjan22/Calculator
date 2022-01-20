#ifndef _MULTIPLY_H_
#define _MULTIPLY_H_

#include "BinaryExpr.h"

class MULTIPLY : public BinaryExpr
{
public:
  /// Constructor
  MULTIPLY (void);

  /// Destructor
   virtual ~MULTIPLY (void);


  /**
   * accept
   *
   * traverses the tree
   * @param[in]       &Visitor    a reference to the visitor class
   *
   */

  virtual void accept (Visitor & visitor);
   /**
   * Priority
   *
   *
   * @return          priority  an integer giving the priority of the operator
   */
  virtual int Priority (void);



protected:
  /// No protected members
private:

  /// No private members

};


#endif   // !defined _MULTIPLY_H_
