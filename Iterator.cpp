
// curr_ begins at s.size() and will count down to zero for the iterator pattern
template <typename T>
Iterator<T>::Iterator (Stack <T> & s):
    s_ (s), curr_ (s.size())
    {

    }

template <typename T>
Iterator<T>::~Iterator (void)
{


}

template <typename T>
bool Iterator<T>::is_done (void)
{
    //returns true when curr_ is less than or equal to 0
    return this->curr_ <= 0;
}
template <typename T>
void Iterator<T>::advance (void)
{
    //decrement curr_ and pop the stack
     -- this->curr_;
     s_.pop();
     return;
}

template <typename T>
T Iterator<T>::operator * (void)
{
    //get top of the stack
    return this->s_.top();
}

template <typename T>
T * Iterator<T>::operator -> (void)
{
    //return address of the top of the stack
    return &this->s_.top();
}
