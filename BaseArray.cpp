// Honor Pledge:
//
// I pledge that I have neither given nor
// received any help on this assignment.
//
// 

#include "BaseArray.h"
#include <stdexcept>         // for std::out_of_bounds exception
#define DEFAULT_SIZE 10

//
// BaseArray
//
template <typename T>
BaseArray <T>::BaseArray (void):
    //array size set to 0
    cur_size_(0),
    //allocating cur_size_ amount of memory to DEFAULT_SIZE
    data_(new T[DEFAULT_SIZE])
    {

    }

//
// BaseArray (size_t)
//
template <typename T>
BaseArray <T>::BaseArray (size_t length):
    // set size equal to length
    cur_size_(length)



    {

		if (length == 0)
        {
            //set constructor to default
            this->data_ = new T[DEFAULT_SIZE];
            this->cur_size_ = 0;


        }
        else
        {
            //allocate length data
            data_ = new T[cur_size_];

        }
    }

//
// BaseArray (size_t, char)
//
template <typename T>
BaseArray <T>::BaseArray (size_t length, T fill):

    //cur_size_ are both initialized to length
    cur_size_(length)

    //allocating cur_size_ amount of memory (equal to length in this instance)

    {
		if (length == 0)
        {
            //set length to 1
            this->data_ = new T[DEFAULT_SIZE];
            this->cur_size_ = 0;
            //fill data with fill
            this->fill(fill);
        }
        else
        {
            this->data_ = new T[cur_size_];
            //fill data with fill
            this->fill(fill);
        }

    }


//
// BaseArray (const BaseArray &)
//
template <typename T>
BaseArray <T>::BaseArray (const BaseArray & array)
{
    this->cur_size_ = array.size();
    this->data_ = array.data_;
    for (int i = 0; i > array.size(); i++)
    {
        this->set(i, array.get(i));
    }
}

//
// ~BaseArray
//
template <typename T>
BaseArray <T>::~BaseArray (void)
{
    //delete allocated space
    if(this->data_)
    {

        delete[] this->data_;

    }

}



//
// operator []
//
template <typename T>
T & BaseArray <T>::operator [] (size_t index)
{
    //if the index is larger than the current size throw an exception
    if( cur_size_ <= index)
    {
        throw std::out_of_range ("Index out of range");
    }
    else
    {
        //return the value at the address (data_ + index)
        return *(data_ + index);
    }
}

//
// operator []
//
template <typename T>
const T & BaseArray <T>::operator [] (size_t index) const
{
    //if the index is larger than the current size throw an exception
    if( cur_size_ <= index)
    {
        throw std::out_of_range ("Index out of range");
    }
    else
    {
        //return the value at the address (data_ + index)
        return *(data_ + index);
    }
}

//
// get
//
template <typename T>
T BaseArray <T>::get (size_t index) const
{
    //if the index is larger than the current size throw an exception
    if (cur_size_ <= index)
    {
        throw std::out_of_range ("Index out of range");
    }
    else
    {
        //return the value at the address (data_ + index)
        return *(data_ + index);
    }
}

//
// set
//
template <typename T>
void BaseArray <T>::set (size_t index, T value)
{
    //if the index is larger than the current size throw an exception
    if (cur_size_ <= index)
    {
        throw std::out_of_range ("Index out of range");
    }
    else
    {
        //set the value at (data_ + index) to T value
        *(data_+index) = value;
    }
}



//
// find (char)
//
template  <typename T>
int BaseArray <T>::find (T value) const
{
    // iterate through the array with index i until value is found or end of array is found (cur_size_)
    for (int i = 0; i < cur_size_; i++)
    {
        //check to see if value is equivalent to the character at index i of the array
        if(value == *(data_ + i))
        {
            //return the index i if the typename is found in the array (first instance of value)
            return i;
        }
    }
    //returns -1 if the typename is not found in the array
    return -1;
}

//
// find (char, size_t)
//
template <typename T>
int BaseArray <T>::find (T val, size_t start) const
{
    //make sure the start is less than the size of the array (out of range case)
    if (cur_size_ < start)
    {

        throw std::out_of_range ("Index out of range");
    }
    //if start is within the bounds of the current size of the array, search
    else
    {
        // iterate through the array with index (i + start) until val is found or end of array is found (cur_size_)
        for (int i = 0; (start + i) < cur_size_; i++)
        {
            //check to see if val is equivalent to the character at index (i + start) of the array
            if(val == *(data_ + i + start))
            {
                //return the index i of the character is found in the array (first instance of val)
                return (start + i);
            }
        }
    }
    //returns -1 if the typename is not found in the array
    //(or start is out of bounds of the array and the exception is handled)
    return -1;
}

//
// operator ==
//
template <typename T>
bool BaseArray <T>::operator == (const BaseArray & rhs) const
{
    //check for self comparison
    if (this == &rhs)
    {
        return true;
    }
    // check to see if the two arrays are the same size, if not they cannot be equal so return false
    else if(this->size() != rhs.size())
    {
        return false;
    }
    else
    {
        //checking all elements of the array
        for(int i = 0; i < rhs.size() ; i++)
        {
            if (this->get(i) == rhs.get(i))
            {
                //do nothing
            }
            else
            {
                return false;
            }
        }
        return true;
    }
}

//
// operator !=
//
template <typename T>
bool BaseArray <T>::operator != (const BaseArray & rhs) const
{
    //check for self comparison
    if (this == &rhs)
    {
        return false;
    }
    // check to see if the two arrays are the same size, if not they cannot be equal so return true
    else if(this->size() != rhs.size())
    {
        return true;
    }
    else
    {
        //checking all elements of the array
        for(int i = 0; i < rhs.size() ; i++)
        {
            if (this->get(i) == rhs.get(i))
            {
                //do nothing
            }
            else
            {
                return true;
            }
        }
        return false;
    }
}

//
// fill
//
template <typename T>
void BaseArray <T>::fill (T value)
{
    // for every value in the array, fill with value
    for (int i = 0; i < this->size(); i++)
        {
            *(data_ + i) = value;
        }


}
