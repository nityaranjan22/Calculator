template <typename T>
Stack <T>::Stack (void):
    //build an array object to store data
    arr(Array<T>())
    {

    }


//
// Stack
//
template <typename T>
Stack <T>::Stack (const Stack & stack):




    //set the Arrays equal
    arr(stack.arr)
    {

    }


//
// ~Stack
//
template <typename T>
Stack <T>::~Stack (void)
{

    //handled by ~BaseArray()
}

//
// push
//
template <typename T>
void Stack <T>::push (T element)
{
    //check for the empty stack
    if(this->is_empty())
    {

		this->arr.resize(1);
        //if it's empty, set the first element in the 0 spot
        this->arr.set(this->arr.size()-1, element);
    }
    else
    {
        //otherwise, set the element at the new top of the stack (arr.size()+1)
        this->arr.resize(this->size() + 1);
        this->arr.set(this->arr.size()-1, element);

    }
}

//
// pop
//
template <typename T>
void Stack <T>::pop (void)
{
    //check for the empty stack
    if(this->is_empty())
    {
        throw empty_exception();
    }
    else
    {
        //if the stack isn't empty, resize

        this->arr.resize(arr.size() - 1);
    }
}

//
// operator =
//
template <typename T>
const Stack <T> & Stack <T>::operator = (const Stack & rhs)
{
    //check for self assignment
    if (this == &rhs)
    {
        return *this;
    }

	//set the Arrays equal
    this->arr = rhs.arr;

    return *this;
}

//
// clear
//
template <typename T>
void Stack <T>::clear (void)
{
    this->arr.resize(0);
}
