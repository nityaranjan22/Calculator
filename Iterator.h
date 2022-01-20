#ifndef _Iterator_H_
#define _Iterator_H_

#include <cstring>          // for size_t definition
#include "Stack.h"
/**
 * @class Iterator
 *
 * Implementation of the Iterator Pattern
 */
template <typename T>
	class Iterator {
	  public:

        typedef T type;

	    /// Default constructor, requires a Stack<T> s
		Iterator (Stack <T> & s);

		///Default destructor
		~Iterator (void);

      /**
       * is_done function, checks to see if the iterator is finished
       *
       * @return    boolean value
       */
		bool is_done (void);

       /**
       * advance function, decrements our stack iterator, pops the stack
       *
       * @return    boolean value
       */
		void advance (void);

       /**
       * overloaded * operator
       *
       * @return    variable of type T
       */
		T operator * (void);

       /**
       * overloaded -> operator
       *
       * @return    *T pointer to a variable of type T
       */
		T * operator -> (void);

	   private:

		Stack <T> & s_;
		size_t curr_;
};

#include "Iterator.cpp" //include for template class
#endif   // !defined _Iterator_H_
