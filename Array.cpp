// Honor Pledge:
//
// I pledge that I have neither given nor
// received any help on this assignment.
//
//
#include <stdexcept>         // for std::out_of_bounds exception
#define DEFAULT_SIZE 10
//
// Array
//
template <typename T>
Array <T>::Array (void):
    //setting the max_size_ to a default (10)
    max_size_(DEFAULT_SIZE),
    //creating a BaseArray object
    BaseArray<T>()
    {

    }

//
// Array (size_t)
//
template <typename T>
Array <T>::Array (size_t length):
    // set max size equal to length
    max_size_(length),
    BaseArray<T>(length)

    {

    }

//
// Array (size_t, char)
//
template <typename T>
Array <T>::Array (size_t length, T fill):

    //max_size_ is initialized to length

    max_size_(length),
    //use base's fill constructor
    BaseArray<T>(length, fill)

    {

    }


//
// Array (const Array &)
//
template <typename T>
Array <T>::Array (const Array & array):
    //set max size equal to the array's max size and use copy constructor to create a base array
    max_size_(array.max_size()),
    BaseArray<T>(array)
    {

    }

//
// ~Array
//
template <typename T>
Array <T>::~Array (void)
{

    //handled by ~BaseArray()
}



//
// resize
//
template <typename T>
void Array <T>::resize (size_t new_size)
{
    //if the arrays are the same size change the current size to the max size, but nothing else
    if (new_size == this->max_size_)
    {
        this->cur_size_ = max_size_;
        return;
    }
    //else if new_size is bigger, preserve data, allocate new space, copy array over, free up old memory
    else if (new_size > this->max_size())
    {
       size_t old_size = this->size();
       //allocate space for "new_data" a temporary array to store data
       T * new_data = new T[old_size];
       //copy old array data into the "new_data" temp array
       for (int i = 0; i < old_size; i++)
        {
            *(new_data + i) = *(this->data_ + i);

        }
       //delete data_ before reallocating space of size new_size
       delete[] this->data_;
       //allocate new size for the array data after deleting the old data space
       this->data_ = new T[new_size];
       //set max size to new size
       max_size_ = new_size;
       //copying array data
       //checking for j<old_size and j<new_size to ensure we are not accessing data outside of range (precaution)
       for (int j = 0; j < old_size && j < new_size; j++)
        {
            this->set(j, *(new_data + j));

        }
        //cleaning up the temporary holder new_data
       delete[] new_data;
       //change the cur_size_ of array to match the new size
       this->cur_size_ = new_size;
       return;
    }
    //else if the new_size is smaller than the current array, trucate it
    else
    {
        this->cur_size_ = new_size;
        return;
    }
}

// need to overload = operator in this dynamic array because it uses resize

//
// operator =
//
template <typename T>
const Array <T> & Array <T>::operator = (const Array & rhs)
{
    //check for self assignment
    if (this == &rhs)
    {
        return *this;
    }
    if (this->max_size() <= rhs.max_size())
    {
        this->resize(rhs.size());
    }
    for (int i = 0; i < rhs.size() && i < this->size(); i++)
    {
        this->set(i, rhs.get(i));

    }

    return *this;
}
